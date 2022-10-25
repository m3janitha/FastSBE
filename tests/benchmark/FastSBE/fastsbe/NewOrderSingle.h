#pragma once
#include<cstdint>
#include<string>
#include<string_view>
#include<ostream>
#include<sideEnum.h>
#include<qtyEncoding.h>
#include<ordTypeEnum.h>
#include<optionalDecimalEncoding.h>
#include<optionalDecimalEncoding.h>
#include<PartyIDSourceEnum.h>
#include<PartyRoleEnum.h>
#include<groupSizeEncoding.h>
#include<qtyEncoding.h>
#include<groupSizeEncoding.h>
#include<groupSizeEncoding.h>
#include<DATA.h>
#include<DATA.h>

namespace fastsbe
{

class NewOrderSingle
{
    
    public:
    	static constexpr const char* name() noexcept
    	{ 
    		return "NewOrderSingle"; 
    	}
    
    	static constexpr std::size_t template_id() noexcept
    	{ 
    		return 99; 
    	}
    
    	static constexpr std::size_t schema() noexcept
    	{  
    		return 91; 
    	}
    
    	static constexpr std::size_t version() noexcept
    	{ 
    		return 0; 
    	}
    
    	static constexpr const char* semantic_type() noexcept
    	{ 
    		return ""; 	
    	}
    
    
    private:
    	#pragma pack(push, 1)
    	char ClOrdId_[8]{};
    	#pragma pack(pop)
    
    public:
    	static constexpr std::size_t ClOrdId_size() noexcept
    	{
    		return 8;
    	}
    
    	static constexpr std::size_t ClOrdId_offset() noexcept
    	{
    		return 0;
    	}
    
    	static constexpr std::size_t ClOrdId_id() noexcept
    	{
    		return 11;
    	}
    
    	static constexpr const char *ClOrdId_name() noexcept
    	{
    		return "ClOrdId";
    	}
    
    	constexpr char *get_ClOrdId() noexcept
    	{
    		return ClOrdId_;
    	}
    
    	constexpr const char *get_ClOrdId() const noexcept
    	{
    		return ClOrdId_;
    	}
    
    	constexpr std::string_view get_ClOrdId_view() noexcept
    	{
    		return std::string_view(ClOrdId_, 8);
    	}
    
    	constexpr const std::string_view get_ClOrdId_view() const noexcept
    	{
    		return std::string_view(ClOrdId_, 8);
    	}
    
    	const std::string get_ClOrdId_string() const noexcept
    	{
    		auto length = 0ULL;
    		for (; length < 8 && *(ClOrdId_ + length) != '\0'; ++length);
    		return std::string(ClOrdId_, length);
    	}
    
    	constexpr auto &set_ClOrdId(const char *value) noexcept
    	{
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic push
    	#pragma GCC diagnostic ignored "-Wstringop-overflow"
    	#endif
    		std::memcpy(ClOrdId_, value, ClOrdId_size());
    		return *this;
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic pop
    	#endif
    	}
    
    	auto &set_ClOrdId(std::string_view value) noexcept
    	{
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic push
    	#pragma GCC diagnostic ignored "-Wstringop-overflow"
    	#endif
    		// auto size = std::min(ClOrdId_size(), value.size());
    		std::memcpy(ClOrdId_, value.data(), ClOrdId_size());
    		return *this;
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic pop
    	#endif
    	}
    
    private:
    	#pragma pack(push, 1)
    	char Account_[8]{};
    	#pragma pack(pop)
    
    public:
    	static constexpr std::size_t Account_size() noexcept
    	{
    		return 8;
    	}
    
    	static constexpr std::size_t Account_offset() noexcept
    	{
    		return ClOrdId_offset() + ClOrdId_size();
    	}
    
    	static constexpr std::size_t Account_id() noexcept
    	{
    		return 1;
    	}
    
    	static constexpr const char *Account_name() noexcept
    	{
    		return "Account";
    	}
    
    	constexpr char *get_Account() noexcept
    	{
    		return Account_;
    	}
    
    	constexpr const char *get_Account() const noexcept
    	{
    		return Account_;
    	}
    
    	constexpr std::string_view get_Account_view() noexcept
    	{
    		return std::string_view(Account_, 8);
    	}
    
    	constexpr const std::string_view get_Account_view() const noexcept
    	{
    		return std::string_view(Account_, 8);
    	}
    
    	const std::string get_Account_string() const noexcept
    	{
    		auto length = 0ULL;
    		for (; length < 8 && *(Account_ + length) != '\0'; ++length);
    		return std::string(Account_, length);
    	}
    
    	constexpr auto &set_Account(const char *value) noexcept
    	{
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic push
    	#pragma GCC diagnostic ignored "-Wstringop-overflow"
    	#endif
    		std::memcpy(Account_, value, Account_size());
    		return *this;
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic pop
    	#endif
    	}
    
    	auto &set_Account(std::string_view value) noexcept
    	{
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic push
    	#pragma GCC diagnostic ignored "-Wstringop-overflow"
    	#endif
    		// auto size = std::min(Account_size(), value.size());
    		std::memcpy(Account_, value.data(), Account_size());
    		return *this;
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic pop
    	#endif
    	}
    
    private:
    	#pragma pack(push, 1)
    	char Symbol_[8]{};
    	#pragma pack(pop)
    
