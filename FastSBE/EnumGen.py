import logging

from FileGen import Indentaion
from FileGen import FileGen
from FileGen import ClassGen

class SwitchForEnumGen:
	switch_begin_ct		='switch (value)\n{{\n'
	switch_case_ct		='case Value::{S_ENUM_VALUE}:\n    return "{S_ENUM_VALUE}";\n'
	switch_null_ct		='case Value::NULL:\n    return "{S_RET_VALUE}";\n'
	switch_default_ct	='default:\n    return "{S_DEFUAULT}";\n'
	switch_end_ct		='}}\n'


	def gen_content(self):
		self.content += self.switch_begin_ct.format()
		for value in self.values:
			(enum_val, ret_val) = value
			self.content += self.switch_case_ct.format(S_ENUM_VALUE = enum_val, S_RET_VALUE = ret_val)
		self.content += self.switch_default_ct.format(S_DEFUAULT = self.default_value)
		self.content += self.switch_end_ct.format()


	def gen_begin(self):
		self.indentation.increment()
		self.gen_content()


	def gen_end(self):
		self.content += self.switch_end_ct.format()
		self.indentation.decrement()


	def __init__(self, handler, indentation, switch_variable, default_value, values=[]):
		self.handler = handler
		self.indentation = indentation
		self.switch_variable = switch_variable
		self.values = values
		self.default_value = default_value
		self.content = ""

		self.gen_begin()
		self.handler.content += self.indentation.get_indented_str(self.content)


	def __del__(self):
		self.gen_end()
		logging.debug('delete SwitchForEnumGen')


class EnumClassGen:
	ostream_enum_def_ct	= open('metadata/c++/message/ostream_enum_def.h', 'r').read()

	class EnumDefinitionGen:
		enum_def_ct			= 'public:\nenum class Value : {encoding_type}\n{{\n'
		enum_def_end_ct		= '};\n'
		enum_value_ct		= '{S_ENUM_NAME} = {S_ENUM_VALUE},\n'


		def gen_enum_begin(self):
			self.indentation.increment()
			enum_def = self.enum_def_ct.format(encoding_type = self.encoding_type)
			self.handler.content += self.indentation.get_indented_str(enum_def)


		def gen_enum_end(self):
			self.handler.content += self.indentation.get_indented_str(self.enum_def_end_ct)
			self.indentation.decrement()


		def gen_enum_values(self, values, encoding_type):
			enum_ct = ""
			for value in values:
				(enum_name, enum_value) = value
				if (encoding_type == 'char'):
					if(enum_name.lower() != 'nullvalue'):
						enum_value = "'" + str(enum_value) + "'"
				enum_ct += self.enum_value_ct.format(S_ENUM_NAME = enum_name, S_ENUM_VALUE = enum_value)
				logging.debug('enum_name: %s, enum_value: %s' , enum_name, enum_value)
			
			self.indentation.increment()
			self.handler.content += self.indentation.get_indented_str(enum_ct)
			self.indentation.decrement()


		def __init__(self, handler, indentation, enum_name, encoding_type, values=[]):
			self.handler = handler
			self.indentation = indentation
			self.enum_name = enum_name
			self.encoding_type = encoding_type
			self.values = values

			self.gen_enum_begin()
			self.gen_enum_values(values = self.values, encoding_type = self.encoding_type)


		def __del__(self):
			self.gen_enum_end()
			logging.debug('delete EnumDefinitionGen')


	class EnumToStrFunctionGen:
		fuction_begin_ct = "\npublic:\nstatic constexpr const char* to_string(Value value) noexcept\n{{"
		fuction_end_ct = "}\n"


		def gen_function_begin(self):
			self.indentation.increment()
			function_begin_def = self.fuction_begin_ct.format()
			self.handler.content += self.indentation.get_indented_str(function_begin_def)


		def gen_function_end(self):
			self.handler.content += self.indentation.get_indented_str(self.fuction_end_ct)
			self.indentation.decrement()


		def __init__(self, handler, indentation, switch_variable, default_value, values=[]):
			self.handler = handler
			self.indentation = indentation

			self.gen_function_begin()
			switch_content = SwitchForEnumGen(handler = self.handler, indentation = self.indentation, switch_variable = 'value', default_value = 'Invalid', values = values)


		def __del__(self):
			self.gen_function_end()
			logging.debug('delete EnumToStrFunctionGen')


	def gen_enum_class_content(self):
		enum_def = self.EnumDefinitionGen(handler = self.handler, indentation = self.indentation, enum_name = self.enum_name, encoding_type = self.encoding_type, values = self.values)

	
	def gen_to_str_function(self):
			switch_content = self.EnumToStrFunctionGen(handler = self.handler, indentation = self.indentation, switch_variable = 'value', default_value = 'Invalid', values = self.values)


	def gen_ostream_enum_def(self, enum_name, namespace):
		field_def = self.ostream_enum_def_ct\
			.replace('S_ENUM_NAME', enum_name)\
			.replace('S_NAMESPACE', namespace)
		self.handler.ostream += field_def
		logging.debug('gen_ostream_field_def_begin')

	def __init__(self, handler, enum_name, encoding_type, values, namespace):
		self.handler = handler
		self.enum_name = enum_name
		self.encoding_type = encoding_type
		self.values = values
		self.content = ""

		self.indentation = Indentaion(0)
		class_gen = ClassGen(handler = self.handler, indentation = self.indentation\
			, class_name = self.enum_name)
		self.gen_enum_class_content()
		self.gen_to_str_function()		
		self.gen_ostream_enum_def(enum_name, namespace)


	def __del__(self):
		logging.debug('delete EnumClassGen')
		