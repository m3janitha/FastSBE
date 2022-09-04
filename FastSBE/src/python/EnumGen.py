class Indentaion:
	def __init__(self, indentation):
		self.indentation = indentation
		self.tab_size = 4
	def increment(self):
		self.indentation += 1

	def decrement(self):
		self.indentation -= 1

	def get_indentation_str(self):
		str = " " * self.tab_size * self.indentation
		return str

	def get_indented_str(self, content):
		indented_str = ""
		for line in content.splitlines():
			indented_str += self.get_indentation_str() + line + "\n"
		return indented_str

class FileGen:
	header_ct		= "#pragma once\n"
	include_ct		= "#include<{include_file}>\n"

	def __init__(self, indentation, file_name, namespace, include_list):
		self.indentation = indentation
		self.file_name = file_name
		self.namespace = namespace
		self.include_list = include_list
		self.content = ""

	def __del__(self):
		file_name_h = self.file_name + '.h'
		file = open(file_name_h,'w').write(self.content)
		print('delete FileGen')

	def gen_header(self):
		header_str = self.header_ct
		self.content += self.indentation.get_indented_str(header_str)

	def gen_includes(self, include_list = []):
		for include in include_list:
			include_str = self.include_ct.format(include_file = include)
			self.content += self.indentation.get_indented_str(include_str)

	class GenNameSpace:
		namespace_ct		= "\nnamespace {s_namespace}\n{{\n"
		namespace_end_ct	= "}\n"

		def gen_namespace_begin(self):
			namespace_str = self.namespace_ct.format(s_namespace = self.namespace)
			self.file_gen.content += self.indentation.get_indented_str(namespace_str)

		def gen_namespace_end(self):
			self.file_gen.content += self.indentation.get_indented_str(self.namespace_end_ct)

		def __init__(self, file_gen, indentation, namespace):
			self.file_gen = file_gen
			self.indentation = indentation
			self.namespace = namespace
			self.gen_namespace_begin()

		def __del__(self):
			self.gen_namespace_end()
			print('delte GenNameSpace')

	class GenClass:
		class_ct		= "\nclass {s_class_name}\n{{\n"
		class_end_ct	= "};\n"

		def gen_class_begin(self):
			class_str = self.class_ct.format(s_class_name = self.class_name)
			self.file_gen.content += self.indentation.get_indented_str(class_str)

		def gen_class_end(self):
			self.file_gen.content += self.indentation.get_indented_str(self.class_end_ct)

		def __init__(self, file_gen, indentation, class_name):
			self.file_gen = file_gen
			self.indentation = indentation
			self.class_name = class_name
			self.gen_class_begin()

		def __del__(self):
			self.gen_class_end()
			print('delte GenClass')

	def gen_file_begin(self):
		self.gen_header()
		self.gen_includes(include_list = self.include_list)
		
	def gen_content(self, content):
			self.content += content

#class GenFunction:
#	def __init__(self, *args, **kwargs):
#		return super().__init__(*args, **kwargs)

#class GenSwitch:
#	switch_begin_ct		= '''switch (value)
#	{\n'''
#	switch_case_ct		='''case Value::S_ENUM_VALUE:
#	return S_RET_VALUE;\n'''
#	switch_default_ct	='''default:
#	return S_DEFUAULT;\n'''
#	switch_end_ct		="}\n"

#	def __init__(self, switch_variable, default_value, values=[]):
#		self.switch_variable = switch_variable
#		self.values = values
#		self.default_value = default_value
#		self.content = ""

#	def gen_content():
#		self.content += self.switch_begin_ct.format()
#		for value in values:
#			(enum_val, ret_val) = value
#			self.content += self.switch_case_ct.format(S_ENUM_VALUE = enum_val, S_RET_VALUE = ret_val)
#		self.content += self.switch_default_ct.format(S_DEFUAULT = self.default_value)
#		self.content += self.switch_end_ct.format()

#	switch_content = GenSwitch(switch_variable = 'value', default_value = 'Invalid', values = self.values)
#	self.file_gen.content += self.indentation.get_indented_str(self.switch_content)

class EnumClassFileGen:
	class EnumDef:
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
			print('delete EnumDef')

	def gen_enum_class_content(self):
		enum_def = self.EnumDef(file_gen = self.file_gen, indentation = self.indentation, enum_name = self.enum_name, encoding_type = self.encoding_type, values = self.values)
		print('XXX')

	def __init__(self, namespace, enum_name, encoding_type, values):
		self.namespace = namespace
		self.enum_name = enum_name
		self.encoding_type = encoding_type
		self.values = values
		include_list = ["cstdint", "string", "string_view", "ostream"]

		self.indentation = Indentaion(0)
		self.file_gen = FileGen(indentation = self.indentation, file_name = self.enum_name, namespace = "sbe::test", include_list = include_list)
		self.file_gen.gen_file_begin()
		namespace = self.file_gen.GenNameSpace(file_gen = self.file_gen, indentation = self.indentation, namespace = self.namespace)
		class_ = self.file_gen.GenClass(file_gen = self.file_gen, indentation = self.indentation, class_name = self.enum_name)
		self.gen_enum_class_content()

	def __del__(self):
		print('delete EnumClassFileGen')
		