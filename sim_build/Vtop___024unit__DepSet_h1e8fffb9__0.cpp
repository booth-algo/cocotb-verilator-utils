// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop___024unit.h"

std::string VL_TO_STRING(const Vtop_m2s_t__struct__0& obj) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop___024unit::VL_TO_STRING\n"); );
    // Body
    std::string out;
    out += "'{request:" + VL_TO_STRING(obj.__PVT__request);
        out += ", request_valid:" + VL_TO_STRING(obj.__PVT__request_valid);
        out += "}";
    return out;
}

std::string VL_TO_STRING(const Vtop_s2m_t__struct__0& obj) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop___024unit::VL_TO_STRING\n"); );
    // Body
    std::string out;
    out += "'{response:" + VL_TO_STRING(obj.__PVT__response);
        out += ", response_valid:" + VL_TO_STRING(obj.__PVT__response_valid);
        out += "}";
    return out;
}
