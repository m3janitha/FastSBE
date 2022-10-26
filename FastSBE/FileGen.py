import logging

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

class ClassGen:
	class_ct		= "\nclass {s_class_name}\n{{\n"
	class_end_ct	= "};\n"


	def gen_class_begin(self):
		class_str = self.class_ct.format(s_class_name = self.class_name)
		self.handler.content += self.indentation.get_indented_str(class_str)


	def gen_class_end(self):
		self.handler.content += self.indentation.get_indented_str(self.class_end_ct)


	def __init__(self, handler, indentation, class_name):
		self.handler = handler
		self.indentation = indentation
		self.class_name = class_name
		#self.namespace_gen = namespace_gen

		logging.debug('create ClassGen: %s', self.class_name)
		self.gen_class_begin()


	def __del__(self):
		self.gen_class_end()
		logging.debug('delte ClassGen %s', self.class_name)


class NameSpaceGen:
	namespace_ct		= "\nnamespace {s_namespace}\n{{\n"
	namespace_end_ct	= "\n}\n"


	def gen_namespace_begin(self):
		namespace_str = self.namespace_ct.format(s_namespace = self.namespace)
		self.content += self.indentation.get_indented_str(namespace_str)


	def gen_namespace_end(self):
		self.content += self.indentation.get_indented_str(self.namespace_end_ct)


	def __init__(self, content, indentation, namespace):
		self.content = content
		self.indentation = indentation
		self.namespace = namespace

		logging.debug('create NameSpaceGen: %s', self.namespace)
		self.gen_namespace_begin()


	def __del__(self):
		self.gen_namespace_end()
		logging.debug('delte NameSpaceGen: %s', self.namespace)


class FileGen:
	header_ct		= "#pragma once\n"
	include_ct		= "#include<{include_file}>\n"

	namespace_ct	= "\nnamespace {s_namespace}\n{{\n"
	namespace_end_ct= "}\n"


	def gen_header(self):
		header_str = self.header_ct
		self.content += self.indentation.get_indented_str(header_str)


	def gen_includes(self, include_list):
		for include in include_list:
			include_str = self.include_ct.format(include_file = include)
			self.content += self.indentation.get_indented_str(include_str)

	def gen_user_includes(self, include_list):
		for include in include_list:
			include_file = include + '.h'
			include_str = self.include_ct.format(include_file = include_file)
			self.content += self.indentation.get_indented_str(include_str)


	def gen_content(self, content):
			self.content += content


	def gen_ostream(self):
			self.content += self.ostream_var
			self.content += self.ostream


	def gen_namespace_begin(self):
		namespace_str = self.namespace_ct.format(s_namespace = self.namespace)
		self.content += self.indentation.get_indented_str(namespace_str)


	def gen_namespace_end(self):
		self.content += self.indentation.get_indented_str(self.namespace_end_ct)


	def gen_file_begin(self):
		self.gen_header()
		self.gen_includes(self.system_includes)
		self.gen_user_includes(self.user_includes)
		self.gen_namespace_begin()

	def gen_stream_operator(self):
		self.content += self.indentation.get_indented_str(namespace_str)


	def gen_file_end(self):
		self.gen_ostream()
		self.gen_namespace_end()		


	def __init__(self, indentation, out_folder, file_name, namespace\
		, system_includes, handler):
		self.out_folder = out_folder
		self.indentation = indentation
		self.file_name = file_name
		self.namespace = namespace
		self.system_includes = system_includes
		self.user_includes = handler.user_includes
		content = handler.content
		self.ostream = handler.ostream
		self.ostream_var = handler.ostream_var
		self.content = ""

		logging.debug('create FileGen: %s', self.file_name)
		self.gen_file_begin()
		#self.file_gen = FileGen(indentation = self.indentation, out_folder = self.out_folder\
		#	, file_name = self.enum_name, namespace = "sbe::test", include_list = self.include_list)
		#namespace_gen = NameSpaceGen(content = self.content, indentation = self.indentation\
		#	, namespace = self.namespace)
		self.gen_content(content)

	def __del__(self):
		self.gen_file_end()
		file_name_h = self.out_folder + '/' + self.file_name + '.h'
		file = open(file_name_h,'w').write(self.content)
		logging.debug('delete FileGen: %s', self.file_name)

class ContentHandler:
	def __init__(self):
		self.content = ""
		self.user_includes =[]
		self.ostream = ""
		self.ostream_var = ""
		self.field_type_and_name = []

