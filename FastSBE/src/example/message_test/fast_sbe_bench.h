#pragma once

#include <benchmark/benchmark.h>

#include <helper.h>
#include <generated/CancelReplace.h>

namespace fastsbe
{
    struct CancelReplaceData
    {
        std::uint32_t clodr_id{};
        std::uint32_t orig_clodr_id{};

        struct PartyInfoData
        {
            std::uint16_t self_match_id{};
            std::uint16_t group_id{};
        };

        PartyInfoData party_info[2]{};

        struct AppInfoData
        {
            std::uint16_t firm_id{};
            std::uint32_t version{};
        };

        AppInfoData app_info[1]{};
    };

    void create_msg(char* buffer)
    {	
        auto& cxl = *reinterpret_cast<test::sbe::CancelReplace*>(buffer);

        cxl.set_clodr_id(get_random_int(123));
        cxl.set_orig_clodr_id(get_random_int(3456));

        auto& party_info = cxl.append_PartyInfo(get_random_int(4));
        for(auto i=0u; i<party_info.get_numInGroup(); i++)
        {
            party_info.get(party_info, i)
                .set_self_match_id(get_random_int(456))
                .set_group_id(get_random_int(4654));
        }

        auto& app_info = cxl.append_AppInfo(get_random_int(3));
        for(auto i=0u; i<party_info.get_numInGroup(); i++)
        {
            app_info.get(app_info, i)
                .set_firm_id(get_random_int(782))
                .set_version(get_random_int(897));
        }
    }

    void benchmakr_cxl(char* buffer)
    {
        auto& cxl = *reinterpret_cast<test::sbe::CancelReplace*>(buffer);

        auto clodr_id = cxl.get_clodr_id();
        benchmark::DoNotOptimize(clodr_id);

        auto orig_clodr_id = cxl.get_orig_clodr_id();
        benchmark::DoNotOptimize(orig_clodr_id);

        auto& party_info = cxl.get_PartyInfo();
        for(auto i=0u; i<party_info.get_numInGroup(); i++)
        {
            auto& data = party_info.get(party_info, i);

            auto self_match_id = data.get_self_match_id();
            benchmark::DoNotOptimize(self_match_id);

            auto group_id = data.get_group_id();
            benchmark::DoNotOptimize(group_id);
        }

        auto& app_info = cxl.get_AppInfo();
        for(auto i=0u; i<app_info.get_numInGroup(); i++)
        {
            auto& data = app_info.get(app_info, i);

            auto firm_id = data.get_firm_id();
            benchmark::DoNotOptimize(firm_id);

            auto version = data.get_version();
            benchmark::DoNotOptimize(version);
        }
    }
}