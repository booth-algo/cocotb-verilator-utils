"""
Unit tests for the cocotb-yaml-runner package
These test the Python code itself, not HDL designs
"""

import pytest
import tempfile
import yaml
from pathlib import Path

from cocotb_yaml_runner import YamlConfig, ModuleConfig, TestConfig


def test_yaml_config_loading():
    """Test that YamlConfig can load a valid YAML file"""
    test_config = {
        'modules': {
            'test_module': {
                'sources': ['test.sv'],
                'toplevel': 'test_module'
            }
        },
        'config': {
            'simulator': 'verilator'
        }
    }

    with tempfile.NamedTemporaryFile(mode='w', suffix='.yaml', delete=False) as f:
        yaml.dump(test_config, f)
        temp_path = f.name

    try:
        config = YamlConfig(temp_path)
        assert config.config['config']['simulator'] == 'verilator'
        assert 'test_module' in config.list_modules()
    finally:
        Path(temp_path).unlink()


def test_module_config_sources():
    """Test that ModuleConfig correctly resolves dependencies"""
    test_config = {
        'libraries': {
            'common': {
                'sources': ['common.sv']
            }
        },
        'modules': {
            'test_module': {
                'sources': ['test.sv'],
                'deps': ['common'],
                'toplevel': 'test_module'
            }
        }
    }

    with tempfile.NamedTemporaryFile(mode='w', suffix='.yaml', delete=False) as f:
        yaml.dump(test_config, f)
        temp_path = f.name

    try:
        yaml_config = YamlConfig(temp_path)
        module_config = yaml_config.get_module('test_module')

        sources = module_config.sources
        assert 'test.sv' in sources
        assert 'common.sv' in sources
    finally:
        Path(temp_path).unlink()


def test_missing_config_file():
    """Test that YamlConfig raises appropriate error for missing file"""
    with pytest.raises(FileNotFoundError):
        YamlConfig('nonexistent.yaml')


def test_cli_init_command():
    """Test that init command creates expected files"""
    pass