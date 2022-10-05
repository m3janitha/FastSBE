#pragma once
#include<cstdint>
#include<string>
#include<string_view>
#include<ostream>

namespace test::sbe
{

class Side
{
    public:
    enum class Value : char
    {
        Buy = 1,
        Sell = 2,
        ShortSell = 3,
        Null = 255,
    };
    
    public:
    static constexpr const char* to_string(Value value) noexcept
    {
        switch (value)
        {
        case Value::Buy:
            return "1";
        case Value::Sell:
            return "2";
        case Value::ShortSell:
            return "3";
        case Value::Null:
            return "255";
        default:
            return "Invalid";
        }
    }
};
}

template <class CharT, class Traits = std::char_traits<CharT>>
inline std::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT, Traits>& os
    , const test::sbe::Side::Value val)
{
    os << test::sbe::Side::to_string(val);
    return os;
}