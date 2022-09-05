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

	def gen_header(self):
		header_str = self.header_ct
		self.content += self.indentation.get_indented_str(header_str)

	def gen_includes(self):
		for include in self.include_list:
			include_str = self.include_ct.format(include_file = include)
			self.content += self.indentation.get_indented_str(include_str)

	def gen_file_begin(self):
		self.gen_header()
		self.gen_includes()

	def __init__(self, indentation, file_name, namespace, include_list):
		self.indentation = indentation
		self.file_name = file_name
		self.namespace = namespace
		self.include_list = include_list
		self.content = ""

		print('create FileGen', self.file_name)
		self.gen_file_begin()

	def __del__(self):
		file_name_h = self.file_name + '.h'
		file = open(file_name_h,'w').write(self.content)
		print('delete FileGen', self.file_name)



	class NameSpaceGen:
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

			print('create NameSpaceGen', self.namespace)
			self.gen_namespace_begin()

		def __del__(self):
			self.gen_namespace_end()
			print('delte NameSpaceGen', self.namespace)

	class ClassGen:
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

			print('create ClassGen', self.class_name)
			self.gen_class_begin()

		def __del__(self):
			self.gen_class_end()
			print('delte ClassGen', self.class_name)
		
	def gen_content(self, content):
			self.content += content