    public:
    	static constexpr std::size_t Symbol_size() noexcept
    	{
    		return 8;
    	}
    
    	static constexpr std::size_t Symbol_offset() noexcept
    	{
    		return Account_offset() + Account_size();
    	}
    
    	static constexpr std::size_t Symbol_id() noexcept
    	{
    		return 55;
    	}
    
    	static constexpr const char *Symbol_name() noexcept
    	{
    		return "Symbol";
    	}
    
    	constexpr char *get_Symbol() noexcept
    	{
    		return Symbol_;
    	}
    
    	constexpr const char *get_Symbol() const noexcept
    	{
    		return Symbol_;
    	}
    
    	constexpr std::string_view get_Symbol_view() noexcept
    	{
    		return std::string_view(Symbol_, 8);
    	}
    
    	constexpr const std::string_view get_Symbol_view() const noexcept
    	{
    		return std::string_view(Symbol_, 8);
    	}
    
    	const std::string get_Symbol_string() const noexcept
    	{
    		auto length = 0ULL;
    		for (; length < 8 && *(Symbol_ + length) != '\0'; ++length);
    		return std::string(Symbol_, length);
    	}
    
    	constexpr auto &set_Symbol(const char *value) noexcept
    	{
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic push
    	#pragma GCC diagnostic ignored "-Wstringop-overflow"
    	#endif
    		std::memcpy(Symbol_, value, Symbol_size());
    		return *this;
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic pop
    	#endif
    	}
    
    	auto &set_Symbol(std::string_view value) noexcept
    	{
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic push
    	#pragma GCC diagnostic ignored "-Wstringop-overflow"
    	#endif
    		// auto size = std::min(Symbol_size(), value.size());
    		std::memcpy(Symbol_, value.data(), Symbol_size());
    		return *this;
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic pop
    	#endif
    	}
    
    private:
    	#pragma pack(push, 1)
    	sideEnum::Value Side_{};
    	#pragma pack(pop)
    
    public:
    	static constexpr std::size_t Side_size() noexcept
    	{
    		return sizeof(sideEnum);
    	}
    
    	static constexpr std::size_t Side_offset() noexcept
    	{ 
    		return Symbol_offset() + Symbol_size(); 
    	}
    	
    	static constexpr const char* Side_name() noexcept
    	{ 
    		return "Side"; 
    	}
    
    	static constexpr sideEnum::Value Side_null_value() noexcept
    	{
    		return sideEnum::Value::Null;
    	}
    
    	constexpr sideEnum::Value get_Side() const noexcept
    	{ 
    		return Side_;
    	}
    	
    	constexpr auto& set_Side(sideEnum::Value value) noexcept
    	{
    		Side_ = value;
    		return *this;
    	}
    
    
    private:
    	#pragma pack(push, 1)
    	std::uint64_t TransactTime_{};
    	#pragma pack(pop)
    
    public:
    	static constexpr std::size_t TransactTime_size() noexcept
    	{
    		return sizeof(std::uint64_t);
    	}
    
    	static constexpr std::size_t TransactTime_offset() noexcept
    	{ 
    		return Side_offset() + Side_size(); 
    	}
    
    	static constexpr std::size_t TransactTime_id() noexcept
    	{ 
    		return 60; 
    	}
    	
    	static constexpr const char* TransactTime_name() noexcept
    	{ 
    		return "TransactTime"; 
    	}
    	
    	static constexpr std::uint64_t TransactTime_min_value() noexcept
    	{ 
    		return 0; 
    	}
    	
    	static constexpr std::uint64_t TransactTime_max_value() noexcept
    	{
    		return 18446744073709551614;
    	}
    	
    	static constexpr std::uint64_t TransactTime_null_value() noexcept
    	{ 
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic push
    	#pragma GCC diagnostic ignored "-Wtype-limits"
    	#endif
    		return 18446744073709551615;
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic pop
    	#endif
    	}
    
    	constexpr std::uint64_t get_TransactTime() const noexcept
    	{ 
    		return TransactTime_;
    	}
    	
    	constexpr auto& set_TransactTime(std::uint64_t value) noexcept
    	{
    		TransactTime_ = value;
    		return *this;
    	}
    
    
    private:
    	#pragma pack(push, 1)
    	qtyEncoding OrderQty_{};
    	#pragma pack(pop)
    
    public:
    	static constexpr std::size_t OrderQty_size() noexcept
    	{
    		return sizeof(qtyEncoding);
    	}
    
    	static constexpr std::size_t OrderQty_offset() noexcept
    	{ 
    		return TransactTime_offset() + TransactTime_size(); 
    	}
    
    	static constexpr std::size_t OrderQty_id() noexcept
    	{ 
    		return 38; 
    	}
    	
    	static constexpr const char* OrderQty_name() noexcept
    	{ 
    		return "OrderQty"; 
    	}
    	
    	constexpr const qtyEncoding& get_OrderQty() const noexcept
    	{ 
    		return OrderQty_;
    	}
    	
    	constexpr qtyEncoding& get_OrderQty() noexcept
    	{
    		return OrderQty_;
    
    	}
    	constexpr auto& set_OrderQty(qtyEncoding& value) noexcept
    	{
    		OrderQty_ = value;
    		return *this;
    	}
    
    
    private:
    	#pragma pack(push, 1)
    	ordTypeEnum::Value OrdType_{};
    	#pragma pack(pop)
    
