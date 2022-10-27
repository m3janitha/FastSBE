#pragma once
#include<cstdint>
#include<string>
#include<string_view>
#include<ostream>
#include<cstring>

namespace fastsbe
{

class ordStatusEnum
{
    public:
    enum class Value : char
    {
        New = '0',
        PartialFilled = '1',
        Filled = '2',
        DoneForDay = '3',
        Canceled = '4',
        PendingCancel = '6',
        Rejected = '8',
        PendingNew = 'A',
        PendingReplace = 'E',
        nullValue = 0,
    };
    
    public:
    static constexpr const char* to_string(Value value) noexcept
    {
        switch (value)
        {
        case Value::New:
            return "New";
        case Value::PartialFilled:
            return "PartialFilled";
        case Value::Filled:
            return "Filled";
        case Value::DoneForDay:
            return "DoneForDay";
        case Value::Canceled:
            return "Canceled";
        case Value::PendingCancel:
            return "PendingCancel";
        case Value::Rejected:
            return "Rejected";
        case Value::PendingNew:
            return "PendingNew";
        case Value::PendingReplace:
            return "PendingReplace";
        case Value::nullValue:
            return "nullValue";
        default:
            return "Invalid";
        }
    }
};

template <class CharT, class Traits = std::char_traits<CharT>>
inline std::basic_ostream<CharT, Traits> &operator<<(std::basic_ostream<CharT, Traits> &os, const fastsbe::ordStatusEnum::Value val)
{
    os << fastsbe::ordStatusEnum::to_string(val);
    return os;
}

}
