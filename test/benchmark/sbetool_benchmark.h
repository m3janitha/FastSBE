#pragma once

#include <benchmark/benchmark.h>

#include <random_gen.h>
#include <SbeTool/sbetool/NewOrderSingle.h>

template <typename Msg>
inline void print_message2(Msg &msg)
{
    std::cout << "[ MESSEGE  ]" << std::endl;
    std::cout << msg << std::endl;
    std::cout << "[----------]" << std::endl;
}

namespace sbetool
{
    void encode_NewOrderSingle_from_struct(char *buffer, std::size_t length, NewOrderSingleData &values, bool display)
    {
        NewOrderSingle msg;
        msg.wrapForEncode(buffer, 0, length)
            .putClOrdId(values.ClOrdId.c_str())
            .putAccount(values.Account.c_str())
            .putSymbol(values.Symbol.c_str())
            .side(static_cast<SideEnum::Value>(values.Side))
            .transactTime(values.TransactTime);

        msg.orderQty().mantissa(values.OrderQty.mantissa);
        msg.ordType(static_cast<OrdTypeEnum::Value>(values.OrdType));
        msg.price().mantissa(values.Price.mantissa);
        msg.stopPx().mantissa(values.StopPx.mantissa);

        auto &PartiesGrp = msg.partiesGrpCount(values.PartiesGrps.size());
        for (auto i = 0u; i < values.PartiesGrps.size(); i++)
        {
            auto &party = values.PartiesGrps[i];
            PartiesGrp.next()
                .putPartyID(party.PartyID.c_str())
                .partyIDSource(static_cast<PartyIDSourceEnum::Value>(party.PartyIDSource))
                .partyRole(static_cast<PartyRoleEnum::Value>(party.PartyRole));
        }

        auto &AllocsGrp = msg.allocsGrpCount(values.AllocsGrps.size());
        for (auto i = 0u; i < values.AllocsGrps.size(); i++)
        {
            auto &alloc = values.AllocsGrps[i];
            AllocsGrp.next()
                .putAllocAccount(alloc.AllocAccount.c_str())
                .allocShares()
                .mantissa(alloc.AllocShares.mantissa);
        }

        auto &TradingSessionsGrp = msg.tradingSessionsGrpCount(values.TradingSessionsGrps.size());
        for (auto i = 0u; i < values.TradingSessionsGrps.size(); i++)
        {
            auto &tradingSession = values.TradingSessionsGrps[i];
            TradingSessionsGrp.next()
                .putTradingSessionID(tradingSession.TradingSessionID.c_str());
        }

        msg.putText(values.Text.c_str(), values.Text.length());
        msg.putClearingFirm(values.ClearingFirm.c_str(), values.ClearingFirm.length());

        benchmark::DoNotOptimize(msg);

        if (display)
            print_message2(msg);
    }

    void decode_NewOrderSingle(char *buffer, std::size_t length, bool display)
    {
        sbetool::NewOrderSingle msg;
        msg.wrapForDecode(buffer, 0, msg.sbeBlockLength(), 0, length);

        auto clodr_id = msg.clOrdId();
        benchmark::DoNotOptimize(clodr_id);
        auto Account = msg.account();
        benchmark::DoNotOptimize(clodr_id);
        auto Symbol = msg.symbol();
        benchmark::DoNotOptimize(Symbol);
        auto Side = msg.side();
        benchmark::DoNotOptimize(Symbol);
        auto TransactTime = msg.transactTime();
        benchmark::DoNotOptimize(TransactTime);

        auto &OrderQty = msg.orderQty();
        auto oq_mantissa = OrderQty.mantissa();
        benchmark::DoNotOptimize(oq_mantissa);
        auto oq_exponent = OrderQty.exponent();
        benchmark::DoNotOptimize(oq_exponent);

        auto &Price = msg.price();
        auto p_mantissa = Price.mantissa();
        benchmark::DoNotOptimize(p_mantissa);
        auto p_exponent = Price.exponent();
        benchmark::DoNotOptimize(p_exponent);

        auto &StopPx = msg.stopPx();
        auto sp_mantissa = StopPx.mantissa();
        benchmark::DoNotOptimize(sp_mantissa);
        auto sp_exponent = StopPx.exponent();
        benchmark::DoNotOptimize(sp_exponent);

        auto &PartiesGrp = msg.partiesGrp();
        while (PartiesGrp.hasNext())
        {
            PartiesGrp.next();

            auto PartyID = PartiesGrp.partyID();
            benchmark::DoNotOptimize(PartyID);
            auto PartyIDSource = PartiesGrp.partyIDSource();
            benchmark::DoNotOptimize(PartyIDSource);
            auto PartyRole = PartiesGrp.partyRole();
            benchmark::DoNotOptimize(PartyRole);
        }

        auto &AllocsGrp = msg.allocsGrp();
        while (AllocsGrp.hasNext())
        {
            AllocsGrp.next();

            auto AllocAccount = AllocsGrp.allocAccount();
            benchmark::DoNotOptimize(AllocAccount);
            auto &AllocShares = AllocsGrp.allocShares();
            auto mantissa = AllocShares.mantissa();
            benchmark::DoNotOptimize(mantissa);
            auto exponent = AllocShares.exponent();
            benchmark::DoNotOptimize(exponent);
        }

        auto &TradingSessionsGrp = msg.tradingSessionsGrp();
        while (TradingSessionsGrp.hasNext())
        {
            TradingSessionsGrp.next();

            auto TradingSessionID = TradingSessionsGrp.tradingSessionID();
            benchmark::DoNotOptimize(TradingSessionID);
        }

        auto Text = msg.text();
        benchmark::DoNotOptimize(Text);

        auto ClearingFirm = msg.clearingFirm();
        benchmark::DoNotOptimize(ClearingFirm);

        if (display)
            print_message2(msg);
    }
}