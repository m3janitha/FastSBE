
class Metadata:
	primitive_types = {
		"int8",	
		"uint8",	
		"int16",
		"uint16",
		"int32",	
		"uint32",
		"int64",	
		"uint64",
		"char",
		}

	c_field_types = {
		"int8"	: "std::int8_t",
		"uint8"	: "std::uint8_t",
		"int16"	: "std::int16_t",
		"uint16": "std::uint16_t",
		"int32"	: "std::int32_t",
		"uint32": "std::uint32_t",
		"int64"	: "std::int64_t",
		"uint64": "std::uint64_t",
		"char"	: "char"
		}

	defult_minimum = {
		"int8"	: 0,
		"uint8"	: -1,
		"int16"	: 0,
		"uint16": -1,
		"int32"	: 0,
		"uint32": -1,
		"int64"	: 0,
		"uint64": -1,
		"char"	: 0,
	}

	defult_maximum = {
		"int8"	: 100,
		"uint8"	: 100,
		"int16"	: 100,
		"uint16": 100,
		"int32"	: 100,
		"uint32": 100,
		"int64"	: 100,
		"uint64": 100,
		"char"	: 255,
	}

	defult_null = {
		"int8"	: 100,
		"uint8"	: 100,
		"int16"	: 100,
		"uint16": 100,
		"int32"	: 100,
		"uint32": 100,
		"int64"	: 100,
		"uint64": 100,
		"char"	: 255,
	}
