#pragma once
#include<cstdint>
#include<string>
#include<string_view>
#include<ostream>
#include<groupSizeEncoding.h>
#include<groupSizeEncoding.h>

namespace test::sbe
{

class CancelReplace
{
    
    public:
    	static constexpr const char* name() noexcept
    	{ 
    		return "CancelReplace"; 
    	}
    
    	static constexpr std::size_t template_id() noexcept
    	{ 
    		return 2; 
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
    		return -1; 
    	}
    	
    	static constexpr std::uint32_t clodr_id_max_value() noexcept
    	{ 
    		return 100; 
    	}
    	
    	static constexpr std::uint32_t clodr_id_null_value() noexcept
    	{ 
    		return 100; 
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
    	std::uint32_t orig_clodr_id_{};
    	#pragma pack(pop)
    
    public:
    	static constexpr std::size_t orig_clodr_id_size() noexcept
    	{
    		return sizeof(std::uint32_t);
    	}
    
    	static constexpr std::size_t orig_clodr_id_offset() noexcept
    	{ 
    		return clodr_id_offset() + clodr_id_size(); 
    	}
    
    	static constexpr std::size_t orig_clodr_id_id() noexcept
    	{ 
    		return 2; 
    	}
    	
    	static constexpr const char* orig_clodr_id_name() noexcept
    	{ 
    		return "orig_clodr_id"; 
    	}
    	
    	static constexpr std::uint32_t orig_clodr_id_min_value() noexcept
    	{ 
    		return -1; 
    	}
    	
    	static constexpr std::uint32_t orig_clodr_id_max_value() noexcept
    	{ 
    		return 100; 
    	}
    	
    	static constexpr std::uint32_t orig_clodr_id_null_value() noexcept
    	{ 
    		return 100; 
    	}
    
    	constexpr std::uint32_t get_orig_clodr_id() const noexcept
    	{ 
    		return orig_clodr_id_;
    	}
    	
    	constexpr auto& set_orig_clodr_id(std::uint32_t value) noexcept
    	{
    		orig_clodr_id_ = value;
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
    class PartyInfo
    {
    	friend CancelReplace;
        
        class data
        {
            
            private:
            	#pragma pack(push, 1)
            	std::uint16_t self_match_id_{};
            	#pragma pack(pop)
            
            public:
            	static constexpr std::size_t self_match_id_size() noexcept
            	{
            		return sizeof(std::uint16_t);
            	}
            
            	static constexpr std::size_t self_match_id_offset() noexcept
            	{ 
            		return 0; 
            	}
            
            	static constexpr std::size_t self_match_id_id() noexcept
            	{ 
            		return 11; 
            	}
            	
            	static constexpr const char* self_match_id_name() noexcept
            	{ 
            		return "self_match_id"; 
            	}
            	
            	static constexpr std::uint16_t self_match_id_min_value() noexcept
            	{ 
            		return -1; 
            	}
            	
            	static constexpr std::uint16_t self_match_id_max_value() noexcept
            	{ 
            		return 100; 
            	}
            	
            	static constexpr std::uint16_t self_match_id_null_value() noexcept
            	{ 
            		return 100; 
            	}
            
            	constexpr std::uint16_t get_self_match_id() const noexcept
            	{ 
            		return self_match_id_;
            	}
            	
            	constexpr auto& set_self_match_id(std::uint16_t value) noexcept
            	{
            		self_match_id_ = value;
            		return *this;
            	}
            
            
            private:
            	#pragma pack(push, 1)
            	std::uint16_t group_id_{};
            	#pragma pack(pop)
            
            public:
            	static constexpr std::size_t group_id_size() noexcept
            	{
            		return sizeof(std::uint16_t);
            	}
            
            	static constexpr std::size_t group_id_offset() noexcept
            	{ 
            		return self_match_id_offset() + self_match_id_size(); 
            	}
            
            	static constexpr std::size_t group_id_id() noexcept
            	{ 
            		return 12; 
            	}
            	
            	static constexpr const char* group_id_name() noexcept
            	{ 
            		return "group_id"; 
            	}
            	
            	static constexpr std::uint16_t group_id_min_value() noexcept
            	{ 
            		return -1; 
            	}
            	
            	static constexpr std::uint16_t group_id_max_value() noexcept
            	{ 
            		return 100; 
            	}
            	
            	static constexpr std::uint16_t group_id_null_value() noexcept
            	{ 
            		return 100; 
            	}
            
            	constexpr std::uint16_t get_group_id() const noexcept
            	{ 
            		return group_id_;
            	}
            	
            	constexpr auto& set_group_id(std::uint16_t value) noexcept
            	{
            		group_id_ = value;
            		return *this;
            	}
            
    };
    
    private:
    #pragma pack(push, 1)
    	groupSizeEncoding header_{};
    #pragma pack(pop)
    
    public:
    	PartyInfo() = default;
    	PartyInfo(std::uint16_t count)
    		:header_(sizeof(PartyInfo::data), count) {}
    
    	data& get(PartyInfo& group, std::size_t group_id) noexcept
    	{
    		auto* buffer = reinterpret_cast<char*>(&group) + sizeof(groupSizeEncoding)
    			+ (header_.get_blockLength() * group_id);
    		return *reinterpret_cast<data*>(buffer);
    	}
    
    	const data& get(const PartyInfo& group, std::size_t group_id) const noexcept
    	{
    		auto* buffer = reinterpret_cast<const char*>(&group) + sizeof(groupSizeEncoding)
    			+ (header_.get_blockLength() * group_id);
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
    	PartyInfo PartyInfo_{};
    	#pragma pack(pop)
    
    public:
    	static constexpr std::size_t PartyInfo_size() noexcept
    	{
    		return sizeof(PartyInfo::data);
    	}
    
    	static constexpr std::size_t PartyInfo_id() noexcept
    	{ 
    		return 10; 
    	}
    	
    	static constexpr const char* PartyInfo_name() noexcept
    	{ 
    		return "PartyInfo"; 
    	}
    
    	std::size_t PartyInfo_offset() const noexcept
    	{
    		return 0;
    	}
    
    	std::size_t PartyInfo_data_length() const noexcept
    	{
    		auto& group = get_PartyInfo();
    		return group.header_.get_blockLength() * group.header_.get_numInGroup();
    	}
    	
    	const PartyInfo& get_PartyInfo() const noexcept
    	{ 
    		const auto* buf = buffer() + PartyInfo_offset();
    		return *reinterpret_cast<const PartyInfo*>(buf);
    	}
    	
    	PartyInfo& get_PartyInfo() noexcept
    	{
    		auto* buf = buffer() + PartyInfo_offset();
    		return *reinterpret_cast<PartyInfo*>(buf);
    	}
    
    	PartyInfo& append_PartyInfo(std::uint16_t count) noexcept
    	{
    		auto* buf = buffer() + PartyInfo_offset();
			//auto* group = new(buf) PartyInfo(count);
			auto& group = *reinterpret_cast<PartyInfo*>(buf);
			group.header_.set_numInGroup(count);
    		return group;
    	}
    
    class AppInfo
    {
    	friend CancelReplace;
        
        class data
        {
            
            private:
            	#pragma pack(push, 1)
            	std::uint16_t firm_id_{};
            	#pragma pack(pop)
            
            public:
            	static constexpr std::size_t firm_id_size() noexcept
            	{
            		return sizeof(std::uint16_t);
            	}
            
            	static constexpr std::size_t firm_id_offset() noexcept
            	{ 
            		return 0; 
            	}
            
            	static constexpr std::size_t firm_id_id() noexcept
            	{ 
            		return 21; 
            	}
            	
            	static constexpr const char* firm_id_name() noexcept
            	{ 
            		return "firm_id"; 
            	}
            	
            	static constexpr std::uint16_t firm_id_min_value() noexcept
            	{ 
            		return -1; 
            	}
            	
            	static constexpr std::uint16_t firm_id_max_value() noexcept
            	{ 
            		return 100; 
            	}
            	
            	static constexpr std::uint16_t firm_id_null_value() noexcept
            	{ 
            		return 100; 
            	}
            
            	constexpr std::uint16_t get_firm_id() const noexcept
            	{ 
            		return firm_id_;
            	}
            	
            	constexpr auto& set_firm_id(std::uint16_t value) noexcept
            	{
            		firm_id_ = value;
            		return *this;
            	}
            
            
            private:
            	#pragma pack(push, 1)
            	std::uint32_t version_{};
            	#pragma pack(pop)
            
            public:
            	static constexpr std::size_t version_size() noexcept
            	{
            		return sizeof(std::uint32_t);
            	}
            
            	static constexpr std::size_t version_offset() noexcept
            	{ 
            		return firm_id_offset() + firm_id_size(); 
            	}
            
            	static constexpr std::size_t version_id() noexcept
            	{ 
            		return 22; 
            	}
            	
            	static constexpr const char* version_name() noexcept
            	{ 
            		return "version"; 
            	}
            	
            	static constexpr std::uint32_t version_min_value() noexcept
            	{ 
            		return -1; 
            	}
            	
            	static constexpr std::uint32_t version_max_value() noexcept
            	{ 
            		return 100; 
            	}
            	
            	static constexpr std::uint32_t version_null_value() noexcept
            	{ 
            		return 100; 
            	}
            
            	constexpr std::uint32_t get_version() const noexcept
            	{ 
            		return version_;
            	}
            	
            	constexpr auto& set_version(std::uint32_t value) noexcept
            	{
            		version_ = value;
            		return *this;
            	}
            
    };
    
    private:
    #pragma pack(push, 1)
    	groupSizeEncoding header_{};
    #pragma pack(pop)
    
    public:
    	AppInfo() = default;
    	AppInfo(std::uint16_t count)
    		:header_(sizeof(AppInfo::data), count) {}
    
    	data& get(AppInfo& group, std::size_t group_id) noexcept
    	{
    		auto* buffer = reinterpret_cast<char*>(&group) + sizeof(groupSizeEncoding)
    			+ (header_.get_blockLength() * group_id);
    		return *reinterpret_cast<data*>(buffer);
    	}
    
    	const data& get(const AppInfo& group, std::size_t group_id) const noexcept
    	{
    		auto* buffer = reinterpret_cast<const char*>(&group) + sizeof(groupSizeEncoding)
    			+ (header_.get_blockLength() * group_id);
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
    	AppInfo AppInfo_{};
    	#pragma pack(pop)
    
    public:
    	static constexpr std::size_t AppInfo_size() noexcept
    	{
    		return sizeof(AppInfo::data);
    	}
    
    	static constexpr std::size_t AppInfo_id() noexcept
    	{ 
    		return 20; 
    	}
    	
    	static constexpr const char* AppInfo_name() noexcept
    	{ 
    		return "AppInfo"; 
    	}
    
    	std::size_t AppInfo_offset() const noexcept
    	{
    		return PartyInfo_offset() + sizeof(PartyInfo::header_) + PartyInfo_data_length();
    	}
    
    	std::size_t AppInfo_data_length() const noexcept
    	{
    		auto& group = get_AppInfo();
    		return group.header_.get_blockLength() * group.header_.get_numInGroup();
    	}
    	
    	const AppInfo& get_AppInfo() const noexcept
    	{ 
    		const auto* buf = buffer() + AppInfo_offset();
    		return *reinterpret_cast<const AppInfo*>(buf);
    	}
    	
    	AppInfo& get_AppInfo() noexcept
    	{
    		auto* buf = buffer() + AppInfo_offset();
    		return *reinterpret_cast<AppInfo*>(buf);
    	}
    
    	AppInfo& append_AppInfo(std::uint16_t count) noexcept
    	{
    		auto* buf = buffer() + AppInfo_offset();
    		//auto* group = new(buf) AppInfo(count);
			auto& group = *reinterpret_cast<AppInfo*>(buf);
			group.header_.set_numInGroup(count);
    		return group;
    	}
};
}

template <class CharT, class Traits = std::char_traits<CharT>>
inline std::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT, Traits>& os
    , const test::sbe::CancelReplace::PartyInfo& group)
{
	for (auto i = 0; i < group.get_numInGroup(); i++)
	{
		auto& g = group.get(group, i);

		os << g.self_match_id_name() << ": " << g.get_self_match_id() << " ";
		os << g.group_id_name() << ": " << g.get_group_id() << " ";
	}
	return os;
};

template <class CharT, class Traits = std::char_traits<CharT>>
inline std::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT, Traits>& os
    , const test::sbe::CancelReplace::AppInfo& group)
{
	for (auto i = 0; i < group.get_numInGroup(); i++)
	{
		auto& g = group.get(group, i);

		os << g.firm_id_name() << ": " << g.get_firm_id() << " ";
		os << g.version_name() << ": " << g.get_version() << " ";
	}
	return os;
};

template <class CharT, class Traits = std::char_traits<CharT>>
inline std::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT, Traits>& os
    , const test::sbe::CancelReplace& msg)
{
	os << msg.clodr_id_name() << ": " << msg.get_clodr_id() << " ";
	os << msg.orig_clodr_id_name() << ": " << msg.get_orig_clodr_id() << " ";
	os << msg.PartyInfo_name() << ": " << msg.get_PartyInfo() << " ";
	os << msg.AppInfo_name() << ": " << msg.get_AppInfo() << " ";
	return os;
};

