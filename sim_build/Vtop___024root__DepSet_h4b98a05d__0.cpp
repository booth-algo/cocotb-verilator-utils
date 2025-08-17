// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop__Syms.h"
#include "Vtop___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(Vtop___024root* vlSelf);
#endif  // VL_DEBUG

void Vtop___024root___eval_triggers__ico(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_triggers__ico\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VicoTriggered.setBit(0U, (IData)(vlSelfRef.__VicoFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__ico(vlSelf);
    }
#endif
}

VL_INLINE_OPT void Vtop___024root___ico_sequent__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ico_sequent__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.example_using_interface_tb__DOT__m2s_request 
        = vlSelfRef.m2s_request;
    vlSelfRef.example_using_interface_tb__DOT__m2s_request_valid 
        = vlSelfRef.m2s_request_valid;
    vlSelfRef.example_using_interface_tb__DOT__dut_I__DOT__data_b 
        = vlSelfRef.example_using_interface_tb__DOT__dut_I__DOT__data_r;
    vlSelfRef.example_using_interface_tb__DOT__clk 
        = vlSelfRef.clk;
    vlSelfRef.example_using_interface_tb__DOT__res_n 
        = vlSelfRef.res_n;
    vlSelfRef.example_using_interface_tb__DOT__dut_I__DOT__counter_b 
        = vlSelfRef.example_using_interface_tb__DOT__dut_I__DOT__counter_r;
    vlSelfRef.example_using_interface_tb__DOT__dut_I__DOT__counter_active_b 
        = vlSelfRef.example_using_interface_tb__DOT__dut_I__DOT__counter_active_r;
    if (vlSymsp->TOP__example_using_interface_tb__DOT__example_i.request_valid) {
        vlSelfRef.example_using_interface_tb__DOT__dut_I__DOT__data_b 
            = vlSymsp->TOP__example_using_interface_tb__DOT__example_i.request;
        vlSelfRef.example_using_interface_tb__DOT__dut_I__DOT__counter_b = 0U;
        vlSelfRef.example_using_interface_tb__DOT__dut_I__DOT__counter_active_b = 1U;
    }
    if (vlSelfRef.example_using_interface_tb__DOT__dut_I__DOT__counter_active_b) {
        vlSelfRef.example_using_interface_tb__DOT__dut_I__DOT__counter_b 
            = (7U & ((IData)(1U) + (IData)(vlSelfRef.example_using_interface_tb__DOT__dut_I__DOT__counter_r)));
    }
    vlSymsp->TOP__example_using_interface_tb__DOT__example_i.response_valid = 0U;
    vlSymsp->TOP__example_using_interface_tb__DOT__example_i.response = 0U;
    if ((4U == (IData)(vlSelfRef.example_using_interface_tb__DOT__dut_I__DOT__counter_r))) {
        vlSelfRef.example_using_interface_tb__DOT__dut_I__DOT__counter_active_b = 0U;
        vlSymsp->TOP__example_using_interface_tb__DOT__example_i.response_valid = 1U;
        vlSymsp->TOP__example_using_interface_tb__DOT__example_i.response 
            = vlSelfRef.example_using_interface_tb__DOT__dut_I__DOT__data_r;
    }
    vlSelfRef.example_using_interface_tb__DOT__dut_I__DOT__clk 
        = vlSelfRef.example_using_interface_tb__DOT__clk;
    vlSelfRef.example_using_interface_tb__DOT__dut_I__DOT__res_n 
        = vlSelfRef.example_using_interface_tb__DOT__res_n;
    vlSelfRef.example_using_interface_tb__DOT__s2m_response_valid 
        = vlSymsp->TOP__example_using_interface_tb__DOT__example_i.response_valid;
    vlSelfRef.example_using_interface_tb__DOT__s2m_response 
        = vlSymsp->TOP__example_using_interface_tb__DOT__example_i.response;
    vlSelfRef.s2m_response_valid = vlSelfRef.example_using_interface_tb__DOT__s2m_response_valid;
    vlSelfRef.s2m_response = vlSelfRef.example_using_interface_tb__DOT__s2m_response;
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(Vtop___024root* vlSelf);
#endif  // VL_DEBUG

void Vtop___024root___eval_triggers__act(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_triggers__act\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered.setBit(0U, ((IData)(vlSelfRef.clk) 
                                          & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__clk__0))));
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__act(vlSelf);
    }