    public:
    	static constexpr std::size_t OrdType_size() noexcept
    	{
    		return sizeof(ordTypeEnum);
    	}
    
    	static constexpr std::size_t OrdType_offset() noexcept
    	{ 
    		return OrderQty_offset() + OrderQty_size(); 
    	}
    	
    	static constexpr const char* OrdType_name() noexcept
    	{ 
    		return "OrdType"; 
    	}
    
    	static constexpr ordTypeEnum::Value OrdType_null_value() noexcept
    	{
    		return ordTypeEnum::Value::Null;
    	}
    
    	constexpr ordTypeEnum::Value get_OrdType() const noexcept
    	{ 
    		return OrdType_;
    	}
    	
    	constexpr auto& set_OrdType(ordTypeEnum::Value value) noexcept
    	{
    		OrdType_ = value;
    		return *this;
    	}
    
    
    private:
    	#pragma pack(push, 1)
    	optionalDecimalEncoding Price_{};
    	#pragma pack(pop)
    
    public:
    	static constexpr std::size_t Price_size() noexcept
    	{
    		return sizeof(optionalDecimalEncoding);
    	}
    
    	static constexpr std::size_t Price_offset() noexcept
    	{ 
    		return OrdType_offset() + OrdType_size(); 
    	}
    
    	static constexpr std::size_t Price_id() noexcept
    	{ 
    		return 44; 
    	}
    	
    	static constexpr const char* Price_name() noexcept
    	{ 
    		return "Price"; 
    	}
    	
    	constexpr const optionalDecimalEncoding& get_Price() const noexcept
    	{ 
    		return Price_;
    	}
    	
    	constexpr optionalDecimalEncoding& get_Price() noexcept
    	{
    		return Price_;
    
    	}
    	constexpr auto& set_Price(optionalDecimalEncoding& value) noexcept
    	{
    		Price_ = value;
    		return *this;
    	}
    
    
    private:
    	#pragma pack(push, 1)
    	optionalDecimalEncoding StopPx_{};
    	#pragma pack(pop)
    
    public:
    	static constexpr std::size_t StopPx_size() noexcept
    	{
    		return sizeof(optionalDecimalEncoding);
    	}
    
    	static constexpr std::size_t StopPx_offset() noexcept
    	{ 
    		return Price_offset() + Price_size(); 
    	}
    
    	static constexpr std::size_t StopPx_id() noexcept
    	{ 
    		return 99; 
    	}
    	
    	static constexpr const char* StopPx_name() noexcept
    	{ 
    		return "StopPx"; 
    	}
    	
    	constexpr const optionalDecimalEncoding& get_StopPx() const noexcept
    	{ 
    		return StopPx_;
    	}
    	
    	constexpr optionalDecimalEncoding& get_StopPx() noexcept
    	{
    		return StopPx_;
    
    	}
    	constexpr auto& set_StopPx(optionalDecimalEncoding& value) noexcept
    	{
    		StopPx_ = value;
    		return *this;
    	}
    
    
    private:
    	#pragma pack(push, 1)
    	char buffer_[1024]{};
    	#pragma pack(pop)
    
    	const char* buffer() const
    	{
    		return buffer_;
    	}
    
    	char* buffer()
    	{
    		return buffer_;
    	}
    
    public:
    
    class PartiesGrp
    {
    	friend NewOrderSingle;
        
        class data
        {
            
            private:
            	#pragma pack(push, 1)
            	char PartyID_[8]{};
            	#pragma pack(pop)
            
            public:
            	static constexpr std::size_t PartyID_size() noexcept
            	{
            		return 8;
            	}
            
            	static constexpr std::size_t PartyID_offset() noexcept
            	{
            		return 0;
            	}
            
            	static constexpr std::size_t PartyID_id() noexcept
            	{
            		return 448;
            	}
            
            	static constexpr const char *PartyID_name() noexcept
            	{
            		return "PartyID";
            	}
            
            	constexpr char *get_PartyID() noexcept
            	{
            		return PartyID_;
            	}
            
            	constexpr const char *get_PartyID() const noexcept
            	{
            		return PartyID_;
            	}
            
            	constexpr std::string_view get_PartyID_view() noexcept
            	{
            		return std::string_view(PartyID_, 8);
            	}
            
            	constexpr const std::string_view get_PartyID_view() const noexcept
            	{
            		return std::string_view(PartyID_, 8);
            	}
            
            	const std::string get_PartyID_string() const noexcept
            	{
            		auto length = 0ULL;
            		for (; length < 8 && *(PartyID_ + length) != '\0'; ++length);
            		return std::string(PartyID_, length);
            	}
            
            	constexpr auto &set_PartyID(const char *value) noexcept
            	{
            	#if defined(__GNUG__)
            	#pragma GCC diagnostic push
            	#pragma GCC diagnostic ignored "-Wstringop-overflow"
            	#endif
            		std::memcpy(PartyID_, value, PartyID_size());
            		return *this;
            	#if defined(__GNUG__)
            	#pragma GCC diagnostic pop
            	#endif
            	}
            
