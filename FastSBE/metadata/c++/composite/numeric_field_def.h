
private:
	#pragma pack(push, 1)
	S_FIELD_TYPE S_FIELD_NAME_{};
	#pragma pack(pop)

public:
	static constexpr std::size_t S_FIELD_NAME_size() noexcept
	{
		return sizeof(S_FIELD_TYPE);
	}

	static constexpr std::size_t S_FIELD_NAME_offset() noexcept
	{ 
		return S_FIELD_OFFSET; 
	}
	
	static constexpr const char* S_FIELD_NAME_name() noexcept
	{ 
		return "S_FIELD_NAME"; 
	}
	
	static constexpr S_FIELD_TYPE S_FIELD_NAME_min_value() noexcept
	{ 
		return S_FIELD_MIN; 
	}
	
	static constexpr S_FIELD_TYPE S_FIELD_NAME_max_value() noexcept
	{
		return S_FIELD_MAX;
	}
	
	static constexpr S_FIELD_TYPE S_FIELD_NAME_null_value() noexcept
	{
	#if defined(__GNUG__)
	#pragma GCC diagnostic push
	#pragma GCC diagnostic ignored "-Wtype-limits"
	#endif
		return S_FIELD_NULL;
	#if defined(__GNUG__)
	#pragma GCC diagnostic pop
	#endif
	}

	constexpr S_FIELD_TYPE get_S_FIELD_NAME() const noexcept
	{ 
		return S_FIELD_NAME_;
	}
	
	constexpr S_MESSAGE_NAME& set_S_FIELD_NAME(S_FIELD_TYPE value) noexcept
	{
		S_FIELD_NAME_ = value;
		return *this;
	}

