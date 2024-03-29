
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

	static constexpr std::size_t S_FIELD_NAME_id() noexcept
	{
		return S_FIELD_ID;
	}

	static constexpr const char *S_FIELD_NAME_name() noexcept
	{
		return "S_FIELD_NAME";
	}

	constexpr const S_FIELD_TYPE &get_S_FIELD_NAME() const noexcept
	{
		return S_FIELD_NAME_;
	}

	constexpr S_FIELD_TYPE &get_S_FIELD_NAME() noexcept
	{
		return S_FIELD_NAME_;
	}
	constexpr auto &set_S_FIELD_NAME(S_FIELD_TYPE &value) noexcept
	{
		S_FIELD_NAME_ = value;
		return *this;
	}

