
public:
	static constexpr std::size_t S_FIELD_NAME_size() noexcept
	{
		return 0;
	}

	static constexpr std::size_t S_FIELD_NAME_offset() noexcept
	{ 
		return S_FIELD_OFFSET; 
	}

	static constexpr std::size_t S_FIELD_NAME_id() noexcept
	{ 
		return S_FIELD_ID; 
	}
	
	static constexpr const char* S_FIELD_NAME_name() noexcept
	{ 
		return "S_FIELD_NAME"; 
	}

	constexpr char* get_S_FIELD_NAME() noexcept
	{ 
		return S_CONST_FIELD_VALUE;
	}

	constexpr const char* get_S_FIELD_NAME() const noexcept
	{ 
		return S_CONST_FIELD_VALUE;
	}

	constexpr std::string_view get_S_FIELD_NAME_str() noexcept
	{ 
		return std::string_view(S_CONST_FIELD_VALUE, S_FIELD_SIZE);
	}

	constexpr const std::string_view get_S_FIELD_NAME_str() const noexcept
	{ 
		return std::string_view(S_CONST_FIELD_VALUE, S_FIELD_SIZE);
	}
