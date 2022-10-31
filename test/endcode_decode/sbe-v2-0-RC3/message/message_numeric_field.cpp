#include <iostream>
#include <limits>

#include <gtest/gtest.h>
#include <random_gen.h>

#include <TestMessage.h>

namespace sbetool
{
    template<typename... T>
    std::size_t get_offset()
    {
        static constexpr const std::size_t field_offset{67};
        return (field_offset + ... + sizeof(T));
    }

    TEST(numeric, field_info_uint64)
    {
        TestMessage msg{};
        EXPECT_EQ(msg.OrderQtyU64_size(), sizeof(std::uint64_t));
        EXPECT_EQ(msg.OrderQtyU64_offset(), get_offset());
        EXPECT_EQ(msg.OrderQtyU64_id(), 38);
        EXPECT_EQ(msg.OrderQtyU64_name(), "OrderQtyU64");

        EXPECT_EQ(msg.OrderQtyU64_min_value(), std::numeric_limits<std::uint64_t>::min());
        EXPECT_EQ(msg.OrderQtyU64_max_value(), std::numeric_limits<std::uint64_t>::max() - 1);
        EXPECT_EQ(msg.OrderQtyU64_null_value(), std::numeric_limits<std::uint64_t>::max());
    }

    TEST(numeric, field_values_uint64)
    {
        TestMessage msg{};
        auto value = random_number<std::uint64_t>();
        msg.set_OrderQtyU64(value);
        EXPECT_EQ(msg.get_OrderQtyU64(), value);
        msg.set_OrderQtyU64(std::numeric_limits<std::uint64_t>::min());
        EXPECT_EQ(msg.get_OrderQtyU64(), std::numeric_limits<std::uint64_t>::min());
        msg.set_OrderQtyU64(std::numeric_limits<std::uint64_t>::max() - 1);
        EXPECT_EQ(msg.get_OrderQtyU64(), std::numeric_limits<std::uint64_t>::max() - 1);
        // null
        msg.set_OrderQtyU64(std::numeric_limits<std::uint64_t>::max());
        EXPECT_EQ(msg.get_OrderQtyU64(), std::numeric_limits<std::uint64_t>::max());
    }

    TEST(numeric, field_info_int64)
    {
        TestMessage msg{};
        EXPECT_EQ(msg.OrderQty64_size(), sizeof(std::int64_t));
        EXPECT_EQ(msg.OrderQty64_offset(), get_offset<std::uint64_t>());
        EXPECT_EQ(msg.OrderQty64_id(), 381);
        EXPECT_EQ(msg.OrderQty64_name(), "OrderQty64");

        EXPECT_EQ(msg.OrderQty64_min_value(), std::numeric_limits<std::int64_t>::min() + 1);
        EXPECT_EQ(msg.OrderQty64_max_value(), std::numeric_limits<std::int64_t>::max());
        EXPECT_EQ(msg.OrderQty64_null_value(), std::numeric_limits<std::int64_t>::min());
    }

    TEST(numeric, field_values_int64)
    {
        TestMessage msg{};
        auto value = random_number<std::int64_t>();
        msg.set_OrderQty64(value);
        EXPECT_EQ(msg.get_OrderQty64(), value);
        msg.set_OrderQty64(std::numeric_limits<std::int64_t>::min());
        EXPECT_EQ(msg.get_OrderQty64(), std::numeric_limits<std::int64_t>::min());
        msg.set_OrderQty64(std::numeric_limits<std::int64_t>::max());
        EXPECT_EQ(msg.get_OrderQty64(), std::numeric_limits<std::int64_t>::max());
        // null
        msg.set_OrderQty64(std::numeric_limits<std::int64_t>::max());
        EXPECT_EQ(msg.get_OrderQty64(), std::numeric_limits<std::int64_t>::max());
    }

    TEST(numeric, field_info_uint32)
    {
        TestMessage msg{};
        EXPECT_EQ(msg.OrderQtyU32_size(), sizeof(std::uint32_t));
        EXPECT_EQ(msg.OrderQtyU32_offset(), (get_offset<std::uint64_t, std::int64_t>()));
        EXPECT_EQ(msg.OrderQtyU32_id(), 382);
        EXPECT_EQ(msg.OrderQtyU32_name(), "OrderQtyU32");

        EXPECT_EQ(msg.OrderQtyU32_min_value(), std::numeric_limits<std::uint32_t>::min());
        EXPECT_EQ(msg.OrderQtyU32_max_value(), std::numeric_limits<std::uint32_t>::max() - 1);
        EXPECT_EQ(msg.OrderQtyU32_null_value(), std::numeric_limits<std::uint32_t>::max());
    }

