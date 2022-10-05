#pragma once
#include <cstdint>
#include <string>
#include <string_view>
#include <ostream>
#include <cstring>

//						char buffer();
//field					offeset
//header

//f1					0
//f2					f1_offset() + sizeof(f1)
//f3					f2_offset() + sizeof(f2)
//f4					f3_offset() + sizeof(f3)

//g1.haeader(s,c)		f4_offset() + sizeof(f3)
						
//g1.f1					g1_offset() + sizeof(haeader) + (c=0)*s + 0
//g1.f2					g1_offset() + sizeof(haeader) + (c=0)*s + group_offset(f1)
//g1.f3					g1_offset() + sizeof(haeader) + (c=0)*s + group_offset(f2)

//g1.f1					g1_offset() + sizeof(haeader) + (c=1)*s + 0
//g1.f2					g1_offset() + sizeof(haeader) + (c=1)*s + group_offset(f1)
//g1.f3					g1_offset() + sizeof(haeader) + (c=1)*s + group_offset(f2)

//g2.header				g1_offest() + sizeof(g1.haeader) + g1.header().size() * g1.header().count();

//g2.f1					g2_offest() + sizeof(haeader) + (c=0)*s + 0
//g2.f2

//d1.header				g2_offest() + sizeof(g2.haeader) + g2.header().size() * g2.header().count();

//d1.data				g2_offest() + sizeof(haeader)

//d2.header				d1_offest() + sizeof(haeader).size();
//
//
//
//

struct composite_1
{
	std::uint32_t f1_{};
	constexpr std::uint32_t get_f1() const noexcept { return f1_; }
	constexpr auto& set_f1(std::uint32_t value) noexcept
	{
		f1_ = value;
		return *this;
	}

	std::uint32_t f2_{};
	constexpr std::uint32_t get_f2() const noexcept { return f2_; }
	constexpr auto& set_f2(std::uint32_t value) noexcept
	{
		f2_ = value;
		return *this;
	}
};

struct MyEnum
{
	enum class Value
	{
		VAL1,
		VAL2,
	};
};

struct message
{
	static constexpr const char* name() noexcept
	{ 
		return "message"; 
	}

	static constexpr std::size_t template_id() noexcept
	{ 
		return 1; 
	}

	static constexpr std::size_t schema() noexcept
	{  
		return 1; 
	}

	static constexpr std::size_t version() noexcept
	{ 
		return 1; 
	}

	static constexpr const char* semantic_type() 
	{ 
		return ""; 	
	}
	
	using f1_type = std::uint32_t;
#pragma pack(push, 1)
	f1_type f1_{};
#pragma pack(pop)

	static constexpr std::size_t f1_offset() noexcept { return 0; }
	static constexpr std::size_t f1_id() noexcept { return 1; }
	static constexpr const char* f1_name() noexcept { return "message"; }
	static constexpr f1_type min_value() noexcept { return 90; }
	static constexpr f1_type max_value() noexcept { return 110; }
	static constexpr f1_type null_value() noexcept { return 110; }

	constexpr f1_type get_f1() const noexcept { return f1_; }
	constexpr message& set_f1(f1_type value) noexcept
	{
		f1_ = value;
		return *this;
	}

	char* buffer() noexcept { return reinterpret_cast<char*>(&f1_); }
	const char* buffer() const noexcept { return reinterpret_cast<const char*>(&f1_); }

	static constexpr std::size_t f2_offset() noexcept { return f1_offset() + sizeof(f1_); }

	using f2_type = std::uint32_t;
#pragma pack(push, 1)
	f2_type f2_{};
#pragma pack(pop)

	constexpr f2_type get_f2() const noexcept { return f2_; }
	constexpr message& set_f2(f2_type value) noexcept
	{
		f2_ = value;
		return *this;
	}

	static constexpr std::size_t f2_id() noexcept { return 2; }
	static constexpr std::size_t f3_offset() noexcept { return f2_offset() + sizeof(f2_); }

#pragma pack(push, 1)
	char f3_[5]{};
#pragma pack(pop)

	constexpr char* get_f3() noexcept { return f3_; }
	constexpr const char* get_f3() const noexcept { return f3_; }

