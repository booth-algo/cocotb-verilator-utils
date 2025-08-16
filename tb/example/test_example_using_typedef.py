"""
CocoTB test for example_using_typedef module
Tests a module that responds with the same data 4 cycles later
"""

import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, Timer
import random

@cocotb.test()
async def test_basic_response(dut):
    """Test that the module responds with same data after 4 cycles"""

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
    test_data = 0xDEADBEEF

    dut._log.info(f"Sending request with data: 0x{test_data:08X}")

    # Send request
    dut.m2s_request.value = test_data
    dut.m2s_request_valid.value = 1
    await RisingEdge(dut.clk)

    # Clear valid after one cycle (pulse)
    dut.m2s_request_valid.value = 0
    await RisingEdge(dut.clk)

    # Wait for response (should take 4 cycles)
    # The module counts 0->1->2->3->4, responds on cycle when counter==4
    response_received = False
    max_wait_cycles = 10  # Safety timeout

    for cycle in range(max_wait_cycles):
        await RisingEdge(dut.clk)

        if dut.s2m_response_valid.value == 1:
            response_data = dut.s2m_response.value
            dut._log.info(f"Response received on cycle {cycle + 1}: 0x{int(response_data):08X}")

            # Check if response matches request
            assert int(response_data) == test_data, f"Response mismatch! Expected 0x{test_data:08X}, got 0x{int(response_data):08X}"

            # Check timing - should be exactly 4 cycles after request
            expected_cycle = 4  # Based on your DUT logic
            assert cycle + 1 == expected_cycle, f"Response timing wrong! Expected cycle {expected_cycle}, got cycle {cycle + 1}"

            response_received = True
            break

    assert response_received, "No response received within timeout!"
    dut._log.info("✓ Test passed: Correct data received at correct time")

@cocotb.test()
async def test_multiple_requests(dut):
    """Test multiple sequential requests"""

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
    test_values = [0x12345678, 0xABCDEF00, 0x55AA55AA]

    for i, test_data in enumerate(test_values):
        dut._log.info(f"Test {i+1}: Sending 0x{test_data:08X}")

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
                assert int(response_data) == test_data, f"Test {i+1} failed: Expected 0x{test_data:08X}, got 0x{int(response_data):08X}"
                response_received = True
                dut._log.info(f"✓ Test {i+1} passed: 0x{int(response_data):08X}")
                break

        assert response_received, f"Test {i+1}: No response received!"

        # Wait a few extra cycles before next request
        for _ in range(3):
            await RisingEdge(dut.clk)

@cocotb.test()
async def test_no_response_without_valid(dut):
    """Test that no response occurs without valid signal"""

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
    dut.m2s_request.value = 0x12345678
    dut.m2s_request_valid.value = 0  # Keep valid low

    # Wait for several cycles
    for cycle in range(10):
        await RisingEdge(dut.clk)

        # Should never get a valid response
        assert dut.s2m_response_valid.value == 0, f"Unexpected response on cycle {cycle + 1}!"

    dut._log.info("✓ Test passed: No response without valid signal")

@cocotb.test()
async def test_random_data(dut):
    """Test with random data values"""

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

    # Test with random data
    for test_num in range(5):
        # Generate random 32-bit value
        test_data = random.randint(0, 0xFFFFFFFF)
        dut._log.info(f"Random test {test_num + 1}: 0x{test_data:08X}")

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
                assert int(response_data) == test_data, f"Random test {test_num + 1} failed!"
                response_received = True
                break

        assert response_received, f"Random test {test_num + 1}: No response!"

        # Small delay between tests
        for _ in range(2):
            await RisingEdge(dut.clk)

    dut._log.info("✓ All random tests passed!")