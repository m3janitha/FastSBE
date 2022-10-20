#pragma once
#include<cstdint>
#include<string>
#include<string_view>
#include<ostream>
#include<TimeInForce.h>
#include<PartyDetails.h>

namespace test::sbe
{

class NewOrder
{
    
    public:
    	static constexpr const char* name() noexcept
    	{ 
    		return "NewOrder"; 
    	}
    
    	static constexpr std::size_t template_id() noexcept
    	{ 
    		return 1; 
    	}
    
    	static constexpr std::size_t schema() noexcept
    	{  
    		return 4; 
    	}
    
    	static constexpr std::size_t version() noexcept
    	{ 
    		return 2; 
    	}
    
    	static constexpr const char* semantic_type() noexcept
    	{ 
    		return ""; 	
    	}
    
    
    private:
    	#pragma pack(push, 1)
    	std::uint32_t clodr_id_{};
    	#pragma pack(pop)
    
    public:
    	static constexpr std::size_t clodr_id_size() noexcept
    	{
    		return sizeof(std::uint32_t);
    	}
    
    	static constexpr std::size_t clodr_id_offset() noexcept
    	{ 
    		return 0; 
    	}
    
    	static constexpr std::size_t clodr_id_id() noexcept
    	{ 
    		return 1; 
    	}
    	
    	static constexpr const char* clodr_id_name() noexcept
    	{ 
    		return "clodr_id"; 
    	}
    	
    	static constexpr std::uint32_t clodr_id_min_value() noexcept
    	{ 
    		return 0; 
    	}
    	
    	static constexpr std::uint32_t clodr_id_max_value() noexcept
    	{
    		return 4294967294;
    	}
    	
    	static constexpr std::uint32_t clodr_id_null_value() noexcept
    	{ 
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic push
    	#pragma GCC diagnostic ignored "-Wtype-limits"
    	#endif
    		return 4294967295;
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic pop
    	#endif
    	}
    
    	constexpr std::uint32_t get_clodr_id() const noexcept
    	{ 
    		return clodr_id_;
    	}
    	
    	constexpr auto& set_clodr_id(std::uint32_t value) noexcept
    	{
    		clodr_id_ = value;
    		return *this;
    	}
    
    
    private:
    	#pragma pack(push, 1)
    	std::uint16_t price_{};
    	#pragma pack(pop)
    
    public:
    	static constexpr std::size_t price_size() noexcept
    	{
    		return sizeof(std::uint16_t);
    	}
    
    	static constexpr std::size_t price_offset() noexcept
    	{ 
    		return clodr_id_offset() + clodr_id_size(); 
    	}
    
    	static constexpr std::size_t price_id() noexcept
    	{ 
    		return 2; 
    	}
    	
    	static constexpr const char* price_name() noexcept
    	{ 
    		return "price"; 
    	}
    	
    	static constexpr std::uint16_t price_min_value() noexcept
    	{ 
    		return 0; 
    	}
    	
    	static constexpr std::uint16_t price_max_value() noexcept
    	{
    		return 65534;
    	}
    	
    	static constexpr std::uint16_t price_null_value() noexcept
    	{ 
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic push
    	#pragma GCC diagnostic ignored "-Wtype-limits"
    	#endif
    		return 65535;
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic pop
    	#endif
    	}
    
    	constexpr std::uint16_t get_price() const noexcept
    	{ 
    		return price_;
    	}
    	
    	constexpr auto& set_price(std::uint16_t value) noexcept
    	{
    		price_ = value;
    		return *this;
    	}
    
    
    public:
    	static constexpr std::size_t trader_size() noexcept
    	{
    		return 0;
    	}
    
    	static constexpr std::size_t trader_offset() noexcept
    	{ 
    		return price_offset() + price_size(); 
    	}
    
    	static constexpr std::size_t trader_id() noexcept
    	{ 
    		return 3; 
    	}
    	
    	static constexpr const char* trader_name() noexcept
    	{ 
    		return "trader"; 
    	}
    
    	constexpr std::uint64_t get_trader() const noexcept
    	{ 
    		return None;
    	}
    
    
    private:
    	#pragma pack(push, 1)
    	std::uint64_t quantity_{};
    	#pragma pack(pop)
    
    public:
    	static constexpr std::size_t quantity_size() noexcept
    	{
    		return sizeof(std::uint64_t);
    	}
    
    	static constexpr std::size_t quantity_offset() noexcept
    	{ 
    		return trader_offset() + trader_size(); 
    	}
    
    	static constexpr std::size_t quantity_id() noexcept
    	{ 
    		return 4; 
    	}
    	
    	static constexpr const char* quantity_name() noexcept
    	{ 
    		return "quantity"; 
    	}
    	
    	static constexpr std::uint64_t quantity_min_value() noexcept
    	{ 
    		return 0; 
    	}
    	
