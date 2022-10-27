
private:
	#pragma pack(push, 1)
	S_GROUP_NAME S_GROUP_NAME_{};
	#pragma pack(pop)

public:
	static constexpr std::size_t S_GROUP_NAME_size() noexcept
	{
		return sizeof(S_GROUP_NAME::data);
	}

	static constexpr std::size_t S_GROUP_NAME_id() noexcept
	{ 
		return S_GROUP_ID; 
	}
	
	static constexpr const char* S_GROUP_NAME_name() noexcept
	{ 
		return "S_GROUP_NAME"; 
	}

	std::size_t S_GROUP_NAME_offset() const noexcept
	{
		return S_GROUP_OFFSET;
	}

	std::size_t S_GROUP_NAME_data_length() const noexcept
	{
		auto& group = get_S_GROUP_NAME();
		return group.header_.get_blockLength() * group.header_.get_S_NUM_IN_GROUP_NAME();
	}
	
	const S_GROUP_NAME& get_S_GROUP_NAME() const noexcept
	{ 
		const auto* buf = buffer() + S_GROUP_NAME_offset();
		return *reinterpret_cast<const S_GROUP_NAME*>(buf);
	}
	
	S_GROUP_NAME& get_S_GROUP_NAME() noexcept
	{
		auto* buf = buffer() + S_GROUP_NAME_offset();
		return *reinterpret_cast<S_GROUP_NAME*>(buf);
	}

	S_GROUP_NAME& append_S_GROUP_NAME(S_NUM_IN_GROUP_TYPE count) noexcept
	{
		auto* buf = buffer() + S_GROUP_NAME_offset();
		auto& group = *reinterpret_cast<S_GROUP_NAME*>(buf);
		group.header_.set_S_BLOCK_LENGTH_NAME(sizeof(S_GROUP_NAME::data));
		group.header_.set_S_NUM_IN_GROUP_NAME(count);
		group.header_.set_S_NUM_GROUPS_NAME(0);	// TODO
		group.header_.set_S_NUM_VAR_DATA_FIELDS_NAME(0);	// TODO
		return group;	
	}

