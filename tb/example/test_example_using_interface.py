"""
CocoTB test for example_using_interface module
Tests a module that uses SystemVerilog interfaces
"""

import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, Timer
import random
import os

@cocotb.test()
async def test_interface_basic_response(dut):
    """Test that the interface module responds correctly"""

    # Enable VCD dumping
    if "COCOTB_ENABLE_WAVES" in os.environ:
        dut._log.info("VCD dumping enabled")

    # Setup clock - 10ns period (100MHz)
    clock = Clock(dut.clk, 10, units="ns")
    cocotb.start_soon(clock.start())

    # Reset the DUT
    dut.res_n.value = 0
    dut.m2s_request.value = 0
    dut.m2s_request_valid.value = 0

    # Wait a few cycles in reset
    for _ in range(5):
        await RisingEdge(dut.clk)

    # Release reset
    dut.res_n.value = 1
    await RisingEdge(dut.clk)

    # Test data
    test_data = 0xCAFEBABE

    dut._log.info(f"Sending interface request with data: 0x{test_data:08X}")

    # Send request
    dut.m2s_request.value = test_data
    dut.m2s_request_valid.value = 1
    await RisingEdge(dut.clk)

    # Clear valid after one cycle (pulse)
    dut.m2s_request_valid.value = 0
    await RisingEdge(dut.clk)

    # Wait for response
    response_received = False
    max_wait_cycles = 10  # Safety timeout

    for cycle in range(max_wait_cycles):
        await RisingEdge(dut.clk)

        if dut.s2m_response_valid.value == 1:
            response_data = dut.s2m_response.value
            dut._log.info(f"Interface response received on cycle {cycle + 1}: 0x{int(response_data):08X}")

            # Check if response matches request
            assert int(response_data) == test_data, f"Interface response mismatch! Expected 0x{test_data:08X}, got 0x{int(response_data):08X}"

            response_received = True
            break

    assert response_received, "No interface response received within timeout!"
    dut._log.info("✓ Interface test passed: Correct data received")

@cocotb.test()
async def test_interface_multiple_requests(dut):
    """Test multiple sequential requests through interface"""

    # Setup clock
    clock = Clock(dut.clk, 10, units="ns")
    cocotb.start_soon(clock.start())

    # Reset
    dut.res_n.value = 0
    dut.m2s_request.value = 0
    dut.m2s_request_valid.value = 0

    for _ in range(5):
        await RisingEdge(dut.clk)

    dut.res_n.value = 1
    await RisingEdge(dut.clk)

    # Test multiple requests
    test_values = [0x11111111, 0x22222222, 0x33333333, 0x44444444]

    for i, test_data in enumerate(test_values):
        dut._log.info(f"Interface test {i+1}: Sending 0x{test_data:08X}")

        # Send request
        dut.m2s_request.value = test_data
        dut.m2s_request_valid.value = 1
        await RisingEdge(dut.clk)
        dut.m2s_request_valid.value = 0

        # Wait for response
        response_received = False
        for cycle in range(10):
            await RisingEdge(dut.clk)

            if dut.s2m_response_valid.value == 1:
                response_data = dut.s2m_response.value
                assert int(response_data) == test_data, f"Interface test {i+1} failed: Expected 0x{test_data:08X}, got 0x{int(response_data):08X}"
                response_received = True
                dut._log.info(f"✓ Interface test {i+1} passed: 0x{int(response_data):08X}")
                break

        assert response_received, f"Interface test {i+1}: No response received!"

        # Wait a few extra cycles before next request
        for _ in range(3):
            await RisingEdge(dut.clk)

