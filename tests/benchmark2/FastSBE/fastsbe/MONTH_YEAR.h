#pragma once
#include<cstdint>
#include<string>
#include<string_view>
#include<ostream>

namespace fastsbe
{

class MONTH_YEAR
{
    
    public:
    	static constexpr const char* name() noexcept
    	{ 
    		return "MONTH_YEAR"; 
    	}
    
    	static constexpr std::size_t template_id() noexcept
    	{ 
    		return 0; 
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
    	std::uint16_t year_{};
    	#pragma pack(pop)
    
    public:
    	static constexpr std::size_t year_size() noexcept
    	{
    		return sizeof(std::uint16_t);
    	}
    
    	static constexpr std::size_t year_offset() noexcept
    	{ 
    		return 0; 
    	}
    	
    	static constexpr const char* year_name() noexcept
    	{ 
    		return "year"; 
    	}
    	
    	static constexpr std::uint16_t year_min_value() noexcept
    	{ 
    		return 0; 
    	}
    	
    	static constexpr std::uint16_t year_max_value() noexcept
    	{
    		return 65534;
    	}
    	
    	static constexpr std::uint16_t year_null_value() noexcept
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
    
    	constexpr std::uint16_t get_year() const noexcept
    	{ 
    		return year_;
    	}
    	
    	constexpr MONTH_YEAR& set_year(std::uint16_t value) noexcept
    	{
    		year_ = value;
    		return *this;
    	}
    
    
    private:
    	#pragma pack(push, 1)
    	std::uint8_t month_{};
    	#pragma pack(pop)
    
    public:
    	static constexpr std::size_t month_size() noexcept
    	{
    		return sizeof(std::uint8_t);
    	}
    
    	static constexpr std::size_t month_offset() noexcept
    	{ 
    		return year_offset() + year_size(); 
    	}
    	
    	static constexpr const char* month_name() noexcept
    	{ 
    		return "month"; 
    	}
    	
    	static constexpr std::uint8_t month_min_value() noexcept
    	{ 
    		return 0; 
    	}
    	
    	static constexpr std::uint8_t month_max_value() noexcept
    	{
    		return 254;
    	}
    	
    	static constexpr std::uint8_t month_null_value() noexcept
    	{
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic push
    	#pragma GCC diagnostic ignored "-Wtype-limits"
    	#endif
    		return 255;
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic pop
    	#endif
    	}
    
    	constexpr std::uint8_t get_month() const noexcept
    	{ 
    		return month_;
    	}
    	
    	constexpr MONTH_YEAR& set_month(std::uint8_t value) noexcept
    	{
    		month_ = value;
    		return *this;
    	}
    
    
    private:
    	#pragma pack(push, 1)
    	std::uint8_t day_{};
    	#pragma pack(pop)
    
    public:
    	static constexpr std::size_t day_size() noexcept
    	{
    		return sizeof(std::uint8_t);
    	}
    
    	static constexpr std::size_t day_offset() noexcept
    	{ 
    		return month_offset() + month_size(); 
    	}
    	
    	static constexpr const char* day_name() noexcept
    	{ 
    		return "day"; 
    	}
    	
    	static constexpr std::uint8_t day_min_value() noexcept
    	{ 
    		return 0; 
    	}
    	
    	static constexpr std::uint8_t day_max_value() noexcept
    	{
    		return 254;
    	}
    	
    	static constexpr std::uint8_t day_null_value() noexcept
    	{
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic push
    	#pragma GCC diagnostic ignored "-Wtype-limits"
    	#endif
    		return 255;
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic pop
    	#endif
    	}
    
    	constexpr std::uint8_t get_day() const noexcept
    	{ 
    		return day_;
    	}
    	
    	constexpr MONTH_YEAR& set_day(std::uint8_t value) noexcept
    	{
    		day_ = value;
    		return *this;
    	}
    
    
    private:
    	#pragma pack(push, 1)
    	std::uint8_t week_{};
    	#pragma pack(pop)
    
    public:
    	static constexpr std::size_t week_size() noexcept
    	{
    		return sizeof(std::uint8_t);
    	}
    
    	static constexpr std::size_t week_offset() noexcept
    	{ 
    		return day_offset() + day_size(); 
    	}
    	
    	static constexpr const char* week_name() noexcept
    	{ 
    		return "week"; 
    	}
    	
    	static constexpr std::uint8_t week_min_value() noexcept
    	{ 
    		return 0; 
    	}
    	
    	static constexpr std::uint8_t week_max_value() noexcept
    	{
    		return 254;
    	}
    	
    	static constexpr std::uint8_t week_null_value() noexcept
    	{
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic push
    	#pragma GCC diagnostic ignored "-Wtype-limits"
    	#endif
    		return 255;
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic pop
    	#endif
    	}
    
    	constexpr std::uint8_t get_week() const noexcept
    	{ 
    		return week_;
    	}
    	
    	constexpr MONTH_YEAR& set_week(std::uint8_t value) noexcept
    	{
    		week_ = value;
    		return *this;
    	}
    
    
    public:
    	MONTH_YEAR() = default;
    
    	/*constexpr */
    	MONTH_YEAR(std::uint16_t year, std::uint8_t month, std::uint8_t day, std::uint8_t week) noexcept
    		:year_(year), month_(month), day_(day), week_(week)
    	{
    		
    	}
    
};
}

template <class CharT, class Traits = std::char_traits<CharT>>
inline std::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT, Traits>& os
    , const fastsbe::MONTH_YEAR& msg)
{
	os << msg.year_name() << ": " << msg.get_year() << " ";
	os << msg.month_name() << ": " << msg.get_month() << " ";
	os << msg.day_name() << ": " << msg.get_day() << " ";
	os << msg.week_name() << ": " << msg.get_week() << " ";
	return os;
};

