#pragma once

#include <vector>
#include <benchmark/benchmark.h>

#include <helper.h>
#include <FastSBE/generated/CancelReplace.h>

namespace fastsbe
{
    void create_msg(char* buffer, repeting_groups_count count, bool display)
    {	
        auto& cxl = *reinterpret_cast<test::sbe::CancelReplace*>(buffer);

        cxl.set_clodr_id(get_random_int(123));
        cxl.set_orig_clodr_id(get_random_int(3456));

        auto& party_info = cxl.append_PartyInfo(count.party_info);
        for(auto i=0u; i<party_info.get_numInGroup(); i++)
        {
            party_info.get(i)
                .set_self_match_id(get_random_int(456))
                .set_group_id(get_random_int(4654));
        }

        auto& app_info = cxl.append_AppInfo(count.app_info);
        for(auto i=0u; i<party_info.get_numInGroup(); i++)
        {
            app_info.get(i)
                .set_firm_id(get_random_int(782))
                .set_version(get_random_int(897));
        }

        if(display)
            std::cout << "FastSBE" << std::endl <<  cxl << std::endl;
    }

    void create_msg_2(char* buffer, CancelReplaceData data, bool display)
    {	
        auto& cxl = *reinterpret_cast<test::sbe::CancelReplace*>(buffer);

        cxl.set_clodr_id(data.clodr_id);
        cxl.set_orig_clodr_id(data.orig_clodr_id);

        auto& party_info = cxl.append_PartyInfo(data.party_info.size());
        for(auto i=0u; i<party_info.get_numInGroup(); i++)
        {
            party_info.get(i)
                .set_self_match_id(data.party_info[i].self_match_id)
                .set_group_id(data.party_info[i].group_id);
        }

        auto& app_info = cxl.append_AppInfo(data.app_info.size());
        for(auto i=0u; i<party_info.get_numInGroup(); i++)
        {
            app_info.get(i)
                .set_firm_id(data.app_info[i].firm_id)
                .set_version(data.app_info[i].version);
        }

        benchmark::DoNotOptimize(cxl);

        if(display)
            std::cout << "FastSBE" << std::endl <<  cxl << std::endl;
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
            auto& data = party_info.get(i);

            auto self_match_id = data.get_self_match_id();
            benchmark::DoNotOptimize(self_match_id);

            auto group_id = data.get_group_id();
            benchmark::DoNotOptimize(group_id);
        }

        auto& app_info = cxl.get_AppInfo();
        for(auto i=0u; i<app_info.get_numInGroup(); i++)
        {
            auto& data = app_info.get(i);

            auto firm_id = data.get_firm_id();
            benchmark::DoNotOptimize(firm_id);

            auto version = data.get_version();
            benchmark::DoNotOptimize(version);
        }
    }
}