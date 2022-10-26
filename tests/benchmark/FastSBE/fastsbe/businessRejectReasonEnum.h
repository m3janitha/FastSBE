#pragma once
#include<cstdint>
#include<string>
#include<string_view>
#include<ostream>
#include<cstring>

namespace fastsbe
{

class businessRejectReasonEnum
{
    public:
    enum class Value : std::uint8_t
    {
        Other = 0,
        UnknownID = 1,
        UnknownSecurity = 2,
        ApplicationNotAvailable = 4,
        NotAuthorized = 6,
        Null = 255,
    };
    
    public:
    static constexpr const char* to_string(Value value) noexcept
    {
        switch (value)
        {
        case Value::Other:
            return "Other";
        case Value::UnknownID:
            return "UnknownID";
        case Value::UnknownSecurity:
            return "UnknownSecurity";
        case Value::ApplicationNotAvailable:
            return "ApplicationNotAvailable";
        case Value::NotAuthorized:
            return "NotAuthorized";
        case Value::Null:
            return "Null";
        default:
            return "Invalid";
        }
    }
};

template <class CharT, class Traits = std::char_traits<CharT>>
inline std::basic_ostream<CharT, Traits> &operator<<(std::basic_ostream<CharT, Traits> &os, const fastsbe::businessRejectReasonEnum::Value val)
{
    os << fastsbe::businessRejectReasonEnum::to_string(val);
    return os;
}

}
