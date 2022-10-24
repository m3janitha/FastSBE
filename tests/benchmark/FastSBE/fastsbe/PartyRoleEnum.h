#pragma once
#include<cstdint>
#include<string>
#include<string_view>
#include<ostream>
#include<cstring>

namespace fastsbe
{

class PartyRoleEnum
{
    public:
    enum class Value : std::uint8_t
    {
        ExecutingFirm = 1,
        BrokerOfCredit = 2,
        ClientID = 3,
        Null = 255,
    };
    
    public:
    static constexpr const char* to_string(Value value) noexcept
    {
        switch (value)
        {
        case Value::ExecutingFirm:
            return "ExecutingFirm";
        case Value::BrokerOfCredit:
            return "BrokerOfCredit";
        case Value::ClientID:
            return "ClientID";
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
    , const fastsbe::PartyRoleEnum::Value val)
{
    os << fastsbe::PartyRoleEnum::to_string(val);
    return os;
}