#pragma once
#include<cstdint>
#include<string>
#include<string_view>
#include<ostream>

namespace test::sbe
{

class groupSizeEncoding
{
    
    public:
    	static constexpr const char* name() noexcept
    	{ 
    		return "groupSizeEncoding"; 
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
    	std::uint16_t blockLength_{};
    	#pragma pack(pop)
    
    public:
    	static constexpr std::size_t blockLength_size() noexcept
    	{
    		return sizeof(std::uint16_t);
    	}
    
    	static constexpr std::size_t blockLength_offset() noexcept
    	{ 
    		return 0; 
    	}
    	
    	static constexpr const char* blockLength_name() noexcept
    	{ 
    		return "blockLength"; 
    	}
    	
    	static constexpr std::uint16_t blockLength_min_value() noexcept
    	{ 
    		return 0; 
    	}
    	
    	static constexpr std::uint16_t blockLength_max_value() noexcept
    	{
    		return 65534;
    	}
    	
    	static constexpr std::uint16_t blockLength_null_value() noexcept
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
    
    	constexpr std::uint16_t get_blockLength() const noexcept
    	{ 
    		return blockLength_;
    	}
    	
    	constexpr groupSizeEncoding& set_blockLength(std::uint16_t value) noexcept
    	{
    		blockLength_ = value;
    		return *this;
    	}
    
    
    private:
    	#pragma pack(push, 1)
    	std::uint16_t numInGroup_{};
    	#pragma pack(pop)
    
    public:
    	static constexpr std::size_t numInGroup_size() noexcept
    	{
    		return sizeof(std::uint16_t);
    	}
    
    	static constexpr std::size_t numInGroup_offset() noexcept
    	{ 
    		return blockLength_offset() + blockLength_size(); 
    	}
    	
    	static constexpr const char* numInGroup_name() noexcept
    	{ 
    		return "numInGroup"; 
    	}
    	
    	static constexpr std::uint16_t numInGroup_min_value() noexcept
    	{ 
    		return 0; 
    	}
    	
    	static constexpr std::uint16_t numInGroup_max_value() noexcept
    	{
    		return 65534;
    	}
    	
    	static constexpr std::uint16_t numInGroup_null_value() noexcept
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
    
    	constexpr std::uint16_t get_numInGroup() const noexcept
    	{ 
    		return numInGroup_;
    	}
    	
    	constexpr groupSizeEncoding& set_numInGroup(std::uint16_t value) noexcept
    	{
    		numInGroup_ = value;
    		return *this;
    	}
    
    
    public:
    	groupSizeEncoding() = default;
    
    	/*constexpr */
    	groupSizeEncoding(std::uint16_t blockLength, std::uint16_t numInGroup) noexcept
    		:blockLength_(blockLength), numInGroup_(numInGroup)
    	{
    		
    	}
    
};
}

template <class CharT, class Traits = std::char_traits<CharT>>
inline std::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT, Traits>& os
    , const test::sbe::groupSizeEncoding& msg)
{
	os << msg.blockLength_name() << ": " << msg.get_blockLength() << " ";
	os << msg.numInGroup_name() << ": " << msg.get_numInGroup() << " ";
	return os;
};