            	auto &set_PartyID(std::string_view value) noexcept
            	{
            	#if defined(__GNUG__)
            	#pragma GCC diagnostic push
            	#pragma GCC diagnostic ignored "-Wstringop-overflow"
            	#endif
            		// auto size = std::min(PartyID_size(), value.size());
            		std::memcpy(PartyID_, value.data(), PartyID_size());
            		return *this;
            	#if defined(__GNUG__)
            	#pragma GCC diagnostic pop
            	#endif
            	}
            
            private:
            	#pragma pack(push, 1)
            	PartyIDSourceEnum::Value PartyIDSource_{};
            	#pragma pack(pop)
            
            public:
            	static constexpr std::size_t PartyIDSource_size() noexcept
            	{
            		return sizeof(PartyIDSourceEnum);
            	}
            
            	static constexpr std::size_t PartyIDSource_offset() noexcept
            	{ 
            		return PartyID_offset() + PartyID_size(); 
            	}
            	
            	static constexpr const char* PartyIDSource_name() noexcept
            	{ 
            		return "PartyIDSource"; 
            	}
            
            	static constexpr PartyIDSourceEnum::Value PartyIDSource_null_value() noexcept
            	{
            		return PartyIDSourceEnum::Value::Null;
            	}
            
            	constexpr PartyIDSourceEnum::Value get_PartyIDSource() const noexcept
            	{ 
            		return PartyIDSource_;
            	}
            	
            	constexpr auto& set_PartyIDSource(PartyIDSourceEnum::Value value) noexcept
            	{
            		PartyIDSource_ = value;
            		return *this;
            	}
            
            
            private:
            	#pragma pack(push, 1)
            	PartyRoleEnum::Value PartyRole_{};
            	#pragma pack(pop)
            
            public:
            	static constexpr std::size_t PartyRole_size() noexcept
            	{
            		return sizeof(PartyRoleEnum);
            	}
            
            	static constexpr std::size_t PartyRole_offset() noexcept
            	{ 
            		return PartyIDSource_offset() + PartyIDSource_size(); 
            	}
            	
            	static constexpr const char* PartyRole_name() noexcept
            	{ 
            		return "PartyRole"; 
            	}
            
            	static constexpr PartyRoleEnum::Value PartyRole_null_value() noexcept
            	{
            		return PartyRoleEnum::Value::Null;
            	}
            
            	constexpr PartyRoleEnum::Value get_PartyRole() const noexcept
            	{ 
            		return PartyRole_;
            	}
            	
            	constexpr auto& set_PartyRole(PartyRoleEnum::Value value) noexcept
            	{
            		PartyRole_ = value;
            		return *this;
            	}
            
    };
    
    private:
    #pragma pack(push, 1)
    	groupSizeEncoding header_{};
    #pragma pack(pop)
    
    public:
    	PartiesGrp() = default;
    	PartiesGrp(std::uint16_t count)
    		:header_(sizeof(PartiesGrp::data), count) {}
    
    	data& get(std::size_t group_id) noexcept
    	{
    		auto* buffer = reinterpret_cast<char*>(&this->header_) + sizeof(groupSizeEncoding)
    			+ (this->header_.get_blockLength() * group_id);
    		return *reinterpret_cast<data*>(buffer);
    	}
    
    	const data& get(std::size_t group_id) const noexcept
    	{
    		auto* buffer = reinterpret_cast<const char*>(&this->header_) + sizeof(groupSizeEncoding)
    			+ (this->header_.get_blockLength() * group_id);
    		return *reinterpret_cast<const data*>(buffer);
    	}
    
    	const auto get_blockLength() const noexcept
    	{
    		return header_.get_blockLength();
    	}
    
    	const auto get_numInGroup() const noexcept
    	{
    		return header_.get_numInGroup();
    	}
    
    };
    
    private:
    	#pragma pack(push, 1)
    	PartiesGrp PartiesGrp_{};
    	#pragma pack(pop)
    
    public:
    	static constexpr std::size_t PartiesGrp_size() noexcept
    	{
    		return sizeof(PartiesGrp::data);
    	}
    
    	static constexpr std::size_t PartiesGrp_id() noexcept
    	{ 
    		return 583; 
    	}
    	
    	static constexpr const char* PartiesGrp_name() noexcept
    	{ 
    		return "PartiesGrp"; 
    	}
    
    	std::size_t PartiesGrp_offset() const noexcept
    	{
    		return 0;
    	}
    
    	std::size_t PartiesGrp_data_length() const noexcept
    	{
    		auto& group = get_PartiesGrp();
    		return group.header_.get_blockLength() * group.header_.get_numInGroup();
    	}
    	
    	const PartiesGrp& get_PartiesGrp() const noexcept
    	{ 
    		const auto* buf = buffer() + PartiesGrp_offset();
    		return *reinterpret_cast<const PartiesGrp*>(buf);
    	}
    	
    	PartiesGrp& get_PartiesGrp() noexcept
    	{
    		auto* buf = buffer() + PartiesGrp_offset();
    		return *reinterpret_cast<PartiesGrp*>(buf);
    	}
    
    	PartiesGrp& append_PartiesGrp(std::uint16_t count) noexcept
    	{
    		auto* buf = buffer() + PartiesGrp_offset();
    		auto& group = *reinterpret_cast<PartiesGrp*>(buf);
    		group.header_.set_blockLength(sizeof(PartiesGrp::data));
    		group.header_.set_numInGroup(count);
    		return group;	
    	}
    public:
    
