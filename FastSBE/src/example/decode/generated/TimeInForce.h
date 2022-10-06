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
    };
    
    public:
    const char* to_string(Value value) const noexcept
    {
        switch (value)
        {
        case Value::Day:
            return 1;
        case Value::IOC:
            return 2;
        case Value::FOK:
            return 3;
        default:
            return Invalid;
        }
    }
};
}
