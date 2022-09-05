import xml.etree.ElementTree as ET
from MessageGen import MessageGen
from EnumGen import EnumClassFileGen

class Gen:
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

	def get_numeric_attrib_of_primitive(self, type):
		min_value = self.defult_minimum[type]
		max_value = self.defult_maximum[type]
		null_value = self.defult_null[type]
		# if minValue or maxValue or nullValue attrib defined by user, override
		if('minValue' in type):
			min_value = type['minValue']
		if('maxValue' in type):
			max_value = type['maxValue']
		if('nullValue' in type):
			null_value = type['nullValue']
		return min_value, max_value, null_value

	#name,primitiveType,minValue,maxValue,nullValue,length,characterEncoding,presence
	#read all type in types section
	def read_all_types(self, types):
		user_defined_types = {}
		for type in types.iter('type'):
			type_name = type.attrib['name']
			user_defined_types.update({type_name : type.attrib})
		return user_defined_types

	def get_primitive_type(self, type, user_defined_types):
		if type in self.primitive_types:
			return type
		else:
			type_attrib = user_defined_types[type]
			#user defined type must have a primitiveType
			primitive_type = type_attrib['primitiveType']
			return primitive_type


	# read all enum in types
	def read_all_enums(self, types, user_defined_types):
		enum_include_list = ["cstdint", "string", "string_view", "ostream"]

		user_defined_enums =[];
		for type in types.iter('enum'):
			enum_values = []
			for field in type:
				print(field.text)
				enum_values.append((field.attrib['name'], field.text))

			type_name = type.attrib['name']
			encoding_type = type.attrib['encodingType']
			#if type is user defined
			primitive_encoding_type = self.get_primitive_type(encoding_type, user_defined_types)
			enum_file = EnumClassFileGen("sbe::test", type_name, primitive_encoding_type, enum_values, enum_include_list)
			user_defined_enums.append(type_name)
		return user_defined_enums

	def read_all_composites(self, types):
		user_defined_composites = []
		for composite in types.iter('composite'):
			composite_name = composite.attrib['composite']
			user_defined_composites.append(composite_name)
		return user_defined_composites

	#primitive type char with length defiend is string
	#any other primitive type is numeric
	def is_numeric(self, primitive_type, attrib):
		if ((primitive_type == 'char') and ('length' in attrib)):
			return False
		else:
			return True

	def read_message_field(self, msg_gen, message_name, field, prvious_field_name, user_defined_types\
		, user_defined_enums, user_defined_composites):
		field_name = field.attrib['name']
		field_id = field.attrib['id']
		field_type = field.attrib['type']

		if(field_type in user_defined_enums):
			print ('enum field:', field_name)
		elif(field_type in user_defined_composites):
			print ('composite field:', field_name)

		#numeirc or string
		primitive_type = self.get_primitive_type(field_type, user_defined_types)

		if(self.is_numeric(field_type, field.attrib) == True):
			if(('presence' in field.attrib) and (field.attrib['presence'] == 'constant')):
				msg_gen.gen_const_numeric_field_def(message_name = message_name, field_type = self.c_field_types[field_type]\
					, field_id = field_id, field_name = field_name, prvious_field_name = prvious_field_name\
					, value = field.text)
			else:
				(min_value, max_value, null_value) = self.get_numeric_attrib_of_primitive(primitive_type)
				msg_gen.gen_numeric_field_def(message_name = message_name, field_type = self.c_field_types[primitive_type]\
					, field_id = field_id, field_name = field_name, prvious_field_name = prvious_field_name\
					, min = min_value, max = max_value, null = null_value)
		elif(primitive_type =='char'):
			msg_gen.gen_string_field_def(message_name = message_name, field_type = self.c_field_types[primitive_type]\
				, field_id = field_id, field_name = field_name, prvious_field_name = prvious_field_name, field_size = type['length'])
		else:
			print ('undefined type field:', field_name, ' primitive_type:', primitive_type)

		return field_name

		#elif (field_type in user_defined_types):
		#	type = user_defined_types[field_type]
		#	primitive_type = type['primitiveType'] 
		#	if(is_numeric(primitive_type) == True):
		#		(min_value, max_value, null_value) = get_numeric_attrib_of_primitive(primitive_type)
		#		msg_gen.gen_numeric_field_def(message_name = message_name, field_type = c_field_types[primitive_type]\
		#			, field_id = field_id, field_name = field_name, prvious_field_name = prvious_field_name\
		#			, min = min_value, max = max_value, null = null_value)
		#	elif (primitive_type == 'char'):
		#		msg_gen.gen_string_field_def(message_name = message_name, field_type = c_field_types[primitive_type]\
		#			, field_id = field_id, field_name = field_name, prvious_field_name = prvious_field_name, field_size = type['length'])

		#return field_name

	def read_message(self, message, user_defined_types, user_defined_enums, user_defined_composites):
		message_name = message.attrib['name']
		message_id = message.attrib['id']
		message_description = message.attrib['description']
		print('message_name:' , message_name, ' message_id:', message_id, ' message_description:', message_description)
		
		include_list = ["cstdint", "string", "string_view", "ostream"]

		msg_gen = MessageGen(message_name = message_name\
			, message_id = message_id\
			, schema = self.schema_id\
			, version = self.schema_version\
			, description = message_description\
			, namespace = "test::sbe"\
			, include_list = include_list)

		namespaces = {'sbe': 'http://fixprotocol.io/2016/sbe'}
		prvious_field_name = "";	
		for field in message.iterfind('field', namespaces):
			prvious_field_name = self.read_message_field(msg_gen, message_name, field, prvious_field_name, user_defined_types\
				, user_defined_enums, user_defined_composites)

		msg_gen.gen_end_of_fields()

	def read_all_msgs(self, root, user_defined_types, user_defined_enums, user_defined_composites):
		namespaces = {'sbe': 'http://fixprotocol.io/2016/sbe'}
		for message in root.iterfind('sbe:message', namespaces):
			self.read_message(message, user_defined_types, user_defined_enums, user_defined_composites)


	def my_main(self):		
		tree = ET.parse('example-schema.xml')
		root = tree.getroot()
		self.schema_id = root.attrib['id']
		self.schema_version = root.attrib['version']
		print('schema_id:' , self.schema_id, ' schema_version:', self.schema_version)

		types = root.find('types')
		user_defined_types = self.read_all_types(types)
		user_defined_enums = self.read_all_enums(types, user_defined_types)
		user_defined_composites = self.read_all_composites(types) 
		self.read_all_msgs(root, user_defined_types, user_defined_enums, user_defined_composites)
		
		#msg_gen = MessageGen(message_name = "NewOrder", id = 1, schema = 3, version = 4, description = "new order message", namespace = "test::sbe")
		#msg = msg_gen.generate_message()
		#file = open("NewOrder.h",'w').write(msg)

		print("end")

	def __init__(self):
		self.my_main()


gen = Gen()
		





