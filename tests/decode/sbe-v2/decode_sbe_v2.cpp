#include <iostream>

#include <gtest/gtest.h>
#include <random_gen.h>

#include <BusinessMessageReject.h>
#include <ExecutionReportTrade.h>
#include <NewOrderSingle.h>

using namespace test::sbe;

template <typename Msg>
void print_message(Msg &msg)
{
    std::cout << "[ MESSEGE  ]" << std::endl;
    std::cout << msg << std::endl;
    std::cout << "[----------]" << std::endl;
}

/* string encoding: Array of char of specified length, delimited by NUL character if a string is shorter than the length specified for a field.*/
/* use max length as (length -1) in encoding to make it always null terminated */
struct NewOrderSingle_T
{
    std::string ClOrdId{random_string(7).c_str()};
    std::string Account{random_string(7).c_str()};
    std::string Symbol{random_string(7).c_str()};
    sideEnum::Value Side{random_enum<test::sbe::sideEnum::Value>('1', '2')};
    struct timestampEncoding
    {
        std::uint64_t time{random_number<std::uint64_t>()};
    };
    timestampEncoding TransactTime{};
    struct qtyEncoding
    {
        std::int32_t mantissa{random_number<std::int32_t>()};
    };
    qtyEncoding OrderQty{};
    ordTypeEnum::Value OrdType{random_enum<ordTypeEnum::Value>('1', '4')};
    struct decimalEncoding
    {
        std::int64_t mantissa{random_number<std::int64_t>()};
    };
    decimalEncoding Price{};
    decimalEncoding StopPx{};
    struct PartiesGrp
    {
        std::string PartyID{random_string(7).c_str()};
        PartyIDSourceEnum::Value PartyIDSource{random_enum<PartyIDSourceEnum::Value>('B', 'C')};
        PartyRoleEnum::Value PartyRole{random_enum<PartyRoleEnum::Value>(1, 3)};
    };
    std::vector<PartiesGrp> PartiesGrps{};
    struct AllocsGrp
    {
        std::string AllocAccount{random_string(15).c_str()};
        qtyEncoding AllocShares{};
    };
    std::vector<AllocsGrp> AllocsGrps{};
    struct TradingSessionsGrp
    {
        std::string TradingSessionID{random_string(7).c_str()};
    };
    std::vector<TradingSessionsGrp> TradingSessionsGrps{};
    std::string Text{random_string(20).c_str()};
    std::string ClearingFirm{random_string(20).c_str()};

    NewOrderSingle_T()
        : PartiesGrps(random_number<std::size_t>(0, 10)),
          AllocsGrps(random_number<std::size_t>(0, 10)),
          TradingSessionsGrps(random_number<std::size_t>(0, 10)) {}
};

void encode(NewOrderSingle_T &values, char *buffer)
{
    auto &msg = *reinterpret_cast<test::sbe::NewOrderSingle *>(buffer);

    msg.set_ClOrdId(values.ClOrdId)
        .set_Account(values.Account)
        .set_Symbol(values.Symbol)
        .set_Side(values.Side);
    msg.get_TransactTime().set_time(values.TransactTime.time);
    msg.get_OrderQty().set_mantissa(values.OrderQty.mantissa);
    msg.set_OrdType(values.OrdType);
    msg.get_Price().set_mantissa(values.Price.mantissa);
    msg.get_StopPx().set_mantissa(values.StopPx.mantissa);

    auto &PartiesGrp = msg.append_PartiesGrp(values.PartiesGrps.size());
    for (auto i = 0u; i < values.PartiesGrps.size(); i++)
    {
        auto &party = values.PartiesGrps[i];
        PartiesGrp.get(i)
            .set_PartyID(party.PartyID)
            .set_PartyIDSource(party.PartyIDSource)
            .set_PartyRole(party.PartyRole);
    }

    auto &AllocsGrp = msg.append_AllocsGrp(values.AllocsGrps.size());
    for (auto i = 0u; i < values.AllocsGrps.size(); i++)
    {
        auto &alloc = values.AllocsGrps[i];
        AllocsGrp.get(i)
            .set_AllocAccount(alloc.AllocAccount)
            .get_AllocShares()
            .set_mantissa(alloc.AllocShares.mantissa);
    }

    auto &TradingSessionsGrp = msg.append_TradingSessionsGrp(values.TradingSessionsGrps.size());
    for (auto i = 0u; i < values.TradingSessionsGrps.size(); i++)
    {
        auto &tradingSession = values.TradingSessionsGrps[i];
        TradingSessionsGrp.get(i)
            .set_TradingSessionID(tradingSession.TradingSessionID);
    }
    msg.append_Text(values.Text.c_str(), values.Text.length());
    msg.append_ClearingFirm(values.ClearingFirm.c_str(), values.ClearingFirm.length());

    print_message(msg);
}

