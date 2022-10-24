#pragma once
#include<cstdint>
#include<string>
#include<string_view>
#include<ostream>

namespace fastsbe
{

class optionalDecimalEncoding
{
    
    public:
    	static constexpr const char* name() noexcept
    	{ 
    		return "optionalDecimalEncoding"; 
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
    	std::int64_t mantissa_{};
    	#pragma pack(pop)
    
    public:
    	static constexpr std::size_t mantissa_size() noexcept
    	{
    		return sizeof(std::int64_t);
    	}
    
    	static constexpr std::size_t mantissa_offset() noexcept
    	{ 
    		return 0; 
    	}
    	
    	static constexpr const char* mantissa_name() noexcept
    	{ 
    		return "mantissa"; 
    	}
    	
    	static constexpr std::int64_t mantissa_min_value() noexcept
    	{ 
    		return -9223372036854775807; 
    	}
    	
    	static constexpr std::int64_t mantissa_max_value() noexcept
    	{
    		return 9223372036854775807;
    	}
    	
    	static constexpr std::int64_t mantissa_null_value() noexcept
    	{
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic push
    	#pragma GCC diagnostic ignored "-Wtype-limits"
    	#endif
    		return -9223372036854775808;
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic pop
    	#endif
    	}
    
    	constexpr std::int64_t get_mantissa() const noexcept
    	{ 
    		return mantissa_;
    	}
    	
    	constexpr optionalDecimalEncoding& set_mantissa(std::int64_t value) noexcept
    	{
    		mantissa_ = value;
    		return *this;
    	}
    
    
    public:
    	static constexpr std::size_t exponent_size() noexcept
    	{
    		return 0;
    	}
    
    	static constexpr std::size_t exponent_offset() noexcept
    	{ 
    		return mantissa_offset() + mantissa_size(); 
    	}
    	
    	static constexpr const char* exponent_name() noexcept
    	{ 
    		return "exponent"; 
    	}
    
    	constexpr std::int8_t get_exponent() noexcept
    	{ 
    		return -3;
    	}
    
    	constexpr std::int8_t get_exponent() const noexcept
    	{ 
    		return -3;
    	}
    
    
    public:
    	optionalDecimalEncoding() = default;
    
    	/*constexpr */
    	optionalDecimalEncoding(std::int64_t mantissa) noexcept
    		:mantissa_(mantissa)
    	{
    		
    	}
    
};
}

template <class CharT, class Traits = std::char_traits<CharT>>
inline std::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT, Traits>& os
    , const fastsbe::optionalDecimalEncoding& msg)
{
	os << msg.mantissa_name() << ": " << msg.get_mantissa() << " ";
	os << msg.exponent_name() << ": " << msg.get_exponent() << " ";
	return os;
};

