// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_fst_c.h"
#include "Vtop__Syms.h"


void Vtop___024root__trace_chg_0_sub_0(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp);

void Vtop___024root__trace_chg_0(void* voidSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_0\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vtop___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vtop___024root__trace_chg_0_sub_0(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_0_sub_0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    bufp->chgBit(oldp+0,(vlSelfRef.clk));
    bufp->chgBit(oldp+1,(vlSelfRef.res_n));
    bufp->chgIData(oldp+2,(vlSelfRef.m2s_request),32);
    bufp->chgBit(oldp+3,(vlSelfRef.m2s_request_valid));
    bufp->chgIData(oldp+4,(vlSelfRef.s2m_response),32);
    bufp->chgBit(oldp+5,(vlSelfRef.s2m_response_valid));
    bufp->chgBit(oldp+6,(vlSelfRef.example_using_interface_tb__DOT__clk));
    bufp->chgBit(oldp+7,(vlSelfRef.example_using_interface_tb__DOT__res_n));
    bufp->chgIData(oldp+8,(vlSelfRef.example_using_interface_tb__DOT__m2s_request),32);
    bufp->chgBit(oldp+9,(vlSelfRef.example_using_interface_tb__DOT__m2s_request_valid));
    bufp->chgIData(oldp+10,(vlSelfRef.example_using_interface_tb__DOT__s2m_response),32);
    bufp->chgBit(oldp+11,(vlSelfRef.example_using_interface_tb__DOT__s2m_response_valid));
    bufp->chgBit(oldp+12,(vlSelfRef.example_using_interface_tb__DOT__dut_I__DOT__clk));
    bufp->chgBit(oldp+13,(vlSelfRef.example_using_interface_tb__DOT__dut_I__DOT__res_n));
    bufp->chgIData(oldp+14,(vlSelfRef.example_using_interface_tb__DOT__dut_I__DOT__data_b),32);
    bufp->chgIData(oldp+15,(vlSelfRef.example_using_interface_tb__DOT__dut_I__DOT__data_r),32);
    bufp->chgCData(oldp+16,(vlSelfRef.example_using_interface_tb__DOT__dut_I__DOT__counter_b),3);
    bufp->chgCData(oldp+17,(vlSelfRef.example_using_interface_tb__DOT__dut_I__DOT__counter_r),3);
    bufp->chgBit(oldp+18,(vlSelfRef.example_using_interface_tb__DOT__dut_I__DOT__counter_active_b));
    bufp->chgBit(oldp+19,(vlSelfRef.example_using_interface_tb__DOT__dut_I__DOT__counter_active_r));
    bufp->chgIData(oldp+20,(vlSymsp->TOP__example_using_interface_tb__DOT__example_i.request),32);
    bufp->chgIData(oldp+21,(vlSymsp->TOP__example_using_interface_tb__DOT__example_i.response),32);
    bufp->chgBit(oldp+22,(vlSymsp->TOP__example_using_interface_tb__DOT__example_i.request_valid));
    bufp->chgBit(oldp+23,(vlSymsp->TOP__example_using_interface_tb__DOT__example_i.response_valid));
}

void Vtop___024root__trace_cleanup(void* voidSelf, VerilatedFst* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_cleanup\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VlUnpacked<CData/*0:0*/, 1> __Vm_traceActivity;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        __Vm_traceActivity[__Vi0] = 0;
    }
    // Body
    vlSymsp->__Vm_activity = false;
    __Vm_traceActivity[0U] = 0U;
}
