
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
		"int8"	: -127,
		"uint8"	: 0,
		"int16"	: -32767,
		"uint16": 0,
		"int32"	: -2147483647,
		"uint32": 0,
		"int64"	: -9223372036854775807,
		"uint64": 0,
		"char"	: 32,
	}

	defult_maximum = {
		"int8"	: 127,
		"uint8"	: 254,
		"int16"	: 32767,
		"uint16": 65534,
		"int32"	: 2147483647,
		"uint32": 4294967294,
		"int64"	: 9223372036854775807,
		"uint64": 18446744073709551614,
		"char"	: 255,
	}

	defult_null = {
		"int8"	: -128,
		"uint8"	: 255,
		"int16"	: -32768,
		"uint16": 65535,
		"int32"	: -2147483648,
		"uint32": 4294967295,
		"int64"	: -9223372036854775808,
		"uint64": 18446744073709551615,
		"char"	: 0,
	}
