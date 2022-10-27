#include <iostream>

#include <gtest/gtest.h>
#include <random_gen.h>

#include <TestMessage.h>

namespace sbetool
{
    TEST(enums, field_info)
    {
        TestMessage msg{};
        EXPECT_EQ(msg.PartyIDSource_size(), 1);
        EXPECT_EQ(msg.PartyIDSource_offset(), 10);
        EXPECT_EQ(msg.PartyIDSource_id(), 447);
        EXPECT_EQ(msg.PartyIDSource_name(), "PartyIDSource");
        EXPECT_EQ(msg.PartyIDSource_null_value(), PartyIDSourceEnum::Value::nullValue);
    }

    TEST(enums, field_values)
    {
        TestMessage msg{};
        msg.set_PartyIDSource(PartyIDSourceEnum::Value::BIC);
        EXPECT_EQ(msg.get_PartyIDSource(), PartyIDSourceEnum::Value::BIC);
        msg.set_PartyIDSource(PartyIDSourceEnum::Value::Proprietary);
        EXPECT_EQ(msg.get_PartyIDSource(), PartyIDSourceEnum::Value::Proprietary);
        msg.set_PartyIDSource(PartyIDSourceEnum::Value::nullValue);
        EXPECT_EQ(msg.get_PartyIDSource(), PartyIDSourceEnum::Value::nullValue);
    }

    TEST(enums, to_string)
    {
        TestMessage msg{};
        EXPECT_EQ(PartyIDSourceEnum::to_string(PartyIDSourceEnum::Value::BIC), "BIC");
        EXPECT_EQ(PartyIDSourceEnum::to_string(PartyIDSourceEnum::Value::Proprietary), "Proprietary");
        EXPECT_EQ(PartyIDSourceEnum::to_string(PartyIDSourceEnum::Value::nullValue), "nullValue");
    }   

    TEST(enums, optional_field_info)
    {
        TestMessage msg{};
        EXPECT_EQ(msg.OptionalPartyIDSource_size(), 1);
        EXPECT_EQ(msg.OptionalPartyIDSource_offset(),11);
        EXPECT_EQ(msg.OptionalPartyIDSource_id(), 448);
        EXPECT_EQ(msg.OptionalPartyIDSource_name(), "OptionalPartyIDSource");
        EXPECT_EQ(msg.OptionalPartyIDSource_null_value(), PartyIDSourceEnum::Value::nullValue);
    }

    TEST(enums, optional_field_values)
    {
        TestMessage msg{};
        EXPECT_EQ(msg.get_OptionalPartyIDSource(), PartyIDSourceEnum::Value::nullValue);

        msg.set_OptionalPartyIDSource(PartyIDSourceEnum::Value::BIC);
        EXPECT_EQ(msg.get_OptionalPartyIDSource(), PartyIDSourceEnum::Value::BIC);
        msg.set_OptionalPartyIDSource(PartyIDSourceEnum::Value::Proprietary);
        EXPECT_EQ(msg.get_OptionalPartyIDSource(), PartyIDSourceEnum::Value::Proprietary);
        msg.set_OptionalPartyIDSource(PartyIDSourceEnum::Value::nullValue);
        EXPECT_EQ(msg.get_OptionalPartyIDSource(), PartyIDSourceEnum::Value::nullValue);
    }

    TEST(enums, const_field_info)
    {
        TestMessage msg{};
        EXPECT_EQ(msg.ConstPartyIDSource_size(), 0);
        EXPECT_EQ(msg.ConstPartyIDSource_offset(), 12);
        EXPECT_EQ(msg.ConstPartyIDSource_id(), 449);
        EXPECT_EQ(msg.ConstPartyIDSource_name(), "ConstPartyIDSource");
    }

    TEST(enums, const_field_values)
    {
        TestMessage msg{};
        EXPECT_EQ(msg.get_ConstPartyIDSource(), PartyIDSourceEnum::Value::Proprietary);
    } 

    TEST(numeric_enums, field_info)
    {
        TestMessage msg{};
        EXPECT_EQ(msg.PartyRole_size(), 1);
        EXPECT_EQ(msg.PartyRole_offset(), 12);
        EXPECT_EQ(msg.PartyRole_id(), 452);
        EXPECT_EQ(msg.PartyRole_name(), "PartyRole");
        EXPECT_EQ(msg.PartyRole_null_value(), PartyRoleEnum::Value::nullValue);
    }

    TEST(numeric_enums, field_values)
    {
        TestMessage msg{};

        msg.set_PartyRole(PartyRoleEnum::Value::ExecutingFirm);
        EXPECT_EQ(msg.get_PartyRole(), PartyRoleEnum::Value::ExecutingFirm);
        msg.set_PartyRole(PartyRoleEnum::Value::BrokerOfCredit);
        EXPECT_EQ(msg.get_PartyRole(), PartyRoleEnum::Value::BrokerOfCredit);
        msg.set_PartyRole(PartyRoleEnum::Value::ClientID);
        EXPECT_EQ(msg.get_PartyRole(), PartyRoleEnum::Value::ClientID);
        msg.set_PartyRole(PartyRoleEnum::Value::nullValue);
        EXPECT_EQ(msg.get_PartyRole(), PartyRoleEnum::Value::nullValue);
    }       
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
