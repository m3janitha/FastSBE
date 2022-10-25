#pragma once

#include <iostream>
#include<ostream>
#include <random>
#include <limits>
#include <type_traits>

template <typename T>
inline T random_number(T s = std::numeric_limits<T>::min(), T e = std::numeric_limits<T>::max())
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<T> distrib(s, e);
    return distrib(gen);
}

inline char random_char(char start = ' ', char end = '~')
{
    auto rnd = random_number(static_cast<std::uint8_t>(start), static_cast<std::uint8_t>(end));
    auto val = static_cast<char>(rnd);
    return val;
}

inline std::string random_length_string(std::size_t max_length)
{
    auto length = random_number<std::size_t>(1, max_length);
    std::string str{};
    for (auto i = 0u; i < length; i++)
        str.push_back(random_char());
    return str;
}

inline std::string random_string(std::size_t length)
{
    std::string str{};
    for (auto i = 0u; i < length; i++)
        str.push_back(random_char());
    return str;
}

template <typename EnumType, typename U = std::underlying_type_t<EnumType>>
inline EnumType random_enum(U start, U end)
{
    if constexpr (std::is_same<std::remove_cv_t<U>, char>::value)
    {
        auto rnd = random_char(start, end);
        return static_cast<EnumType>(rnd);
    }
    else
    {
        auto rnd = random_number(start, end);
        return static_cast<EnumType>(rnd);
    }
}

template <typename U>
inline U random_enum_underlying_type(U start, U end)
{
    if constexpr (std::is_same<std::remove_cv_t<U>, char>::value)
    {
        auto rnd = random_char(start, end);
        return rnd;
    }
    else
    {
        auto rnd = random_number(start, end);
        return rnd;
    }
}
