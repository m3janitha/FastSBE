#include <cstdlib>
#include <iostream>
#include <ctime>

#include <benchmark/benchmark.h>

#include <fast_sbe_bench.h>
#include <sbe_tool_bench.h>

repeting_groups_count count{5,10};

class FastSBEFixture : public benchmark::Fixture 
{
public:
    void SetUp(const ::benchmark::State& state) 
    {
        fastsbe::create_msg_from_random(msg_, count, false);
        data = create_cancel_replace_data(count);
    }

    void TearDown(const ::benchmark::State& state) {}

    char msg_[1024]{};
    CancelReplaceData data{};
};

class SbeToolFixture : public benchmark::Fixture 
{
public:
    void SetUp(const ::benchmark::State& state) 
    {
        sbetool::create_msg_from_random(msg_, sizeof(msg_), count, false);
        data = create_cancel_replace_data(count);
    }

    void TearDown(const ::benchmark::State& state) {}

    char msg_[1024]{};
    CancelReplaceData data{};
};

BENCHMARK_F(FastSBEFixture, BM_Decode_CancelReplace)(benchmark::State& st) 
{
   for (auto _ : st) 
   {
        fastsbe::benchmakr_cxl(msg_);
   }
}

BENCHMARK_F(SbeToolFixture, BM_Decode_CancelReplace)(benchmark::State& st) 
{
   for (auto _ : st) 
   {
        sbetool::benchmakr_cxl(msg_, sizeof(msg_));
   }
}

BENCHMARK_F(FastSBEFixture, BM_Encode_CancelReplace_random)(benchmark::State& st) 
{
   for (auto _ : st) 
   {
        fastsbe::create_msg_from_random(msg_, count, false);
   }
}

BENCHMARK_F(SbeToolFixture, BM_Encode_CancelReplace_random)(benchmark::State& st)
{
   for (auto _ : st) 
   {
        sbetool::create_msg_from_random(msg_, sizeof(msg_), count, false);
   }
}

BENCHMARK_F(FastSBEFixture, BM_Encode_CancelReplace_from_struct)(benchmark::State& st) 
{
   for (auto _ : st) 
   {
        fastsbe::create_msg_from_c_struct(msg_, data, false);
   }
}

BENCHMARK_F(SbeToolFixture, BM_Encode_CancelReplace_from_struct)(benchmark::State& st)
{
   for (auto _ : st) 
   {
        sbetool::create_msg_from_c_struct(msg_, sizeof(msg_), data, false);
   }
}

BENCHMARK_F(SbeToolFixture, BM_Encode_get_from_cancel_replace_data)(benchmark::State& st)
{
   for (auto _ : st) 
   {
        benchmark_get_from_cancel_replace_data(data);
   }
}

BENCHMARK_MAIN();



