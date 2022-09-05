
private:
	#pragma pack(push, 1)
	char S_FIELD_NAME_[S_FIELD_SIZE]{};
	#pragma pack(pop)

public:
	static constexpr std::size_t S_FIELD_NAME_size() noexcept
	{
		return S_FIELD_SIZE;
	}

	static constexpr std::size_t S_FIELD_NAME_offset() noexcept
	{ 
		return S_FIELD_OFFSET; 
	}

	static constexpr std::size_t S_FIELD_NAME_id() noexcept
	{ 
		return S_FIELD_ID; 
	}
	
	static constexpr const char* S_FIELD_NAME_name() const noexcept
	{ 
		return "S_FIELD_NAME"; 
	}

	constexpr char* get_S_FIELD_NAME() noexcept
	{ 
		return S_FIELD_NAME_;
	}

	constexpr const char* get_S_FIELD_NAME() const noexcept
	{ 
		return S_FIELD_NAME_;
	}

	constexpr std::string_view get_S_FIELD_NAME_str() noexcept
	{ 
		return std::string_view(S_FIELD_NAME_, 5);
	}

	constexpr const std::string_view get_S_FIELD_NAME_str() const noexcept
	{ 
		return std::string_view(S_FIELD_NAME_, 5);
	}

	constexpr message& set_S_FIELD_NAME(const char* value) noexcept
	{
		auto length = strlen(value);
		std::memcpy(f3_, value, length);
		return *this;
	}

	constexpr message& set_S_FIELD_NAME(std::string_view value) noexcept
	{
		constexpr auto size = std::min(S_FIELD_NAME_size(), value.size());
		std::memcpy(f3_, value.data(), size);
		return *this;
	}

