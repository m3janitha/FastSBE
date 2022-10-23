#pragma once

#include <benchmark/benchmark.h>

#include <random_gen.h>
#include <NewOrderSingle.h>
#include <NewOrderSingleData.h>

template <typename Msg>
inline void print_message(Msg &msg)
{
    std::cout << "[ MESSEGE  ]" << std::endl;
    std::cout << msg << std::endl;
    std::cout << "[----------]" << std::endl;
}

namespace fastsbe
{
    void encode_NewOrderSingle_from_struct(char *buffer, NewOrderSingleData &values, bool display)
    {
        auto &msg = *reinterpret_cast<fastsbe::NewOrderSingle *>(buffer);

        msg.set_ClOrdId(values.ClOrdId)
            .set_Account(values.Account)
            .set_Symbol(values.Symbol)
            .set_Side(static_cast<sideEnum::Value>(values.Side));
        msg.set_TransactTime(values.TransactTime);
        msg.get_OrderQty().set_mantissa(values.OrderQty.mantissa);
        msg.set_OrdType(static_cast<ordTypeEnum::Value>(values.OrdType));
        msg.get_Price().set_mantissa(values.Price.mantissa);
        msg.get_StopPx().set_mantissa(values.StopPx.mantissa);

        auto &PartiesGrp = msg.append_PartiesGrp(values.PartiesGrps.size());
        for (auto i = 0u; i < values.PartiesGrps.size(); i++)
        {
            auto &party = values.PartiesGrps[i];
            PartiesGrp.get(i)
                .set_PartyID(party.PartyID)
                .set_PartyIDSource(static_cast<fastsbe::PartyIDSourceEnum::Value>(party.PartyIDSource))
                .set_PartyRole(static_cast<fastsbe::PartyRoleEnum::Value>(party.PartyRole));
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

        benchmark::DoNotOptimize(msg);

        if (display)
            print_message(msg);
    }

    void decode_NewOrderSingle(char *buffer, bool display)
    {
        auto &msg = *reinterpret_cast<fastsbe::NewOrderSingle *>(buffer);

        auto clodr_id = msg.get_ClOrdId();
        benchmark::DoNotOptimize(clodr_id);
        auto Account = msg.get_Account();
        benchmark::DoNotOptimize(clodr_id);
        auto Symbol = msg.get_Symbol();
        benchmark::DoNotOptimize(Symbol);
        auto Side = msg.get_Side();
        benchmark::DoNotOptimize(Symbol);

        auto TransactTime = msg.get_TransactTime();
        benchmark::DoNotOptimize(TransactTime);

        auto &OrderQty = msg.get_OrderQty();
        auto oq_mantissa = OrderQty.get_mantissa();
        benchmark::DoNotOptimize(oq_mantissa);
        auto oq_exponent = OrderQty.get_exponent();
        benchmark::DoNotOptimize(oq_exponent);

        auto &Price = msg.get_Price();
        auto p_mantissa = Price.get_mantissa();
        benchmark::DoNotOptimize(p_mantissa);
        auto p_exponent = Price.get_exponent();
        benchmark::DoNotOptimize(p_exponent);

        auto &StopPx = msg.get_StopPx();
        auto sp_mantissa = StopPx.get_mantissa();
        benchmark::DoNotOptimize(sp_mantissa);
        auto sp_exponent = StopPx.get_exponent();
        benchmark::DoNotOptimize(sp_exponent);

        auto &PartiesGrp = msg.get_PartiesGrp();
        for (auto i = 0u; i < PartiesGrp.get_numInGroup(); i++)
        {
            auto &party = PartiesGrp.get(i);

            auto PartyID = party.get_PartyID();
            benchmark::DoNotOptimize(PartyID);
            auto PartyIDSource = party.get_PartyIDSource();
            benchmark::DoNotOptimize(PartyIDSource);
            auto PartyRole = party.get_PartyRole();
            benchmark::DoNotOptimize(PartyRole);
        }

        auto &AllocsGrp = msg.get_AllocsGrp();
        for (auto i = 0u; i < AllocsGrp.get_numInGroup(); i++)
        {
            auto &alloc = AllocsGrp.get(i);

            auto AllocAccount = alloc.get_AllocAccount();
            benchmark::DoNotOptimize(AllocAccount);
            auto &AllocShares = alloc.get_AllocShares();
            auto mantissa = AllocShares.get_mantissa();
            benchmark::DoNotOptimize(mantissa);
            auto exponent = AllocShares.get_exponent();
            benchmark::DoNotOptimize(exponent);
        }

        auto &TradingSessionsGrp = msg.get_TradingSessionsGrp();
        for (auto i = 0u; i < TradingSessionsGrp.get_numInGroup(); i++)
        {
            auto &tradingSession = TradingSessionsGrp.get(i);

            auto TradingSessionID = tradingSession.get_TradingSessionID();
            benchmark::DoNotOptimize(TradingSessionID);
        }

        auto Text = msg.get_Text().get_str();
        benchmark::DoNotOptimize(Text);

        auto ClearingFirm = msg.get_ClearingFirm().get_str();
        benchmark::DoNotOptimize(ClearingFirm);

        if (display)
            print_message(msg);
    }
}