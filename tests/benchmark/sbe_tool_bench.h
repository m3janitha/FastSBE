#pragma once

#include <benchmark/benchmark.h>
#include <helper.h>
#include <SBETool/sbetest/CancelReplace.h>

namespace sbetool
{
    void create_msg_from_random(char* buffer, std::size_t length, repeting_groups_count count, bool display)
    {
        sbetest::CancelReplace cxl;
        cxl.wrapForEncode(buffer, 0, length)
            .clodr_id(get_random_int(123))
            .orig_clodr_id(get_random_int(3456));
        
        auto party_info_count = count.party_info;
        auto& party_info = cxl.partyInfoCount(party_info_count);
        for(auto i=0u; i<party_info_count; i++)
        {
            party_info.next()
                .self_match_id(get_random_int(456))
                .group_id(get_random_int(4654));
        }

        auto app_info_count = count.app_info;
        auto& app_info = cxl.appInfoCount(app_info_count);
        for(auto i=0u; i<app_info_count; i++)
        {
            app_info.next()
                .firm_id(get_random_int(782))
                .version(get_random_int(897));
        }

        if(display)
            std::cout << "SBETool" << std::endl <<  cxl << std::endl;
            //std::cout << cxl.sbeBlockLength() << std::endl;
    }

    void create_msg_from_c_struct(char* buffer, std::size_t length, CancelReplaceData& data, bool display)
    {
        sbetest::CancelReplace cxl;
        cxl.wrapForEncode(buffer, 0, length)
            .clodr_id(data.clodr_id)
            .orig_clodr_id(data.orig_clodr_id);
        
        auto party_info_count = data.party_info.size();
        auto& party_info = cxl.partyInfoCount(party_info_count);
        for(auto i=0u; i<party_info_count; i++)
        {
            party_info.next()
                .self_match_id(data.party_info[i].self_match_id)
                .group_id(data.party_info[i].group_id);
        }

        auto app_info_count = data.app_info.size();
        auto& app_info = cxl.appInfoCount(app_info_count);
        for(auto i=0u; i<app_info_count; i++)
        {
            app_info.next()
                .firm_id(data.app_info[i].firm_id)
                .version(data.app_info[i].version);
        }

        benchmark::DoNotOptimize(cxl);

        if(display)
            std::cout << "SBETool" << std::endl <<  cxl << std::endl;
            //std::cout << cxl.sbeBlockLength() << std::endl;
    }    

    void benchmakr_cxl(char* buffer, std::size_t length)
    {
        sbetest::CancelReplace cxl;
        cxl.wrapForDecode(buffer,0,8,0,length);

        auto clodr_id = cxl.clodr_id();
        benchmark::DoNotOptimize(clodr_id);

        auto orig_clodr_id = cxl.orig_clodr_id();
        benchmark::DoNotOptimize(orig_clodr_id);

        auto &party_info = cxl.partyInfo();
        while (party_info.hasNext())
        {
            party_info.next();
            
            auto self_match_id = party_info.self_match_id();
            benchmark::DoNotOptimize(self_match_id);

            auto group_id = party_info.group_id();
            benchmark::DoNotOptimize(group_id);
        }

        auto& app_info = cxl.appInfo();
        while (app_info.hasNext())
        {
            app_info.next();

            auto firm_id = app_info.firm_id();
            benchmark::DoNotOptimize(firm_id);

            auto version = app_info.version();
            benchmark::DoNotOptimize(version);
        }
    }
}