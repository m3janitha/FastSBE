#pragma once
#include<cstdint>
#include<string>
#include<string_view>
#include<ostream>
#include<cstring>

namespace fastsbe
{

class messageHeader
{
    
    public:
    	static constexpr const char* name() noexcept
    	{ 
    		return "messageHeader"; 
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
    	
    	constexpr messageHeader& set_blockLength(std::uint16_t value) noexcept
    	{
    		blockLength_ = value;
    		return *this;
    	}
    
    
    private:
    	#pragma pack(push, 1)
    	std::uint16_t templateId_{};
    	#pragma pack(pop)
    
    public:
    	static constexpr std::size_t templateId_size() noexcept
    	{
    		return sizeof(std::uint16_t);
    	}
    
    	static constexpr std::size_t templateId_offset() noexcept
    	{ 
    		return blockLength_offset() + blockLength_size(); 
    	}
    	
    	static constexpr const char* templateId_name() noexcept
    	{ 
    		return "templateId"; 
    	}
    	
    	static constexpr std::uint16_t templateId_min_value() noexcept
    	{ 
    		return 0; 
    	}
    	
    	static constexpr std::uint16_t templateId_max_value() noexcept
    	{
    		return 65534;
    	}
    	
    	static constexpr std::uint16_t templateId_null_value() noexcept
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
    
    	constexpr std::uint16_t get_templateId() const noexcept
    	{ 
    		return templateId_;
    	}
    	
    	constexpr messageHeader& set_templateId(std::uint16_t value) noexcept
    	{
    		templateId_ = value;
    		return *this;
    	}
    
    
    private:
    	#pragma pack(push, 1)
    	std::uint16_t schemaId_{};
    	#pragma pack(pop)
    
    public:
    	static constexpr std::size_t schemaId_size() noexcept
    	{
    		return sizeof(std::uint16_t);
    	}
    
    	static constexpr std::size_t schemaId_offset() noexcept
    	{ 
    		return templateId_offset() + templateId_size(); 
    	}
    	
    	static constexpr const char* schemaId_name() noexcept
    	{ 
    		return "schemaId"; 
    	}
    	
    	static constexpr std::uint16_t schemaId_min_value() noexcept
    	{ 
    		return 0; 
    	}
    	
    	static constexpr std::uint16_t schemaId_max_value() noexcept
    	{
    		return 65534;
    	}
    	
    	static constexpr std::uint16_t schemaId_null_value() noexcept
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
    
    	constexpr std::uint16_t get_schemaId() const noexcept
    	{ 
    		return schemaId_;
    	}
    	
    	constexpr messageHeader& set_schemaId(std::uint16_t value) noexcept
    	{
    		schemaId_ = value;
    		return *this;
    	}
    
    
    private:
    	#pragma pack(push, 1)
    	std::uint16_t version_{};
    	#pragma pack(pop)
    
    public:
    	static constexpr std::size_t version_size() noexcept
    	{
    		return sizeof(std::uint16_t);
    	}
    
    	static constexpr std::size_t version_offset() noexcept
    	{ 
    		return schemaId_offset() + schemaId_size(); 
    	}
    	
    	static constexpr const char* version_name() noexcept
    	{ 
    		return "version"; 
    	}
    	
    	static constexpr std::uint16_t version_min_value() noexcept
    	{ 
    		return 0; 
    	}
    	
    	static constexpr std::uint16_t version_max_value() noexcept
    	{
    		return 65534;
    	}
    	
    	static constexpr std::uint16_t version_null_value() noexcept
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
    
    	constexpr std::uint16_t get_version() const noexcept
    	{ 
    		return version_;
    	}
    	
    	constexpr messageHeader& set_version(std::uint16_t value) noexcept
    	{
    		version_ = value;
    		return *this;
    	}
    
    
    public:
    	messageHeader() = default;
    
    	/*constexpr */
    	messageHeader(std::uint16_t blockLength, std::uint16_t templateId, std::uint16_t schemaId, std::uint16_t version) noexcept
    		:blockLength_(blockLength), templateId_(templateId), schemaId_(schemaId), version_(version)
    	{
    		
    	}
    
};
}

template <class CharT, class Traits = std::char_traits<CharT>>
inline std::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT, Traits>& os
    , const fastsbe::messageHeader& msg)
{
	os << msg.blockLength_name() << ": " << msg.get_blockLength() << " ";
	os << msg.templateId_name() << ": " << msg.get_templateId() << " ";
	os << msg.schemaId_name() << ": " << msg.get_schemaId() << " ";
	os << msg.version_name() << ": " << msg.get_version() << " ";
	return os;
};

