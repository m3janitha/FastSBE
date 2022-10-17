
private:
#pragma pack(push, 1)
	S_DIAMENTION_TYPE header_{};
#pragma pack(pop)

public:
	S_VAR_LEN_DATA_NAME() = default;

	std::basic_string_view<S_VAR_LEN_DATA_VAR_DATA_TYPE> get() noexcept
	{
		auto* buffer = reinterpret_cast<char*>(&this->header_) + sizeof(S_DIAMENTION_TYPE);
		return {reinterpret_cast<S_VAR_LEN_DATA_VAR_DATA_TYPE*>(buffer), this->header_.get_S_VAR_LEN_DATA_LENGTH_NAME()};
	}

	const std::basic_string_view<S_VAR_LEN_DATA_VAR_DATA_TYPE> get() const noexcept
	{
		auto* buffer = reinterpret_cast<const char*>(&this->header_) + sizeof(S_DIAMENTION_TYPE);
		return {reinterpret_cast<const S_VAR_LEN_DATA_VAR_DATA_TYPE*>(buffer), this->header_.get_S_VAR_LEN_DATA_LENGTH_NAME()};
	}

	const auto get_S_VAR_LEN_DATA_LENGTH_NAME() const noexcept
	{
		return header_.get_S_VAR_LEN_DATA_LENGTH_NAME();
	}

