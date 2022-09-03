
public:
	static constexpr const char* name() noexcept
	{ 
		return "s_message_name"; 
	}

	static constexpr std::size_t template_id() noexcept
	{ 
		return s_message_id; 
	}

	static constexpr std::size_t schema() noexcept
	{  
		return s_schema; 
	}

	static constexpr std::size_t version() noexcept
	{ 
		return s_version; 
	}

	static constexpr const char* semantic_type() noexcept
	{ 
		return ""; 	
	}

