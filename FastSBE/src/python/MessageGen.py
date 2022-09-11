from FileGen import Indentaion
from FileGen import FileGen

class MessageGen:
    message_def_ct                  = open('c++/message/message_def.h', 'r').read()
    #numeirc
    message_numeric_field_ct        = open('c++/message/numeric_field_def.h', 'r').read()
    message_const_numeric_field_ct  = open('c++/message/const_numeric_field_def.h', 'r').read()
    #enum
    message_enum_field_ct           = open('c++/message/enum_field_def.h', 'r').read()
    message_const_enum_field_ct     = open('c++/message/const_enum_field_def.h', 'r').read()
    #string
    message_string_field_ct         = open('c++/message/string_field_def.h', 'r').read()
    message_const_string_field_ct   = open('c++/message/const_string_field_def.h', 'r').read()
    #composite
    message_composite_field_ct      = open('c++/message/composite_field_def.h', 'r').read()
    
    #numeirc
    composite_numeric_field_ct      = open('c++/composite/numeric_field_def.h', 'r').read()
    composite_const_numeric_field_ct= open('c++/composite/const_numeric_field_def.h', 'r').read()
    #enum
    composite_enum_field_ct         = open('c++/composite/enum_field_def.h', 'r').read()
    composite_const_enum_field_ct   = open('c++/composite/const_enum_field_def.h', 'r').read()
    #string
    composite_string_field_ct       = open('c++/composite/string_field_def.h', 'r').read()
    composite_const_string_field_ct = open('c++/composite/const_string_field_def.h', 'r').read()

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


    def gen_message_numeric_field_def(self, message_name\
        , field_type, field_id, field_name, prvious_field_name\
        , min, max, null):
        field_def = self.message_numeric_field_ct\
            .replace('S_MESSAGE_NAME', message_name)\
            .replace('S_FIELD_ID', str(field_id))\
            .replace('S_FIELD_TYPE', field_type)\
            .replace('S_FIELD_OFFSET', self.get_field_offset(prvious_field_name))\
            .replace('S_FIELD_NAME', field_name)\
            .replace('S_FIELD_MIN', str(min))\
            .replace('S_FIELD_MAX', str(max))\
            .replace('S_FIELD_NULL', str(null))
        self.file_gen.content += self.indentation.get_indented_str(field_def)
        print('gen_message_numeric_field_def', field_name)

    def gen_composite_numeric_field_def(self, message_name\
        , field_type, field_name, prvious_field_name\
        , min, max, null):
        field_def = self.composite_numeric_field_ct\
            .replace('S_MESSAGE_NAME', message_name)\
            .replace('S_FIELD_TYPE', field_type)\
            .replace('S_FIELD_OFFSET', self.get_field_offset(prvious_field_name))\
            .replace('S_FIELD_NAME', field_name)\
            .replace('S_FIELD_MIN', str(min))\
            .replace('S_FIELD_MAX', str(max))\
            .replace('S_FIELD_NULL', str(null))
        self.file_gen.content += self.indentation.get_indented_str(field_def)
        print('gen_composite_numeric_field_def', field_name)


    def gen_message_const_numeric_field_def(self, message_name\
        , field_type, field_id, field_name, prvious_field_name, value):
        field_def = self.message_const_numeric_field_ct\
            .replace('S_MESSAGE_NAME', message_name)\
            .replace('S_FIELD_ID', str(field_id))\
            .replace('S_FIELD_TYPE', field_type)\
            .replace('S_FIELD_OFFSET', self.get_field_offset(prvious_field_name))\
            .replace('S_FIELD_NAME', field_name)\
            .replace('S_CONST_FIELD_VALUE', str(value))
        self.file_gen.content += self.indentation.get_indented_str(field_def)
        print('gen_message_const_numeric_field_def', field_name)

    def gen_composite_const_numeric_field_def(self, message_name\
        , field_type, field_name, prvious_field_name, value):
        field_def = self.composite_const_numeric_field_ct\
            .replace('S_MESSAGE_NAME', message_name)\
            .replace('S_FIELD_TYPE', field_type)\
            .replace('S_FIELD_OFFSET', self.get_field_offset(prvious_field_name))\
            .replace('S_FIELD_NAME', field_name)\
            .replace('S_CONST_FIELD_VALUE', str(value))
        self.file_gen.content += self.indentation.get_indented_str(field_def)
        print('gen_composite_const_numeric_field_def', field_name)


    def gen_message_enum_field_def(self, message_name\
        , field_type, field_id, field_name, prvious_field_name\
        , null):
        field_def = self.message_enum_field_ct\
            .replace('S_MESSAGE_NAME', message_name)\
            .replace('S_FIELD_ID', str(field_id))\
            .replace('S_FIELD_TYPE', field_type)\
            .replace('S_FIELD_OFFSET', self.get_field_offset(prvious_field_name))\
            .replace('S_FIELD_NAME', field_name)\
            .replace('S_FIELD_NULL', str(null))
        self.file_gen.content += self.indentation.get_indented_str(field_def)
        print('gen_message_enum_field_def', field_name)

    def gen_composite_enum_field_def(self, message_name\
        , field_type, field_name, prvious_field_name\
        , null):
        field_def = self.composite_enum_field_ct\
            .replace('S_MESSAGE_NAME', message_name)\
            .replace('S_FIELD_TYPE', field_type)\
            .replace('S_FIELD_OFFSET', self.get_field_offset(prvious_field_name))\
            .replace('S_FIELD_NAME', field_name)\
            .replace('S_FIELD_NULL', str(null))
        self.file_gen.content += self.indentation.get_indented_str(field_def)
        print('gen_composite_enum_field_def', field_name)


    def gen_message_const_enum_field_def(self, message_name\
        , field_type, field_id, field_name, prvious_field_name, value):
        field_def = self.message_const_enum_field_ct\
            .replace('S_MESSAGE_NAME', message_name)\
            .replace('S_FIELD_ID', str(field_id))\
            .replace('S_FIELD_TYPE', field_type)\
            .replace('S_FIELD_OFFSET', self.get_field_offset(prvious_field_name))\
            .replace('S_FIELD_NAME', field_name)\
            .replace('S_CONST_FIELD_VALUE', str(value))
        self.file_gen.content += self.indentation.get_indented_str(field_def)
        print('gen_message_const_enum_field_def', field_name)

    def gen_composite_const_enum_field_def(self, message_name\
        , field_type, field_name, prvious_field_name, value):
        field_def = self.composite_const_enum_field_ct\
            .replace('S_MESSAGE_NAME', message_name)\
            .replace('S_FIELD_TYPE', field_type)\
            .replace('S_FIELD_OFFSET', self.get_field_offset(prvious_field_name))\
            .replace('S_FIELD_NAME', field_name)\
            .replace('S_CONST_FIELD_VALUE', str(value))
        self.file_gen.content += self.indentation.get_indented_str(field_def)
        print('gen_composite_const_enum_field_def', field_name)


    def gen_message_string_field_def(self, message_name, field_type, field_id, field_name\
        , prvious_field_name, field_size):
        field_def = self.message_string_field_ct\
            .replace('S_MESSAGE_NAME', message_name)\
            .replace('S_FIELD_ID', str(field_id))\
            .replace('S_FIELD_TYPE', field_type)\
            .replace('S_FIELD_OFFSET', self.get_field_offset(prvious_field_name))\
            .replace('S_FIELD_NAME', field_name)\
            .replace('S_FIELD_SIZE', field_size)
        self.file_gen.content += self.indentation.get_indented_str(field_def)
        print('gen_message_string_field_def', field_name)

    def gen_composite_string_field_def(self, message_name, field_type, field_name\
        , prvious_field_name, field_size):
        field_def = self.composite_string_field_ct\
            .replace('S_MESSAGE_NAME', message_name)\
            .replace('S_FIELD_TYPE', field_type)\
            .replace('S_FIELD_OFFSET', self.get_field_offset(prvious_field_name))\
            .replace('S_FIELD_NAME', field_name)\
            .replace('S_FIELD_SIZE', field_size)
        self.file_gen.content += self.indentation.get_indented_str(field_def)
        print('gen_composite_string_field_def', field_name)


    def gen_message_const_string_field_def(self, message_name, field_type, field_id, field_name\
        , prvious_field_name, field_size):
        field_def = self.message_const_string_field_ct\
            .replace('S_MESSAGE_NAME', message_name)\
            .replace('S_FIELD_ID', str(field_id))\
            .replace('S_FIELD_TYPE', field_type)\
            .replace('S_FIELD_OFFSET', self.get_field_offset(prvious_field_name))\
            .replace('S_FIELD_NAME', field_name)\
            .replace('S_FIELD_SIZE', field_size)\
            .replace('S_CONST_FIELD_VALUE', str(value))
        self.file_gen.content += self.indentation.get_indented_str(field_def)
        print('gen_message_const_string_field_def', field_name)

    def gen_composite_const_string_field_def(self, message_name, field_type, field_name\
        , prvious_field_name, field_size, value):
        field_def = self.composite_const_string_field_ct\
            .replace('S_MESSAGE_NAME', message_name)\
            .replace('S_FIELD_TYPE', field_type)\
            .replace('S_FIELD_OFFSET', self.get_field_offset(prvious_field_name))\
            .replace('S_FIELD_NAME', field_name)\
            .replace('S_FIELD_SIZE', field_size)\
            .replace('S_CONST_FIELD_VALUE', str(value))
        self.file_gen.content += self.indentation.get_indented_str(field_def)
        print('gen_composite_const_string_field_def', field_name)


    def gen_message_composite_field_def(self, message_name\
        , field_type, field_id, field_name, prvious_field_name):
        field_def = self.message_composite_field_ct\
            .replace('S_MESSAGE_NAME', message_name)\
            .replace('S_FIELD_ID', str(field_id))\
            .replace('S_FIELD_TYPE', field_type)\
            .replace('S_FIELD_OFFSET', self.get_field_offset(prvious_field_name))\
            .replace('S_FIELD_NAME', field_name)
        self.file_gen.content += self.indentation.get_indented_str(field_def)
        print('gen_message_composite_field_def', field_name)

    def gen_end_of_fields(self):
        self.indentation.decrement()
