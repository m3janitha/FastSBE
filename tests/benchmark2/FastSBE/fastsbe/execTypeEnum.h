#pragma once
#include<cstdint>
#include<string>
#include<string_view>
#include<ostream>
#include<cstring>

namespace fastsbe
{

class execTypeEnum
{
    public:
    enum class Value : char
    {
        New = '0',
        DoneForDay = '3',
        Canceled = '4',
        Replaced = '5',
        PendingCancel = '6',
        Rejected = '8',
        PendingNew = 'A',
        Trade = 'F',
        Null = 0,
    };
    
    public:
    static constexpr const char* to_string(Value value) noexcept
    {
        switch (value)
        {
        case Value::New:
            return "New";
        case Value::DoneForDay:
            return "DoneForDay";
        case Value::Canceled:
            return "Canceled";
        case Value::Replaced:
            return "Replaced";
        case Value::PendingCancel:
            return "PendingCancel";
        case Value::Rejected:
            return "Rejected";
        case Value::PendingNew:
            return "PendingNew";
        case Value::Trade:
            return "Trade";
        case Value::Null:
            return "Null";
        default:
            return "Invalid";
        }
    }
};
}

template <class CharT, class Traits = std::char_traits<CharT>>
inline std::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT, Traits>& os
    , const fastsbe::execTypeEnum::Value val)
{
    os << fastsbe::execTypeEnum::to_string(val);
    return os;
}