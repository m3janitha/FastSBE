
private:
	#pragma pack(push, 1)
	char buffer_[S_FIELD_SIZE]{};
	#pragma pack(pop)

	const char *buffer() const
	{
		return buffer_;
	}

	char *buffer()
	{
		return buffer_;
	}

