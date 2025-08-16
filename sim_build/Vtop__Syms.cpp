// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vtop__pch.h"
#include "Vtop.h"
#include "Vtop___024root.h"
#include "Vtop___024unit.h"

// FUNCTIONS
Vtop__Syms::~Vtop__Syms()
{

    // Tear down scope hierarchy
    __Vhier.remove(0, &__Vscope_example_using_typedef_tb);
    __Vhier.remove(&__Vscope_example_using_typedef_tb, &__Vscope_example_using_typedef_tb__dut_I);

}

Vtop__Syms::Vtop__Syms(VerilatedContext* contextp, const char* namep, Vtop* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
{
        // Check resources
        Verilated::stackCheck(25);
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-12);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
    // Setup scopes
    __Vscope_TOP.configure(this, name(), "TOP", "TOP", "<null>", 0, VerilatedScope::SCOPE_OTHER);
    __Vscope_example_using_typedef_tb.configure(this, name(), "example_using_typedef_tb", "example_using_typedef_tb", "example_using_typedef_tb", -12, VerilatedScope::SCOPE_MODULE);
    __Vscope_example_using_typedef_tb__dut_I.configure(this, name(), "example_using_typedef_tb.dut_I", "dut_I", "example_using_typedef", -12, VerilatedScope::SCOPE_MODULE);

    // Set up scope hierarchy
    __Vhier.add(0, &__Vscope_example_using_typedef_tb);
    __Vhier.add(&__Vscope_example_using_typedef_tb, &__Vscope_example_using_typedef_tb__dut_I);

    // Setup export functions
    for (int __Vfinal = 0; __Vfinal < 2; ++__Vfinal) {
        __Vscope_TOP.varInsert(__Vfinal,"clk", &(TOP.clk), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0,0);
        __Vscope_TOP.varInsert(__Vfinal,"m2s_request", &(TOP.m2s_request), false, VLVT_UINT32,VLVD_IN|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_TOP.varInsert(__Vfinal,"m2s_request_valid", &(TOP.m2s_request_valid), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0,0);
        __Vscope_TOP.varInsert(__Vfinal,"res_n", &(TOP.res_n), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0,0);
        __Vscope_TOP.varInsert(__Vfinal,"s2m_response", &(TOP.s2m_response), false, VLVT_UINT32,VLVD_OUT|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_TOP.varInsert(__Vfinal,"s2m_response_valid", &(TOP.s2m_response_valid), false, VLVT_UINT8,VLVD_OUT|VLVF_PUB_RW,0,0);
        __Vscope_example_using_typedef_tb.varInsert(__Vfinal,"DATA_WIDTH", const_cast<void*>(static_cast<const void*>(&(TOP.example_using_typedef_tb__DOT__DATA_WIDTH))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_example_using_typedef_tb.varInsert(__Vfinal,"clk", &(TOP.example_using_typedef_tb__DOT__clk), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_example_using_typedef_tb.varInsert(__Vfinal,"m2s_request", &(TOP.example_using_typedef_tb__DOT__m2s_request), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_example_using_typedef_tb.varInsert(__Vfinal,"m2s_request_valid", &(TOP.example_using_typedef_tb__DOT__m2s_request_valid), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_example_using_typedef_tb.varInsert(__Vfinal,"m2s_struct", &(TOP.example_using_typedef_tb__DOT__m2s_struct), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_example_using_typedef_tb.varInsert(__Vfinal,"res_n", &(TOP.example_using_typedef_tb__DOT__res_n), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_example_using_typedef_tb.varInsert(__Vfinal,"s2m_response", &(TOP.example_using_typedef_tb__DOT__s2m_response), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_example_using_typedef_tb.varInsert(__Vfinal,"s2m_response_valid", &(TOP.example_using_typedef_tb__DOT__s2m_response_valid), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_example_using_typedef_tb.varInsert(__Vfinal,"s2m_struct", &(TOP.example_using_typedef_tb__DOT__s2m_struct), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_example_using_typedef_tb__dut_I.varInsert(__Vfinal,"DATA_WIDTH", const_cast<void*>(static_cast<const void*>(&(TOP.example_using_typedef_tb__DOT__dut_I__DOT__DATA_WIDTH))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_example_using_typedef_tb__dut_I.varInsert(__Vfinal,"clk", &(TOP.example_using_typedef_tb__DOT__dut_I__DOT__clk), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_example_using_typedef_tb__dut_I.varInsert(__Vfinal,"counter_active_b", &(TOP.example_using_typedef_tb__DOT__dut_I__DOT__counter_active_b), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_example_using_typedef_tb__dut_I.varInsert(__Vfinal,"counter_active_r", &(TOP.example_using_typedef_tb__DOT__dut_I__DOT__counter_active_r), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_example_using_typedef_tb__dut_I.varInsert(__Vfinal,"counter_b", &(TOP.example_using_typedef_tb__DOT__dut_I__DOT__counter_b), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,2,0);
        __Vscope_example_using_typedef_tb__dut_I.varInsert(__Vfinal,"counter_r", &(TOP.example_using_typedef_tb__DOT__dut_I__DOT__counter_r), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,2,0);
        __Vscope_example_using_typedef_tb__dut_I.varInsert(__Vfinal,"data_b", &(TOP.example_using_typedef_tb__DOT__dut_I__DOT__data_b), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_example_using_typedef_tb__dut_I.varInsert(__Vfinal,"data_r", &(TOP.example_using_typedef_tb__DOT__dut_I__DOT__data_r), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_example_using_typedef_tb__dut_I.varInsert(__Vfinal,"m2s", &(TOP.example_using_typedef_tb__DOT__dut_I__DOT__m2s), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_example_using_typedef_tb__dut_I.varInsert(__Vfinal,"res_n", &(TOP.example_using_typedef_tb__DOT__dut_I__DOT__res_n), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_example_using_typedef_tb__dut_I.varInsert(__Vfinal,"s2m", &(TOP.example_using_typedef_tb__DOT__dut_I__DOT__s2m), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
    }
}
