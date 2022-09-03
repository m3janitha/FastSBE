
private:
	#pragma pack(push, 1)
	s_field_type field_{};
	#pragma pack(pop)

public:
	static constexpr std::size_t field_offset() noexcept 
	{ 
		return s_offset; 
	}

	static constexpr std::size_t field_id() noexcept 
	{ 
		return field_id; 
	}
	
	static constexpr const char* field_name() noexcept 
	{ 
		return "field"; 
	}
	
	static constexpr s_field_type min_value() noexcept 
	{ 
		return s_min; 
	}
	
	static constexpr s_field_type max_value() noexcept 
	{ 
		return s_max; 
	}
	
	static constexpr s_field_type null_value() noexcept 
	{ 
		return s_null; 
	}

	constexpr s_field_type get_field() const noexcept 
	{ 
		return field_; 
	}
	
	constexpr s_message_name& set_field(s_field_type value) noexcept
	{
		field_ = value;
		return *this;
	}

