/* Generated SBE (Simple Binary Encoding) message codec */
#ifndef _SBETOOL_ORDTYPEENUM_H_
#define _SBETOOL_ORDTYPEENUM_H_

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

class OrdTypeEnum
{
public:
    enum Value
    {
        Market = static_cast<char>(49),
        Limit = static_cast<char>(50),
        Stop = static_cast<char>(51),
        StopLimit = static_cast<char>(52),
        NULL_VALUE = static_cast<char>(0)
    };

    static OrdTypeEnum::Value get(const char value)
    {
        switch (value)
        {
            case static_cast<char>(49): return Market;
            case static_cast<char>(50): return Limit;
            case static_cast<char>(51): return Stop;
            case static_cast<char>(52): return StopLimit;
            case static_cast<char>(0): return NULL_VALUE;
        }

        throw std::runtime_error("unknown value for enum OrdTypeEnum [E103]");
    }

    static const char *c_str(const OrdTypeEnum::Value value)
    {
        switch (value)
        {
            case Market: return "Market";
            case Limit: return "Limit";
            case Stop: return "Stop";
            case StopLimit: return "StopLimit";
            case NULL_VALUE: return "NULL_VALUE";
        }

        throw std::runtime_error("unknown value for enum OrdTypeEnum [E103]:");
    }

    template<typename CharT, typename Traits>
    friend std::basic_ostream<CharT, Traits> & operator << (
        std::basic_ostream<CharT, Traits> &os, OrdTypeEnum::Value m)
    {
        return os << OrdTypeEnum::c_str(m);
    }
};

}

#endif
