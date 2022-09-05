from FileGen import Indentaion
from FileGen import FileGen

class MessageGen:
    message_def_ct = open('c++/message_def.h', 'r').read()
    numeric_field_ct = open('c++/numeric_field_def.h', 'r').read()
    const_numeric_field_ct = open('c++/const_numeric_field_def.h', 'r').read()
    string_field_ct = open('c++/string_field_def.h', 'r').read()

    def gen_message_descriptor(self):
        message_def = self.message_def_ct\
            .replace('S_MESSAGE_NAME', self.message_name)\
            .replace('S_MESSAGE_ID', str(self.message_id))\
            .replace('S_SCHEMA_ID', str(self.schema))\
            .replace('S_VERSION_ID', str(self.version))
        self.file_gen.content += self.indentation.get_indented_str(message_def)

    def __init__(self, message_name, message_id, schema, version, description, namespace, include_list):
        self.message_name = message_name
        self.message_id = message_id
        self.schema = schema
        self.version = version
        self.description = description
        self.namespace = namespace
        self.include_list = include_list
        self.content = ""

        print('create MessageGen', self.message_name)
        self.indentation = Indentaion(0)
        self.file_gen = FileGen(indentation = self.indentation, file_name = self.message_name, namespace = "sbe::test", include_list = self.include_list)
        self.namespace = self.file_gen.NameSpaceGen(file_gen = self.file_gen, indentation = self.indentation, namespace = self.namespace)
        self.class_ = self.file_gen.ClassGen(file_gen = self.file_gen, indentation = self.indentation, class_name = self.message_name)
        
        self.indentation.increment()
        self.gen_message_descriptor()

    def __del__(self):
        print('delete MessageGen', self.message_name)

    def get_field_offset(self, prvious_field_name):
        if(prvious_field_name ==""):
            return '0';
        else:
            return prvious_field_name + '_offset() + ' + prvious_field_name + '_size()'
    
    def gen_numeric_field_def(self, message_name, field_type, field_id, field_name, prvious_field_name, min, max, null):
        field_def = self.numeric_field_ct\
            .replace('S_MESSAGE_NAME', message_name)\
            .replace('S_FIELD_TYPE', field_type)\
            .replace('S_FIELD_OFFSET', self.get_field_offset(prvious_field_name))\
            .replace('S_FIELD_ID', str(field_id))\
            .replace('S_FIELD_NAME', field_name)\
            .replace('S_FIELD_MIN', str(min))\
            .replace('S_FIELD_MAX', str(max))\
            .replace('S_FIELD_NULL', str(null))
        self.file_gen.content += self.indentation.get_indented_str(field_def)
        print('gen_numeric_field_def', field_name)

    def gen_const_numeric_field_def(self, message_name, field_type, field_id, field_name, prvious_field_name, value):
        field_def = self.const_numeric_field_ct\
            .replace('S_MESSAGE_NAME', message_name)\
            .replace('S_FIELD_TYPE', field_type)\
            .replace('S_FIELD_OFFSET', self.get_field_offset(prvious_field_name))\
            .replace('S_FIELD_ID', str(field_id))\
            .replace('S_FIELD_NAME', field_name)\
            .replace('S_CONST_FIELD_VALUE', str(value))
        self.file_gen.content += self.indentation.get_indented_str(field_def)
        print('gen_numeric_field_def', field_name)

    def gen_string_field_def(self, message_name, field_type, field_id, field_name, prvious_field_name, field_size):
        field_def = self.string_field_ct\
            .replace('S_MESSAGE_NAME', message_name)\
            .replace('S_FIELD_TYPE', field_type)\
            .replace('S_FIELD_OFFSET', self.get_field_offset(prvious_field_name))\
            .replace('S_FIELD_ID', str(field_id))\
            .replace('S_FIELD_NAME', field_name)\
            .replace('S_FIELD_SIZE', field_size)
        self.file_gen.content += self.indentation.get_indented_str(field_def)
        print('gen_string_field_def', field_name)

    def gen_end_of_fields(self):
        self.indentation.decrement()

    def generate_message(self):
        self.gen_includes()
        self.gen_namespace_begin()
        self.gen_class_begin()
        self.gen_message_descriptor()
        self.gen_numeric_field_def(message_name = self.message_name\
            , field_type = "std::uint32_t"\
            , field_id = 1\
            , field_name = "price"\
            , min = 30\
            , max = 99\
            , null = 255)
        return self.content
