
public:
	static constexpr const char* name() noexcept
	{ 
		return "S_MESSAGE_NAME"; 
	}

	static constexpr std::size_t template_id() noexcept
	{ 
		return S_MESSAGE_ID; 
	}

	static constexpr std::size_t schema() noexcept
	{  
		return S_SCHEMA_ID; 
	}

	static constexpr std::size_t version() noexcept
	{ 
		return S_VERSION_ID; 
	}

	static constexpr const char* semantic_type() noexcept
	{ 
		return ""; 	
	}