@cocotb.test()
async def test_interface_no_spurious_response(dut):
    """Test that interface doesn't generate spurious responses"""

    # Setup clock
    clock = Clock(dut.clk, 10, units="ns")
    cocotb.start_soon(clock.start())

    # Reset
    dut.res_n.value = 0
    dut.m2s_request.value = 0
    dut.m2s_request_valid.value = 0

    for _ in range(5):
        await RisingEdge(dut.clk)

    dut.res_n.value = 1
    await RisingEdge(dut.clk)

    # Set request data but don't assert valid
    dut.m2s_request.value = 0x87654321
    dut.m2s_request_valid.value = 0  # Keep valid low

    # Wait for several cycles
    for cycle in range(10):
        await RisingEdge(dut.clk)

        # Should never get a valid response
        assert dut.s2m_response_valid.value == 0, f"Unexpected interface response on cycle {cycle + 1}!"

    dut._log.info("✓ Interface test passed: No spurious responses")

@cocotb.test()
async def test_interface_boundary_values(dut):
    """Test interface with boundary values"""

    # Setup clock
    clock = Clock(dut.clk, 10, units="ns")
    cocotb.start_soon(clock.start())

    # Reset
    dut.res_n.value = 0
    dut.m2s_request.value = 0
    dut.m2s_request_valid.value = 0

    for _ in range(5):
        await RisingEdge(dut.clk)

    dut.res_n.value = 1
    await RisingEdge(dut.clk)

    # Test boundary values
    boundary_values = [
        0x00000000,  # All zeros
        0xFFFFFFFF,  # All ones
        0x80000000,  # MSB set
        0x00000001,  # LSB set
        0x55555555,  # Alternating pattern
        0xAAAAAAAA,  # Inverse alternating pattern
    ]

    for i, test_data in enumerate(boundary_values):
        dut._log.info(f"Interface boundary test {i+1}: 0x{test_data:08X}")

        # Send request
        dut.m2s_request.value = test_data
        dut.m2s_request_valid.value = 1
        await RisingEdge(dut.clk)
        dut.m2s_request_valid.value = 0

        # Wait for response
        response_received = False
        for cycle in range(8):
            await RisingEdge(dut.clk)

            if dut.s2m_response_valid.value == 1:
                response_data = dut.s2m_response.value
                assert int(response_data) == test_data, f"Interface boundary test {i+1} failed!"
                response_received = True
                dut._log.info(f"✓ Interface boundary test {i+1} passed: 0x{int(response_data):08X}")
                break

        assert response_received, f"Interface boundary test {i+1}: No response!"

        # Small delay between tests
        for _ in range(2):
            await RisingEdge(dut.clk)

    dut._log.info("✓ All interface boundary tests passed!")

@cocotb.test()
async def test_interface_reset_behavior(dut):
    """Test interface behavior during and after reset"""

    # Setup clock
    clock = Clock(dut.clk, 10, units="ns")
    cocotb.start_soon(clock.start())

    # Start with reset asserted
    dut.res_n.value = 0
    dut.m2s_request.value = 0xABCDEF00
    dut.m2s_request_valid.value = 1

    # Wait a few cycles in reset
    for cycle in range(5):
        await RisingEdge(dut.clk)
        # Should not see any responses during reset
        assert dut.s2m_response_valid.value == 0, f"Unexpected response during reset on cycle {cycle + 1}"

    # Release reset but keep request active
    dut.res_n.value = 1
    await RisingEdge(dut.clk)

    # Clear request
    dut.m2s_request_valid.value = 0
    await RisingEdge(dut.clk)

    # Now send a proper request to verify normal operation after reset
    test_data = 0x12345678
    dut.m2s_request.value = test_data
    dut.m2s_request_valid.value = 1
    await RisingEdge(dut.clk)
    dut.m2s_request_valid.value = 0

    # Wait for response
    response_received = False
    for cycle in range(10):
        await RisingEdge(dut.clk)

        if dut.s2m_response_valid.value == 1:
            response_data = int(dut.s2m_response.value)
            assert response_data == test_data, f"Post-reset interface test failed!"
            response_received = True
            break

    assert response_received, "No response after reset!"
    dut._log.info("✓ Interface reset behavior test passed!")