
class MessageGen:
    def __init__(self, message_name, message_id, schema, version, description, namespace):
        self.message_name = message_name
        self.message_id = message_id
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
        self.string_field_ct = open('c++/string_field_def.h', 'r').read()

    def __del__(self):
        file_name = self.message_name + '.h'
        file = open(file_name,'w').write(self.content)

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

    class GenNameSpace:
         def __init__(self, message_gen, tab_index):
             self.message_gen = message_gen
             self.tab_index = tab_index
             self.message_gen.gen_namespace_begin(self.tab_index)
         def __del__(self):
             self.message_gen.gen_namespace_end(self.tab_index)

    def gen_class_begin(self, tab_index):
        self.content += self.class_ct.format(tabs = self.gen_tabs(tab_index), s_class_name = self.message_name)

    def gen_class_end(self, tab_index):
        self.content += "};\n"

    class GenClass:
         def __init__(self, message_gen, tab_index):
             self.message_gen = message_gen
             self.tab_index = tab_index
             self.message_gen.gen_class_begin(self.tab_index)
         def __del__(self):
             self.message_gen.gen_class_end(self.tab_index)

    def tab_multi_lines(self, tab_index, variable):
        str = ""
        for line in variable.splitlines():
            str += self.gen_tabs(tab_index) + line + "\n"
        return str

    def gen_message_descriptor(self, tab_index):
        message_text = self.message_def_ct\
            .replace('S_MESSAGE_NAME', self.message_name)\
            .replace('S_MESSAGE_ID', str(self.message_id))\
            .replace('S_SCHEMA_ID', str(self.schema))\
            .replace('S_VERSION_ID', str(self.version))        
        self.content += self.tab_multi_lines(tab_index= tab_index, variable = message_text)

    def get_field_offset(self, prvious_field_name):
        if(prvious_field_name ==""):
            return '0';
        else:
            return prvious_field_name + '_offset() + ' + prvious_field_name + '_size()'
    
    def gen_numeric_field_def(self, tab_index, message_name, field_type, field_id, field_name, prvious_field_name, min, max, null):
        field_text = self.numeric_field_ct\
            .replace('S_MESSAGE_NAME', message_name)\
            .replace('S_FIELD_TYPE', field_type)\
            .replace('S_FIELD_OFFSET', self.get_field_offset(prvious_field_name))\
            .replace('S_FIELD_ID', str(field_id))\
            .replace('S_FIELD_NAME', field_name)\
            .replace('S_FIELD_MIN', str(min))\
            .replace('S_FIELD_MAX', str(max))\
            .replace('S_FIELD_NULL', str(null))
        self.content += self.tab_multi_lines(tab_index = tab_index, variable = field_text)

    def gen_string_field_def(self, tab_index, message_name, field_type, field_id, field_name, prvious_field_name, field_size):
        field_text = self.string_field_ct\
            .replace('S_MESSAGE_NAME', message_name)\
            .replace('S_FIELD_TYPE', field_type)\
            .replace('S_FIELD_OFFSET', self.get_field_offset(prvious_field_name))\
            .replace('S_FIELD_ID', str(field_id))\
            .replace('S_FIELD_NAME', field_name)\
            .replace('S_FIELD_SIZE', field_size)
        self.content += self.tab_multi_lines(tab_index = tab_index, variable = field_text)

    def generate_message(self):
        self.gen_includes(tab_index = 0, include_list = ["cstdint", "string", "string_view", "ostream"])
        self.gen_namespace_begin(tab_index = 0)
        self.gen_class_begin(tab_index = 0)
        self.gen_message_descriptor(tab_index = 0)
        self.gen_numeric_field_def(tab_index = 0\
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
