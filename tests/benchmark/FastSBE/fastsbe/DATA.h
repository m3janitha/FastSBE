#pragma once
#include<cstdint>
#include<string>
#include<string_view>
#include<ostream>
#include<cstring>

namespace fastsbe
{

class DATA
{
    
    public:
    	static constexpr const char* name() noexcept
    	{ 
    		return "DATA"; 
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
    	std::uint16_t length_{};
    	#pragma pack(pop)
    
    public:
    	static constexpr std::size_t length_size() noexcept
    	{
    		return sizeof(std::uint16_t);
    	}
    
    	static constexpr std::size_t length_offset() noexcept
    	{ 
    		return 0; 
    	}
    	
    	static constexpr const char* length_name() noexcept
    	{ 
    		return "length"; 
    	}
    	
    	static constexpr std::uint16_t length_min_value() noexcept
    	{ 
    		return 0; 
    	}
    	
    	static constexpr std::uint16_t length_max_value() noexcept
    	{
    		return 65534;
    	}
    	
    	static constexpr std::uint16_t length_null_value() noexcept
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
    
    	constexpr std::uint16_t get_length() const noexcept
    	{ 
    		return length_;
    	}
    	
    	constexpr DATA& set_length(std::uint16_t value) noexcept
    	{
    		length_ = value;
    		return *this;
    	}
    
    
    private:
    	#pragma pack(push, 1)
    	char varData_[0]{};
    	#pragma pack(pop)
    
    public:
    	static constexpr std::size_t varData_size() noexcept
    	{
    		return 0;
    	}
    
    	static constexpr std::size_t varData_offset() noexcept
    	{ 
    		return length_offset() + length_size(); 
    	}
    	
    	static constexpr const char* varData_name() noexcept
    	{ 
    		return "varData"; 
    	}
    
    	constexpr char* get_varData() noexcept
    	{ 
    		return varData_;
    	}
    
    	constexpr const char* get_varData() const noexcept
    	{ 
    		return varData_;
    	}
    
    	constexpr std::string_view get_varData_view() noexcept
    	{ 
    		return std::string_view(varData_, 0);
    	}
    
    	constexpr const std::string_view get_varData_view() const noexcept
    	{ 
    		return std::string_view(varData_, 0);
    	}
    
    	auto& set_varData(const char* value) noexcept
    	{
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic push
    	#pragma GCC diagnostic ignored "-Wstringop-overflow"
    	#endif		
    		//auto length = strlen(value);
    		std::memcpy(varData_, value, varData_size());
    		return *this;
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic pop
    	#endif			
    	}
    
    	auto& set_varData(std::string_view value) noexcept
    	{
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic push
    	#pragma GCC diagnostic ignored "-Wstringop-overflow"
    	#endif		
    		//constexpr auto size = std::min(varData_size(), value.size());
    		//auto size = std::min(varData_size(), value.size());
    		std::memcpy(varData_, value.data(), varData_size());
    		return *this;
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic pop
    	#endif			
    	}
    
    
    public:
    	DATA() = default;
    
    	/*constexpr */
    	DATA(std::uint16_t length, std::string_view varData) noexcept
    		:length_(length)
    	{
    		varData.copy(varData_,varData_size());
    	}
    
};
}

template <class CharT, class Traits = std::char_traits<CharT>>
inline std::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT, Traits>& os
    , const fastsbe::DATA& msg)
{
	os << msg.length_name() << ": " << msg.get_length() << " ";
	os << msg.varData_name() << ": " << msg.get_varData() << " ";
	return os;
};

