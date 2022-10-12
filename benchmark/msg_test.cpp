#include <fast_sbe_bench.h>
#include <sbe_tool_bench.h>


int main()
{
    repeting_groups_count count{4,5};
    auto data = create_cancel_replace_data(count);
    char buffer1[1024]{};
	fastsbe::create_msg_from_random(buffer1, count, true);
    fastsbe::create_msg_from_c_struct(buffer1, data, true);

    char buffer2[1024]{};
    sbetool::create_msg_from_random(buffer2, sizeof(buffer2), count, true);
    sbetool::create_msg_from_c_struct(buffer2, sizeof(buffer2), data, true);
}