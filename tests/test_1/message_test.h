#include<iostream>

#include "message.h"

void test_create()
{
	char buffer[2048];

	message m1{};
	auto s = sizeof(message);

	// 4 + 4 + 5 + (2+4) + (2+4)

	//19+ 8*2
	m1.set_f1(99);
	m1.set_f2(88);

	std::cout << "XXXXXXXXX" << std::endl;
	std::cout << m1 << std::endl;

	auto& g1 = m1.append_group1(2);
	g1.get(g1, 0)
		.set_f1(123)
		.set_f2(345);
	g1.get(g1, 1)
		.set_f1(567)
		.set_f2(890);

	std::cout << g1 << std::endl;

	auto& g2 = m1.append_group2(3);
	g2.get(g2, 0)
		.set_f1(1)
		.set_f2(3);
	g2.get(g2, 1)
		.set_f1(5)
		.set_f2(7);
	g2.get(g2, 2)
		.set_f1(8)
		.set_f2(9);

	m1.append_v_data1("justtest");

	std::cout << g1 << std::endl;
	std::cout << g2 << std::endl;
	std::cout << m1 << std::endl;

	auto* x = new(buffer) message();
}
