# Utils for cocotb with Verilator

### Purpose of the project

Setting up a testbench that automatically

### Requirements

- Verilator (developed on 5.038, any Verilator version 5.X should work)
- cocotb (cocotb-config) >= 1.8.0 (developed on 1.9.2)

### What does this repo contain?

`cocotb-yaml-runner`: a pip package which setups with `cocotb` with `Verilator` and uses `yaml` to create a simplified build system, similar to Bazel.

### (temporary) Instructions to build Python package locally
- To test out its functionality in this repository, go to `cocotb-yaml-runner/` and run `pip install -e .` to install the pip package in active development mode.
- Go back to `/`.
- Run `cocotb-yaml --help` to explore options.
- For example, `cocotb-yaml --test test_example_using_interface`.

Setting up package in another repository:
- First run `cocotb-yaml init`, which should initialize a `.yaml` template.
- TBD: Need better support for this

### (new) Instructions
- The `cocotb-yaml-runner` has been uploaded to PyPI.
- Link: https://pypi.org/project/cocotb-yaml-runner/

### Notes
- The repository gives an example of how you might want to structure your codebase with the `cocotb-yaml-runner`. It provides two examples, one with a testbench wrapper for interfaces, and another one for typedefs. The reason is that Verilator does not directly support interfaces or typedefs inputs and outputs in a module's port map.
- Originally developed with `tox`, hence why there is a `tox.ini` file. This will be kept or maybe phase out shortly after.
- The .gitignore of this repository is incomplete.
