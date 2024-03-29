import xml.etree.ElementTree as ET
import logging

from MessageGen import MessageGen
from Metadata import Metadata
from EnumGen import EnumClassGen
from GroupGen import GroupGen
from VariableLengthDataGen import VariableLengthDataGen
from FileGen import ContentHandler
from FileGen import Indentaion
from FileGen import *

class Parser:
	def get_null_value_of_primitive(self, type):
		null_value = Metadata.defult_null[type]
		# if minValue or maxValue or nullValue attrib defined by user, override
		if('nullValue' in type):
			null_value = type['nullValue']
		return null_value


	def get_numeric_attrib_of_primitive(self, type):
		min_value = Metadata.defult_minimum[type]
		max_value = Metadata.defult_maximum[type]
		null_value = Metadata.defult_null[type]
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
		if (primitive_type in Metadata.primitive_types):
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
	#parse all type in types section
	def parse_all_types(self, types):
		for type in types.iter('type'):
			type_name = type.attrib['name']
			self.user_defined_types.update({type_name : type.attrib})


	def update_enum_attrib(self, type):
		items = type.items()
		enum_attrib = {}
		for (key, value) in items:
			enum_attrib[key] = value
		
		encoding_type = type.attrib['encodingType']
		if encoding_type in Metadata.primitive_types:
			return enum_attrib
		else:
			if (encoding_type in self.user_defined_types):
				type_attrib = self.user_defined_types[encoding_type]
				enum_attrib.update(type_attrib)
			else:
				logging.error('%s is not defined in types', encoding_type)
				exit()

		logging.debug('enum_attrib %s', enum_attrib)
		return enum_attrib


	def update_field_attrib(self, field):
		items = field.items()
		field_attrib = {}
		for (key, value) in items:
			field_attrib[key] = value

		field_type = field.attrib['type']

		if (field_type in Metadata.primitive_types):
			return field_attrib
		else:
			if (field_type in self.user_defined_types):
				type_attrib = self.user_defined_types[field_type]
				field_attrib.update(type_attrib)
			else:
				logging.error('%s is not defined in types', field_type)
				exit()

		logging.debug('field_attrib %s', field_attrib)
		return field_attrib


	def update_type_attrib(self, field):
		items = field.items()
		field_attrib = {}
		for (key, value) in items:
			field_attrib[key] = value

		l = lambda attrib: attrib['type'] if('type' in attrib)\
		   else ( attrib['primitiveType'] if 'primitiveType' in attrib else None)
		field_type = l(field.attrib)

		if (field_type in Metadata.primitive_types):
			return field_attrib
		else:
			if (field_type in self.user_defined_types):
				type_attrib = self.user_defined_types[field_type]
				field_attrib.update(type_attrib)
			else:
				logging.error('%s is not defined in types', field_type)
				exit()

		logging.debug('field_attrib %s', field_attrib)
		return field_attrib


	def get_primitive_encoding_type(self, enum_attrib):
		if 'primitiveType' in enum_attrib:
			return enum_attrib['primitiveType']
		elif 'encodingType' in enum_attrib:
			return enum_attrib['encodingType']
		else:
			logging.error('type or primitiveType is not defined in %s', enum_attrib['name']) 
			exit()


	def get_primitive_type(self, field_attrib):
		if 'primitiveType' in field_attrib:
			return field_attrib['primitiveType']
		elif 'type' in field_attrib:
			return field_attrib['type']
		else:
			logging.error('type or primitiveType is not defined in %s', field_attrib['name']) 
			exit()

	def get_enum_null_value(self, enum_attrib):
		#defined anywhere in the fields
		enum_name = enum_attrib['name']
		xpath = ".//*[@name='" + enum_name + "']"
		field = self.root.find(xpath)

		primitive_encoding_type = self.get_primitive_encoding_type(enum_attrib)
		(min_value, max_value, null_value) = self.get_numeric_attrib_of_primitive(primitive_encoding_type)
		if 'nullValue' in field:
			null_value = field['nullValue']

		return 'nullValue', null_value

	def generate_enum(self, type):
		enum_values = []
		for field in type:
			enum_values.append((field.attrib['name'], field.text))		

		enum_name = type.attrib['name']
		encoding_type = type.attrib['encodingType']
		#if type is user defined
		enum_attrib = self.update_enum_attrib(type = type)
		primitive_encoding_type = self.get_primitive_encoding_type(enum_attrib)
		enum_values.append(self.get_enum_null_value(enum_attrib))
		handler = ContentHandler()
		enum_file = EnumClassGen(handler, enum_name, Metadata.c_field_types[primitive_encoding_type]\
			, enum_values, self.namespace)
		self.user_defined_enums.append(enum_name)

		system_includes = ["cstdint", "string", "string_view", "ostream", "cstring"]
		handler.user_includes = []
		indentation = Indentaion(0)
		FileGen(indentation = indentation, out_folder = self.out_folder\
			, file_name = enum_name, namespace = self.namespace\
			, system_includes = system_includes, handler = handler)


	# read all enum in types
	def parse_all_enums(self, types):
		for type in types.iter('enum'):
			self.generate_enum(type)


	def get_composite_type(self, type):
		if('type' in type.attrib):
			return type.attrib['type']
		elif('primitiveType' in type.attrib):
			return type.attrib['primitiveType']


	def get_enum_const_value(field):
		if 'valueRef' in field.attrib:
			return field.attrib['valueRef'].split('.')[1]
		else:
			return field.text

	def get_enum_type(field):
		if 'valueRef' in field.attrib:
			return field.attrib['valueRef'].split('.')[0]
		else:
			return field.attrib['type']


	def generate_composite_type(self, field_gen, composite_name, type, prvious_type_name):
		type_name = type.attrib['name']
		composite_type = self.get_composite_type(type)
		includes = []
		
		#enum
		if('valueRef' in type.attrib.keys()):
			composite_type = Parser.get_enum_type(type)

		if(composite_type in self.user_defined_enums):
			includes.append(composite_type)
			if(self.is_const_type(type.attrib)):
				logging.debug('const enum field: %s', type_name)
				field_gen.gen_composite_const_enum_field_def(message_name = composite_name, field_type = composite_type\
					, field_name = type_name, prvious_field_name = prvious_type_name\
					, value = Parser.get_enum_const_value(type))
				return type_name, includes
			else:
				logging.debug('enum field: %s', type_name)
				null_value = 0
				field_gen.gen_composite_enum_field_def(message_name = composite_name, field_type = composite_type\
					, field_name = type_name, prvious_field_name = prvious_type_name\
					, null = null_value)
				return type_name, includes
		
		field_attrib =  self.update_type_attrib(field = type)
		primitive_type = self.get_primitive_type(type.attrib)
		field_type = Metadata.c_field_types[primitive_type]

		#string
		if(self.is_string_field(primitive_type, field_attrib)):
			if(self.is_const_type(type.attrib)):
				logging.debug('const string field: %s', type_name)
				field_gen.gen_composite_const_string_field_def(message_name = composite_name\
					, field_type = field_type\
					, field_name = type_name, prvious_field_name = prvious_type_name, field_size = type.attrib['length']\
					, value = type.text)
				return type_name, includes
			else:
				logging.debug('const string field: %s', type_name)
				field_gen.gen_composite_string_field_def(message_name = composite_name\
					, field_type = field_type\
					, field_name = type_name, prvious_field_name = prvious_type_name, field_size = type.attrib['length'])
				return type_name, includes
		
		#numric
		if(self.is_numeric(primitive_type, type.attrib) == True):
			if(('presence' in type.attrib) and (type.attrib['presence'] == 'constant')):
				field_gen.gen_composite_const_numeric_field_def(message_name = composite_name\
					, field_type = field_type\
					, field_name = type_name, prvious_field_name = prvious_type_name\
					, value = type.text)
				return type_name, includes
			else:
				(min_value, max_value, null_value) = self.get_numeric_attrib_of_primitive(primitive_type)
				field_gen.gen_composite_numeric_field_def(message_name = composite_name\
					, field_type = field_type\
					, field_name = type_name, prvious_field_name = prvious_type_name\
					, min = min_value, max = max_value, null = null_value)
				return type_name, includes
		else:
			logging.error('field type or primitive type is not defined in: %s', type_name)
			exit()


	# description is an optional attribute
	def get_description(message):
		if 'description' in message.attrib:
			return message.attrib['description']
		else:
			return ""

	def generate_composite_class(self, composite, handler):
		composite_name = composite.attrib['name']
		description = Parser.get_description(composite)
		msg_gen = MessageGen(handler = handler, message_name = composite_name, message_id = 0\
			, schema = self.schema_id, version = self.schema_version, description = description, namespace = self.namespace)

		msg_gen.field_gen.gen_ostream_begin()
		prvious_type_name = "";
		for type in composite.iter('type'):
			prvious_type_name, includes = self.generate_composite_type(msg_gen.field_gen, composite_name, type\
				, prvious_type_name)
		msg_gen.field_gen.gen_ostream_end()
		msg_gen.field_gen.gen_constructor()

	def generate_composite(self, composite):
		composite_name = composite.attrib['name']
		logging.debug('generate_composite: %s ' , composite_name)		

		handler = ContentHandler()
		self.generate_composite_class(composite, handler)

		system_includes = ["cstdint", "string", "string_view", "ostream", "cstring"]
		indentation = Indentaion(0)
		FileGen(indentation = indentation, out_folder = self.out_folder\
			, file_name = composite_name, namespace = self.namespace\
			, system_includes = system_includes, handler = handler)


	def parse_all_composites(self, types):
		for composite in types.iter('composite'):
			composite_name = composite.attrib['name']
			self.user_defined_composites.append(composite_name)
			self.generate_composite(composite)


	def generate_message_field(self, field_gen, message_name, field, prvious_field_name, is_group, group_name):
		field_name = field.attrib['name']
		field_id = field.attrib['id']
		field_type = field.attrib['type']

		#enum
		if(field_type in self.user_defined_enums):
			if(self.is_const_type(field.attrib)):
				logging.debug('const enum field: %s', field_name)
				field_gen.gen_message_const_enum_field_def(message_name = message_name, field_type = field_type\
					, field_id = field_id, field_name = field_name, prvious_field_name = prvious_field_name\
					, value = Parser.get_enum_const_value(field), is_group = is_group, group_name = group_name)
				return field_name
			else:
				logging.debug('enum field: %s', field_name)
				null_value = 0
				field_gen.gen_message_enum_field_def(message_name = message_name, field_type = field_type\
					, field_id = field_id, field_name = field_name, prvious_field_name = prvious_field_name\
					, null = null_value, is_group = is_group, group_name = group_name)
				return field_name

		#composite
		if(field_type in self.user_defined_composites):
			logging.debug('composite field: %s', field_name)
			field_gen.gen_message_composite_field_def(message_name = message_name, field_type = field_type\
				, field_id = field_id, field_name = field_name, prvious_field_name = prvious_field_name\
				, is_group = is_group, group_name = group_name)
			return field_name

		# combine field.attrib and type attrib
		field_attrib = self.update_field_attrib(field)
		primitive_type = self.get_primitive_type(field_attrib)

		#string
		if(self.is_string_field(primitive_type, field_attrib)):
			if(self.is_const_type(field_attrib)):
				logging.debug('const string field: %s', field_name)
				field_gen.gen_message_const_string_field_def(message_name = message_name\
					, field_type = Metadata.c_field_types[primitive_type]\
					, field_id = field_id, field_name = field_name, prvious_field_name = prvious_field_name\
					, field_size = field_attrib['length']\
					, value = field.text, is_group = is_group, group_name = group_name)
				return field_name

			else:
				logging.debug('const string field: %s', field_name)
				field_gen.gen_message_string_field_def(message_name = message_name\
					, field_type = Metadata.c_field_types[primitive_type]\
					, field_id = field_id, field_name = field_name, prvious_field_name = prvious_field_name\
					, field_size = field_attrib['length'], is_group = is_group, group_name = group_name)
				return field_name

		#numeric
		if(self.is_numeric(primitive_type, field_attrib) == True):
			logging.debug('const numeric field: %s', field_name)
			if(('presence' in field_attrib) and (field_attrib['presence'] == 'constant')):
				field_gen.gen_message_const_numeric_field_def(message_name = message_name\
					, field_type = Metadata.c_field_types[primitive_type]\
					, field_id = field_id, field_name = field_name, prvious_field_name = prvious_field_name\
					, value = field.text, is_group = is_group, group_name = group_name)
				return field_name
			else:
				logging.debug('numeric field: %s', field_name)
				(min_value, max_value, null_value) = self.get_numeric_attrib_of_primitive(primitive_type)
				field_gen.gen_message_numeric_field_def(message_name = message_name\
					, field_type = Metadata.c_field_types[primitive_type]\
					, field_id = field_id, field_name = field_name, prvious_field_name = prvious_field_name\
					, min = min_value, max = max_value, null = null_value, is_group = is_group, group_name = group_name)
				return field_name

		logging.error('field type or primitive type is not defined in: %s', field_name)
		exit()

		return field_name


	def generate_group_fields(self, msg_gen, handler, group_gen, group, message_name):

		data_gen = group_gen.GroupDataGen(handler = handler, indentation = msg_gen.indentation
									, namespace = self.namespace)
		group_name = group.attrib['name']

		data_gen.field_gen.gen_ostream_group_begin(group_name, message_name)
		prvious_field_name = ""
		for field in group:
			if (field.tag == 'field'):
				prvious_field_name = self.generate_message_field(data_gen.field_gen\
					, group_name, field, prvious_field_name, is_group = True, group_name = group_name)
		data_gen.field_gen.gen_ostream_group_end()


	def update_group_size_encoding_types(group_size_encoding_type_entry, composite, index):
		type = composite[index]
		default_type_name = Metadata.default_group_size_encoding_names[index].lower()
		if (type.attrib['name'].lower() != default_type_name):
			logging.error('invalid group size encoding. expected %s confiured %s'\
				, default_type_name.lower(), type.attrib['name'].lower())
			exit()
		else:
			group_size_encoding_type = { 
				"name": type.attrib['name'], 
				"type" : Metadata.c_field_types[type.attrib['primitiveType']]  
			}
			group_size_encoding_type_entry.append(group_size_encoding_type)


	def parse_group_size_encoding_header(self, dimension_type):
		if(dimension_type in self.group_size_encoding_types.keys()):
			return self.group_size_encoding_types[dimension_type]
		else:
			xpath = ".//*[@name='" + dimension_type + "']"
			composite = self.root.find(xpath)
			group_size_encoding_type = []
			field_count = len(composite)
			if(field_count < 2):
				logging.error('invalid group size encoding. expected at least 2 field')
				exit()
			elif(field_count == 2):
				Parser.update_group_size_encoding_types(group_size_encoding_type, composite, 0)
				Parser.update_group_size_encoding_types(group_size_encoding_type, composite, 1)
			elif(field_count == 4):
				Parser.update_group_size_encoding_types(group_size_encoding_type, composite, 0)
				Parser.update_group_size_encoding_types(group_size_encoding_type, composite, 1)
				Parser.update_group_size_encoding_types(group_size_encoding_type, composite, 2)
				Parser.update_group_size_encoding_types(group_size_encoding_type, composite, 3)
		
			self.group_size_encoding_types.update({dimension_type : group_size_encoding_type})
			logging.debug('update group size encoding. %s', group_size_encoding_type)
			return group_size_encoding_type


	def update_variable_data_encoding_types(variable_data_encoding_type_entry, composite, index):
		type = composite[index]
		default_type_name = Metadata.default_variable_data_encoding_names[index].lower()
		if (type.attrib['name'].lower() != default_type_name):
			logging.error('invalid variable data encoding. expected %s confiured %s'\
				, default_type_name.lower(), type.attrib['name'].lower())
			exit()
		else:
			variable_data_encoding_type = { 
				"name": type.attrib['name'], 
				"type" : Metadata.c_field_types[type.attrib['primitiveType']]  
			}
			variable_data_encoding_type_entry.append(variable_data_encoding_type)


	def parse_variable_data_encoding_header(self, type):
		if(type in self.variable_data_encoding_types.keys()):
			return self.variable_data_encoding_types[type]
		else:
			xpath = ".//*[@name='" + type + "']"
			composite = self.root.find(xpath)
			variable_data_encoding_type = []
			field_count = len(composite)
			if(field_count < 2):
				logging.error('invalid variable data encoding. expected at least 2 field')
				exit()
			elif(field_count == 2):
				Parser.update_variable_data_encoding_types(variable_data_encoding_type, composite, 0)
				Parser.update_variable_data_encoding_types(variable_data_encoding_type, composite, 1)		

			self.variable_data_encoding_types.update({type : variable_data_encoding_type})
			logging.debug('variable data encoding. %s', variable_data_encoding_type)
			return variable_data_encoding_type


	def generate_nested_group(self, msg_gen, handler, group, message_name, dimension):
		group_name = group.attrib['name']
		group_id = group.attrib['id']
		dimension_type = group.attrib['dimensionType']
		
		group_gen = GroupGen(handler = handler, indentation = msg_gen.indentation\
			, name = group_name, id = group_id, message_name = message_name, namespace = self.namespace\
			, dimension_type = dimension_type)

		self.generate_group_fields(msg_gen, handler, group_gen, group, message_name)

		dimension_type_count = len(dimension)
		if(dimension_type_count == 2):
			msg_gen.field_gen.gen_nested_group_def(group_name = group_name, dimension_type = dimension_type\
				, block_length_name = dimension[0]['name']\
				, num_in_group_name = dimension[1]['name'], num_in_group_type = dimension[1]['type'])

		elif(dimension_type_count == 4):
			msg_gen.field_gen.gen_nested_group_def_4(group_name = group_name, dimension_type = dimension_type\
				, block_length_name = dimension[0]['name']\
				, num_in_group_name = dimension[1]['name'], num_in_group_type = dimension[1]['type']\
				, num_groups_type = dimension[2]['type']\
				, num_var_data_field_type = dimension[3]['type'])


	def parse_group(self, msg_gen, handler, message_name, group, prvious_field_name):
		group_name = group.attrib['name']
		group_id = group.attrib['id']
		dimension_type = group.attrib['dimensionType']

		dimension = self.parse_group_size_encoding_header(dimension_type)

		self.generate_nested_group(msg_gen, handler, group, message_name, dimension)

		dimension_type_count = len(dimension)
		if(dimension_type_count == 2):
			msg_gen.field_gen.gen_group_def(group_name = group_name\
				, prvious_group_name = prvious_field_name, group_id = group_id\
				, dimension_type = dimension_type, block_length_name = 'blockLength'\
				, num_in_group_name = 'numInGroup', num_in_group_type = 'std::uint16_t')
		elif(dimension_type_count == 4):
			msg_gen.field_gen.gen_group_def_4(group_name = group_name
				, prvious_group_name = prvious_field_name, group_id = group_id\
				, dimension_type = dimension_type, block_length_name = dimension[0]['name']\
				, num_in_group_name = dimension[1]['name'], num_in_group_type = dimension[1]['type']\
				, num_groups_name = dimension[2]['name'], num_groups_type = dimension[2]['type']\
				, num_var_data_fields_name = dimension[3]['name'], num_var_data_fields_type = dimension[3]['type'])

		return group_name;


	def generate_nested_variable_length_data(self, msg_gen, handler, var_len_data, message_name, dimension):
		name = var_len_data.attrib['name']
		id = var_len_data.attrib['id']
		dimension_type = var_len_data.attrib['type']
		
		group_gen = VariableLengthDataGen(handler = handler, indentation = msg_gen.indentation\
			, name = name, id = id, message_name = message_name, namespace = self.namespace\
			, dimension_type = dimension_type)

		msg_gen.field_gen.gen_nested_variable_length_data_def(var_len_data_name = name, dimension_type = dimension_type\
			, dimension = dimension)		


	def parse_data(self, msg_gen, handler, message_name, var_len_data, prvious_var_len_data_name):
		name = var_len_data.attrib['name']
		id = var_len_data.attrib['id']
		dimension_type = var_len_data.attrib['type']

		dimension = self.parse_variable_data_encoding_header(dimension_type)
		self.generate_nested_variable_length_data(msg_gen, handler, var_len_data, message_name, dimension)

		msg_gen.field_gen.gen_variable_length_data_def(var_len_data_name = name\
			, prvious_var_len_data_name = prvious_var_len_data_name, var_len_data_id = id\
			, dimension_type = dimension_type, dimension = dimension)

		return name;
		

	def generate_message(self, message, handler):
		message_name = message.attrib['name']
		message_id = message.attrib['id']		
		description = Parser.get_description(message)

		msg_gen = MessageGen(handler = handler, message_name = message_name, message_id = message_id\
			, schema = self.schema_id, version = self.schema_version, description = description, namespace = self.namespace)

		msg_gen.field_gen.gen_ostream_begin()			
		is_group_section = False
		is_var_data_section = False
		prvious_field_name = "";
		for eliment in message:
			if (eliment.tag == 'field'):
				prvious_field_name = self.generate_message_field(msg_gen.field_gen, message_name, eliment\
					, prvious_field_name, is_group = False, group_name = '')
			elif(eliment.tag == 'group'):
				if(is_group_section == False):
					#this is the first group field
					is_group_section = True
					prvious_field_name = "";
					msg_gen.field_gen.gen_buffer_def(1024)					
					
				prvious_field_name = self.parse_group(msg_gen, handler, message_name, eliment\
					, prvious_field_name)

			elif(eliment.tag == 'data'):
				if(is_var_data_section == False):
					is_var_data_section = True
					#this is the first variable length data field
					if(is_group_section == True):
						#there was a group before data
						pass
					else:					
						prvious_field_name = "";					
						msg_gen.field_gen.gen_buffer_def(1024)
						is_fixed_length_section = False

				prvious_field_name = self.parse_data(msg_gen, handler, message_name, eliment\
					, prvious_field_name)

		msg_gen.field_gen.gen_ostream_end()


	def parse_message(self, message):
		message_name = message.attrib['name']
		logging.debug('message_name: %s', message_name)

		handler = ContentHandler()
		self.generate_message(message, handler)

		system_includes = ["cstdint", "string", "string_view", "ostream", "cstring"]
		indentation = Indentaion(0)
		FileGen(indentation = indentation, out_folder = self.out_folder\
			, file_name = message_name, namespace = self.namespace\
			, system_includes = system_includes, handler = handler)


	def parse_all_messages(self, root):
		messages = root.find('messages')
		if not messages:
			namespaces = {'sbe' : root.tag.split('}')[0].strip('{')}
			for message in root.iterfind('sbe:message', namespaces):
				self.parse_message(message)
		else:
			namespaces = {'sbe' : root.tag.split('}')[0].strip('{')}
			for message in messages.iterfind('sbe:message', namespaces):
				self.parse_message(message)

	def run(self):
		tree = ET.parse(self.schema_file)
		self.root = tree.getroot()
		self.schema_id = self.root.attrib['id']
		self.schema_version = self.root.attrib['version']
		logging.debug('schema_id: %s schema_version: %s', self.schema_id, self.schema_version)

		types = self.root.find('types')
		self.parse_all_types(types = types)
		self.parse_all_enums(types = types)
		self.parse_all_composites(types = types)
		self.parse_all_messages(root = self.root)



	def __init__(self, schema_file, out_folder, override_namespace):
		self.schema_file = schema_file
		self.out_folder = out_folder
		self.namespace = override_namespace

		self.user_defined_types = {}
		self.user_defined_enums = []
		self.user_defined_composites = []
		self.group_size_encoding_types = {}
		self.variable_data_encoding_types = {}

		self.run()

		logging.debug('end')