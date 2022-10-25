#include <iostream>

#include <gtest/gtest.h>
#include <random_gen.h>

#include <NewOrderSingle.h>

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

    // guaranteed to be null terminated
    TEST(string, empty_string)
    {
        NewOrderSingle msg{};
        msg.set_ClOrdId("");
        EXPECT_EQ(std::string(msg.get_ClOrdId()), std::string(""));
        // string_view of field length
        EXPECT_EQ(msg.get_ClOrdId_view().at(0), '\0');
        // null terminated string
        EXPECT_EQ(msg.get_ClOrdId_string(), std::string(""));
    }

    TEST(string, const_empty_string)
    {
        const NewOrderSingle msg{};
        const_cast<NewOrderSingle &>(msg).set_ClOrdId("");

        EXPECT_EQ(std::string(msg.get_ClOrdId()), std::string(""));
        // string_view of field length
        EXPECT_EQ(msg.get_ClOrdId_view().at(0), '\0');
        // null terminated string
        EXPECT_EQ(msg.get_ClOrdId_string(), std::string(""));
    }

    // always set field_length – 1 characters in string fields for efficient decoding.
    // guaranteed to be null terminated
    TEST(string, max_length_minus_one)
    {
        NewOrderSingle msg{};
        auto ClOrdId = random_string(7);
        msg.set_ClOrdId(ClOrdId);

        EXPECT_EQ(std::string(msg.get_ClOrdId()), ClOrdId);
        auto ClOrdId_view = ClOrdId;
        ClOrdId_view.push_back('\0');
        EXPECT_EQ(msg.get_ClOrdId_view(), ClOrdId_view);
        EXPECT_EQ(msg.get_ClOrdId_string(), ClOrdId);
    }

    TEST(string, const_max_length_minus_one)
    {
        NewOrderSingle msg{};
        auto ClOrdId = random_string(7);
        const_cast<NewOrderSingle &>(msg).set_ClOrdId(ClOrdId);

        EXPECT_EQ(std::string(msg.get_ClOrdId()), ClOrdId);
        auto ClOrdId_view = ClOrdId;
        ClOrdId_view.push_back('\0');
        EXPECT_EQ(msg.get_ClOrdId_view(), ClOrdId_view);
        EXPECT_EQ(msg.get_ClOrdId_string(), ClOrdId);
    }

    TEST(string, max_length)
    {
        NewOrderSingle msg{};
        auto ClOrdId = random_string(8);
        msg.set_ClOrdId(ClOrdId);

        // unsafe. string is not null terminated
        // EXPECT_EQ(std::string(msg.get_ClOrdId()), ClOrdId);
        EXPECT_EQ(msg.get_ClOrdId_view(), std::string_view(ClOrdId));
        EXPECT_EQ(msg.get_ClOrdId_string(), ClOrdId);
    }

    TEST(string, const_max_length)
    {
        NewOrderSingle msg{};
        auto ClOrdId = random_string(8);
        const_cast<NewOrderSingle &>(msg).set_ClOrdId(ClOrdId);

        EXPECT_EQ(msg.get_ClOrdId_view(), std::string_view(ClOrdId));
        EXPECT_EQ(msg.get_ClOrdId_string(), ClOrdId);
    }

    TEST(string, set_from_string_view)
    {
        {
            NewOrderSingle msg{};
            std::string_view ClOrdId("");
            msg.set_ClOrdId(ClOrdId);

            EXPECT_EQ(std::string(msg.get_ClOrdId()), std::string(""));
            // string_view of field length
            EXPECT_EQ(msg.get_ClOrdId_view().at(0), '\0');
            // null terminated string
            EXPECT_EQ(msg.get_ClOrdId_string(), std::string(""));
        }
        {
            NewOrderSingle msg{};
            std::string_view ClOrdId(random_string(7).c_str());
            msg.set_ClOrdId(ClOrdId);

            EXPECT_EQ(std::string(msg.get_ClOrdId()), ClOrdId);
            std::string ClOrdId_view = ClOrdId.data();
            ClOrdId_view.push_back('\0');

            EXPECT_EQ(msg.get_ClOrdId_view(), std::string_view(ClOrdId_view));
            EXPECT_EQ(msg.get_ClOrdId_string(), ClOrdId);
        }
        {
            NewOrderSingle msg{};
            std::string_view ClOrdId(random_string(8).c_str());
            msg.set_ClOrdId(ClOrdId);

            EXPECT_EQ(msg.get_ClOrdId_view(), std::string_view(ClOrdId));
            EXPECT_EQ(msg.get_ClOrdId_string(), ClOrdId);
        }
    }
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
