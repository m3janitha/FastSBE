#include <cstdlib>
#include <iostream>
#include <ctime>

#include <benchmark/benchmark.h>

#include <generated/CancelReplace.h>
#include <helper.h>


class MyFixture : public benchmark::Fixture 
{
public:
    void SetUp(const ::benchmark::State& state) 
    {
        create_msg(msg_);
    }

    void TearDown(const ::benchmark::State& state) 
    {
    }

    test::sbe::CancelReplace msg_{};
};

BENCHMARK_F(MyFixture, BM_Decode_CancelReplace)(benchmark::State& st) 
{
   for (auto _ : st) 
   {
        benchmakr_cxl(reinterpret_cast<char*>(&msg_));
   }
}

static void BM_StringCreation(benchmark::State& state)
{
    for (auto _ : state)
    {
        std::string empty_string;
        benchmark::DoNotOptimize(empty_string);
    }
}

BENCHMARK(BM_StringCreation);

BENCHMARK_MAIN();