    TEST(numeric, field_values_uint32)
    {
        TestMessage msg{};
        auto value = random_number<std::uint32_t>();
        msg.set_OrderQtyU32(value);
        EXPECT_EQ(msg.get_OrderQtyU32(), value);
        msg.set_OrderQtyU32(std::numeric_limits<std::uint32_t>::min());
        EXPECT_EQ(msg.get_OrderQtyU32(), std::numeric_limits<std::uint32_t>::min());
        msg.set_OrderQtyU32(std::numeric_limits<std::uint32_t>::max() - 1);
        EXPECT_EQ(msg.get_OrderQtyU32(), std::numeric_limits<std::uint32_t>::max() - 1);
        // null
        msg.set_OrderQtyU32(std::numeric_limits<std::uint32_t>::max());
        EXPECT_EQ(msg.get_OrderQtyU32(), std::numeric_limits<std::uint32_t>::max());
    }

    TEST(numeric, field_info_int32)
    {
        TestMessage msg{};
        EXPECT_EQ(msg.OrderQty32_size(), sizeof(std::int32_t));
        EXPECT_EQ(msg.OrderQty32_offset(), (get_offset<std::uint64_t, std::int64_t, std::uint32_t>()));
        EXPECT_EQ(msg.OrderQty32_id(), 383);
        EXPECT_EQ(msg.OrderQty32_name(), "OrderQty32");

        EXPECT_EQ(msg.OrderQty32_min_value(), std::numeric_limits<std::int32_t>::min() + 1);
        EXPECT_EQ(msg.OrderQty32_max_value(), std::numeric_limits<std::int32_t>::max());
        EXPECT_EQ(msg.OrderQty32_null_value(), std::numeric_limits<std::int32_t>::min());
    }

    TEST(numeric, field_values_int32)
    {
        TestMessage msg{};
        auto value = random_number<std::int32_t>();
        msg.set_OrderQty32(value);
        EXPECT_EQ(msg.get_OrderQty32(), value);
        msg.set_OrderQty32(std::numeric_limits<std::int32_t>::min());
        EXPECT_EQ(msg.get_OrderQty32(), std::numeric_limits<std::int32_t>::min());
        msg.set_OrderQty32(std::numeric_limits<std::int32_t>::max());
        EXPECT_EQ(msg.get_OrderQty32(), std::numeric_limits<std::int32_t>::max());
        // null
        msg.set_OrderQty32(std::numeric_limits<std::int32_t>::max());
        EXPECT_EQ(msg.get_OrderQty32(), std::numeric_limits<std::int32_t>::max());
    } 

    TEST(numeric, field_info_uint16)
    {
        TestMessage msg{};
        EXPECT_EQ(msg.OrderQtyU16_size(), sizeof(std::uint16_t));
        EXPECT_EQ(msg.OrderQtyU16_offset(), (get_offset<std::uint64_t, std::int64_t, std::uint32_t, std::int32_t>()));
        EXPECT_EQ(msg.OrderQtyU16_id(), 384);
        EXPECT_EQ(msg.OrderQtyU16_name(), "OrderQtyU16");

        EXPECT_EQ(msg.OrderQtyU16_min_value(), std::numeric_limits<std::uint16_t>::min());
        EXPECT_EQ(msg.OrderQtyU16_max_value(), std::numeric_limits<std::uint16_t>::max() - 1);
        EXPECT_EQ(msg.OrderQtyU16_null_value(), std::numeric_limits<std::uint16_t>::max());
    }

    TEST(numeric, field_values_uint16)
    {
        TestMessage msg{};
        auto value = random_number<std::uint16_t>();
        msg.set_OrderQtyU16(value);
        EXPECT_EQ(msg.get_OrderQtyU16(), value);
        msg.set_OrderQtyU16(std::numeric_limits<std::uint16_t>::min());
        EXPECT_EQ(msg.get_OrderQtyU16(), std::numeric_limits<std::uint16_t>::min());
        msg.set_OrderQtyU16(std::numeric_limits<std::uint16_t>::max() - 1);
        EXPECT_EQ(msg.get_OrderQtyU16(), std::numeric_limits<std::uint16_t>::max() - 1);
        // null
        msg.set_OrderQtyU16(std::numeric_limits<std::uint16_t>::max());
        EXPECT_EQ(msg.get_OrderQtyU16(), std::numeric_limits<std::uint16_t>::max());
    }

