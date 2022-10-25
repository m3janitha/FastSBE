
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
	
	static constexpr const char* S_FIELD_NAME_name() noexcept
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

	constexpr std::string_view get_S_FIELD_NAME_view() noexcept
	{ 
		return std::string_view(S_FIELD_NAME_, S_FIELD_SIZE);
	}

	constexpr const std::string_view get_S_FIELD_NAME_view() const noexcept
	{ 
		return std::string_view(S_FIELD_NAME_, S_FIELD_SIZE);
	}

	auto& set_S_FIELD_NAME(const char* value) noexcept
	{
	#if defined(__GNUG__)
	#pragma GCC diagnostic push
	#pragma GCC diagnostic ignored "-Wstringop-overflow"
	#endif		
		//auto length = strlen(value);
		std::memcpy(S_FIELD_NAME_, value, S_FIELD_NAME_size());
		return *this;
	#if defined(__GNUG__)
	#pragma GCC diagnostic pop
	#endif			
	}

	auto& set_S_FIELD_NAME(std::string_view value) noexcept
	{
	#if defined(__GNUG__)
	#pragma GCC diagnostic push
	#pragma GCC diagnostic ignored "-Wstringop-overflow"
	#endif		
		//constexpr auto size = std::min(S_FIELD_NAME_size(), value.size());
		//auto size = std::min(S_FIELD_NAME_size(), value.size());
		std::memcpy(S_FIELD_NAME_, value.data(), S_FIELD_NAME_size());
		return *this;
	#if defined(__GNUG__)
	#pragma GCC diagnostic pop
	#endif			
	}

