#include <fast_sbe_bench.h>
#include <sbe_tool_bench.h>
#include <iostream>

int main()
{
    std::cout << "FastSBE" << std::endl;
    char buffer1[1024]{};
	fastsbe::create_msg(buffer1);
    auto& cxl = *reinterpret_cast<test::sbe::CancelReplace*>(buffer1);
    std::cout << cxl << std::endl;


    std::cout << "SbeTool" << std::endl;
    char buffer2[1024]{};
    sbetool::create_msg(buffer2, sizeof(buffer2));
    sbetest::CancelReplace cxl_2;
    cxl_2.wrapForEncode(buffer2, 0, sizeof(buffer2));
    std::cout << cxl_2 << std::endl;
}