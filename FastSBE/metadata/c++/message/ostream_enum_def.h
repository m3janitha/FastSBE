
template <class CharT, class Traits = std::char_traits<CharT>>
inline std::basic_ostream<CharT, Traits> &operator<<(std::basic_ostream<CharT, Traits> &os, const S_NAMESPACE::S_ENUM_NAME::Value val)
{
    os << S_NAMESPACE::S_ENUM_NAME::to_string(val);
    return os;
}

