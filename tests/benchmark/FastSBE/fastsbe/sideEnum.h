#pragma once
#include<cstdint>
#include<string>
#include<string_view>
#include<ostream>
#include<cstring>

namespace fastsbe
{

class sideEnum
{
    public:
    enum class Value : char
    {
        Buy = '1',
        Sell = '2',
        Null = 0,
    };
    
    public:
    static constexpr const char* to_string(Value value) noexcept
    {
        switch (value)
        {
        case Value::Buy:
            return "Buy";
        case Value::Sell:
            return "Sell";
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
    , const fastsbe::sideEnum::Value val)
{
    os << fastsbe::sideEnum::to_string(val);
    return os;
}