	constexpr std::string_view get_f3_str() noexcept { return std::string_view(f3_, 5); }
	constexpr const std::string_view get_f3_str() const noexcept { return std::string_view(f3_, 5); }

	static constexpr std::size_t f3_size() noexcept { return 5;}

	message& set_f3(const char* value) noexcept
	{
		auto length = strlen(value);
		std::memcpy(f3_, value, length);
		return *this;
	}

	message& set_f3(std::string_view value) noexcept
	{
		auto size = std::min(f3_size(), value.size());
		std::memcpy(f3_, value.data(), size);
		return *this;
	}

	static constexpr std::size_t f3_id() noexcept { return 3; }

	static constexpr std::size_t f5_offset() noexcept { return f3_offset() + sizeof(f5_); }
	using f5_type = MyEnum::Value;
#pragma pack(push, 1)
	f5_type f5_{};
#pragma pack(pop)

	constexpr f5_type get_f5() const noexcept { return f5_; }
	constexpr message& set_f5(f5_type value) noexcept
	{
		f5_ = value;
		return *this;
	}

	static constexpr std::size_t f5_id() noexcept { return 2; }

	char buffx_[512]{};

	constexpr std::size_t group1_offset() const noexcept { return 0; }

	struct group1
	{
		using data_size_type = std::uint32_t;
		using data_count_type = std::uint16_t;

		struct data
		{
#pragma pack(push, 1)
			std::uint32_t f1_{};
#pragma pack(pop)
			constexpr std::uint32_t get_f1() const noexcept { return f1_; }
			constexpr data& set_f1(std::uint32_t value) noexcept
			{
				f1_ = value;
				return *this;
			}
			static constexpr std::size_t f1_id() noexcept { return 11; }

#pragma pack(push, 1)
			std::uint32_t f2_{};
#pragma pack(pop)
			constexpr std::uint32_t get_f2() const noexcept { return f2_; }
			constexpr data& set_f2(std::uint32_t value) noexcept
			{
				f2_ = value;
				return *this;
			}
			static constexpr std::size_t f2_id() noexcept { return 12; }

			static constexpr data_size_type data_size() noexcept { return sizeof(data); }
		};

		struct group_header
		{
#pragma pack(push, 1)
			const data_size_type size_{ data::data_size() };
#pragma pack(pop)
			constexpr std::uint32_t get_size() const noexcept { return data::data_size(); }

#pragma pack(push, 1)
			data_count_type count_{ 0 };
#pragma pack(pop)
			constexpr data_count_type get_count() const noexcept { return count_; }

			group_header() = default;
			group_header(data_count_type count)
				:count_(count) {}
			group_header(data_size_type size, data_count_type count)
				:size_(size), count_(count) {}
		};

#pragma pack(push, 1)
		group_header header_{};
#pragma pack(pop)

		group1() = default;
		group1(data_count_type count)
			:header_(count) {}

		constexpr data_size_type get_size() const noexcept { return header_.get_size(); }
		constexpr data_count_type get_count() const noexcept { return header_.get_count(); }

		data& get(group1& group, std::size_t group_id) noexcept
		{
			auto offset = sizeof(group_header) + (header_.get_size() * group_id);
			auto* buffer = reinterpret_cast<char*>(&group) + sizeof(group_header) + (header_.get_size() * group_id);
			return *reinterpret_cast<data*>(buffer);
		}

		const data& get(const group1& group, std::size_t group_id) const noexcept
		{
			auto* buffer = reinterpret_cast<const char*>(&group) + sizeof(group_header) + (header_.get_size() * header_.get_count());
			return *reinterpret_cast<const data*>(buffer);

		}

		data& get(char* buffer, std::size_t group_id) noexcept
		{
			auto* buf = buffer + sizeof(group_header) + (header_.get_size() * header_.get_count());
			return *reinterpret_cast<data*>(buffer);
		}

		const data& get(const char* buffer, std::size_t group_id) const noexcept
		{
			auto* buf = buffer + sizeof(group_header) + (header_.get_size() * header_.get_count());
			return *reinterpret_cast<const data*>(buffer);
		}
	};

#pragma pack(push, 1)
	group1 group1_{};
#pragma pack(pop)

