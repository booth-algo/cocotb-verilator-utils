// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop___024root.h"

VL_ATTR_COLD void Vtop___024root___eval_static(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_static\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
}

VL_ATTR_COLD void Vtop___024root___eval_initial(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vtop___024root___eval_final(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_final\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(Vtop___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtop___024root___eval_phase__stl(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_settle(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_settle\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY(((0x64U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("/Users/kev/cocotb-verilator-utils/tb/example/example_using_typedef_tb.sv", 1, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vtop___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelfRef.__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__stl\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VstlTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

void Vtop___024root___ico_sequent__TOP__0(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_stl(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_stl\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        Vtop___024root___ico_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD void Vtop___024root___eval_triggers__stl(Vtop___024root* vlSelf);

VL_ATTR_COLD bool Vtop___024root___eval_phase__stl(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__stl\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vtop___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelfRef.__VstlTriggered.any();
    if (__VstlExecute) {
        Vtop___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__ico\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VicoTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VicoTriggered.word(0U))) {
        VL_DBG_MSGF("         'ico' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__act\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__nba(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__nba\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtop___024root___ctor_var_reset(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ctor_var_reset\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
    vlSelf->clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16707436170211756652ull);
    vlSelf->res_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10971415812964045113ull);
    vlSelf->m2s_request = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12965096087582585472ull);
    vlSelf->m2s_request_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2071901410876432842ull);
    vlSelf->s2m_response = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15828161343962676133ull);
    vlSelf->s2m_response_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2653560739349784382ull);
    vlSelf->example_using_typedef_tb__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12126951971273111874ull);
    vlSelf->example_using_typedef_tb__DOT__res_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15446410485954498443ull);
    vlSelf->example_using_typedef_tb__DOT__m2s_request = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8174121377901335091ull);
    vlSelf->example_using_typedef_tb__DOT__m2s_request_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13777124095620557513ull);
    vlSelf->example_using_typedef_tb__DOT__s2m_response = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17981914879460725200ull);
    vlSelf->example_using_typedef_tb__DOT__s2m_response_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12058237233987987990ull);
    vlSelf->example_using_typedef_tb__DOT__m2s_struct.__PVT__request = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3630873213247995174ull);
    vlSelf->example_using_typedef_tb__DOT__m2s_struct.__PVT__request_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3630873213247995174ull);
    vlSelf->example_using_typedef_tb__DOT__s2m_struct.__PVT__response = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11160816167839561082ull);
    vlSelf->example_using_typedef_tb__DOT__s2m_struct.__PVT__response_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11160816167839561082ull);
    vlSelf->example_using_typedef_tb__DOT__dut_I__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14912448448588283379ull);
    vlSelf->example_using_typedef_tb__DOT__dut_I__DOT__res_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13841393962989404640ull);
    vlSelf->example_using_typedef_tb__DOT__dut_I__DOT__m2s.__PVT__request = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11162793252958764812ull);
    vlSelf->example_using_typedef_tb__DOT__dut_I__DOT__m2s.__PVT__request_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11162793252958764812ull);
    vlSelf->example_using_typedef_tb__DOT__dut_I__DOT__s2m.__PVT__response = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2398854039196077257ull);
    vlSelf->example_using_typedef_tb__DOT__dut_I__DOT__s2m.__PVT__response_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2398854039196077257ull);
    vlSelf->example_using_typedef_tb__DOT__dut_I__DOT__data_b = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 164498539336891568ull);
    vlSelf->example_using_typedef_tb__DOT__dut_I__DOT__data_r = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3213009695105706483ull);
    vlSelf->example_using_typedef_tb__DOT__dut_I__DOT__counter_b = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 9788792507671083585ull);
    vlSelf->example_using_typedef_tb__DOT__dut_I__DOT__counter_r = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 4086885042281624023ull);
    vlSelf->example_using_typedef_tb__DOT__dut_I__DOT__counter_active_b = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13270901412381552830ull);
    vlSelf->example_using_typedef_tb__DOT__dut_I__DOT__counter_active_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11804662912396648364ull);
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9526919608049418986ull);
}
