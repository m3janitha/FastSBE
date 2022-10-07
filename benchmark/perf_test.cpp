#include <cstdlib>
#include <iostream>
#include <ctime>

#include <benchmark/benchmark.h>

#include <fast_sbe_bench.h>
#include <sbe_tool_bench.h>


class FastSBEFixture : public benchmark::Fixture 
{
public:
    void SetUp(const ::benchmark::State& state) 
    {
        fastsbe::create_msg(msg_);
    }

    void TearDown(const ::benchmark::State& state) 
    {
    }

    char msg_[1024]{};
};

class SbeToolFixture : public benchmark::Fixture 
{
public:
    void SetUp(const ::benchmark::State& state) 
    {
        sbetool::create_msg(msg_, sizeof(msg_));
    }

    void TearDown(const ::benchmark::State& state) 
    {
    }

    char msg_[1024]{};
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

BENCHMARK_MAIN();



