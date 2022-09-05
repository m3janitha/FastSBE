from FileGen import Indentaion
from FileGen import FileGen

class SwitchForEnumGen:
	switch_begin_ct		= "switch (value)\n{{\n"
	switch_case_ct		="case Value::{S_ENUM_VALUE}:\nreturn {S_RET_VALUE};\n"
	switch_null_ct		="case Value::NULL:\nreturn {S_RET_VALUE};\n"
	switch_default_ct	="default:\nreturn {S_DEFUAULT};\n"
	switch_end_ct		="}}\n"

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

	def __init__(self, file_gen, indentation, switch_variable, default_value, values=[]):
		self.file_gen = file_gen
		self.indentation = indentation
		self.switch_variable = switch_variable
		self.values = values
		self.default_value = default_value
		self.content = ""

		self.gen_begin()
		self.file_gen.content += self.indentation.get_indented_str(self.content)

	def __del__(self):
		self.gen_end()
		print('delete SwitchForEnumGen')

class EnumClassFileGen:
	class EnumDefinitionGen:
		enum_def_ct		= "enum class Value : {encoding_type}\n{{\n"
		enum_def_end_ct = "};\n"
		enum_value_ct	= "{S_ENUM_NAME} = {S_ENUM_VALUE},\n"

		def gen_enum_begin(self):
			self.indentation.increment()
			enum_def = self.enum_def_ct.format(encoding_type = self.encoding_type)
			self.file_gen.content += self.indentation.get_indented_str(enum_def)

		def gen_enum_end(self):
			self.file_gen.content += self.indentation.get_indented_str(self.enum_def_end_ct)
			self.indentation.decrement()

		def gen_enum_values(self, values):
			enum_ct = ""
			for value in values:
				(enum_name, enum_value) = value
				enum_ct += self.enum_value_ct.format(S_ENUM_NAME = enum_name, S_ENUM_VALUE = enum_value)
				print(enum_name, enum_value)

			#enum_ct += self.enum_value_ct.format(S_ENUM_NAME = NULL, S_ENUM_VALUE = enum_value)
			
			self.indentation.increment()
			self.file_gen.content += self.indentation.get_indented_str(enum_ct)
			self.indentation.decrement()

		def __init__(self, file_gen, indentation, enum_name, encoding_type, values=[]):
			self.file_gen = file_gen
			self.indentation = indentation
			self.enum_name = enum_name
			self.encoding_type = encoding_type
			self.values = values

			self.gen_enum_begin()
			self.gen_enum_values(values = self.values)

		def __del__(self):
			self.gen_enum_end()
			print('delete EnumDefinitionGen')

	class EnumToStrFunctionGen:
		fuction_begin_ct = "\npublic:\nconst char* to_string(Value value) const noexcept\n{{"
		fuction_end_ct = "}\n"

		def gen_function_begin(self):
			self.indentation.increment()
			function_begin_def = self.fuction_begin_ct.format()
			self.file_gen.content += self.indentation.get_indented_str(function_begin_def)

		def gen_function_end(self):
			self.file_gen.content += self.indentation.get_indented_str(self.fuction_end_ct)
			self.indentation.decrement()

		def __init__(self, file_gen, indentation, switch_variable, default_value, values=[]):
			self.file_gen = file_gen
			self.indentation = indentation

			self.gen_function_begin()
			switch_content = SwitchForEnumGen(file_gen = self.file_gen, indentation = self.indentation, switch_variable = 'value', default_value = 'Invalid', values = values)

		def __del__(self):
			self.gen_function_end()
			print('delete EnumToStrFunctionGen')

	def gen_enum_class_content(self):
		enum_def = self.EnumDefinitionGen(file_gen = self.file_gen, indentation = self.indentation, enum_name = self.enum_name, encoding_type = self.encoding_type, values = self.values)
	
	def gen_to_str_function(self):
			switch_content = self.EnumToStrFunctionGen(file_gen = self.file_gen, indentation = self.indentation, switch_variable = 'value', default_value = 'Invalid', values = self.values)

	def __init__(self, namespace, enum_name, encoding_type, values, include_list):
		self.namespace = namespace
		self.enum_name = enum_name
		self.encoding_type = encoding_type
		self.values = values
		self.include_list = include_list

		self.indentation = Indentaion(0)
		self.file_gen = FileGen(indentation = self.indentation, file_name = self.enum_name, namespace = "sbe::test", include_list = self.include_list)
		namespace = self.file_gen.NameSpaceGen(file_gen = self.file_gen, indentation = self.indentation, namespace = self.namespace)
		class_ = self.file_gen.ClassGen(file_gen = self.file_gen, indentation = self.indentation, class_name = self.enum_name)
		self.gen_enum_class_content()
		self.gen_to_str_function()

	def __del__(self):
		print('delete EnumClassFileGen')
		