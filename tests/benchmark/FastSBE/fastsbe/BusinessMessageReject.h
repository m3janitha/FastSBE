#pragma once
#include<cstdint>
#include<string>
#include<string_view>
#include<ostream>
#include<cstring>
#include<businessRejectReasonEnum.h>
#include<DATA.h>

namespace fastsbe
{

class BusinessMessageReject
{
    
    public:
    	static constexpr const char* name() noexcept
    	{ 
    		return "BusinessMessageReject"; 
    	}
    
    	static constexpr std::size_t template_id() noexcept
    	{ 
    		return 97; 
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
    	char BusinesRejectRefId_[8]{};
    	#pragma pack(pop)
    
    public:
    	static constexpr std::size_t BusinesRejectRefId_size() noexcept
    	{
    		return 8;
    	}
    
    	static constexpr std::size_t BusinesRejectRefId_offset() noexcept
    	{
    		return 0;
    	}
    
    	static constexpr std::size_t BusinesRejectRefId_id() noexcept
    	{
    		return 379;
    	}
    
    	static constexpr const char *BusinesRejectRefId_name() noexcept
    	{
    		return "BusinesRejectRefId";
    	}
    
    	constexpr char *get_BusinesRejectRefId() noexcept
    	{
    		return BusinesRejectRefId_;
    	}
    
    	constexpr const char *get_BusinesRejectRefId() const noexcept
    	{
    		return BusinesRejectRefId_;
    	}
    
    	constexpr std::string_view get_BusinesRejectRefId_view() noexcept
    	{
    		return std::string_view(BusinesRejectRefId_, 8);
    	}
    
    	constexpr const std::string_view get_BusinesRejectRefId_view() const noexcept
    	{
    		return std::string_view(BusinesRejectRefId_, 8);
    	}
    
    	const std::string get_BusinesRejectRefId_string() const noexcept
    	{
    		auto length = 0ULL;
    		for (; length < 8 && *(BusinesRejectRefId_ + length) != '\0'; ++length);
    		return std::string(BusinesRejectRefId_, length);
    	}
    
    	constexpr auto &set_BusinesRejectRefId(const char *value) noexcept
    	{
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic push
    	#pragma GCC diagnostic ignored "-Wstringop-overflow"
    	#endif
    		std::memcpy(BusinesRejectRefId_, value, BusinesRejectRefId_size());
    		return *this;
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic pop
    	#endif
    	}
    
    	auto &set_BusinesRejectRefId(std::string_view value) noexcept
    	{
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic push
    	#pragma GCC diagnostic ignored "-Wstringop-overflow"
    	#endif
    		// auto size = std::min(BusinesRejectRefId_size(), value.size());
    		std::memcpy(BusinesRejectRefId_, value.data(), BusinesRejectRefId_size());
    		return *this;
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic pop
    	#endif
    	}
    
    private:
    	#pragma pack(push, 1)
    	businessRejectReasonEnum::Value BusinessRejectReason_{};
    	#pragma pack(pop)
    
    public:
    	static constexpr std::size_t BusinessRejectReason_size() noexcept
    	{
    		return sizeof(businessRejectReasonEnum);
    	}
    
    	static constexpr std::size_t BusinessRejectReason_offset() noexcept
    	{ 
    		return BusinesRejectRefId_offset() + BusinesRejectRefId_size(); 
    	}
    	
    	static constexpr const char* BusinessRejectReason_name() noexcept
    	{ 
    		return "BusinessRejectReason"; 
    	}
    
    	static constexpr businessRejectReasonEnum::Value BusinessRejectReason_null_value() noexcept
    	{
    		return businessRejectReasonEnum::Value::Null;
    	}
    
    	constexpr businessRejectReasonEnum::Value get_BusinessRejectReason() const noexcept
    	{ 
    		return BusinessRejectReason_;
    	}
    	
    	constexpr auto& set_BusinessRejectReason(businessRejectReasonEnum::Value value) noexcept
    	{
    		BusinessRejectReason_ = value;
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
    
    class Text
    {
    	friend BusinessMessageReject;
    
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
    		return 0;
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
};
}

template <class CharT, class Traits = std::char_traits<CharT>>
inline std::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT, Traits>& os
    , const fastsbe::BusinessMessageReject& msg)
{
	os << msg.BusinesRejectRefId_name() << ": " << msg.get_BusinesRejectRefId() << " ";
	os << msg.BusinessRejectReason_name() << ": " << msg.get_BusinessRejectReason() << " ";
	os << msg.Text_name() << ": " << msg.get_Text().get_str() << " ";
	return os;
};

