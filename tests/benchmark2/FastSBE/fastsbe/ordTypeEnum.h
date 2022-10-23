#pragma once
#include<cstdint>
#include<string>
#include<string_view>
#include<ostream>
#include<cstring>

namespace fastsbe
{

class ordTypeEnum
{
    public:
    enum class Value : char
    {
        Market = '1',
        Limit = '2',
        Stop = '3',
        StopLimit = '4',
        Null = 0,
    };
    
    public:
    static constexpr const char* to_string(Value value) noexcept
    {
        switch (value)
        {
        case Value::Market:
            return "Market";
        case Value::Limit:
            return "Limit";
        case Value::Stop:
            return "Stop";
        case Value::StopLimit:
            return "StopLimit";
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
    , const fastsbe::ordTypeEnum::Value val)
{
    os << fastsbe::ordTypeEnum::to_string(val);
    return os;
}