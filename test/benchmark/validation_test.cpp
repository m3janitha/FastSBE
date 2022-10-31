#include <fastsbe_benchmark.h>
#include <sbetool_benchmark.h>

int main()
{
    NewOrderSingleData data{};

    char buffer1[1024]{};
    fastsbe::encode_NewOrderSingle_from_struct(buffer1, data, true);
    fastsbe::decode_NewOrderSingle(buffer1, true);

    char buffer2[1024]{};
    sbetool::encode_NewOrderSingle_from_struct(buffer1, sizeof(buffer2), data, true);
    sbetool::decode_NewOrderSingle(buffer1, sizeof(buffer2), true);
}