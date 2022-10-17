
private:
	#pragma pack(push, 1)
	S_VAR_LEN_DATA_NAME S_VAR_LEN_DATA_NAME_{};
	#pragma pack(pop)

public:
	static constexpr std::size_t S_VAR_LEN_DATA_NAME_size() noexcept
	{
		return 0;
	}

	static constexpr std::size_t S_VAR_LEN_DATA_NAME_id() noexcept
	{ 
		return S_VAR_LEN_DATA_ID; 
	}
	
	static constexpr const char* S_VAR_LEN_DATA_NAME_name() noexcept
	{ 
		return "S_VAR_LEN_DATA_NAME"; 
	}

	std::size_t S_VAR_LEN_DATA_NAME_offset() const noexcept
	{
		return S_VAR_LEN_DATA_OFFSET;
	}

	std::size_t S_VAR_LEN_DATA_NAME_data_length() const noexcept
	{
		auto& data = get_S_VAR_LEN_DATA_NAME();
		return data.header_.get_S_VAR_LEN_DATA_LENGTH_NAME();
	}
	
	const S_VAR_LEN_DATA_NAME& get_S_VAR_LEN_DATA_NAME() const noexcept
	{ 
		const auto* buf = buffer() + S_VAR_LEN_DATA_NAME_offset();
		return *reinterpret_cast<const S_VAR_LEN_DATA_NAME*>(buf);
	}
	
	S_VAR_LEN_DATA_NAME& get_S_VAR_LEN_DATA_NAME() noexcept
	{
		auto* buf = buffer() + S_VAR_LEN_DATA_NAME_offset();
		return *reinterpret_cast<S_VAR_LEN_DATA_NAME*>(buf);
	}

	S_VAR_LEN_DATA_NAME& append_S_VAR_LEN_DATA_NAME(S_VAR_LEN_DATA_LENGTH_TYPE length) noexcept
	{
		auto* buf = buffer() + S_VAR_LEN_DATA_NAME_offset();
		auto& data = *reinterpret_cast<S_VAR_LEN_DATA_NAME*>(buf);
		data.header_.set_S_VAR_LEN_DATA_LENGTH_NAME(length);
		return data;	
	}
