
private:
#pragma pack(push, 1)
	S_DIMENTION_TYPE header_{};
#pragma pack(pop)

public:
	S_GROUP_NAME() = default;
	S_GROUP_NAME(S_DIMENTION_COUNT_TYPE count)
		:header_(sizeof(S_GROUP_NAME::data), count) {}

	// data& get(S_GROUP_NAME& group, std::size_t group_id) noexcept
	// {
	// 	auto* buffer = reinterpret_cast<char*>(&group) + sizeof(S_DIMENTION_TYPE)
	// 		+ (header_.get_S_DIMENTION_SIZE_NAME() * group_id);
	// 	return *reinterpret_cast<data*>(buffer);
	// }
	data& get(std::size_t group_id) noexcept
	{
		auto* buffer = reinterpret_cast<char*>(&this->header_) + sizeof(S_DIMENTION_TYPE)
			+ (this->header_.get_S_DIMENTION_SIZE_NAME() * group_id);
		//auto offset2 = sizeof(S_DIMENTION_TYPE) +(this->header_.get_S_DIMENTION_SIZE_NAME() * group_id);
		return *reinterpret_cast<data*>(buffer);
	}

	// const data& get(const S_GROUP_NAME& group, std::size_t group_id) const noexcept
	// {
	// 	auto* buffer = reinterpret_cast<const char*>(&group) + sizeof(S_DIMENTION_TYPE)
	// 		+ (header_.get_S_DIMENTION_SIZE_NAME() * group_id);
	// 	return *reinterpret_cast<const data*>(buffer);
	// }
	const data& get(std::size_t group_id) const noexcept
	{
		auto* buffer = reinterpret_cast<const char*>(&this->header_) + sizeof(S_DIMENTION_TYPE)
			+ (this->header_.get_S_DIMENTION_SIZE_NAME() * group_id);
		//auto offset2 = sizeof(S_DIMENTION_TYPE) +(this->header_.get_S_DIMENTION_SIZE_NAME() * group_id);
		return *reinterpret_cast<const data*>(buffer);
	}

	const auto get_blockLength() const noexcept
	{
		return header_.get_blockLength();
	}

	const auto get_numInGroup() const noexcept
	{
		return header_.get_numInGroup();
	}

