/* Generated SBE (Simple Binary Encoding) message codec */
#ifndef _SBETOOL_ORDSTATUSENUM_H_
#define _SBETOOL_ORDSTATUSENUM_H_

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

class OrdStatusEnum
{
public:
    enum Value
    {
        New = static_cast<char>(48),
        PartialFilled = static_cast<char>(49),
        Filled = static_cast<char>(50),
        DoneForDay = static_cast<char>(51),
        Canceled = static_cast<char>(52),
        PendingCancel = static_cast<char>(54),
        Rejected = static_cast<char>(56),
        PendingNew = static_cast<char>(65),
        PendingReplace = static_cast<char>(69),
        NULL_VALUE = static_cast<char>(0)
    };

    static OrdStatusEnum::Value get(const char value)
    {
        switch (value)
        {
            case static_cast<char>(48): return New;
            case static_cast<char>(49): return PartialFilled;
            case static_cast<char>(50): return Filled;
            case static_cast<char>(51): return DoneForDay;
            case static_cast<char>(52): return Canceled;
            case static_cast<char>(54): return PendingCancel;
            case static_cast<char>(56): return Rejected;
            case static_cast<char>(65): return PendingNew;
            case static_cast<char>(69): return PendingReplace;
            case static_cast<char>(0): return NULL_VALUE;
        }

        throw std::runtime_error("unknown value for enum OrdStatusEnum [E103]");
    }

    static const char *c_str(const OrdStatusEnum::Value value)
    {
        switch (value)
        {
            case New: return "New";
            case PartialFilled: return "PartialFilled";
            case Filled: return "Filled";
            case DoneForDay: return "DoneForDay";
            case Canceled: return "Canceled";
            case PendingCancel: return "PendingCancel";
            case Rejected: return "Rejected";
            case PendingNew: return "PendingNew";
            case PendingReplace: return "PendingReplace";
            case NULL_VALUE: return "NULL_VALUE";
        }

        throw std::runtime_error("unknown value for enum OrdStatusEnum [E103]:");
    }

    template<typename CharT, typename Traits>
    friend std::basic_ostream<CharT, Traits> & operator << (
        std::basic_ostream<CharT, Traits> &os, OrdStatusEnum::Value m)
    {
        return os << OrdStatusEnum::c_str(m);
    }
};

}

#endif
