/* Generated SBE (Simple Binary Encoding) message codec */
#ifndef _SBETOOL_SIDEENUM_H_
#define _SBETOOL_SIDEENUM_H_

#if !defined(__STDC_LIMIT_MACROS)
#  define __STDC_LIMIT_MACROS 1
#endif

#include <cstdint>
#include <iomanip>
#include <limits>
#include <ostream>
#include <stdexcept>
#include <sstream>
#include <string>

#define SBE_NULLVALUE_INT8 (std::numeric_limits<std::int8_t>::min)()
#define SBE_NULLVALUE_INT16 (std::numeric_limits<std::int16_t>::min)()
#define SBE_NULLVALUE_INT32 (std::numeric_limits<std::int32_t>::min)()
#define SBE_NULLVALUE_INT64 (std::numeric_limits<std::int64_t>::min)()
#define SBE_NULLVALUE_UINT8 (std::numeric_limits<std::uint8_t>::max)()
#define SBE_NULLVALUE_UINT16 (std::numeric_limits<std::uint16_t>::max)()
#define SBE_NULLVALUE_UINT32 (std::numeric_limits<std::uint32_t>::max)()
#define SBE_NULLVALUE_UINT64 (std::numeric_limits<std::uint64_t>::max)()

namespace sbetool {

class SideEnum
{
public:
    enum Value
    {
        Buy = static_cast<char>(49),
        Sell = static_cast<char>(50),
        NULL_VALUE = static_cast<char>(0)
    };

    static SideEnum::Value get(const char value)
    {
        switch (value)
        {
            case static_cast<char>(49): return Buy;
            case static_cast<char>(50): return Sell;
            case static_cast<char>(0): return NULL_VALUE;
        }

        throw std::runtime_error("unknown value for enum SideEnum [E103]");
    }

    static const char *c_str(const SideEnum::Value value)
    {
        switch (value)
        {
            case Buy: return "Buy";
            case Sell: return "Sell";
            case NULL_VALUE: return "NULL_VALUE";
        }

        throw std::runtime_error("unknown value for enum SideEnum [E103]:");
    }

    template<typename CharT, typename Traits>
    friend std::basic_ostream<CharT, Traits> & operator << (
        std::basic_ostream<CharT, Traits> &os, SideEnum::Value m)
    {
        return os << SideEnum::c_str(m);
    }
};

}

#endif