    class AllocsGrp
    {
    	friend NewOrderSingle;
        
        class data
        {
            
            private:
            	#pragma pack(push, 1)
            	char AllocAccount_[16]{};
            	#pragma pack(pop)
            
            public:
            	static constexpr std::size_t AllocAccount_size() noexcept
            	{
            		return 16;
            	}
            
            	static constexpr std::size_t AllocAccount_offset() noexcept
            	{
            		return 0;
            	}
            
            	static constexpr std::size_t AllocAccount_id() noexcept
            	{
            		return 79;
            	}
            
            	static constexpr const char *AllocAccount_name() noexcept
            	{
            		return "AllocAccount";
            	}
            
            	constexpr char *get_AllocAccount() noexcept
            	{
            		return AllocAccount_;
            	}
            
            	constexpr const char *get_AllocAccount() const noexcept
            	{
            		return AllocAccount_;
            	}
            
            	constexpr std::string_view get_AllocAccount_view() noexcept
            	{
            		return std::string_view(AllocAccount_, 16);
            	}
            
            	constexpr const std::string_view get_AllocAccount_view() const noexcept
            	{
            		return std::string_view(AllocAccount_, 16);
            	}
            
            	const std::string get_AllocAccount_string() const noexcept
            	{
            		auto length = 0ULL;
            		for (; length < 16 && *(AllocAccount_ + length) != '\0'; ++length);
            		return std::string(AllocAccount_, length);
            	}
            
            	constexpr auto &set_AllocAccount(const char *value) noexcept
            	{
            	#if defined(__GNUG__)
            	#pragma GCC diagnostic push
            	#pragma GCC diagnostic ignored "-Wstringop-overflow"
            	#endif
            		std::memcpy(AllocAccount_, value, AllocAccount_size());
            		return *this;
            	#if defined(__GNUG__)
            	#pragma GCC diagnostic pop
            	#endif
            	}
            
            	auto &set_AllocAccount(std::string_view value) noexcept
            	{
            	#if defined(__GNUG__)
            	#pragma GCC diagnostic push
            	#pragma GCC diagnostic ignored "-Wstringop-overflow"
            	#endif
            		// auto size = std::min(AllocAccount_size(), value.size());
            		std::memcpy(AllocAccount_, value.data(), AllocAccount_size());
            		return *this;
            	#if defined(__GNUG__)
            	#pragma GCC diagnostic pop
            	#endif
            	}
            
            private:
            	#pragma pack(push, 1)
            	qtyEncoding AllocShares_{};
            	#pragma pack(pop)
            
            public:
            	static constexpr std::size_t AllocShares_size() noexcept
            	{
            		return sizeof(qtyEncoding);
            	}
            
            	static constexpr std::size_t AllocShares_offset() noexcept
            	{ 
            		return AllocAccount_offset() + AllocAccount_size(); 
            	}
            
            	static constexpr std::size_t AllocShares_id() noexcept
            	{ 
            		return 80; 
            	}
            	
            	static constexpr const char* AllocShares_name() noexcept
            	{ 
            		return "AllocShares"; 
            	}
            	
            	constexpr const qtyEncoding& get_AllocShares() const noexcept
            	{ 
            		return AllocShares_;
            	}
            	
            	constexpr qtyEncoding& get_AllocShares() noexcept
            	{
            		return AllocShares_;
            
            	}
            	constexpr auto& set_AllocShares(qtyEncoding& value) noexcept
            	{
            		AllocShares_ = value;
            		return *this;
            	}
            
    };
    
    private:
    #pragma pack(push, 1)
    	groupSizeEncoding header_{};
    #pragma pack(pop)
    
    public:
    	AllocsGrp() = default;
    	AllocsGrp(std::uint16_t count)
    		:header_(sizeof(AllocsGrp::data), count) {}
    
    	data& get(std::size_t group_id) noexcept
    	{
    		auto* buffer = reinterpret_cast<char*>(&this->header_) + sizeof(groupSizeEncoding)
    			+ (this->header_.get_blockLength() * group_id);
    		return *reinterpret_cast<data*>(buffer);
    	}
    
    	const data& get(std::size_t group_id) const noexcept
    	{
    		auto* buffer = reinterpret_cast<const char*>(&this->header_) + sizeof(groupSizeEncoding)
    			+ (this->header_.get_blockLength() * group_id);
    		return *reinterpret_cast<const data*>(buffer);
    	}
    
    	const auto get_blockLength() const noexcept
    	{
    		return header_.get_blockLength();
    	}
    
    	const auto get_numInGroup() const noexcept
    	{
    		return header_.get_numInGroup();
    	}
    
    };
    
    private:
    	#pragma pack(push, 1)
    	AllocsGrp AllocsGrp_{};
    	#pragma pack(pop)
    
    public:
    	static constexpr std::size_t AllocsGrp_size() noexcept
    	{
    		return sizeof(AllocsGrp::data);
    	}
    
    	static constexpr std::size_t AllocsGrp_id() noexcept
    	{ 
    		return 78; 
    	}
    	
    	static constexpr const char* AllocsGrp_name() noexcept
    	{ 
    		return "AllocsGrp"; 
    	}
    
    	std::size_t AllocsGrp_offset() const noexcept
    	{
    		return PartiesGrp_offset() + sizeof(PartiesGrp::header_) + PartiesGrp_data_length();
    	}
    
