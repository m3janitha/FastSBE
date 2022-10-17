import logging

from FileGen import Indentaion
from FileGen import ClassGen
from MessageGen import FieldGen

class VariableLengthDataGen:
	group_qulifiyer_def_ct = open('metadata/c++/message/group_qulifiyer_def.h', 'r').read()
	group_class_qulifiyer_def_ct = 'public:'

	def gen_qulifiyer_def(self, message_name):
			field_def = self.group_qulifiyer_def_ct\
				.replace('S_MESSAGE_NAME', message_name)
			self.handler.content += self.indentation.get_indented_str(field_def)
			

	def __init__(self, handler, indentation, name, id, message_name, namespace, dimension_type):
		self.handler = handler
		self.indentation = indentation
		self.name = name
		self.id = id
		self.dimension_type = dimension_type

		logging.debug('create VariableLengthDataGen: %s', self.name)
		self.handler.content += self.indentation.get_indented_str(self.group_class_qulifiyer_def_ct)
		self.class_gen = ClassGen(handler = self.handler, indentation = self.indentation\
			, class_name = self.name)

		self.gen_qulifiyer_def(message_name)


	def __del__(self):
		logging.debug('delete GroupGen: %s', self.name)


