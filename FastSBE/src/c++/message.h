#pragma once
#include <cstdint>
#include <string>
#include <string_view>
#include <ostream>

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

enum class enum_1 : char
{
	VALUE1 = '1',
	VALUE2 = '2'
};

const char* to_string(enum_1 value)
{
	switch (value)
	{
	case enum_1::VALUE1:
		return "1";
	case enum_1::VALUE2:
		return "2";
	default:
		return "Invalid";
	}
}

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

struct message
{
	static constexpr std::size_t f1_offset() noexcept { return 0; }

	using f1_type = std::uint32_t;
#pragma pack(push, 1)
	f1_type f1_{};
#pragma pack(pop)

	char* buffer() noexcept { return reinterpret_cast<char*>(&f1_); }
	const char* buffer() const noexcept { return reinterpret_cast<const char*>(&f1_); }

	constexpr f1_type get_f1() const noexcept { return f1_; }
	constexpr message& set_f1(f1_type value) noexcept
	{
		f1_ = value;
		return *this;
	}
	static constexpr std::size_t f1_id() noexcept { return 1; }
	static constexpr f1_type min_value() noexcept { return 90; }
	static constexpr f1_type max_value() noexcept { return 110; }

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

	constexpr char* get_m3() noexcept { return f3_; }
	constexpr const char* get_m3() const noexcept { return f3_; }

	constexpr std::string_view get_ms3_str() noexcept { return std::string_view(f3_, 5); }
	constexpr const std::string_view get_ms3_str() const noexcept { return std::string_view(f3_, 5); }

	static constexpr std::size_t f3_id() noexcept { return 3; }

	constexpr std::size_t group1_offset() const noexcept { return f3_offset() + sizeof(f3_); }
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
		auto* buf = buffer() + group1_offset();
		return *reinterpret_cast<group1*>(buf);
	}

	const group1& get_group1() const noexcept 
	{ 
		const auto* buf = buffer() + group1_offset();
		return *reinterpret_cast<const group1*>(buf); 
	}

	group1& append_group1(std::uint16_t count) noexcept
	{
		auto* buf = buffer() + group1_offset();
		auto* group = new(buf) group1(count);
		return *group;
	}

	constexpr std::size_t group2_offset() const noexcept { return group1_offset() + sizeof(group1::group_header) + (group1_.header_.get_size() * group1_.header_.get_count()); }
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
		auto* buf = buffer() + group2_offset();
		auto* group = new(buf) group2(count);
		return *group;
	}

	constexpr std::size_t v_data1_offset() const noexcept { return group2_offset() + sizeof(group2::group_header) + (group2_.header_.get_size() * group2_.header_.get_count()); }
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
