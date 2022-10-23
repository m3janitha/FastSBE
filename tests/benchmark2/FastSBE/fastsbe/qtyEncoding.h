#pragma once
#include<cstdint>
#include<string>
#include<string_view>
#include<ostream>

namespace fastsbe
{

class qtyEncoding
{
    
    public:
    	static constexpr const char* name() noexcept
    	{ 
    		return "qtyEncoding"; 
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
    	std::int32_t mantissa_{};
    	#pragma pack(pop)
    
    public:
    	static constexpr std::size_t mantissa_size() noexcept
    	{
    		return sizeof(std::int32_t);
    	}
    
    	static constexpr std::size_t mantissa_offset() noexcept
    	{ 
    		return 0; 
    	}
    	
    	static constexpr const char* mantissa_name() noexcept
    	{ 
    		return "mantissa"; 
    	}
    	
    	static constexpr std::int32_t mantissa_min_value() noexcept
    	{ 
    		return -2147483647; 
    	}
    	
    	static constexpr std::int32_t mantissa_max_value() noexcept
    	{
    		return 2147483647;
    	}
    	
    	static constexpr std::int32_t mantissa_null_value() noexcept
    	{
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic push
    	#pragma GCC diagnostic ignored "-Wtype-limits"
    	#endif
    		return -2147483648;
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic pop
    	#endif
    	}
    
    	constexpr std::int32_t get_mantissa() const noexcept
    	{ 
    		return mantissa_;
    	}
    	
    	constexpr qtyEncoding& set_mantissa(std::int32_t value) noexcept
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
    		return 0;
    	}
    
    	constexpr std::int8_t get_exponent() const noexcept
    	{ 
    		return 0;
    	}
    
    
    public:
    	qtyEncoding() = default;
    
    	/*constexpr */
    	qtyEncoding(std::int32_t mantissa) noexcept
    		:mantissa_(mantissa)
    	{
    		
    	}
    
};
}

template <class CharT, class Traits = std::char_traits<CharT>>
inline std::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT, Traits>& os
    , const fastsbe::qtyEncoding& msg)
{
	os << msg.mantissa_name() << ": " << msg.get_mantissa() << " ";
	os << msg.exponent_name() << ": " << msg.get_exponent() << " ";
	return os;
};

