"""
CLI for running tests from YAML config
"""

import argparse, sys, logging, traceback
from pathlib import Path
from tb.common.module_runner import (
    run_test_from_yaml,
    run_test_suite_from_yaml,
    list_available_targets,
    YamlConfig
)

def setup_logging(verbose: bool = False):
    level = logging.DEBUG if verbose else logging.INFO
    logging.basicConfig(
        level=level,
        format='%(asctime)s - %(name)s - %(levelname)s - %(message)s'
    )

def main():
    parser = argparse.ArgumentParser(
        description="Run SystemVerilog tests using YAML config",
        formatter_class=argparse.RawDescriptionHelpFormatter,
        epilog="""
Examples:
    # List available targets
    python -m tb.common.cli --list

    # Run specific test
    python -m tb.common.cli --test=[test_name]

    # Run specific test variant
    python -m tb.common.cli --test=[test_name] --variant=[e.g., basic]

    # Run test suite
    # python -m tb.common.cli --suite=unit_tests

    # Via tox
    tox -e test-module -- --test=[test_name] --variant=wide
    tox -e test-suite -- --suite=regression
        """
    )

    action_group = parser.add_mutually_exclusive_group(required=True)
    action_group.add_argument(
        '--test',
        help='Test to run from YAML config (e.g. test_[module_name])'
    )
    action_group.add_argument(
        '--suite',
        help='Test suite to run from YAML config'
    )
    action_group.add_argument(
        '--list',
        action='store_true',
        help='List all available targets'
    )

    parser.add_argument(
        '--variant',
        help='Specific test variant to run'
    )
    parser.add_argument(
        '--config',
        default='modules.yaml',
        help='Path to YAML config file (default: modules.yaml)'
    )
    parser.add_argument(
        '--verbose', '-v',
        action='store_true',
        help='Enable verbose output'
    )
    parser.add_argument(
        '--dry-run',
        action='store_true',
        help='Show what would be run without actually running it'
    )

    args = parser.parse_args()

    setup_logging(args.verbose)
    logger = logging.getLogger(__name__)

    config_path = Path(args.config)
    if not config_path.exists():
        logger.error(f"Config file {config_path} not found")
        return 1

    try:
        if args.list:
            list_available_targets(args.config)
            return 0

        elif args.test:
            if args.dry_run:
                yaml_config = YamlConfig(args.config)
                test_config = yaml_config.get_test(args.test)

                if test_config:
                    print(f"Would run test: {args.test}")
                    if args.variant:
                        print(f"  Variant: {args.variant}")
                    print(f"  Target module: {test_config.target_module}")
                    print(f"  Testbench: {test_config.testbench_toplevel}")
                    print(f"  Sources: {test_config.get_all_sources()}")
                else:
                    logger.error(f"Test {args.test} not found")
                    return 1
            else:
                run_test_from_yaml(args.test, args.variant, args.config)
            return 0

        elif args.suite:
            if args.dry_run:
                yaml_config = YamlConfig(args.config)
                test_names = yaml_config.get_test_suite(args.suite)
                print(f"Would run test suite: {args.suite}")
                print(f"  Tests: {test_names}")
            else:
                run_test_suite_from_yaml(args.suite, args.config)
            return 0

    except Exception as e:
        logger.error(f"Error: {e}")
        if args.verbose:
            traceback.print_exc()
        return 1

if __name__ == "__main__":
    sys.exit(main())
