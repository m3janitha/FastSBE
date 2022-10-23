/* Generated SBE (Simple Binary Encoding) message codec */
#ifndef _SBETOOL_PARTYIDSOURCEENUM_H_
#define _SBETOOL_PARTYIDSOURCEENUM_H_

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

class PartyIDSourceEnum
{
public:
    enum Value
    {
        BIC = static_cast<char>(66),
        Proprietary = static_cast<char>(67),
        NULL_VALUE = static_cast<char>(0)
    };

    static PartyIDSourceEnum::Value get(const char value)
    {
        switch (value)
        {
            case static_cast<char>(66): return BIC;
            case static_cast<char>(67): return Proprietary;
            case static_cast<char>(0): return NULL_VALUE;
        }

        throw std::runtime_error("unknown value for enum PartyIDSourceEnum [E103]");
    }

    static const char *c_str(const PartyIDSourceEnum::Value value)
    {
        switch (value)
        {
            case BIC: return "BIC";
            case Proprietary: return "Proprietary";
            case NULL_VALUE: return "NULL_VALUE";
        }

        throw std::runtime_error("unknown value for enum PartyIDSourceEnum [E103]:");
    }

    template<typename CharT, typename Traits>
    friend std::basic_ostream<CharT, Traits> & operator << (
        std::basic_ostream<CharT, Traits> &os, PartyIDSourceEnum::Value m)
    {
        return os << PartyIDSourceEnum::c_str(m);
    }
};

}

#endif
