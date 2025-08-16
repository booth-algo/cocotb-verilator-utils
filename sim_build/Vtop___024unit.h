// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP___024UNIT_H_
#define VERILATED_VTOP___024UNIT_H_  // guard

#include "verilated.h"
#include "Vtop___024unit.h"


class Vtop__Syms;
struct Vtop_m2s_t__struct__0 {
    IData/*31:0*/ __PVT__request;
    CData/*0:0*/ __PVT__request_valid;

    bool operator==(const Vtop_m2s_t__struct__0& rhs) const {
        return __PVT__request == rhs.__PVT__request
            && __PVT__request_valid == rhs.__PVT__request_valid;
    }
    bool operator!=(const Vtop_m2s_t__struct__0& rhs) const {
        return !(*this == rhs);
    }

    bool operator<(const Vtop_m2s_t__struct__0& rhs) const {
        return std::tie(__PVT__request, __PVT__request_valid)
            <  std::tie(rhs.__PVT__request, rhs.__PVT__request_valid);
    }
};
template <>
struct VlIsCustomStruct<Vtop_m2s_t__struct__0> : public std::true_type {};
struct Vtop_s2m_t__struct__0 {
    IData/*31:0*/ __PVT__response;
    CData/*0:0*/ __PVT__response_valid;

    bool operator==(const Vtop_s2m_t__struct__0& rhs) const {
        return __PVT__response == rhs.__PVT__response
            && __PVT__response_valid == rhs.__PVT__response_valid;
    }
    bool operator!=(const Vtop_s2m_t__struct__0& rhs) const {
        return !(*this == rhs);
    }

    bool operator<(const Vtop_s2m_t__struct__0& rhs) const {
        return std::tie(__PVT__response, __PVT__response_valid)
            <  std::tie(rhs.__PVT__response, rhs.__PVT__response_valid);
    }
};
template <>
struct VlIsCustomStruct<Vtop_s2m_t__struct__0> : public std::true_type {};

class alignas(VL_CACHE_LINE_BYTES) Vtop___024unit final : public VerilatedModule {
  public:

    // INTERNAL VARIABLES
    Vtop__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtop___024unit(Vtop__Syms* symsp, const char* v__name);
    ~Vtop___024unit();
    VL_UNCOPYABLE(Vtop___024unit);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};

std::string VL_TO_STRING(const Vtop_m2s_t__struct__0& obj);
std::string VL_TO_STRING(const Vtop_s2m_t__struct__0& obj);

#endif  // guard