    	std::size_t AllocsGrp_data_length() const noexcept
    	{
    		auto& group = get_AllocsGrp();
    		return group.header_.get_blockLength() * group.header_.get_numInGroup();
    	}
    	
    	const AllocsGrp& get_AllocsGrp() const noexcept
    	{ 
    		const auto* buf = buffer() + AllocsGrp_offset();
    		return *reinterpret_cast<const AllocsGrp*>(buf);
    	}
    	
    	AllocsGrp& get_AllocsGrp() noexcept
    	{
    		auto* buf = buffer() + AllocsGrp_offset();
    		return *reinterpret_cast<AllocsGrp*>(buf);
    	}
    
    	AllocsGrp& append_AllocsGrp(std::uint16_t count) noexcept
    	{
    		auto* buf = buffer() + AllocsGrp_offset();
    		auto& group = *reinterpret_cast<AllocsGrp*>(buf);
    		group.header_.set_blockLength(sizeof(AllocsGrp::data));
    		group.header_.set_numInGroup(count);
    		return group;	
    	}
    public:
    
    class TradingSessionsGrp
    {
    	friend NewOrderSingle;
        
        class data
        {
            
            private:
            	#pragma pack(push, 1)
            	char TradingSessionID_[8]{};
            	#pragma pack(pop)
            
            public:
            	static constexpr std::size_t TradingSessionID_size() noexcept
            	{
            		return 8;
            	}
            
            	static constexpr std::size_t TradingSessionID_offset() noexcept
            	{
            		return 0;
            	}
            
            	static constexpr std::size_t TradingSessionID_id() noexcept
            	{
            		return 336;
            	}
            
            	static constexpr const char *TradingSessionID_name() noexcept
            	{
            		return "TradingSessionID";
            	}
            
            	constexpr char *get_TradingSessionID() noexcept
            	{
            		return TradingSessionID_;
            	}
            
            	constexpr const char *get_TradingSessionID() const noexcept
            	{
            		return TradingSessionID_;
            	}
            
            	constexpr std::string_view get_TradingSessionID_view() noexcept
            	{
            		return std::string_view(TradingSessionID_, 8);
            	}
            
            	constexpr const std::string_view get_TradingSessionID_view() const noexcept
            	{
            		return std::string_view(TradingSessionID_, 8);
            	}
            
            	const std::string get_TradingSessionID_string() const noexcept
            	{
            		auto length = 0ULL;
            		for (; length < 8 && *(TradingSessionID_ + length) != '\0'; ++length);
            		return std::string(TradingSessionID_, length);
            	}
            
            	constexpr auto &set_TradingSessionID(const char *value) noexcept
            	{
            	#if defined(__GNUG__)
            	#pragma GCC diagnostic push
            	#pragma GCC diagnostic ignored "-Wstringop-overflow"
            	#endif
            		std::memcpy(TradingSessionID_, value, TradingSessionID_size());
            		return *this;
            	#if defined(__GNUG__)
            	#pragma GCC diagnostic pop
            	#endif
            	}
            
            	auto &set_TradingSessionID(std::string_view value) noexcept
            	{
            	#if defined(__GNUG__)
            	#pragma GCC diagnostic push
            	#pragma GCC diagnostic ignored "-Wstringop-overflow"
            	#endif
            		// auto size = std::min(TradingSessionID_size(), value.size());
            		std::memcpy(TradingSessionID_, value.data(), TradingSessionID_size());
            		return *this;
            	#if defined(__GNUG__)
            	#pragma GCC diagnostic pop
            	#endif
            	}
    };
    
    private:
    #pragma pack(push, 1)
    	groupSizeEncoding header_{};
    #pragma pack(pop)
    
    public:
    	TradingSessionsGrp() = default;
    	TradingSessionsGrp(std::uint16_t count)
    		:header_(sizeof(TradingSessionsGrp::data), count) {}
    
    	data& get(std::size_t group_id) noexcept
    	{
    		auto* buffer = reinterpret_cast<char*>(&this->header_) + sizeof(groupSizeEncoding)
    			+ (this->header_.get_blockLength() * group_id);
    		return *reinterpret_cast<data*>(buffer);
    	}
    
    	const data& get(std::size_t group_id) const noexcept
    	{
    		auto* buffer = reinterpret_cast<const char*>(&this->header_) + sizeof(groupSizeEncoding)
    			+ (this->header_.get_blockLength() * group_id);
    		return *reinterpret_cast<const data*>(buffer);
    	}
    
    	const auto get_blockLength() const noexcept
    	{
    		return header_.get_blockLength();
    	}
    
    	const auto get_numInGroup() const noexcept
    	{
    		return header_.get_numInGroup();
    	}
    
    };
    
    private:
    	#pragma pack(push, 1)
    	TradingSessionsGrp TradingSessionsGrp_{};
    	#pragma pack(pop)
    
    public:
    	static constexpr std::size_t TradingSessionsGrp_size() noexcept
    	{
    		return sizeof(TradingSessionsGrp::data);
    	}
    
    	static constexpr std::size_t TradingSessionsGrp_id() noexcept
    	{ 
    		return 386; 
    	}
    	
    	static constexpr const char* TradingSessionsGrp_name() noexcept
    	{ 
    		return "TradingSessionsGrp"; 
    	}
    
