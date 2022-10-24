#include <cstdlib>
#include <iostream>
#include <ctime>

#include <benchmark/benchmark.h>

#include <NewOrderSingleData.h>
#include <fastsbe_benchmark.h>
#include <sbetool_benchmark.h>


class FastSBEFixture : public benchmark::Fixture 
{
public:
    void SetUp(const ::benchmark::State& state) 
    {
        fastsbe::encode_NewOrderSingle_from_struct(buffer_, data, false);
    }

    char buffer_[1024]{};
    NewOrderSingleData data{3,3,3};
};

class SbeToolFixture : public benchmark::Fixture 
{
public:
    void SetUp(const ::benchmark::State& state) 
    {
        sbetool::encode_NewOrderSingle_from_struct(buffer_, sizeof(buffer_), data, false);
    }

    char buffer_[1024]{};
    NewOrderSingleData data{3,3,3};
};

BENCHMARK_F(FastSBEFixture, BM_Decode_NewOrderSingle)(benchmark::State& st) 
{
   for (auto _ : st) 
   {
        fastsbe::decode_NewOrderSingle(buffer_, false);
   }
}

BENCHMARK_F(SbeToolFixture, BM_Decode_NewOrderSingle)(benchmark::State& st) 
{
   for (auto _ : st) 
   {
        sbetool::decode_NewOrderSingle(buffer_, sizeof(buffer_), false);
   }
}

BENCHMARK_F(FastSBEFixture, BM_encode_NewOrderSingle_from_struct)(benchmark::State& st) 
{
   for (auto _ : st) 
   {
        fastsbe::encode_NewOrderSingle_from_struct(buffer_, data, false);
   }
}

BENCHMARK_F(SbeToolFixture, BM_encode_NewOrderSingle_from_struct)(benchmark::State& st)
{
   for (auto _ : st) 
   {
        sbetool::encode_NewOrderSingle_from_struct(buffer_, sizeof(buffer_), data, false);
   }
}

// BENCHMARK_F(FastSBEFixture, BM_Encode_CancelReplace_from_struct)(benchmark::State& st) 
// {
//    for (auto _ : st) 
//    {
//         fastsbe::create_msg_from_c_struct(msg_, data, false);
//    }
// }

// BENCHMARK_F(SbeToolFixture, BM_Encode_CancelReplace_from_struct)(benchmark::State& st)
// {
//    for (auto _ : st) 
//    {
//         sbetool::create_msg_from_c_struct(msg_, sizeof(msg_), data, false);
//    }
// }

// BENCHMARK_F(SbeToolFixture, BM_Encode_get_from_cancel_replace_data)(benchmark::State& st)
// {
//    for (auto _ : st) 
//    {
//         benchmark_get_from_cancel_replace_data(data);
//    }
// }

BENCHMARK_MAIN();