    TEST(numeric, field_info_int16)
    {
        TestMessage msg{};
        EXPECT_EQ(msg.OrderQty16_size(), sizeof(std::int16_t));
        EXPECT_EQ(msg.OrderQty16_offset(), (get_offset<std::uint64_t, std::int64_t, std::uint32_t, std::int32_t, std::uint16_t>()));
        EXPECT_EQ(msg.OrderQty16_id(), 385);
        EXPECT_EQ(msg.OrderQty16_name(), "OrderQty16");

        EXPECT_EQ(msg.OrderQty16_min_value(), std::numeric_limits<std::int16_t>::min() + 1);
        EXPECT_EQ(msg.OrderQty16_max_value(), std::numeric_limits<std::int16_t>::max());
        EXPECT_EQ(msg.OrderQty16_null_value(), std::numeric_limits<std::int16_t>::min());
    }

    TEST(numeric, field_values_int16)
    {
        TestMessage msg{};
        auto value = random_number<std::int16_t>();
        msg.set_OrderQty16(value);
        EXPECT_EQ(msg.get_OrderQty16(), value);
        msg.set_OrderQty16(std::numeric_limits<std::int16_t>::min());
        EXPECT_EQ(msg.get_OrderQty16(), std::numeric_limits<std::int16_t>::min());
        msg.set_OrderQty16(std::numeric_limits<std::int16_t>::max());
        EXPECT_EQ(msg.get_OrderQty16(), std::numeric_limits<std::int16_t>::max());
        // null
        msg.set_OrderQty16(std::numeric_limits<std::int16_t>::max());
        EXPECT_EQ(msg.get_OrderQty16(), std::numeric_limits<std::int16_t>::max());
    }    

    TEST(numeric, field_info_uint8)
    {
        TestMessage msg{};
        EXPECT_EQ(msg.OrderQtyU8_size(), sizeof(std::uint8_t));
        EXPECT_EQ(msg.OrderQtyU8_offset(), (get_offset<std::uint64_t, std::int64_t, std::uint32_t, std::int32_t, std::uint16_t, std::int16_t>()));
        EXPECT_EQ(msg.OrderQtyU8_id(), 386);
        EXPECT_EQ(msg.OrderQtyU8_name(), "OrderQtyU8");

        EXPECT_EQ(msg.OrderQtyU8_min_value(), std::numeric_limits<std::uint8_t>::min());
        EXPECT_EQ(msg.OrderQtyU8_max_value(), std::numeric_limits<std::uint8_t>::max() - 1);
        EXPECT_EQ(msg.OrderQtyU8_null_value(), std::numeric_limits<std::uint8_t>::max());
    }

    TEST(numeric, field_values_uint8)
    {
        TestMessage msg{};
        auto value = random_number<std::uint8_t>();
        msg.set_OrderQtyU8(value);
        EXPECT_EQ(msg.get_OrderQtyU8(), value);
        msg.set_OrderQtyU8(std::numeric_limits<std::uint8_t>::min());
        EXPECT_EQ(msg.get_OrderQtyU8(), std::numeric_limits<std::uint8_t>::min());
        msg.set_OrderQtyU8(std::numeric_limits<std::uint8_t>::max() - 1);
        EXPECT_EQ(msg.get_OrderQtyU8(), std::numeric_limits<std::uint8_t>::max() - 1);
        // null
        msg.set_OrderQtyU8(std::numeric_limits<std::uint8_t>::max());
        EXPECT_EQ(msg.get_OrderQtyU8(), std::numeric_limits<std::uint8_t>::max());
    }