    	std::size_t TradingSessionsGrp_offset() const noexcept
    	{
    		return AllocsGrp_offset() + sizeof(AllocsGrp::header_) + AllocsGrp_data_length();
    	}
    
    	std::size_t TradingSessionsGrp_data_length() const noexcept
    	{
    		auto& group = get_TradingSessionsGrp();
    		return group.header_.get_blockLength() * group.header_.get_numInGroup();
    	}
    	
    	const TradingSessionsGrp& get_TradingSessionsGrp() const noexcept
    	{ 
    		const auto* buf = buffer() + TradingSessionsGrp_offset();
    		return *reinterpret_cast<const TradingSessionsGrp*>(buf);
    	}
    	
    	TradingSessionsGrp& get_TradingSessionsGrp() noexcept
    	{
    		auto* buf = buffer() + TradingSessionsGrp_offset();
    		return *reinterpret_cast<TradingSessionsGrp*>(buf);
    	}
    
    	TradingSessionsGrp& append_TradingSessionsGrp(std::uint16_t count) noexcept
    	{
    		auto* buf = buffer() + TradingSessionsGrp_offset();
    		auto& group = *reinterpret_cast<TradingSessionsGrp*>(buf);
    		group.header_.set_blockLength(sizeof(TradingSessionsGrp::data));
    		group.header_.set_numInGroup(count);
    		return group;	
    	}
    public:
    
    class Text
    {
    	friend NewOrderSingle;
    
    private:
    #pragma pack(push, 1)
    	DATA header_{};
    #pragma pack(pop)
    
    public:
    	Text() = default;
    
    	std::basic_string_view<char> get_str() noexcept
    	{
    		auto* buffer = reinterpret_cast<char*>(&this->header_) + sizeof(DATA);
    		return {reinterpret_cast<char*>(buffer), this->header_.get_length()};
    	}
    
    	const std::basic_string_view<char> get_str() const noexcept
    	{
    		auto* buffer = reinterpret_cast<const char*>(&this->header_) + sizeof(DATA);
    		return {reinterpret_cast<const char*>(buffer), this->header_.get_length()};
    	}
    
    	char* get() noexcept
    	{
    		auto* buffer = reinterpret_cast<char*>(&this->header_) + sizeof(DATA);
    		return reinterpret_cast<char*>(buffer);
    	}
    
    	const char* get() const noexcept
    	{
    		auto* buffer = reinterpret_cast<const char*>(&this->header_) + sizeof(DATA);
    		return reinterpret_cast<const char*>(buffer);
    	}
    
    	const auto get_length() const noexcept
    	{
    		return header_.get_length();
    	}
    
    };
    
    private:
    	#pragma pack(push, 1)
    	Text Text_{};
    	#pragma pack(pop)
    
    public:
    	static constexpr std::size_t Text_size() noexcept
    	{
    		return 0;
    	}
    
    	static constexpr std::size_t Text_id() noexcept
    	{ 
    		return 58; 
    	}
    	
    	static constexpr const char* Text_name() noexcept
    	{ 
    		return "Text"; 
    	}
    
    	std::size_t Text_offset() const noexcept
    	{
    		return TradingSessionsGrp_offset() + sizeof(TradingSessionsGrp::header_) + TradingSessionsGrp_data_length();
    	}
    
    	std::size_t Text_data_length() const noexcept
    	{
    		auto& data = get_Text();
    		return data.header_.get_length();
    	}
    	
    	const Text& get_Text() const noexcept
    	{ 
    		const auto* buf = buffer() + Text_offset();
    		return *reinterpret_cast<const Text*>(buf);
    	}
    	
    	Text& get_Text() noexcept
    	{
    		auto* buf = buffer() + Text_offset();
    		return *reinterpret_cast<Text*>(buf);
    	}
    
    	Text& append_Text(const char* value, std::uint16_t length) noexcept
    	{
    		auto* buf = buffer() + Text_offset();
    		auto& data = *reinterpret_cast<Text*>(buf);
    		data.header_.set_length(length);
    		std::memcpy(data.get(), value, length);
    		return data;
    	}
    
    	Text& append_Text(std::basic_string_view<char> value) noexcept
    	{
    		auto* buf = buffer() + Text_offset();
    		auto& data = *reinterpret_cast<Text*>(buf);
    		data.header_.set_length(value.size());
    		std::memcpy(data.get(), value.data(), value.size());
    		return data;	
    	}
    public:
    
    class ClearingFirm
    {
    	friend NewOrderSingle;
    
    private:
    #pragma pack(push, 1)
    	DATA header_{};
    #pragma pack(pop)
    
    public:
    	ClearingFirm() = default;
    
    	std::basic_string_view<char> get_str() noexcept
    	{
    		auto* buffer = reinterpret_cast<char*>(&this->header_) + sizeof(DATA);
    		return {reinterpret_cast<char*>(buffer), this->header_.get_length()};
    	}
    
    	const std::basic_string_view<char> get_str() const noexcept
    	{
    		auto* buffer = reinterpret_cast<const char*>(&this->header_) + sizeof(DATA);
    		return {reinterpret_cast<const char*>(buffer), this->header_.get_length()};
    	}
    