void decode(NewOrderSingle_T &values, char *buffer)
{
    auto &msg = *reinterpret_cast<test::sbe::NewOrderSingle *>(buffer);

    EXPECT_EQ(msg.get_ClOrdId(), values.ClOrdId);
    EXPECT_EQ(msg.get_Account(), values.Account);
    EXPECT_EQ(msg.get_Symbol(), values.Symbol);
    EXPECT_EQ(msg.get_Side(), values.Side);

    auto &TransactTime = msg.get_TransactTime();
    EXPECT_EQ(TransactTime.get_time(), values.TransactTime.time);
    EXPECT_EQ(TransactTime.get_unit(), TimeUnit::Value::nanosecond);

    auto &OrderQty = msg.get_OrderQty();
    EXPECT_EQ(OrderQty.get_mantissa(), values.OrderQty.mantissa);
    EXPECT_EQ(OrderQty.get_exponent(), static_cast<std::int8_t>(0));

    auto &Price = msg.get_Price();
    EXPECT_EQ(Price.get_mantissa(), values.Price.mantissa);
    EXPECT_EQ(Price.get_exponent(), static_cast<std::int8_t>(-3));

    auto &StopPx = msg.get_StopPx();
    EXPECT_EQ(StopPx.get_mantissa(), values.StopPx.mantissa);
    EXPECT_EQ(StopPx.get_exponent(), static_cast<std::int8_t>(-3));

    auto &PartiesGrp = msg.get_PartiesGrp();
    for (auto i = 0u; i < values.PartiesGrps.size(); i++)
    {
        auto &party = PartiesGrp.get(i);
        auto &party_t = values.PartiesGrps[i];
        EXPECT_EQ(party.get_PartyID(), party_t.PartyID);
        EXPECT_EQ(party.get_PartyIDSource(), party_t.PartyIDSource);
        EXPECT_EQ(party.get_PartyRole(), party_t.PartyRole);
    }

    auto &AllocsGrp = msg.get_AllocsGrp();
    for (auto i = 0u; i < values.AllocsGrps.size(); i++)
    {
        auto &alloc = AllocsGrp.get(i);
        auto &alloc_t = values.AllocsGrps[i];

        EXPECT_EQ(alloc.get_AllocAccount(), alloc_t.AllocAccount);

        auto &AllocShares = alloc.get_AllocShares();
        EXPECT_EQ(AllocShares.get_mantissa(), alloc_t.AllocShares.mantissa);
        EXPECT_EQ(AllocShares.get_exponent(), static_cast<std::int8_t>(0));
    }

    auto &TradingSessionsGrp = msg.get_TradingSessionsGrp();
    for (auto i = 0u; i < values.TradingSessionsGrps.size(); i++)
    {
        auto &tradingSession = TradingSessionsGrp.get(i);
        auto &tradingSession_t = values.TradingSessionsGrps[i];

        EXPECT_EQ(tradingSession.get_TradingSessionID(), tradingSession_t.TradingSessionID);
    }

    auto Text = msg.get_Text().get_str();
    EXPECT_EQ(std::string(Text.data(), Text.length()), values.Text);

    auto ClearingFirm = msg.get_ClearingFirm().get_str();
    EXPECT_EQ(std::string(ClearingFirm.data(), ClearingFirm.length()), values.ClearingFirm);

    print_message(msg);
}

class EncodeDecodeFixture : public testing::Test
{
protected:
    char buffer_[2048]{};
    NewOrderSingle_T values_{};
};

TEST_F(EncodeDecodeFixture, encode_and_decode)
{
    encode(values_, buffer_);
    decode(values_, buffer_);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}