#!/usr/bin/env python3
"""
Combined Cocotb Verilator runner that handles SystemVerilog compilation correctly
"""

import re
import sys
import shutil
import argparse
from pathlib import Path
from datetime import datetime
from os import getenv, environ

from cocotb.runner import get_runner

# -------- helper: collect all include directories ---------------------
INCLUDE_RE = re.compile(r'`include\s+"([^"]+\.sv)"')

def collect_include_dirs(source_files: list[Path], base_rtl: Path) -> set[Path]:
    """
    Return every directory that contains at least one file that is
    referenced by an `include in any of the given sources.
    """
    dirs = set()
    for sv in source_files:
        if not sv.exists():
            continue
        txt = sv.read_text(encoding="utf-8", errors="ignore")
        for inc in INCLUDE_RE.findall(txt):
            # resolve relative to the file that contains the include
            candidate = sv.parent / inc
            if candidate.is_file():
                dirs.add(candidate.parent.resolve())
                continue
            # also try relative to the rtl root
            candidate = base_rtl / inc
            if candidate.is_file():
                dirs.add(candidate.parent.resolve())
                continue
            # finally, try rtl/common
            candidate = base_rtl / "common" / Path(inc).name
            if candidate.is_file():
                dirs.add(candidate.parent.resolve())
    return dirs

def get_files_included_by(sv_file: Path, rtl_dir: Path) -> set[Path]:
    """
    Recursively find all files included by a SystemVerilog file via `include statements
    """
    included_files = set()

    if not sv_file.exists():
        return included_files

    txt = sv_file.read_text(encoding="utf-8", errors="ignore")
    for inc in INCLUDE_RE.findall(txt):
        # Try different search paths
        for search_path in [sv_file.parent, rtl_dir / "common", rtl_dir]:
            candidate = search_path / inc
            if candidate.exists():
                resolved_candidate = candidate.resolve()
                included_files.add(resolved_candidate)
                # Recursively find files included by this file
                included_files.update(get_files_included_by(resolved_candidate, rtl_dir))
                break

    return included_files

def get_unique_sv_files(main_file: Path, rtl_dir: Path) -> list[Path]:
    """
    Get only the main SystemVerilog file for compilation.
    Files included via `include directives should NOT be passed as separate sources.
    """
    required_files = set()

    # Add the main file
    if main_file.exists():
        required_files.add(main_file.resolve())

    # Find what files are included by the main file
    included_files = get_files_included_by(main_file, rtl_dir)

    print(f"Files included via `include directives (will NOT be compiled separately):")
    for inc_file in sorted(included_files):
        print(f"  {inc_file}")

    # Do NOT add files that are included via `include - they'll be processed by the preprocessor
    # Only add files that are NOT included but might be needed as separate compilation units

    potential_additional_files = [
        "axi4_read_if.sv",
        "axi_stream_if.sv"
    ]

    for interface in potential_additional_files:
        interface_path = (rtl_dir / "common" / interface).resolve()
        # Only add if it exists AND is not already included by the main file
        if interface_path.exists() and interface_path not in included_files:
            required_files.add(interface_path)

    # Convert back to list and sort for consistent ordering
    return sorted(list(required_files))

def move_waveform_file(test_dir: Path, module_under_test: str, test_files_dir: Path) -> None:
    """Move and timestamp waveform files"""
    waves_dir = test_dir / 'waves'
    waves_dir.mkdir(parents=True, exist_ok=True)

    # Look for VCD file in multiple locations
    sim_build_dir = test_dir / 'sim_build'
    possible_vcd_locations = [
        sim_build_dir / 'dump.vcd',
        sim_build_dir / 'trace.vcd',
        sim_build_dir / f'{module_under_test}.vcd',
        test_files_dir / 'dump.vcd',  # Check test directory too
        test_files_dir / 'trace.vcd',
        test_files_dir / f'{module_under_test}.vcd'
    ]

    src_vcd = None
    for vcd_path in possible_vcd_locations:
        if vcd_path.exists():
            src_vcd = vcd_path
            print(f"Found VCD file: {src_vcd}")
            break

    if src_vcd is None:
        print("Warning: No waveform file found in expected locations:")
        for loc in possible_vcd_locations:
            print(f"  {loc} - {'exists' if loc.exists() else 'not found'}")

        # List all VCD files in both directories to help debug
        all_vcd_files = []
        for search_dir in [sim_build_dir, test_files_dir]:
            if search_dir.exists():
                vcd_files = list(search_dir.glob("*.vcd"))
                all_vcd_files.extend(vcd_files)

        if all_vcd_files:
            print(f"Found VCD files in other locations: {all_vcd_files}")
            src_vcd = all_vcd_files[0]  # Use the first one found
        else:
            print("No .vcd files found anywhere")
            return

    dest_vcd = waves_dir / 'dump.vcd'
    shutil.copy(str(src_vcd), str(dest_vcd))

    timestamped_filename = datetime.now().strftime('%y%m%d_%H%M%S_') + module_under_test + '.vcd'
    timestamped_vcd = waves_dir / timestamped_filename
    shutil.copy(str(dest_vcd), str(timestamped_vcd))

    record_file = waves_dir / 'record.txt'
    with record_file.open('a') as record:
        record.write(f'{timestamped_filename}\n')
    print(f'Waveform {timestamped_filename} saved and recorded.')

