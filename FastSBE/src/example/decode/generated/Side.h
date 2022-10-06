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
    };
    
    public:
    const char* to_string(Value value) const noexcept
    {
        switch (value)
        {
        case Value::Buy:
            return 1;
        case Value::Sell:
            return 2;
        case Value::ShortSell:
            return 3;
        default:
            return Invalid;
        }
    }
};
}