	static constexpr std::size_t group1_id() noexcept { return 10; }

	group1& get_group1() noexcept 
	{
		auto* buf = buffx_ + group1_offset();
		return *reinterpret_cast<group1*>(buf);
	}

	const group1& get_group1() const noexcept 
	{ 
		const auto* buf = buffx_ + group1_offset();
		return *reinterpret_cast<const group1*>(buf); 
	}

	group1& append_group1(std::uint16_t count) noexcept
	{
		auto* buf = buffx_ + group1_offset();
		auto* group = new(buf) group1(count);
		return *group;
	}

	std::size_t group1_data_length() const noexcept
	{
		auto group = get_group1();
		return group.header_.get_size() * group.header_.get_count(); 
	}

	std::size_t group2_offset() const noexcept 
	{ 
		//return group1_offset() + sizeof(group1::group_header) + (group1_.header_.get_size() * group1_.header_.get_count());
		auto previous_grp = get_group1();
		return group1_offset() + sizeof(group1::group_header) + group1_data_length(); 
	}

	struct group2
	{
		using data_size_type = std::uint32_t;
		using data_count_type = std::uint16_t;

		struct data
		{
#pragma pack(push, 1)
			std::uint32_t f1_{};
#pragma pack(pop)
			constexpr std::uint32_t get_f1() const noexcept { return f1_; }
			constexpr data& set_f1(std::uint32_t value) noexcept
			{
				f1_ = value;
				return *this;
			}
			static constexpr std::size_t f1_id() noexcept { return 21; }

#pragma pack(push, 1)
			std::uint32_t f2_{};
#pragma pack(pop)
			constexpr std::uint32_t get_f2() const noexcept { return f2_; }
			constexpr data& set_f2(std::uint32_t value) noexcept
			{
				f2_ = value;
				return *this;
			}
			static constexpr std::size_t f2_id() noexcept { return 22; }

			static constexpr data_size_type data_size() noexcept { return sizeof(data); }
		};

		struct group_header
		{
#pragma pack(push, 1)
			const data_size_type size_{ data::data_size() };
#pragma pack(pop)
			constexpr data_size_type get_size() const noexcept { return data::data_size(); }

#pragma pack(push, 1)
			data_count_type count_{ 0 };
#pragma pack(pop)
			constexpr data_count_type get_count() const noexcept { return count_; }

			group_header() = default;
			group_header(data_count_type count)
				:count_(count) {}
			group_header(data_size_type size, data_count_type count)
				:size_(size), count_(count) {}
		};

#pragma pack(push, 1)
		group_header header_{};
#pragma pack(pop)
		group2() = default;
		group2(data_count_type count)
			:header_(count) {}

		constexpr data_size_type get_size() const noexcept { return header_.get_size(); }
		constexpr data_count_type get_count() const noexcept { return header_.get_count(); }

		data& get(group2& group, std::size_t group_id) noexcept
		{
			auto* buffer = reinterpret_cast<char*>(&group) + sizeof(group_header) + (header_.get_size() * group_id);
			return *reinterpret_cast<data*>(buffer);
		}

		const data& get(const group2& group, std::size_t group_id) const noexcept
		{
			auto* buffer = reinterpret_cast<const char*>(&group) + sizeof(group_header) + (header_.get_size() * header_.get_count());
			return *reinterpret_cast<const data*>(buffer);
		}

		const data& get(const char* buffer, std::size_t group_id) const noexcept
		{
			auto* buf = buffer + sizeof(group_header) +(header_.get_size() * header_.get_count());
			return *reinterpret_cast<const data*>(buffer);
		}

		data& get(char* buffer, std::size_t group_id) noexcept
		{
			auto* buf = buffer + sizeof(group_header) + (header_.get_size() * header_.get_count());
			return *reinterpret_cast<data*>(buffer);
		}
	};

#pragma pack(push, 1)
	group2 group2_{};
#pragma pack(pop)

	static constexpr std::size_t group2_id() noexcept { return 20; }

	group2& get_group2() noexcept
	{
		auto* buf = buffer() + group2_offset();
		return *reinterpret_cast<group2*>(buf);
	}
	const group2& get_group2() const noexcept
	{
		const auto* buf = buffer() + group2_offset();
		return *reinterpret_cast<const group2*>(buf);
	}