    	char* get() noexcept
    	{
    		auto* buffer = reinterpret_cast<char*>(&this->header_) + sizeof(DATA);
    		return reinterpret_cast<char*>(buffer);
    	}
    
    	const char* get() const noexcept
    	{
    		auto* buffer = reinterpret_cast<const char*>(&this->header_) + sizeof(DATA);
    		return reinterpret_cast<const char*>(buffer);
    	}
    
    	const auto get_length() const noexcept
    	{
    		return header_.get_length();
    	}
    
    };
    
    private:
    	#pragma pack(push, 1)
    	ClearingFirm ClearingFirm_{};
    	#pragma pack(pop)
    
    public:
    	static constexpr std::size_t ClearingFirm_size() noexcept
    	{
    		return 0;
    	}
    
    	static constexpr std::size_t ClearingFirm_id() noexcept
    	{ 
    		return 439; 
    	}
    	
    	static constexpr const char* ClearingFirm_name() noexcept
    	{ 
    		return "ClearingFirm"; 
    	}
    
    	std::size_t ClearingFirm_offset() const noexcept
    	{
    		return Text_offset() + sizeof(Text::header_) + Text_data_length();
    	}
    
    	std::size_t ClearingFirm_data_length() const noexcept
    	{
    		auto& data = get_ClearingFirm();
    		return data.header_.get_length();
    	}
    	
    	const ClearingFirm& get_ClearingFirm() const noexcept
    	{ 
    		const auto* buf = buffer() + ClearingFirm_offset();
    		return *reinterpret_cast<const ClearingFirm*>(buf);
    	}
    	
    	ClearingFirm& get_ClearingFirm() noexcept
    	{
    		auto* buf = buffer() + ClearingFirm_offset();
    		return *reinterpret_cast<ClearingFirm*>(buf);
    	}
    
    	ClearingFirm& append_ClearingFirm(const char* value, std::uint16_t length) noexcept
    	{
    		auto* buf = buffer() + ClearingFirm_offset();
    		auto& data = *reinterpret_cast<ClearingFirm*>(buf);
    		data.header_.set_length(length);
    		std::memcpy(data.get(), value, length);
    		return data;
    	}
    
    	ClearingFirm& append_ClearingFirm(std::basic_string_view<char> value) noexcept
    	{
    		auto* buf = buffer() + ClearingFirm_offset();
    		auto& data = *reinterpret_cast<ClearingFirm*>(buf);
    		data.header_.set_length(value.size());
    		std::memcpy(data.get(), value.data(), value.size());
    		return data;	
    	}
};
}

template <class CharT, class Traits = std::char_traits<CharT>>
inline std::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT, Traits>& os
    , const fastsbe::NewOrderSingle::PartiesGrp& group)
{
	for (auto i = 0; i < group.get_numInGroup(); i++)
	{
		auto& g = group.get(i);

		os << g.PartyID_name() << ": " << g.get_PartyID() << " ";
		os << g.PartyIDSource_name() << ": " << g.get_PartyIDSource() << " ";
		os << g.PartyRole_name() << ": " << g.get_PartyRole() << " ";
	}
	return os;
};

template <class CharT, class Traits = std::char_traits<CharT>>
inline std::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT, Traits>& os
    , const fastsbe::NewOrderSingle::AllocsGrp& group)
{
	for (auto i = 0; i < group.get_numInGroup(); i++)
	{
		auto& g = group.get(i);

		os << g.AllocAccount_name() << ": " << g.get_AllocAccount() << " ";
		os << g.AllocShares_name() << ": " << g.get_AllocShares() << " ";
	}
	return os;
};

template <class CharT, class Traits = std::char_traits<CharT>>
inline std::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT, Traits>& os
    , const fastsbe::NewOrderSingle::TradingSessionsGrp& group)
{
	for (auto i = 0; i < group.get_numInGroup(); i++)
	{
		auto& g = group.get(i);

		os << g.TradingSessionID_name() << ": " << g.get_TradingSessionID() << " ";
	}
	return os;
};

template <class CharT, class Traits = std::char_traits<CharT>>
inline std::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT, Traits>& os
    , const fastsbe::NewOrderSingle& msg)
{
	os << msg.ClOrdId_name() << ": " << msg.get_ClOrdId() << " ";
	os << msg.Account_name() << ": " << msg.get_Account() << " ";
	os << msg.Symbol_name() << ": " << msg.get_Symbol() << " ";
	os << msg.Side_name() << ": " << msg.get_Side() << " ";
	os << msg.TransactTime_name() << ": " << msg.get_TransactTime() << " ";
	os << msg.OrderQty_name() << ": " << msg.get_OrderQty() << " ";
	os << msg.OrdType_name() << ": " << msg.get_OrdType() << " ";
	os << msg.Price_name() << ": " << msg.get_Price() << " ";
	os << msg.StopPx_name() << ": " << msg.get_StopPx() << " ";
	os << msg.PartiesGrp_name() << ": " << msg.get_PartiesGrp() << " ";
	os << msg.AllocsGrp_name() << ": " << msg.get_AllocsGrp() << " ";
	os << msg.TradingSessionsGrp_name() << ": " << msg.get_TradingSessionsGrp() << " ";
	os << msg.Text_name() << ": " << msg.get_Text().get_str() << " ";
	os << msg.ClearingFirm_name() << ": " << msg.get_ClearingFirm().get_str() << " ";
	return os;
};

