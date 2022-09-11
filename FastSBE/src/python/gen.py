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


	def get_null_value_of_primitive(self, type):
		null_value = self.defult_null[type]
		# if minValue or maxValue or nullValue attrib defined by user, override
		if('nullValue' in type):
			null_value = type['nullValue']
		return null_value


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


	#primitive_types are numeric
	def is_numeric(self, primitive_type, attrib):
		if (primitive_type in self.primitive_types):
			return True
		else:
			return False


	#primitive type char with length defiend and length == 1 is string
	def is_string_field(self, primitive_type, attrib):
		if ((primitive_type == 'char') and ('length' in attrib)):
			return True
		else:
			return False


	def is_const_type(self, field_attrib):
		if(('presence' in field_attrib) and (field_attrib['presence'] == 'constant')):
			return True
		else:
			return False


	#name,primitiveType,minValue,maxValue,nullValue,length,characterEncoding,presence
	#read all type in types section
	def read_all_types(self, types):
		user_defined_types = {}
		for type in types.iter('type'):
			type_name = type.attrib['name']
			user_defined_types.update({type_name : type.attrib})
		return user_defined_types

	def update_enum_attrib(self, field, user_defined_types):
		items = field.items()
		enum_attrib = {}
		for (key, value) in items:
			enum_attrib[key] = value
		
		encoding_type = field.attrib['encodingType']
		if encoding_type in self.primitive_types:
			return enum_attrib
		else:
			if (encoding_type in user_defined_types):
				type_attrib = user_defined_types[encoding_type]
				enum_attrib.update(type_attrib)
			else:
				print(encoding_type, ' is not defined in types')
				exit(self, 1)

		print('enum_attrib', enum_attrib)
		return enum_attrib


	def update_field_attrib(self, field, user_defined_types):
		items = field.items()
		field_attrib = {}
		for (key, value) in items:
			field_attrib[key] = value

		field_type = field.attrib['type']

		if (field_type in self.primitive_types):
			return field_attrib
		else:
			if (field_type in user_defined_types):
				type_attrib = user_defined_types[field_type]
				field_attrib.update(type_attrib)
			else:
				print(field_type, ' is not defined in types')
				exit(self, 1)

		print('field_attrib', field_attrib)
		return field_attrib

	def update_type_attrib(self, field, user_defined_types):
		items = field.items()
		field_attrib = {}
		for (key, value) in items:
			field_attrib[key] = value

		l = lambda attrib: attrib['type'] if('type' in attrib)\
		   else ( attrib['primitiveType'] if 'primitiveType' in attrib else None)
		field_type = l(field.attrib)

		if (field_type in self.primitive_types):
			return field_attrib
		else:
			if (field_type in user_defined_types):
				type_attrib = user_defined_types[field_type]
				field_attrib.update(type_attrib)
			else:
				print(field_type, ' is not defined in types')
				exit(self, 1)

		print('field_attrib', field_attrib)
		return field_attrib

	def get_primitive_encoding_type(self, enum_attrib):
		if 'primitiveType' in enum_attrib:
			return enum_attrib['primitiveType']
		elif 'encodingType' in enum_attrib:
			return enum_attrib['encodingType']
		else:
			print('type or primitiveType is not defined in', enum_attrib['name']) 
			exit(self,1)

	def get_primitive_type(self, field_attrib):
		if 'primitiveType' in field_attrib:
			return field_attrib['primitiveType']
		elif 'type' in field_attrib:
			return field_attrib['type']
		else:
			print('type or primitiveType is not defined in', field_attrib['name']) 
			exit(self,1)

	# read all enum in types
	def read_all_enums(self, types, user_defined_types):
		enum_include_list = ["cstdint", "string", "string_view", "ostream"]

		user_defined_enums =[];
		for type in types.iter('enum'):
			enum_values = []
			for field in type:
				print(field.text)
				enum_values.append((field.attrib['name'], field.text))

			enum_name = type.attrib['name']
			encoding_type = type.attrib['encodingType']
			#if type is user defined
			enum_attrib = self.update_enum_attrib(type, user_defined_types)
			primitive_encoding_type = self.get_primitive_encoding_type(enum_attrib)
			enum_file = EnumClassFileGen("sbe::test", enum_name, self.c_field_types[primitive_encoding_type], enum_values, enum_include_list)
			user_defined_enums.append(enum_name)
		return user_defined_enums

	def get_composite_type(self, type):
		if('type' in type.attrib):
			return type.attrib['type']
		elif('primitiveType' in type.attrib):
			return type.attrib['primitiveType']

	def read_composite_type(self, msg_gen, composite_name, type, prvious_type_name, user_defined_types\
		, user_defined_enums):
		type_name = type.attrib['name']
		composite_type = self.get_composite_type(type)
		
		#enum
		if(composite_type in user_defined_enums):
			if(self.is_const_type(type.attrib)):
				print ('const enum field:', type_name)
				msg_gen.gen_composite_const_enum_field_def(message_name = composite_name, field_type = composite_type\
					, field_name = type_name, prvious_field_name = prvious_type_name\
					, value = type.text)
				return type_name
			else:
				print ('enum field:', type_name)
				null_value = 0
				msg_gen.gen_composite_enum_field_def(message_name = composite_name, field_type = composite_type\
					, field_name = type_name, prvious_field_name = prvious_type_name\
					, null = null_value)
				return type_name
		
		field_attrib =  self.update_type_attrib(type, user_defined_types)
		primitive_type = self.get_primitive_type(type.attrib)

		#string
		if(self.is_string_field(primitive_type, field_attrib)):
			if(self.is_const_type(type.attrib)):
				print ('const string field:', type_name)
				msg_gen.gen_composite_const_string_field_def(message_name = composite_name, field_type = self.c_field_types[primitive_type]\
					, field_name = type_name, prvious_field_name = prvious_type_name, field_size = type.attrib['length']\
					, value = type.text)
				return type_name
			else:
				print ('const string field:', type_name)
				msg_gen.gen_composite_string_field_def(message_name = composite_name, field_type = self.c_field_types[primitive_type]\
					, field_name = type_name, prvious_field_name = prvious_type_name, field_size = type.attrib['length'])
				return type_name
		
		#numric
		if(self.is_numeric(primitive_type, type.attrib) == True):
			if(('presence' in type.attrib) and (type.attrib['presence'] == 'constant')):
				msg_gen.gen_composite_const_numeric_field_def(message_name = composite_name, field_type = self.c_field_types[primitive_type]\
					, field_name = type_name, prvious_field_name = prvious_type_name\
					, value = type.text)
				return type_name
			else:
				(min_value, max_value, null_value) = self.get_numeric_attrib_of_primitive(primitive_type)
				msg_gen.gen_composite_numeric_field_def(message_name = composite_name, field_type = self.c_field_types[primitive_type]\
					, field_name = type_name, prvious_field_name = prvious_type_name\
					, min = min_value, max = max_value, null = null_value)
				return type_name
		else:
			print ('field type or primitive type is not defined in :', type_name)
			exit(1)

		return type_name


	# description is an optional attribute
	def get_description(message):
		if 'description' in message.attrib:
			return message.attrib['description']
		else:
			return ""


	def gen_composite(self, composite, user_defined_types, user_defined_enums):
		composite_name = composite.attrib['name']
		description = Gen.get_description(composite)
		print('composite_name:' , composite_name, ' description:', description)
		
		include_list = ["cstdint", "string", "string_view", "ostream"]

		msg_gen = MessageGen(message_name = composite_name\
			, message_id = 0\
			, schema = self.schema_id\
			, version = self.schema_version\
			, description = description\
			, namespace = "test::sbe"\
			, include_list = include_list)

		prvious_type_name = "";
		for type in composite.iter('type'):
			prvious_type_name = self.read_composite_type(msg_gen, composite_name, type\
				, prvious_type_name, user_defined_types\
				, user_defined_enums)

		msg_gen.gen_end_of_fields()


	def read_all_composites(self, types, user_defined_types, user_defined_enums):
		user_defined_composites = []
		for composite in types.iter('composite'):
			composite_name = composite.attrib['name']
			user_defined_composites.append(composite_name)

		self.gen_composite(composite, user_defined_types, user_defined_enums)
		return user_defined_composites


	def read_message_field(self, msg_gen, message_name, field, prvious_field_name, user_defined_types\
		, user_defined_enums, user_defined_composites):
		field_name = field.attrib['name']
		field_id = field.attrib['id']
		field_type = field.attrib['type']

		#enum
		if(field_type in user_defined_enums):
			if(self.is_const_type(field.attrib)):
				print ('const enum field:', field_name)
				msg_gen.gen_message_const_enum_field_def(message_name = message_name, field_type = field_type\
					, field_id = field_id, field_name = field_name, prvious_field_name = prvious_field_name\
					, value = field.text)
				return field_name
			else:
				print ('enum field:', field_name)
				null_value = 0
				msg_gen.gen_message_enum_field_def(message_name = message_name, field_type = field_type\
					, field_id = field_id, field_name = field_name, prvious_field_name = prvious_field_name\
					, null = null_value)
				return field_name

		#composite
		if(field_type in user_defined_composites):
			print ('composite field:', field_name)
			msg_gen.gen_message_composite_field_def(message_name = message_name, field_type = field_type\
				, field_id = field_id, field_name = field_name, prvious_field_name = prvious_field_name)
			return field_name

		# combine field.attrib and type attrib
		field_attrib = self.update_field_attrib(field, user_defined_types)
		primitive_type = self.get_primitive_type(field_attrib)

		#string
		if(self.is_string_field(primitive_type, field_attrib)):
			if(self.is_const_type(field_attrib)):
				print ('const string field:', field_name)
				msg_gen.gen_message_const_string_field_def(message_name = message_name\
					, field_type = self.c_field_types[primitive_type]\
					, field_id = field_id, field_name = field_name, prvious_field_name = prvious_field_name\
					, field_size = field_attrib['length']\
					, value = field.text)
				return field_name

			else:
				print ('const string field:', field_name)
				msg_gen.gen_message_string_field_def(message_name = message_name\
					, field_type = self.c_field_types[primitive_type]\
					, field_id = field_id, field_name = field_name, prvious_field_name = prvious_field_name\
					, field_size = field_attrib['length'])
				return field_name

		#numeric
		if(self.is_numeric(primitive_type, field_attrib) == True):
			print ('const numeric field:', field_name)
			if(('presence' in field_attrib) and (field_attrib['presence'] == 'constant')):
				msg_gen.gen_message_const_numeric_field_def(message_name = message_name\
					, field_type = self.c_field_types[primitive_type]\
					, field_id = field_id, field_name = field_name, prvious_field_name = prvious_field_name\
					, value = field.text)
				return field_name
			else:
				print ('numeric field:', field_name)
				(min_value, max_value, null_value) = self.get_numeric_attrib_of_primitive(primitive_type)
				msg_gen.gen_message_numeric_field_def(message_name = message_name\
					, field_type = self.c_field_types[primitive_type]\
					, field_id = field_id, field_name = field_name, prvious_field_name = prvious_field_name\
					, min = min_value, max = max_value, null = null_value)
				return field_name

		print ('field type or primitive type is not defined in :', field_name)
		exit(1)

		return field_name


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
		user_defined_composites = self.read_all_composites(types, user_defined_types, user_defined_enums) 
		self.read_all_msgs(root, user_defined_types, user_defined_enums, user_defined_composites)
		
		#msg_gen = MessageGen(message_name = "NewOrder", id = 1, schema = 3, version = 4, description = "new order message", namespace = "test::sbe")
		#msg = msg_gen.generate_message()
		#file = open("NewOrder.h",'w').write(msg)

		print("end")

	def __init__(self):
		self.my_main()


gen = Gen()
		





