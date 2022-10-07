#pragma once
#include<cstdint>
#include<string>
#include<string_view>
#include<ostream>

namespace test::sbe
{

class TimeInForce
{
    public:
    enum class Value : std::uint8_t
    {
        Day = 1,
        IOC = 2,
        FOK = 3,
        Null = 100,
    };
    
    public:
    static constexpr const char* to_string(Value value) noexcept
    {
        switch (value)
        {
        case Value::Day:
            return "1";
        case Value::IOC:
            return "2";
        case Value::FOK:
            return "3";
        case Value::Null:
            return "100";
        default:
            return "Invalid";
        }
    }
};
}

template <class CharT, class Traits = std::char_traits<CharT>>
inline std::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT, Traits>& os
    , const test::sbe::TimeInForce::Value val)
{
    os << test::sbe::TimeInForce::to_string(val);
    return os;
}