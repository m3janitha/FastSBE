
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
		return group.header_.get_blockLength() * group.header_.get_numInGroup();
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

	S_GROUP_NAME& append_S_GROUP_NAME(S_DIMENTION_COUNT_TYPE count) noexcept
	{
		auto* buf = buffer() + S_GROUP_NAME_offset();
		auto* group = new(buf) S_GROUP_NAME(count);
		return *group;
	}
