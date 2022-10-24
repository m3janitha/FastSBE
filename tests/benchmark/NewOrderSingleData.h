#pragma once

#include <string>
#include <cstdint>
#include <vector>


#include <random_gen.h>

struct NewOrderSingleData
{
    std::string ClOrdId{random_string(7).c_str()};
    std::string Account{random_string(7).c_str()};
    std::string Symbol{random_string(7).c_str()};
    char Side{random_enum_underlying_type<char>('1', '2')};
    std::uint64_t TransactTime{random_number<std::uint64_t>()};
    struct qtyEncoding
    {
        std::int32_t mantissa{random_number<std::int32_t>()};
    };
    qtyEncoding OrderQty{};
    char OrdType{random_enum_underlying_type<char>('1', '4')};
    struct decimalEncoding
    {
        std::int64_t mantissa{random_number<std::int64_t>()};
    };
    decimalEncoding Price{};
    decimalEncoding StopPx{};
    struct PartiesGrp
    {
        std::string PartyID{random_string(7).c_str()};
        char PartyIDSource{random_enum_underlying_type<char>('B', 'C')};
        std::uint8_t PartyRole{random_enum_underlying_type<std::uint8_t>(1, 3)};
    };
    std::vector<PartiesGrp> PartiesGrps{};
    struct AllocsGrp
    {
        std::string AllocAccount{random_string(15).c_str()};
        qtyEncoding AllocShares{};
    };
    std::vector<AllocsGrp> AllocsGrps{};
    struct TradingSessionsGrp
    {
        std::string TradingSessionID{random_string(7).c_str()};
    };
    std::vector<TradingSessionsGrp> TradingSessionsGrps{};
    std::string Text{random_string(20).c_str()};
    std::string ClearingFirm{random_string(20).c_str()};

    NewOrderSingleData()
        : PartiesGrps(random_number<std::size_t>(0, 10)),
          AllocsGrps(random_number<std::size_t>(0, 10)),
          TradingSessionsGrps(random_number<std::size_t>(0, 10)) {}

    NewOrderSingleData(std::size_t parties_grps, std::size_t allocs_grps, std::size_t trading_sessions_grps)
        : PartiesGrps(parties_grps), AllocsGrps(allocs_grps), TradingSessionsGrps(trading_sessions_grps) {}
};