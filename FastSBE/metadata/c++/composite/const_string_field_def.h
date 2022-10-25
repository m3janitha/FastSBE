
public:
	static constexpr std::size_t S_FIELD_NAME_size() noexcept
	{
		return 0;
	}

	static constexpr std::size_t S_FIELD_NAME_offset() noexcept
	{
		return S_FIELD_OFFSET;
	}

	static constexpr const char *S_FIELD_NAME_name() noexcept
	{
		return "S_FIELD_NAME";
	}

	constexpr const char *get_S_FIELD_NAME() noexcept
	{
		return "S_CONST_FIELD_VALUE";
	}

	constexpr const char *get_S_FIELD_NAME() const noexcept
	{
		return "S_CONST_FIELD_VALUE";
	}

	constexpr std::string_view get_S_FIELD_NAME_view() noexcept
	{
		return std::string_view("S_CONST_FIELD_VALUE", S_FIELD_SIZE);
	}

	constexpr const std::string_view get_S_FIELD_NAME_view() const noexcept
	{
		return std::string_view("S_CONST_FIELD_VALUE", S_FIELD_SIZE);
	}

	std::string get_S_FIELD_NAME_string() noexcept
	{
		return std::string("S_CONST_FIELD_VALUE", S_FIELD_SIZE);
	}

	const std::string get_S_FIELD_NAME_string() const noexcept
	{
		return std::string("S_CONST_FIELD_VALUE", S_FIELD_SIZE);
	}
