#include <iostream>

#include <gtest/gtest.h>
#include <random_gen.h>

#include <TestMessage.h>

namespace sbetool
{
    TEST(string_const, field_info)
    {
        TestMessage msg{};
        EXPECT_EQ(msg.SessionID_size(), 0);
        EXPECT_EQ(msg.SessionID_offset(), 8);
        EXPECT_EQ(msg.SessionID_id(), 1);
        EXPECT_EQ(msg.SessionID_name(), "SessionID");
    }

    TEST(string_const, get_field)
    {
        TestMessage msg{};
        const char* SessionID = "ABCDEFGH";

        EXPECT_EQ(msg.get_SessionID(), SessionID);
        EXPECT_EQ(msg.get_SessionID_view(), std::string_view(SessionID));
        EXPECT_EQ(msg.get_SessionID_string(), std::string(SessionID));
    }

    TEST(string_const, get_field_const)
    {
        const TestMessage msg{};
        const char* SessionID = "ABCDEFGH";

        EXPECT_EQ(msg.get_SessionID(), SessionID);
        EXPECT_EQ(msg.get_SessionID_view(), std::string_view(SessionID));
        EXPECT_EQ(msg.get_SessionID_string(), std::string(SessionID));
    }
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
