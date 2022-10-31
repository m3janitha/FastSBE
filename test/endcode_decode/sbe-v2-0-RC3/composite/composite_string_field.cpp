#include <iostream>

#include <gtest/gtest.h>
#include <random_gen.h>

#include <TestMessage.h>

namespace sbetool
{
    static constexpr const std::size_t field_offset{0};

    // guaranteed to be null terminated
    TEST(composite_string, field_info)
    {
        TestMessage msg{};
        auto &composite = msg.get_TestComposite();

        EXPECT_EQ(composite.ClOrdId_size(), 8);
        EXPECT_EQ(composite.ClOrdId_offset(), field_offset);
        EXPECT_EQ(composite.ClOrdId_name(), "ClOrdId");
    }

    // guaranteed to be null terminated
    TEST(composite_string, empty_string)
    {
        TestMessage msg{};
        auto &composite = msg.get_TestComposite();

        composite.set_ClOrdId("");
        EXPECT_EQ(std::string(composite.get_ClOrdId()), std::string(""));
        // string_view of field length
        EXPECT_EQ(composite.get_ClOrdId_view().at(0), '\0');
        // null terminated string
        EXPECT_EQ(composite.get_ClOrdId_string(), std::string(""));
    }

    TEST(composite_string, const_empty_string)
    {
        const TestMessage msg{};
        const auto &composite = msg.get_TestComposite();
        const_cast<TestComposite &>(composite).set_ClOrdId("");

        EXPECT_EQ(std::string(composite.get_ClOrdId()), std::string(""));
        // string_view of field length
        EXPECT_EQ(composite.get_ClOrdId_view().at(0), '\0');
        // null terminated string
        EXPECT_EQ(composite.get_ClOrdId_string(), std::string(""));
    }

    // always set field_length – 1 characters in string fields for efficient decoding.
    // guaranteed to be null terminated
    TEST(composite_string, max_length_minus_one)
    {
        TestMessage msg{};
        auto &composite = msg.get_TestComposite();

        auto ClOrdId = random_string(7);
        composite.set_ClOrdId(ClOrdId);

        EXPECT_EQ(std::string(composite.get_ClOrdId()), ClOrdId);
        auto ClOrdId_view = ClOrdId;
        ClOrdId_view.push_back('\0');
        EXPECT_EQ(composite.get_ClOrdId_view(), ClOrdId_view);
        EXPECT_EQ(composite.get_ClOrdId_string(), ClOrdId);
    }

    TEST(composite_string, const_max_length_minus_one)
    {
        TestMessage msg{};
        auto &composite = msg.get_TestComposite();

        auto ClOrdId = random_string(7);
        const_cast<TestComposite &>(composite).set_ClOrdId(ClOrdId);

        EXPECT_EQ(std::string(composite.get_ClOrdId()), ClOrdId);
        auto ClOrdId_view = ClOrdId;
        ClOrdId_view.push_back('\0');
        EXPECT_EQ(composite.get_ClOrdId_view(), ClOrdId_view);
        EXPECT_EQ(composite.get_ClOrdId_string(), ClOrdId);
    }

    TEST(composite_string, max_length)
    {
        TestMessage msg{};
        auto &composite = msg.get_TestComposite();

        auto ClOrdId = random_string(8);
        composite.set_ClOrdId(ClOrdId);

        // unsafe. string is not null terminated
        // EXPECT_EQ(std::string(composite.get_ClOrdId()), ClOrdId);
        EXPECT_EQ(composite.get_ClOrdId_view(), std::string_view(ClOrdId));
        EXPECT_EQ(composite.get_ClOrdId_string(), ClOrdId);
    }

    TEST(composite_string, const_max_length)
    {
        TestMessage msg{};
        auto &composite = msg.get_TestComposite();

        auto ClOrdId = random_string(8);
        const_cast<TestComposite &>(composite).set_ClOrdId(ClOrdId);

        EXPECT_EQ(composite.get_ClOrdId_view(), std::string_view(ClOrdId));
        EXPECT_EQ(composite.get_ClOrdId_string(), ClOrdId);
    }

    TEST(composite_string, set_from_string_view)
    {
        {
            TestMessage msg{};
            auto &composite = msg.get_TestComposite();

            std::string_view ClOrdId("");
            composite.set_ClOrdId(ClOrdId);

            EXPECT_EQ(std::string(composite.get_ClOrdId()), std::string(""));
            // string_view of field length
            EXPECT_EQ(composite.get_ClOrdId_view().at(0), '\0');
            // null terminated string
            EXPECT_EQ(composite.get_ClOrdId_string(), std::string(""));
        }
        {
            TestMessage msg{};
            auto &composite = msg.get_TestComposite();

            std::string_view ClOrdId(random_string(7).c_str());
            composite.set_ClOrdId(ClOrdId);

            EXPECT_EQ(std::string(composite.get_ClOrdId()), ClOrdId);
            std::string ClOrdId_view = ClOrdId.data();
            ClOrdId_view.push_back('\0');

            EXPECT_EQ(composite.get_ClOrdId_view(), std::string_view(ClOrdId_view));
            EXPECT_EQ(composite.get_ClOrdId_string(), ClOrdId);
        }
        {
            TestMessage msg{};
            auto &composite = msg.get_TestComposite();

            std::string_view ClOrdId(random_string(8).c_str());
            composite.set_ClOrdId(ClOrdId);

            EXPECT_EQ(composite.get_ClOrdId_view(), std::string_view(ClOrdId));
            EXPECT_EQ(composite.get_ClOrdId_string(), ClOrdId);
        }
    }

    TEST(string_const, field_info)
    {
        TestMessage msg{};
        auto &composite = msg.get_TestComposite();

        EXPECT_EQ(composite.ConstClOrdId_size(), 0);
        EXPECT_EQ(composite.ConstClOrdId_offset(), field_offset + 8);
        EXPECT_EQ(composite.ConstClOrdId_name(), "ConstClOrdId");
    }

    TEST(string_const, get_field)
    {
        TestMessage msg{};
        auto &composite = msg.get_TestComposite();
        const char *ConstClOrdId = "ABCDEFGH";

        EXPECT_EQ(composite.get_ConstClOrdId(), ConstClOrdId);
        EXPECT_EQ(composite.get_ConstClOrdId_view(), std::string_view(ConstClOrdId));
        EXPECT_EQ(composite.get_ConstClOrdId_string(), std::string(ConstClOrdId));
    }

    TEST(string_const, get_field_const)
    {
        const TestMessage msg{};
        const auto &composite = msg.get_TestComposite();
        const char *ConstClOrdId = "ABCDEFGH";

        EXPECT_EQ(composite.get_ConstClOrdId(), ConstClOrdId);
        EXPECT_EQ(composite.get_ConstClOrdId_view(), std::string_view(ConstClOrdId));
        EXPECT_EQ(composite.get_ConstClOrdId_string(), std::string(ConstClOrdId));
    }
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
