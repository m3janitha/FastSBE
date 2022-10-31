#include <iostream>

#include <gtest/gtest.h>

namespace sbetool
{
    template <typename Msg>
    void validate_field_info()
    {
        Msg msg{};
        EXPECT_EQ(msg.PartyIDSource_size(), 1);
        EXPECT_EQ(msg.PartyIDSource_offset(), 16);
        EXPECT_EQ(msg.PartyIDSource_id(), 447);
        EXPECT_EQ(msg.PartyIDSource_name(), "PartyIDSource");
    }

    template <typename Msg>
    void validate_field_values(Msg &msg)
    {
        msg.set_PartyIDSource(PartyIDSourceEnum::Value::BIC);
        EXPECT_EQ(msg.get_PartyIDSource(), PartyIDSourceEnum::Value::BIC);
        msg.set_PartyIDSource(PartyIDSourceEnum::Value::Proprietary);
        EXPECT_EQ(msg.get_PartyIDSource(), PartyIDSourceEnum::Value::Proprietary);
        msg.set_PartyIDSource(PartyIDSourceEnum::Value::nullValue);
        EXPECT_EQ(msg.get_PartyIDSource(), PartyIDSourceEnum::Value::nullValue);
    }

    template <typename Msg>
    void validate_optional_field_info()
    {
        Msg msg{};
        EXPECT_EQ(msg.OptionalPartyIDSource_size(), 1);
        EXPECT_EQ(msg.OptionalPartyIDSource_offset(), 17);
        EXPECT_EQ(msg.OptionalPartyIDSource_id(), 448);
        EXPECT_EQ(msg.OptionalPartyIDSource_name(), "OptionalPartyIDSource");
    }

    template <typename Msg>
    void optional_field_values()
    {
        Msg msg{};
        EXPECT_EQ(msg.get_PartyIDSource(), PartyIDSourceEnum::Value::nullValue);

        validate_field_values(msg);
    }
}