    	static constexpr std::uint64_t quantity_max_value() noexcept
    	{
    		return 18446744073709551614;
    	}
    	
    	static constexpr std::uint64_t quantity_null_value() noexcept
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
    
    	constexpr std::uint64_t get_quantity() const noexcept
    	{ 
    		return quantity_;
    	}
    	
    	constexpr auto& set_quantity(std::uint64_t value) noexcept
    	{
    		quantity_ = value;
    		return *this;
    	}
    
    
    private:
    	#pragma pack(push, 1)
    	char text_[6]{};
    	#pragma pack(pop)
    
    public:
    	static constexpr std::size_t text_size() noexcept
    	{
    		return 6;
    	}
    
    	static constexpr std::size_t text_offset() noexcept
    	{ 
    		return quantity_offset() + quantity_size(); 
    	}
    
    	static constexpr std::size_t text_id() noexcept
    	{ 
    		return 5; 
    	}
    	
    	static constexpr const char* text_name() noexcept
    	{ 
    		return "text"; 
    	}
    
    	constexpr char* get_text() noexcept
    	{ 
    		return text_;
    	}
    
    	constexpr const char* get_text() const noexcept
    	{ 
    		return text_;
    	}
    
    	constexpr std::string_view get_text_str() noexcept
    	{ 
    		return std::string_view(text_, 6);
    	}
    
    	constexpr const std::string_view get_text_str() const noexcept
    	{ 
    		return std::string_view(text_, 6);
    	}
    
    	constexpr auto& set_text(const char* value) noexcept
    	{
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic push
    	#pragma GCC diagnostic ignored "-Wstringop-overflow"
    	#endif
    		std::memcpy(text_, value, text_size());
    		return *this;
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic pop
    	#endif	
    	}
    
    	auto& set_text(std::string_view value) noexcept
    	{
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic push
    	#pragma GCC diagnostic ignored "-Wstringop-overflow"
    	#endif
    		//auto size = std::min(text_size(), value.size());
    		std::memcpy(text_, value.data(), text_size());
    		return *this;
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic pop
    	#endif	
    	}
    
    
    private:
    	#pragma pack(push, 1)
    	TimeInForce::Value time_in_force_{};
    	#pragma pack(pop)
    
    public:
    	static constexpr std::size_t time_in_force_size() noexcept
    	{
    		return sizeof(TimeInForce);
    	}
    
    	static constexpr std::size_t time_in_force_offset() noexcept
    	{ 
    		return text_offset() + text_size(); 
    	}
    	
    	static constexpr const char* time_in_force_name() noexcept
    	{ 
    		return "time_in_force"; 
    	}
    
    	static constexpr TimeInForce::Value time_in_force_null_value() noexcept
    	{
    		return TimeInForce::Value::Null;
    	}
    
    	constexpr TimeInForce::Value get_time_in_force() const noexcept
    	{ 
    		return time_in_force_;
    	}
    	
    	constexpr auto& set_time_in_force(TimeInForce::Value value) noexcept
    	{
    		time_in_force_ = value;
    		return *this;
    	}
    
    
    private:
    	#pragma pack(push, 1)
    	PartyDetails party_details_{};
    	#pragma pack(pop)
    
    public:
    	static constexpr std::size_t party_details_size() noexcept
    	{
    		return sizeof(PartyDetails);
    	}
    
    	static constexpr std::size_t party_details_offset() noexcept
    	{ 
    		return time_in_force_offset() + time_in_force_size(); 
    	}
    
    	static constexpr std::size_t party_details_id() noexcept
    	{ 
    		return 7; 
    	}
    	
    	static constexpr const char* party_details_name() noexcept
    	{ 
    		return "party_details"; 
    	}
    	
    	constexpr const PartyDetails& get_party_details() const noexcept
    	{ 
    		return party_details_;
    	}
    	
    	constexpr PartyDetails& get_party_details() noexcept
    	{
    		return party_details_;
    
    	}
    	constexpr auto& set_party_details(PartyDetails& value) noexcept
    	{
    		party_details_ = value;
    		return *this;
    	}
    
};
}

template <class CharT, class Traits = std::char_traits<CharT>>
inline std::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT, Traits>& os
    , const test::sbe::NewOrder& msg)
{
	os << msg.clodr_id_name() << ": " << msg.get_clodr_id() << " ";
	os << msg.price_name() << ": " << msg.get_price() << " ";
	os << msg.trader_name() << ": " << msg.get_trader() << " ";
	os << msg.quantity_name() << ": " << msg.get_quantity() << " ";
	os << msg.text_name() << ": " << msg.get_text() << " ";
	os << msg.time_in_force_name() << ": " << msg.get_time_in_force() << " ";
	os << msg.party_details_name() << ": " << msg.get_party_details() << " ";
	return os;
};