    TEST(numeric, field_info_int8)
    {
        TestMessage msg{};
        EXPECT_EQ(msg.OrderQty8_size(), sizeof(std::int8_t));
        EXPECT_EQ(msg.OrderQty8_offset(), (get_offset<std::uint64_t, std::int64_t, std::uint32_t, std::int32_t, std::uint16_t, std::int16_t, std::uint8_t>()));
        EXPECT_EQ(msg.OrderQty8_id(), 387);
        EXPECT_EQ(msg.OrderQty8_name(), "OrderQty8");

        EXPECT_EQ(msg.OrderQty8_min_value(), std::numeric_limits<std::int8_t>::min() + 1);
        EXPECT_EQ(msg.OrderQty8_max_value(), std::numeric_limits<std::int8_t>::max());
        EXPECT_EQ(msg.OrderQty8_null_value(), std::numeric_limits<std::int8_t>::min());
    }

    TEST(numeric, field_values_int8)
    {
        TestMessage msg{};
        auto value = random_number<std::int8_t>();
        msg.set_OrderQty8(value);
        EXPECT_EQ(msg.get_OrderQty8(), value);
        msg.set_OrderQty8(std::numeric_limits<std::int8_t>::min());
        EXPECT_EQ(msg.get_OrderQty8(), std::numeric_limits<std::int8_t>::min());
        msg.set_OrderQty8(std::numeric_limits<std::int8_t>::max());
        EXPECT_EQ(msg.get_OrderQty8(), std::numeric_limits<std::int8_t>::max());
        // null
        msg.set_OrderQty8(std::numeric_limits<std::int8_t>::max());
        EXPECT_EQ(msg.get_OrderQty8(), std::numeric_limits<std::int8_t>::max());
    }  

    TEST(numeric, optional_field_info_uint64)
    {
        TestMessage msg{};
        EXPECT_EQ(msg.OptionalOrderQtyU64_size(), sizeof(std::uint64_t));
        EXPECT_EQ(msg.OptionalOrderQtyU64_offset(), (get_offset<std::uint64_t, std::int64_t, std::uint32_t, std::int32_t
            , std::uint16_t, std::int16_t, std::uint8_t, std::int8_t>()));
        EXPECT_EQ(msg.OptionalOrderQtyU64_id(), 388);
        EXPECT_EQ(msg.OptionalOrderQtyU64_name(), "OptionalOrderQtyU64");

        EXPECT_EQ(msg.OptionalOrderQtyU64_min_value(), std::numeric_limits<std::uint64_t>::min());
        EXPECT_EQ(msg.OptionalOrderQtyU64_max_value(), std::numeric_limits<std::uint64_t>::max() - 1);
        EXPECT_EQ(msg.OptionalOrderQtyU64_null_value(), std::numeric_limits<std::uint64_t>::max());
    }

    TEST(numeric, optional_field_values_uint64)
    {
        TestMessage msg{};
        auto value = random_number<std::uint64_t>();
        msg.set_OptionalOrderQtyU64(value);
        EXPECT_EQ(msg.get_OptionalOrderQtyU64(), value);
        msg.set_OptionalOrderQtyU64(std::numeric_limits<std::uint64_t>::min());
        EXPECT_EQ(msg.get_OptionalOrderQtyU64(), std::numeric_limits<std::uint64_t>::min());
        msg.set_OptionalOrderQtyU64(std::numeric_limits<std::uint64_t>::max() - 1);
        EXPECT_EQ(msg.get_OptionalOrderQtyU64(), std::numeric_limits<std::uint64_t>::max() - 1);
        // null
        msg.set_OptionalOrderQtyU64(std::numeric_limits<std::uint64_t>::max());
        EXPECT_EQ(msg.get_OptionalOrderQtyU64(), std::numeric_limits<std::uint64_t>::max());
    }

    TEST(numeric, const_field_info_uint64)
    {
        TestMessage msg{};
        EXPECT_EQ(msg.ConstOrderQty64_size(), 0);
        EXPECT_EQ(msg.ConstOrderQty64_offset(), (get_offset<std::uint64_t, std::int64_t, std::uint32_t, std::int32_t
            , std::uint16_t, std::int16_t, std::uint8_t, std::int8_t, std::uint64_t>()));
        EXPECT_EQ(msg.ConstOrderQty64_id(), 389);
        EXPECT_EQ(msg.ConstOrderQty64_name(), "ConstOrderQty64");
    }

    TEST(numeric, const_field_values_uint64)
    {
        TestMessage msg{};

        EXPECT_EQ(msg.get_ConstOrderQty64(), 42545);
    }    
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
