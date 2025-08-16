// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP___024ROOT_H_
#define VERILATED_VTOP___024ROOT_H_  // guard

#include "verilated.h"
#include "Vtop___024unit.h"


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop___024root final : public VerilatedModule {
  public:
    // CELLS
    Vtop___024unit* __PVT____024unit;

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(res_n,0,0);
    VL_IN8(m2s_request_valid,0,0);
    VL_OUT8(s2m_response_valid,0,0);
    CData/*0:0*/ example_using_typedef_tb__DOT__clk;
    CData/*0:0*/ example_using_typedef_tb__DOT__res_n;
    CData/*0:0*/ example_using_typedef_tb__DOT__m2s_request_valid;
    CData/*0:0*/ example_using_typedef_tb__DOT__s2m_response_valid;
    CData/*0:0*/ example_using_typedef_tb__DOT__dut_I__DOT__clk;
    CData/*0:0*/ example_using_typedef_tb__DOT__dut_I__DOT__res_n;
    CData/*2:0*/ example_using_typedef_tb__DOT__dut_I__DOT__counter_b;
    CData/*2:0*/ example_using_typedef_tb__DOT__dut_I__DOT__counter_r;
    CData/*0:0*/ example_using_typedef_tb__DOT__dut_I__DOT__counter_active_b;
    CData/*0:0*/ example_using_typedef_tb__DOT__dut_I__DOT__counter_active_r;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __VactContinue;
    VL_IN(m2s_request,31,0);
    VL_OUT(s2m_response,31,0);
    IData/*31:0*/ example_using_typedef_tb__DOT__m2s_request;
    IData/*31:0*/ example_using_typedef_tb__DOT__s2m_response;
    IData/*31:0*/ example_using_typedef_tb__DOT__dut_I__DOT__data_b;
    IData/*31:0*/ example_using_typedef_tb__DOT__dut_I__DOT__data_r;
    IData/*31:0*/ __VactIterCount;
    Vtop_m2s_t__struct__0 example_using_typedef_tb__DOT__m2s_struct;
    Vtop_s2m_t__struct__0 example_using_typedef_tb__DOT__s2m_struct;
    Vtop_m2s_t__struct__0 example_using_typedef_tb__DOT__dut_I__DOT__m2s;
    Vtop_s2m_t__struct__0 example_using_typedef_tb__DOT__dut_I__DOT__s2m;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtop__Syms* const vlSymsp;

    // PARAMETERS
    static constexpr IData/*31:0*/ example_using_typedef_tb__DOT__DATA_WIDTH = 0x00000020U;
    static constexpr IData/*31:0*/ example_using_typedef_tb__DOT__dut_I__DOT__DATA_WIDTH = 0x00000020U;

    // CONSTRUCTORS
    Vtop___024root(Vtop__Syms* symsp, const char* v__name);
    ~Vtop___024root();
    VL_UNCOPYABLE(Vtop___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