	group2& append_group2(std::uint16_t count) noexcept
	{
		auto aaa = group1_offset();
		auto bbb = group2_offset();
		auto* buf = buffer() + group2_offset();
		auto* group = new(buf) group2(count);
		return *group;
	}

	std::size_t group2_data_length() const noexcept
	{
		auto group = get_group2();
		return group.header_.get_size() * group.header_.get_count(); 
	}

	std::size_t v_data1_offset() const noexcept 
	{ 
		//return group1_offset() + sizeof(group1::group_header) + (group1_.header_.get_size() * group1_.header_.get_count());
		auto previous_grp = get_group2();
		return group2_offset() + sizeof(group2::group_header) + group2_data_length(); 
	}
	
	struct v_data1
	{
		struct v_data_header
		{
#pragma pack(push, 1)
			std::uint32_t size_{ 0 };
#pragma pack(pop)
			constexpr std::uint32_t get_size() const noexcept { return size_; }
			constexpr void set_size(std::uint32_t value) noexcept { size_ = value; }

			v_data_header() = default;
			v_data_header(std::uint32_t size)
				:size_(size) {}
		};

#pragma pack(push, 1)
		v_data_header header_{};
#pragma pack(pop)
		v_data1() = default;
		v_data1(std::uint32_t size)
			:header_(size) {}
	};

#pragma pack(push, 1)
	v_data1 v_data1_{};
#pragma pack(pop)

	static constexpr std::size_t v_data1_id() noexcept { return 30; }

	std::basic_string_view<char> get_v_data1() noexcept
	{
		auto* buf = buffer() + v_data1_offset();
		auto* header = reinterpret_cast<v_data1::v_data_header*>(buf);
		auto* data = buf + sizeof(v_data1);
		return std::basic_string_view<char>(data, header->get_size());
	}
	std::basic_string_view<char> get_v_data1() const noexcept
	{
		auto* buf = buffer() + v_data1_offset();
		auto* header = reinterpret_cast<const v_data1::v_data_header*>(buf);
		auto* data = buf + sizeof(v_data1);
		return std::basic_string_view<char>(data, header->get_size());
	}

	void append_v_data1(std::basic_string_view<char> value) noexcept
	{
		auto* buf = buffer() + v_data1_offset();
		auto* data = buf + sizeof(v_data1);
		std::memcpy(data, value.data(), value.size());
		reinterpret_cast<v_data1::v_data_header*>(buf)->set_size(value.size());
	}

	void append_v_data1(const char* value) noexcept
	{
		auto length = strlen(value);
		auto* buf = buffer() + v_data1_offset();
		auto* data = buf + sizeof(v_data1);
		std::memcpy(data, value, length);
		reinterpret_cast<v_data1::v_data_header*>(buf)->set_size(length);
	}

#pragma pack(push, 1)
	char buff_[1024];
#pragma pack(pop)
};

template <class CharT, class Traits = std::char_traits<CharT>>
std::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT, Traits>& os, message::group1& group)
{
	for (auto i = 0; i < group.get_count(); i++)
	{
		auto& g = group.get(group, i);
		os << g.f1_id() << ":" << g.get_f1() << ", ";
		os << g.f2_id() << ":" << g.get_f2() << ", ";
	}
	return os;
}

template <class CharT, class Traits = std::char_traits<CharT>>
std::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT, Traits>& os, message::group2& group)
{
	for (auto i = 0; i < group.get_count(); i++)
	{
		auto& g = group.get(group, i);
		os << g.f1_id() << ":" << g.get_f1() << ", "
			<< g.f2_id() << ":" << g.get_f2() << ", ";
	}
	return os;
}

template <class CharT, class Traits = std::char_traits<CharT>>
std::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT, Traits>& os, message& msg)
{
	os << msg.f1_id() << ": " << msg.get_f1() << ", "
		<< msg.f2_id() << ": " << msg.get_f2() << ", "
		<< msg.group1_id() << ": " << msg.get_group1() << ", "
		<< msg.group2_id() << ": " << msg.get_group2() << ", "
		<< msg.v_data1_id() << ": " << msg.get_v_data1();

	return os;
}
