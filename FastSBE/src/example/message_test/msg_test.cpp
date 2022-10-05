#include <helper.h>
#include <iostream>

int main()
{
    std::cout << "XX" << std::endl;
    test::sbe::CancelReplace cxl{};
	create_msg(cxl);
    std::cout << cxl << std::endl;
}