def run_single_test(
    module_under_test: str,
    enable_trace: bool = False,
    test_module: str = None
) -> dict:
    """
    Run a single cocotb test for the specified module
    """
    current_dir = Path(__file__).parent
    project_dir = current_dir.parent
    rtl_dir = project_dir / 'rtl'
    test_dir = current_dir
    sim_build_dir = current_dir / 'sim_build'

    print("#" * 40)
    print(f"# Testing {module_under_test}")
    print("#" * 40)

    # 1. Find the top-level SV file
    sv_file_path = None
    for candidate in rtl_dir.rglob(f'{module_under_test}.sv'):
        if candidate.is_file():
            sv_file_path = candidate
            break

    if sv_file_path is None:
        raise FileNotFoundError(f"Cannot find {module_under_test}.sv anywhere under {rtl_dir}")

    # 2. Get unique set of required SV files (prevents duplicates)
    required_sv_files = get_unique_sv_files(sv_file_path, rtl_dir)

    print("Files being compiled:")
    for f in required_sv_files:
        print(f"  {f}")

    # 3. Gather include directories
    include_dirs = collect_include_dirs(required_sv_files, rtl_dir)
    # Add common directory explicitly
    include_dirs.add((rtl_dir / "common").resolve())

    # Convert to list for consistent ordering
    include_paths = sorted(list(include_dirs))

    print("\nInclude paths being used:")
    for path in include_paths:
        print(f"  -I{path}")

    # 4. Clean build directory
    if sim_build_dir.exists():
        shutil.rmtree(sim_build_dir)
    print('\nRemoved all previous sim_build.* files/directories.')
    sim_build_dir.mkdir(parents=True, exist_ok=True)

    # 5. Find or default the python testbench
    if test_module is None:
        py_testbench_file = None
        for candidate in test_dir.rglob(f'{module_under_test}_test.py'):
            if candidate.is_file():
                py_testbench_file = candidate
                break
        test_module = py_testbench_file.stem if py_testbench_file else f"{module_under_test}_test"

    # 6. Set up environment - find the directory containing the test file
    if py_testbench_file and py_testbench_file.exists():
        test_files_dir = py_testbench_file.parent
        print(f"Found test file: {py_testbench_file}")
    else:
        test_files_dir = test_dir
        print(f"Test file not found, using default directory: {test_files_dir}")

    sys.path.insert(0, str(test_files_dir))
    print(f"Added to Python path: {test_files_dir}")

    environ['PYTHONPYCACHEPREFIX'] = str(sim_build_dir / '__pycache__')
    environ['GMON_OUT_PREFIX'] = str(sim_build_dir)

    # 7. Initialize runner
    runner = get_runner(getenv("SIM", "verilator"))

    # 8. Build the simulation
    try:
        print("\nBuilding simulation...")
        runner.build(
            verilog_sources=[str(f) for f in required_sv_files],
            includes=[str(p) for p in include_paths],
            hdl_toplevel=module_under_test,
            build_args=[
                "-Wno-GENUNNAMED",
                "-Wno-WIDTHEXPAND",
                "-Wno-WIDTHTRUNC",
                "-Wno-UNOPTFLAT",
                "-prof-c",
                "--assert",
                "--stats",
                "-O2",
                "-build-jobs", "8",
                "-Wno-fatal",
                "-Wno-lint",
                "-Wno-style",
            ],
            build_dir=sim_build_dir,
            waves=enable_trace
        )
        print("Build completed successfully!")

    except Exception as build_error:
        print(f"\nBuild failed: {build_error}")
        return {
            "success": False,
            "error": str(build_error),
            "stage": "build"
        }

    # 9. Run the test
    try:
        print("\nRunning test...")
        runner.test(
            hdl_toplevel=module_under_test,
            hdl_toplevel_lang="verilog",
            test_module=test_module,
            results_xml=str(sim_build_dir / "results.xml"),
            build_dir=sim_build_dir,
            test_dir=str(test_files_dir),
            waves=enable_trace
        )
        print("Test completed successfully!")

        # Move waveform files if tracing was enabled
        if enable_trace:
            move_waveform_file(test_dir, module_under_test, test_files_dir)

        return {
            "success": True,
            "module": module_under_test,
            "test_module": test_module
        }

    except Exception as test_error:
        print(f"\nTest failed: {test_error}")
        return {
            "success": False,
            "error": str(test_error),
            "stage": "test"
        }

def main():
    parser = argparse.ArgumentParser(description='Combined Cocotb Verilator runner')
    parser.add_argument('-n', '--name', type=str, required=True,
                       help='Name of the module being tested (without .sv extension)')
    parser.add_argument('-t', '--trace', type=int, default=0,
                       help='Enable trace waveform (1 or 0)')
    parser.add_argument('--test-module', type=str,
                       help='Override test module name (default: <module>_test)')

    args = parser.parse_args()

    module_under_test = args.name
    enable_trace = bool(args.trace)
    test_module = args.test_module

    try:
        result = run_single_test(
            module_under_test=module_under_test,
            enable_trace=enable_trace,
            test_module=test_module
        )

        if result["success"]:
            print(f"\n✅ SUCCESS: {module_under_test} test passed!")
            sys.exit(0)
        else:
            print(f"\n❌ FAILED: {module_under_test} test failed at {result['stage']}")
            print(f"Error: {result['error']}")
            sys.exit(1)

    except Exception as e:
        print(f"\n❌ FATAL ERROR: {e}")
        sys.exit(1)

if __name__ == '__main__':
    main()
