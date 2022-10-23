#include <fastsbe_benchmark.h>
// #include <sbe_tool_bench.h>

int main()
{

    char buffer1[1024]{};
    NewOrderSingleData data{};
	fastsbe::encode_NewOrderSingle_from_struct(buffer1, data, true);
    fastsbe::decode_NewOrderSingle(buffer1, true);

    // char buffer2[1024]{};
    // sbetool::create_msg_from_random(buffer2, sizeof(buffer2), count, true);
    // sbetool::create_msg_from_c_struct(buffer2, sizeof(buffer2), data, true);
}