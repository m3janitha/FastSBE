#pragma once
#include<cstdint>
#include<string>
#include<string_view>
#include<ostream>
#include<cstring>

namespace fastsbe
{

class PartyIDSourceEnum
{
    public:
    enum class Value : char
    {
        BIC = 'B',
        Proprietary = 'C',
        Null = 0,
    };
    
    public:
    static constexpr const char* to_string(Value value) noexcept
    {
        switch (value)
        {
        case Value::BIC:
            return "BIC";
        case Value::Proprietary:
            return "Proprietary";
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
    , const fastsbe::PartyIDSourceEnum::Value val)
{
    os << fastsbe::PartyIDSourceEnum::to_string(val);
    return os;
}