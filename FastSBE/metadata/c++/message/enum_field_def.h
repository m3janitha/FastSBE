
private:
	#pragma pack(push, 1)
	S_FIELD_TYPE::Value S_FIELD_NAME_{};
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

	static constexpr std::size_t S_FIELD_NAME_id() noexcept
	{ 
		return S_FIELD_ID; 
	}

	static constexpr const char* S_FIELD_NAME_name() noexcept
	{ 
		return "S_FIELD_NAME"; 
	}

	static constexpr S_FIELD_TYPE::Value S_FIELD_NAME_null_value() noexcept
	{
		return S_FIELD_TYPE::Value::nullValue;
	}

	constexpr S_FIELD_TYPE::Value get_S_FIELD_NAME() const noexcept
	{ 
		return S_FIELD_NAME_;
	}
	
	constexpr auto& set_S_FIELD_NAME(S_FIELD_TYPE::Value value) noexcept
	{
		S_FIELD_NAME_ = value;
		return *this;
	}

