#include <iostream>

#include <gtest/gtest.h>
#include <random_gen.h>

#include <NewOrderSingle.h>
#include <TestMessage.h>

namespace sbetool
{
    // guaranteed to be null terminated
    TEST(string, field_info)
    {
        NewOrderSingle msg{};
        EXPECT_EQ(msg.ClOrdId_size(), 8);
        EXPECT_EQ(msg.ClOrdId_offset(), 0);
        EXPECT_EQ(msg.ClOrdId_id(), 11);
        EXPECT_EQ(msg.ClOrdId_name(), "ClOrdId");
    }
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
