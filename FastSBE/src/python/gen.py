import xml.etree.ElementTree as ET

class MessageGen:
    def __init__(self, message_name, id, schema, version, description, namespace):
        self.message_name = message_name
        self.message_id = id
        self.schema = schema
        self.version = version
        self.description = description
        self.namespace = namespace
        self.content = ""
        self.include_ct     = "{tabs}#include<{include_file}>\n"
        self.namespace_ct   = "\n{tabs}namespace {s_namespace}\n{{\n"
        self.class_ct       = "\n{tabs}class {s_class_name}\n{{\n"
        self.message_def_ct = open('c++/message_def.h', 'r').read()
        self.numeric_field_ct = open('c++/numeric_field_def.h', 'r').read()

    def gen_tabs(self, tab_index):
        str = " " * 4 * tab_index
        return str

    def gen_includes(self, tab_index, include_list = []):
        for include in include_list:
            self.content += self.include_ct.format(tabs = self.gen_tabs(tab_index), include_file = include)

    def gen_namespace_begin(self, tab_index):
        self.content += self.namespace_ct.format(tabs = self.gen_tabs(tab_index), s_namespace = self.namespace)

    def gen_namespace_end(self, tab_index):
        self.content += "}\n"

    def gen_class_begin(self, tab_index):
        self.content += self.class_ct.format(tabs = self.gen_tabs(tab_index), s_class_name = self.message_name)

    def gen_class_end(self, tab_index):
        self.content += "}\n"

    def tab_multi_lines(self, tab_index, variable):
        str = ""
        for line in variable.splitlines():
            str += self.gen_tabs(tab_index) + line + "\n"
        return str

    def gen_message_descriptor(self, tab_index):
        message_text = self.message_def_ct\
            .replace('s_message_name', self.message_name)\
            .replace('s_message_id', str(self.message_id))\
            .replace('s_schema', str(self.schema))\
            .replace('s_version', str(self.version))        
        self.content += self.tab_multi_lines(tab_index= tab_index, variable = message_text)
    
    def gen_numeric_field_descriptor(self, tab_index, message_name, field_type, field_id, field_name, min, max, null):
        field_text = self.numeric_field_ct\
            .replace('s_message_name', message_name)\
            .replace('s_field_type', field_type)\
            .replace('s_offset', str(0))\
            .replace('s_field_id', str(field_id))\
            .replace('field_name', field_name)\
            .replace('s_min', str(min))\
            .replace('s_max', str(max))\
            .replace('s_null', str(null))
        self.content += self.tab_multi_lines(tab_index = tab_index, variable = field_text)

    def generate_message(self):
        self.gen_includes(tab_index = 0, include_list = ["cstdint", "string", "string_view", "ostream"])
        self.gen_namespace_begin(tab_index = 0)
        self.gen_class_begin(tab_index = 0)
        self.gen_message_descriptor(tab_index = 0)
        self.gen_numeric_field_descriptor(tab_index = 0\
            , message_name = self.message_name\
            , field_type = "std::uint32_t"\
            , field_id = 1\
            , field_name = "price"\
            , min = 30\
            , max = 99\
            , null = 255)
        self.gen_class_end(tab_index = 0)
        self.gen_namespace_end(tab_index = 0)
        return self.content



msg_gen = MessageGen(message_name = "NewOrder", id = 1, schema = 3, version = 4, description = "new order message", namespace = "test::sbe")
msg = msg_gen.generate_message()
file = open("NewOrder.h",'w').write(msg)

print("end")


