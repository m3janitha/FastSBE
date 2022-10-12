#pragma once

#include <cstdlib>
#include <iostream>
#include <ctime>

#include <benchmark/benchmark.h>

inline int get_random_int(int base)
{
    std::srand(std::time(nullptr));
    int xrandom_variable = 1 + std::rand()/((RAND_MAX + 1u)/base);
    return xrandom_variable;
}

struct repeting_groups_count
{
    std::uint16_t party_info{0};
    std::uint16_t app_info{0};
};

struct CancelReplaceData
{
    std::uint32_t clodr_id{};
    std::uint32_t orig_clodr_id{};

    struct PartyInfoData
    {
        std::uint16_t self_match_id{};
        std::uint16_t group_id{};

        PartyInfoData(std::uint16_t self_match, std::uint16_t group)
            :self_match_id(self_match), group_id(group){}  
    };

    struct AppInfoData
    {
        std::uint16_t firm_id{};
        std::uint32_t version{};

        AppInfoData(std::uint16_t firm, std::uint32_t ver)
            :firm_id(firm), version(ver){}        
    };

    std::vector<PartyInfoData> party_info{};
    std::vector<AppInfoData> app_info{};        
};

inline CancelReplaceData create_cancel_replace_data(repeting_groups_count count)
{
    CancelReplaceData data{};

    data.clodr_id = get_random_int(123);
    data.orig_clodr_id = get_random_int(3456);

    for(auto i=0u;i<count.party_info; i++)
    {
        data.party_info.emplace_back(static_cast<std::uint16_t>(get_random_int(456))
            , static_cast<std::uint16_t>(get_random_int(4654)));
    }

    for(auto i=0u;i<count.app_info; i++)
    {
        data.app_info.emplace_back(static_cast<std::uint16_t>(get_random_int(782))
            , static_cast<std::uint32_t>(get_random_int(897)));
    }

    return data;
}

inline void benchmark_get_from_cancel_replace_data(CancelReplaceData& data)
{
    benchmark::DoNotOptimize(data.clodr_id);
    benchmark::DoNotOptimize(data.orig_clodr_id);

    auto party_info_count = data.party_info.size();
    for(auto i=0u; i<party_info_count; i++)
    {
        benchmark::DoNotOptimize(data.party_info[i].self_match_id);
        benchmark::DoNotOptimize(data.party_info[i].group_id);
    }

    auto app_info_count = data.app_info.size();
    for(auto i=0u; i<app_info_count; i++)
    {
        benchmark::DoNotOptimize(data.app_info[i].firm_id);
        benchmark::DoNotOptimize(data.app_info[i].version);
    }
}