#endif
}

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.res_n) {
        vlSymsp->TOP__example_using_interface_tb__DOT__example_i.request 
            = vlSelfRef.m2s_request;
        vlSelfRef.example_using_interface_tb__DOT__dut_I__DOT__data_r 
            = vlSelfRef.example_using_interface_tb__DOT__dut_I__DOT__data_b;
        vlSelfRef.example_using_interface_tb__DOT__dut_I__DOT__counter_r 
            = vlSelfRef.example_using_interface_tb__DOT__dut_I__DOT__counter_b;
    } else {
        vlSymsp->TOP__example_using_interface_tb__DOT__example_i.request = 0U;
        vlSelfRef.example_using_interface_tb__DOT__dut_I__DOT__data_r = 0U;
        vlSelfRef.example_using_interface_tb__DOT__dut_I__DOT__counter_r = 0U;
    }
    vlSymsp->TOP__example_using_interface_tb__DOT__example_i.request_valid 
        = ((IData)(vlSelfRef.res_n) && (IData)(vlSelfRef.m2s_request_valid));
    vlSelfRef.example_using_interface_tb__DOT__dut_I__DOT__counter_active_r 
        = ((IData)(vlSelfRef.res_n) && (IData)(vlSelfRef.example_using_interface_tb__DOT__dut_I__DOT__counter_active_b));
    vlSymsp->TOP__example_using_interface_tb__DOT__example_i.response_valid = 0U;
    vlSymsp->TOP__example_using_interface_tb__DOT__example_i.response = 0U;
    if ((4U == (IData)(vlSelfRef.example_using_interface_tb__DOT__dut_I__DOT__counter_r))) {
        vlSymsp->TOP__example_using_interface_tb__DOT__example_i.response_valid = 1U;
        vlSymsp->TOP__example_using_interface_tb__DOT__example_i.response 
            = vlSelfRef.example_using_interface_tb__DOT__dut_I__DOT__data_r;
    }
    vlSelfRef.example_using_interface_tb__DOT__s2m_response_valid 
        = vlSymsp->TOP__example_using_interface_tb__DOT__example_i.response_valid;
    vlSelfRef.example_using_interface_tb__DOT__s2m_response 
        = vlSymsp->TOP__example_using_interface_tb__DOT__example_i.response;
    vlSelfRef.s2m_response_valid = vlSelfRef.example_using_interface_tb__DOT__s2m_response_valid;
    vlSelfRef.s2m_response = vlSelfRef.example_using_interface_tb__DOT__s2m_response;
}

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__1(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__1\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.example_using_interface_tb__DOT__dut_I__DOT__data_b 
        = vlSelfRef.example_using_interface_tb__DOT__dut_I__DOT__data_r;
    vlSelfRef.example_using_interface_tb__DOT__dut_I__DOT__counter_b 
        = vlSelfRef.example_using_interface_tb__DOT__dut_I__DOT__counter_r;
    vlSelfRef.example_using_interface_tb__DOT__dut_I__DOT__counter_active_b 
        = vlSelfRef.example_using_interface_tb__DOT__dut_I__DOT__counter_active_r;
    if (vlSymsp->TOP__example_using_interface_tb__DOT__example_i.request_valid) {
        vlSelfRef.example_using_interface_tb__DOT__dut_I__DOT__data_b 
            = vlSymsp->TOP__example_using_interface_tb__DOT__example_i.request;
        vlSelfRef.example_using_interface_tb__DOT__dut_I__DOT__counter_b = 0U;
        vlSelfRef.example_using_interface_tb__DOT__dut_I__DOT__counter_active_b = 1U;
    }
    if (vlSelfRef.example_using_interface_tb__DOT__dut_I__DOT__counter_active_b) {
        vlSelfRef.example_using_interface_tb__DOT__dut_I__DOT__counter_b 
            = (7U & ((IData)(1U) + (IData)(vlSelfRef.example_using_interface_tb__DOT__dut_I__DOT__counter_r)));
    }
    if ((4U == (IData)(vlSelfRef.example_using_interface_tb__DOT__dut_I__DOT__counter_r))) {
        vlSelfRef.example_using_interface_tb__DOT__dut_I__DOT__counter_active_b = 0U;
    }
}
