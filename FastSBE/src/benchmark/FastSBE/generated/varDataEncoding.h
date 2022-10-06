#pragma once
#include<cstdint>
#include<string>
#include<string_view>
#include<ostream>

namespace test::sbe
{

class varDataEncoding
{
    
    public:
    	static constexpr const char* name() noexcept
    	{ 
    		return "varDataEncoding"; 
    	}
    
    	static constexpr std::size_t template_id() noexcept
    	{ 
    		return 0; 
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
    	std::uint32_t length_{};
    	#pragma pack(pop)
    
    public:
    	static constexpr std::size_t length_size() noexcept
    	{
    		return sizeof(std::uint32_t);
    	}
    
    	static constexpr std::size_t length_offset() noexcept
    	{ 
    		return 0; 
    	}
    	
    	static constexpr const char* length_name() noexcept
    	{ 
    		return "length"; 
    	}
    	
    	static constexpr std::uint32_t length_min_value() noexcept
    	{ 
    		return -1; 
    	}
    	
    	static constexpr std::uint32_t length_max_value() noexcept
    	{ 
    		return 100; 
    	}
    	
    	static constexpr std::uint32_t length_null_value() noexcept
    	{ 
    		return 100; 
    	}
    
    	constexpr std::uint32_t get_length() const noexcept
    	{ 
    		return length_;
    	}
    	
    	constexpr varDataEncoding& set_length(std::uint32_t value) noexcept
    	{
    		length_ = value;
    		return *this;
    	}
    
    
    private:
    	#pragma pack(push, 1)
    	std::uint8_t varData_{};
    	#pragma pack(pop)
    
    public:
    	static constexpr std::size_t varData_size() noexcept
    	{
    		return sizeof(std::uint8_t);
    	}
    
    	static constexpr std::size_t varData_offset() noexcept
    	{ 
    		return length_offset() + length_size(); 
    	}
    	
    	static constexpr const char* varData_name() noexcept
    	{ 
    		return "varData"; 
    	}
    	
    	static constexpr std::uint8_t varData_min_value() noexcept
    	{ 
    		return -1; 
    	}
    	
    	static constexpr std::uint8_t varData_max_value() noexcept
    	{ 
    		return 100; 
    	}
    	
    	static constexpr std::uint8_t varData_null_value() noexcept
    	{ 
    		return 100; 
    	}
    
    	constexpr std::uint8_t get_varData() const noexcept
    	{ 
    		return varData_;
    	}
    	
    	constexpr varDataEncoding& set_varData(std::uint8_t value) noexcept
    	{
    		varData_ = value;
    		return *this;
    	}
    
    
    public:
    	varDataEncoding() = default;
    
    	constexpr varDataEncoding(std::uint32_t length, std::uint8_t varData) noexcept
    		:length_(length), varData_(varData)
    	{
    		
    	}
    
};
}

template <class CharT, class Traits = std::char_traits<CharT>>
inline std::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT, Traits>& os
    , const test::sbe::varDataEncoding& msg)
{
	os << msg.length_name() << ": " << msg.get_length() << " ";
	os << msg.varData_name() << ": " << msg.get_varData() << " ";
	return os;
};

