#include <fast_sbe_bench.h>
#include <sbe_tool_bench.h>
#include <iostream>

int main()
{
    repeting_groups_count count{4,5};
    auto data = create_random_data(count);
    char buffer1[1024]{};
	fastsbe::create_msg(buffer1, count, true);
    fastsbe::create_msg_2(buffer1, data, true);

    char buffer2[1024]{};
    sbetool::create_msg(buffer2, sizeof(buffer2), count, true);
    sbetool::create_msg_2(buffer2, sizeof(buffer2), data, true);
}