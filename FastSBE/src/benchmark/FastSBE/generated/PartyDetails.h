#pragma once
#include<cstdint>
#include<string>
#include<string_view>
#include<ostream>
#include<TimeInForce.h>
#include<TimeInForce.h>

namespace test::sbe
{

class PartyDetails
{
    
    public:
    	static constexpr const char* name() noexcept
    	{ 
    		return "PartyDetails"; 
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
    	TimeInForce::Value time_in_force_{};
    	#pragma pack(pop)
    
    public:
    	static constexpr std::size_t time_in_force_size() noexcept
    	{
    		return sizeof(TimeInForce);
    	}
    
    	static constexpr std::size_t time_in_force_offset() noexcept
    	{ 
    		return 0; 
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
    	
    	constexpr PartyDetails& set_time_in_force(TimeInForce::Value value) noexcept
    	{
    		time_in_force_ = value;
    		return *this;
    	}
    
    
    public:
    	static constexpr std::size_t ord_status_size() noexcept
    	{
    		return 0;
    	}
    
    	static constexpr std::size_t ord_status_offset() noexcept
    	{
    		return time_in_force_offset() + time_in_force_size();
    	}
    
    	static constexpr const char* ord_status_name() noexcept
    	{
    		return "ord_status";
    	}
    
    	constexpr TimeInForce::Value get_ord_status() const noexcept
    	{
    		return TimeInForce::Value::Day;
    	}
    
    private:
    	#pragma pack(push, 1)
    	char executor_[4]{};
    	#pragma pack(pop)
    
    public:
    	static constexpr std::size_t executor_size() noexcept
    	{
    		return 4;
    	}
    
    	static constexpr std::size_t executor_offset() noexcept
    	{ 
    		return ord_status_offset() + ord_status_size(); 
    	}
    	
    	static constexpr const char* executor_name() noexcept
    	{ 
    		return "executor"; 
    	}
    
    	constexpr char* get_executor() noexcept
    	{ 
    		return executor_;
    	}
    
    	constexpr const char* get_executor() const noexcept
    	{ 
    		return executor_;
    	}
    
    	constexpr std::string_view get_executor_str() noexcept
    	{ 
    		return std::string_view(executor_, 4);
    	}
    
    	constexpr const std::string_view get_executor_str() const noexcept
    	{ 
    		return std::string_view(executor_, 4);
    	}
    
    	auto& set_executor(const char* value) noexcept
    	{
    		auto length = strlen(value);
    		std::memcpy(executor_, value, length);
    		return *this;
    	}
    
    	auto& set_executor(std::string_view value) noexcept
    	{
    		//constexpr auto size = std::min(executor_size(), value.size());
    		auto size = std::min(executor_size(), value.size());
    		std::memcpy(executor_, value.data(), size);
    		return *this;
    	}
    
    
    private:
    	#pragma pack(push, 1)
    	std::uint16_t capacity_{};
    	#pragma pack(pop)
    
    public:
    	static constexpr std::size_t capacity_size() noexcept
    	{
    		return sizeof(std::uint16_t);
    	}
    
    	static constexpr std::size_t capacity_offset() noexcept
    	{ 
    		return executor_offset() + executor_size(); 
    	}
    	
    	static constexpr const char* capacity_name() noexcept
    	{ 
    		return "capacity"; 
    	}
    	
    	static constexpr std::uint16_t capacity_min_value() noexcept
    	{ 
    		return -1; 
    	}
    	
    	static constexpr std::uint16_t capacity_max_value() noexcept
    	{ 
    		return 100; 
    	}
    	
    	static constexpr std::uint16_t capacity_null_value() noexcept
    	{ 
    		return 100; 
    	}
    
    	constexpr std::uint16_t get_capacity() const noexcept
    	{ 
    		return capacity_;
    	}
    	
    	constexpr PartyDetails& set_capacity(std::uint16_t value) noexcept
    	{
    		capacity_ = value;
    		return *this;
    	}
    
    
    public:
    	static constexpr std::size_t handle_inst_size() noexcept
    	{
    		return 0;
    	}
    
    	static constexpr std::size_t handle_inst_offset() noexcept
    	{ 
    		return capacity_offset() + capacity_size(); 
    	}
    	
    	static constexpr const char* handle_inst_name() noexcept
    	{ 
    		return "handle_inst"; 
    	}
    
    	constexpr std::uint32_t get_handle_inst() const noexcept
    	{ 
    		return 56;
    	}
    
    
    public:
    	PartyDetails() = default;
    
    	constexpr PartyDetails(TimeInForce::Value time_in_force, std::string_view executor, std::uint16_t capacity) noexcept
    		:time_in_force_(time_in_force), capacity_(capacity)
    	{
    		executor.copy(executor_,executor_size());
    	}
    
};
}

template <class CharT, class Traits = std::char_traits<CharT>>
inline std::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT, Traits>& os
    , const test::sbe::PartyDetails& msg)
{
	os << msg.time_in_force_name() << ": " << msg.get_time_in_force() << " ";
	os << msg.ord_status_name() << ": " << msg.get_ord_status() << " ";
	os << msg.executor_name() << ": " << msg.get_executor() << " ";
	os << msg.capacity_name() << ": " << msg.get_capacity() << " ";
	os << msg.handle_inst_name() << ": " << msg.get_handle_inst() << " ";
	return os;
};

