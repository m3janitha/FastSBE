#include <iostream>

#include <gtest/gtest.h>
#include <random_gen.h>

#include <TestMessage.h>

namespace sbetool
{
    TEST(enums, field_info)
    {
        TestMessage msg{};
        auto& composite = msg.get_TestComposite();
        EXPECT_EQ(composite.PartyIDSource_size(), 1);
        EXPECT_EQ(composite.PartyIDSource_offset(),0);
        EXPECT_EQ(composite.PartyIDSource_name(), "PartyIDSource");
        EXPECT_EQ(composite.PartyIDSource_null_value(), PartyIDSourceEnum::Value::nullValue);
    }

    TEST(enums, field_values)
    {
        TestMessage msg{};
        auto& composite = msg.get_TestComposite();

        composite.set_PartyIDSource(PartyIDSourceEnum::Value::BIC);
        EXPECT_EQ(composite.get_PartyIDSource(), PartyIDSourceEnum::Value::BIC);

        composite.set_PartyIDSource(PartyIDSourceEnum::Value::Proprietary);
        EXPECT_EQ(composite.get_PartyIDSource(), PartyIDSourceEnum::Value::Proprietary);

        composite.set_PartyIDSource(PartyIDSourceEnum::Value::nullValue);
        EXPECT_EQ(composite.get_PartyIDSource(), PartyIDSourceEnum::Value::nullValue);
    } 

    TEST(enums, optional_field_info)
    {
        TestMessage msg{};
        auto& composite = msg.get_TestComposite();

        EXPECT_EQ(composite.OptionalPartyIDSource_size(), 1);
        EXPECT_EQ(composite.OptionalPartyIDSource_offset(), 1);
        EXPECT_EQ(composite.OptionalPartyIDSource_name(), "OptionalPartyIDSource");
        EXPECT_EQ(composite.OptionalPartyIDSource_null_value(), PartyIDSourceEnum::Value::nullValue);
    }

    TEST(enums, optional_field_values)
    {
        TestMessage msg{};
        auto& composite = msg.get_TestComposite();

        EXPECT_EQ(composite.get_OptionalPartyIDSource(), PartyIDSourceEnum::Value::nullValue);

        composite.set_OptionalPartyIDSource(PartyIDSourceEnum::Value::BIC);
        EXPECT_EQ(composite.get_OptionalPartyIDSource(), PartyIDSourceEnum::Value::BIC);

        composite.set_OptionalPartyIDSource(PartyIDSourceEnum::Value::Proprietary);
        EXPECT_EQ(composite.get_OptionalPartyIDSource(), PartyIDSourceEnum::Value::Proprietary);

        composite.set_OptionalPartyIDSource(PartyIDSourceEnum::Value::nullValue);
        EXPECT_EQ(composite.get_OptionalPartyIDSource(), PartyIDSourceEnum::Value::nullValue);
    }

    TEST(enums, const_field_info)
    {
        TestMessage msg{};
        auto& composite = msg.get_TestComposite();

        EXPECT_EQ(composite.ConstPartyIDSource_size(), 0);
        EXPECT_EQ(composite.ConstPartyIDSource_offset(), 2);
        EXPECT_EQ(composite.ConstPartyIDSource_name(), "ConstPartyIDSource");
    }

    TEST(enums, const_field_values)
    {
        TestMessage msg{};
        auto& composite = msg.get_TestComposite();
        
        EXPECT_EQ(composite.get_ConstPartyIDSource(), PartyIDSourceEnum::Value::Proprietary);
    }    
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
