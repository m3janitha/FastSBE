import logging

from FileGen import Indentaion
from FileGen import FileGen
from FileGen import ClassGen
from FileGen import ContentHandler

class FieldGen:
    message_def_ct                  = open('metadata/c++/message/message_def.h', 'r').read()
    #numeirc
    message_numeric_field_ct        = open('metadata/c++/message/numeric_field_def.h', 'r').read()
    message_const_numeric_field_ct  = open('metadata/c++/message/const_numeric_field_def.h', 'r').read()
    #enum
    message_enum_field_ct           = open('metadata/c++/message/enum_field_def.h', 'r').read()
    message_const_enum_field_ct     = open('metadata/c++/message/const_enum_field_def.h', 'r').read()
    #string
    message_string_field_ct         = open('metadata/c++/message/string_field_def.h', 'r').read()
    message_const_string_field_ct   = open('metadata/c++/message/const_string_field_def.h', 'r').read()
    #composite
    message_composite_field_ct      = open('metadata/c++/message/composite_field_def.h', 'r').read()
    
    #numeirc
    composite_numeric_field_ct      = open('metadata/c++/composite/numeric_field_def.h', 'r').read()
    composite_const_numeric_field_ct= open('metadata/c++/composite/const_numeric_field_def.h', 'r').read()
    #enum
    composite_enum_field_ct         = open('metadata/c++/composite/enum_field_def.h', 'r').read()
    composite_const_enum_field_ct   = open('metadata/c++/composite/const_enum_field_def.h', 'r').read()
    #string
    composite_string_field_ct       = open('metadata/c++/composite/string_field_def.h', 'r').read()
    composite_const_string_field_ct = open('metadata/c++/composite/const_string_field_def.h', 'r').read()

    constructor_ct                  = open('metadata/c++/composite/constructor_def.h', 'r').read()


    #group
    nested_group_def_ct             = open('metadata/c++/message/nested_group_def.h', 'r').read()
    nested_group_def_ct_4           = open('metadata/c++/message/nested_group_def_4.h', 'r').read()
    group_def_ct                    = open('metadata/c++/message/group_def.h', 'r').read()
    group_def_ct_4                  = open('metadata/c++/message/group_def_4.h', 'r').read()

    #variable length data
    nested_var_len_data_def_ct      = open('metadata/c++/message/nested_variable_length_data_def.h', 'r').read()
    var_len_data_def_ct             = open('metadata/c++/message/variable_length_data_def.h', 'r').read()

    #buffer
    buffer_def_ct                   = open('metadata/c++/message/buffer_def.h', 'r').read()

    #ostream
    ostream_field_def_begin_ct      = open('metadata/c++/message/ostream_field_def_begin.h', 'r').read()
    ostream_field_def_end_ct        = open('metadata/c++/message/ostream_field_def_end.h', 'r').read()
    ostream_field_def_ct            = open('metadata/c++/message/ostream_field_def.h', 'r').read()
    ostream_group_def_begin_ct      = open('metadata/c++/message/ostream_group_def_begin.h', 'r').read()
    ostream_group_def_end_ct        = open('metadata/c++/message/ostream_group_def_end.h', 'r').read()
    ostream_group_field_def_ct      = open('metadata/c++/message/ostream_group_field_def.h', 'r').read()
    


    def gen_message_descriptor(self, message_name, message_id, schema, version, description):
        message_def = self.message_def_ct\
            .replace('S_MESSAGE_NAME', message_name)\
            .replace('S_MESSAGE_ID', str(message_id))\
            .replace('S_SCHEMA_ID', str(schema))\
            .replace('S_VERSION_ID', str(version))
        self.handler.content += self.indentation.get_indented_str(message_def)


    def get_field_offset(self, prvious_field_name):
        if(prvious_field_name ==""):
            return '0';
        else:
            return prvious_field_name + '_offset() + ' + prvious_field_name + '_size()'

    def get_group_offset(self, prvious_field_name):
        if(prvious_field_name ==""):
            return '0';
        else:
            return prvious_field_name + '_offset() + ' + 'sizeof(' + prvious_field_name + '::header_) + ' + prvious_field_name + '_data_length()'


    def gen_ostream_field_def_begin(self):
        field_def = self.ostream_field_def_begin_ct\
            .replace('S_NAMESPACE', self.namespace)\
            .replace('S_MESSAGE_NAME', self.message_name)
        self.handler.ostream += field_def
        logging.debug('gen_ostream_field_def_begin')

    def gen_ostream_field_def_end(self):
        self.handler.ostream += self.ostream_field_def_end_ct
        logging.debug('gen_ostream_def')

    def gen_ostream_begin(self):
        self.gen_ostream_field_def_begin()

    def gen_ostream_end(self):
        self.gen_ostream_field_def_end()

    def gen_ostream_field_def(self, field_name):
        field_def = self.ostream_field_def_ct\
            .replace('S_MESSAGE_NAME', self.message_name)\
            .replace('S_FIELD_NAME', field_name)
        field_def += '\n'
        self.handler.ostream += field_def
        logging.debug('gen_ostream_def')


    def gen_ostream_field(self, field_name, is_group, group_name):
        if(is_group == False):
            self.gen_ostream_field_def(field_name)
        else:
            self.gen_ostream_group_field_def(field_name, group_name)


    def gen_ostream_group_def_begin(self, group_name, message_name):
        field_def = self.ostream_group_def_begin_ct\
            .replace('S_NAMESPACE', self.namespace)\
            .replace('S_MESSAGE_NAME', message_name)\
            .replace('S_GROUP_NAME', group_name)
        self.handler.ostream_var += field_def
        logging.debug('gen_ostream_field_def_begin')

    def gen_ostream_group_def_end(self):
        self.handler.ostream_var += self.ostream_group_def_end_ct
        logging.debug('gen_ostream_def')

    def gen_ostream_group_begin(self, group_name, message_name):
        self.gen_ostream_group_def_begin(group_name, message_name)

    def gen_ostream_group_end(self):
        self.gen_ostream_group_def_end()

    def gen_ostream_group_field_def(self, field_name, group_name):
        field_def = self.ostream_group_field_def_ct\
            .replace('S_MESSAGE_NAME', self.message_name)\
            .replace('S_GROUP_NAME', self.message_name)\
            .replace('S_FIELD_NAME', field_name)
        field_def += '\n'
        self.handler.ostream_var += field_def
        logging.debug('gen_ostream_def')

    def gen_message_numeric_field_def(self, message_name\
        , field_type, field_id, field_name, prvious_field_name\
        , min, max, null, is_group, group_name):
        field_def = self.message_numeric_field_ct\
            .replace('S_MESSAGE_NAME', message_name)\
            .replace('S_FIELD_ID', str(field_id))\
            .replace('S_FIELD_TYPE', field_type)\
            .replace('S_FIELD_OFFSET', self.get_field_offset(prvious_field_name))\
            .replace('S_FIELD_NAME', field_name)\
            .replace('S_FIELD_MIN', str(min))\
            .replace('S_FIELD_MAX', str(max))\
            .replace('S_FIELD_NULL', str(null))
        self.handler.content += self.indentation.get_indented_str(field_def)
        self.gen_ostream_field(field_name, is_group, group_name)
        logging.debug('gen_message_numeric_field_def: %s', field_name)

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
        self.handler.content += self.indentation.get_indented_str(field_def)
        self.gen_ostream_field_def(field_name)
        self.handler.field_type_and_name.append([field_type, field_name])
        logging.debug('gen_composite_numeric_field_def: %s', field_name)


    def gen_message_const_numeric_field_def(self, message_name\
        , field_type, field_id, field_name, prvious_field_name, value, is_group, group_name):
        field_def = self.message_const_numeric_field_ct\
            .replace('S_MESSAGE_NAME', message_name)\
            .replace('S_FIELD_ID', str(field_id))\
            .replace('S_FIELD_TYPE', field_type)\
            .replace('S_FIELD_OFFSET', self.get_field_offset(prvious_field_name))\
            .replace('S_FIELD_NAME', field_name)\
            .replace('S_CONST_FIELD_VALUE', str(value))
        self.handler.content += self.indentation.get_indented_str(field_def)
        self.gen_ostream_field(field_name, is_group, group_name)
        logging.debug('gen_message_const_numeric_field_def: %s', field_name)

    def gen_composite_const_numeric_field_def(self, message_name\
        , field_type, field_name, prvious_field_name, value):
        field_def = self.composite_const_numeric_field_ct\
            .replace('S_MESSAGE_NAME', message_name)\
            .replace('S_FIELD_TYPE', field_type)\
            .replace('S_FIELD_OFFSET', self.get_field_offset(prvious_field_name))\
            .replace('S_FIELD_NAME', field_name)\
            .replace('S_CONST_FIELD_VALUE', str(value))
        self.handler.content += self.indentation.get_indented_str(field_def)
        self.gen_ostream_field_def(field_name)
        logging.debug('gen_composite_const_numeric_field_def: %s', field_name)


    def gen_message_enum_field_def(self, message_name\
        , field_type, field_id, field_name, prvious_field_name\
        , null, is_group, group_name):
        field_def = self.message_enum_field_ct\
            .replace('S_MESSAGE_NAME', message_name)\
            .replace('S_FIELD_ID', str(field_id))\
            .replace('S_FIELD_TYPE', field_type)\
            .replace('S_FIELD_OFFSET', self.get_field_offset(prvious_field_name))\
            .replace('S_FIELD_NAME', field_name)\
            .replace('S_FIELD_NULL', str(null))
        self.handler.content += self.indentation.get_indented_str(field_def)
        self.gen_ostream_field(field_name, is_group, group_name)
        self.handler.user_includes.append(field_type)
        logging.debug('gen_message_enum_field_def: %s', field_name)

    def gen_composite_enum_field_def(self, message_name\
        , field_type, field_name, prvious_field_name\
        , null):
        field_def = self.composite_enum_field_ct\
            .replace('S_MESSAGE_NAME', message_name)\
            .replace('S_FIELD_TYPE', field_type)\
            .replace('S_FIELD_OFFSET', self.get_field_offset(prvious_field_name))\
            .replace('S_FIELD_NAME', field_name)\
            .replace('S_FIELD_NULL', str(null))
        self.handler.content += self.indentation.get_indented_str(field_def)
        self.gen_ostream_field_def(field_name)
        self.handler.user_includes.append(field_type)
        self.handler.field_type_and_name.append([field_type + '::Value', field_name])
        logging.debug('gen_composite_enum_field_def: %s', field_name)


    def gen_message_const_enum_field_def(self, message_name\
        , field_type, field_id, field_name, prvious_field_name, value, is_group, group_name):
        field_def = self.message_const_enum_field_ct\
            .replace('S_MESSAGE_NAME', message_name)\
            .replace('S_FIELD_ID', str(field_id))\
            .replace('S_FIELD_TYPE', field_type)\
            .replace('S_FIELD_OFFSET', self.get_field_offset(prvious_field_name))\
            .replace('S_FIELD_NAME', field_name)\
            .replace('S_CONST_FIELD_VALUE', str(value))
        self.handler.content += self.indentation.get_indented_str(field_def)
        self.gen_ostream_field(field_name, is_group, group_name)
        self.handler.user_includes.append(field_type)
        logging.debug('gen_message_const_enum_field_def: %s', field_name)

    def gen_composite_const_enum_field_def(self, message_name\
        , field_type, field_name, prvious_field_name, value):
        field_def = self.composite_const_enum_field_ct\
            .replace('S_MESSAGE_NAME', message_name)\
            .replace('S_FIELD_TYPE', field_type)\
            .replace('S_FIELD_OFFSET', self.get_field_offset(prvious_field_name))\
            .replace('S_FIELD_NAME', field_name)\
            .replace('S_CONST_FIELD_VALUE', str(value))
        self.handler.content += self.indentation.get_indented_str(field_def)
        self.gen_ostream_field_def(field_name)
        self.handler.user_includes.append(field_type)
        logging.debug('gen_composite_const_enum_field_def: %s', field_name)


    def gen_message_string_field_def(self, message_name, field_type, field_id, field_name\
        , prvious_field_name, field_size, is_group, group_name):
        field_def = self.message_string_field_ct\
            .replace('S_MESSAGE_NAME', message_name)\
            .replace('S_FIELD_ID', str(field_id))\
            .replace('S_FIELD_TYPE', field_type)\
            .replace('S_FIELD_OFFSET', self.get_field_offset(prvious_field_name))\
            .replace('S_FIELD_NAME', field_name)\
            .replace('S_FIELD_SIZE', field_size)
        self.handler.content += self.indentation.get_indented_str(field_def)
        self.gen_ostream_field(field_name, is_group, group_name)
        logging.debug('gen_message_string_field_def: %s', field_name)

    def gen_composite_string_field_def(self, message_name, field_type, field_name\
        , prvious_field_name, field_size):
        field_def = self.composite_string_field_ct\
            .replace('S_MESSAGE_NAME', message_name)\
            .replace('S_FIELD_TYPE', field_type)\
            .replace('S_FIELD_OFFSET', self.get_field_offset(prvious_field_name))\
            .replace('S_FIELD_NAME', field_name)\
            .replace('S_FIELD_SIZE', field_size)
        self.handler.content += self.indentation.get_indented_str(field_def)
        self.gen_ostream_field_def(field_name)
        self.handler.field_type_and_name.append([field_type, field_name])
        logging.debug('gen_composite_string_field_def: %s', field_name)


    def gen_message_const_string_field_def(self, message_name, field_type, field_id, field_name\
        , prvious_field_name, field_size, is_group, group_name):
        field_def = self.message_const_string_field_ct\
            .replace('S_MESSAGE_NAME', message_name)\
            .replace('S_FIELD_ID', str(field_id))\
            .replace('S_FIELD_TYPE', field_type)\
            .replace('S_FIELD_OFFSET', self.get_field_offset(prvious_field_name))\
            .replace('S_FIELD_NAME', field_name)\
            .replace('S_FIELD_SIZE', field_size)\
            .replace('S_CONST_FIELD_VALUE', str(value))
        self.handler.content += self.indentation.get_indented_str(field_def)
        self.gen_ostream_field(field_name, is_group, group_name)
        logging.debug('gen_message_const_string_field_def: %s', field_name)

    def gen_composite_const_string_field_def(self, message_name, field_type, field_name\
        , prvious_field_name, field_size, value):
        field_def = self.composite_const_string_field_ct\
            .replace('S_MESSAGE_NAME', message_name)\
            .replace('S_FIELD_TYPE', field_type)\
            .replace('S_FIELD_OFFSET', self.get_field_offset(prvious_field_name))\
            .replace('S_FIELD_NAME', field_name)\
            .replace('S_FIELD_SIZE', field_size)\
            .replace('S_CONST_FIELD_VALUE', str(value))
        self.handler.content += self.indentation.get_indented_str(field_def)
        self.gen_ostream_field_def(field_name)
        logging.debug('gen_composite_const_string_field_def: %s', field_name)


    def gen_message_composite_field_def(self, message_name\
        , field_type, field_id, field_name, prvious_field_name, is_group, group_name):
        field_def = self.message_composite_field_ct\
            .replace('S_MESSAGE_NAME', message_name)\
            .replace('S_FIELD_ID', str(field_id))\
            .replace('S_FIELD_TYPE', field_type)\
            .replace('S_FIELD_OFFSET', self.get_field_offset(prvious_field_name))\
            .replace('S_FIELD_NAME', field_name)
        self.handler.content += self.indentation.get_indented_str(field_def)
        self.gen_ostream_field(field_name, is_group, group_name)
        self.handler.user_includes.append(field_type)
        self.handler.field_type_and_name.append([field_type, field_name])
        logging.debug('gen_message_composite_field_def: %s', field_name)


    def gen_nested_group_def(self, group_name\
        , dimension_type, block_length_name, num_in_group_name\
        , num_in_group_type):
        field_def = self.nested_group_def_ct\
            .replace('S_GROUP_NAME', group_name)\
            .replace('S_DIAMENTION_TYPE', dimension_type)\
            .replace('S_BLOCK_LENGTH_NAME', block_length_name)\
            .replace('S_NUM_IN_GROUP_NAME', num_in_group_name)\
            .replace('S_NUM_IN_GROUP_TYPE', num_in_group_type)
        self.handler.content += self.indentation.get_indented_str(field_def)
        self.handler.user_includes.append(dimension_type)
        logging.debug('gen_nested_group_def: %s', group_name)

    def gen_nested_group_def_4(self, group_name\
        , dimension_type, block_length_name, num_in_group_name\
        , num_in_group_type, num_groups_type, num_var_data_field_type):
        field_def = self.nested_group_def_ct_4\
            .replace('S_GROUP_NAME', group_name)\
            .replace('S_DIAMENTION_TYPE', dimension_type)\
            .replace('S_BLOCK_LENGTH_NAME', block_length_name)\
            .replace('S_NUM_IN_GROUP_NAME', num_in_group_name)\
            .replace('S_NUM_IN_GROUP_TYPE', num_in_group_type)\
            .replace('S_NUM_GROUPS_TYPE', num_groups_type)\
            .replace('S_NUM_VAR_DATA_FIELDS_TYPE', num_var_data_field_type)             
        self.handler.content += self.indentation.get_indented_str(field_def)
        self.handler.user_includes.append(dimension_type)
        logging.debug('gen_nested_group_def_4: %s', group_name)        


    def gen_group_def(self, group_name, prvious_group_name, group_id\
        , dimension_type, block_length_name
        , num_in_group_name, num_in_group_type):
        field_def = self.group_def_ct\
            .replace('S_GROUP_NAME', group_name)\
            .replace('S_GROUP_ID', group_id)\
            .replace('S_GROUP_OFFSET', self.get_group_offset(str(prvious_group_name)))\
            .replace('S_DIAMENTION_TYPE', dimension_type)\
            .replace('S_BLOCK_LENGTH_NAME', block_length_name)\
            .replace('S_NUM_IN_GROUP_NAME', num_in_group_name)\
            .replace('S_NUM_IN_GROUP_TYPE', num_in_group_type)                           
        self.handler.content += self.indentation.get_indented_str(field_def)
        self.gen_ostream_field_def(group_name)
        logging.debug('gen_group_def: %s', group_name)

    def gen_group_def_4(self, group_name, prvious_group_name, group_id\
        , dimension_type, block_length_name
        , num_in_group_name, num_in_group_type\
        , num_groups_name, num_groups_type\
        , num_var_data_fields_name, num_var_data_fields_type):
        field_def = self.group_def_ct_4\
            .replace('S_GROUP_NAME', group_name)\
            .replace('S_GROUP_ID', group_id)\
            .replace('S_GROUP_OFFSET', self.get_group_offset(str(prvious_group_name)))\
            .replace('S_DIAMENTION_TYPE', dimension_type)\
            .replace('S_BLOCK_LENGTH_NAME', block_length_name)\
            .replace('S_NUM_IN_GROUP_NAME', num_in_group_name)\
            .replace('S_NUM_IN_GROUP_TYPE', num_in_group_type)\
            .replace('S_NUM_GROUPS_NAME', num_groups_name)\
            .replace('S_NUM_GROUPS_TYPE', num_groups_type)\
            .replace('S_NUM_VAR_DATA_FIELDS_NAME', num_var_data_fields_name)\
            .replace('S_NUM_VAR_DATA_FIELDS_TYPE', num_var_data_fields_type)                            
        self.handler.content += self.indentation.get_indented_str(field_def)
        self.gen_ostream_field_def(group_name)
        logging.debug('gen_group_def_4: %s', group_name)


    def gen_nested_variable_length_data_def(self, var_len_data_name\
        , dimension_type, dimension):
        var_len_data_length_name = dimension[0]['name']
        var_len_data_length_type = dimension[0]['type']
        var_len_data_var_data_type = dimension[1]['type']

        field_def = self.nested_var_len_data_def_ct\
            .replace('S_VAR_LEN_DATA_NAME', var_len_data_name)\
            .replace('S_DIAMENTION_TYPE', dimension_type)\
            .replace('S_VAR_LEN_DATA_LENGTH_NAME', var_len_data_length_name)\
            .replace('S_VAR_LEN_DATA_LENGTH_TYPE', var_len_data_length_type)\
            .replace('S_VAR_LEN_DATA_VAR_DATA_TYPE', var_len_data_var_data_type)
        self.handler.content += self.indentation.get_indented_str(field_def)
        self.handler.user_includes.append(dimension_type)
        logging.debug('nested_variable_length_data_def: %s', var_len_data_name)

    def gen_variable_length_data_def(self, var_len_data_name, prvious_var_len_data_name, var_len_data_id\
        , dimension_type, dimension):
        var_len_data_length_name = dimension[1]['name']
        var_len_data_length_type = dimension[1]['type']        
        field_def = self.var_len_data_def_ct\
            .replace('S_VAR_LEN_DATA_NAME', var_len_data_name)\
            .replace('S_VAR_LEN_DATA_ID', var_len_data_id)\
            .replace('S_VAR_LEN_DATA_OFFSET', self.get_group_offset(str(prvious_var_len_data_name)))\
            .replace('S_DIAMENTION_TYPE', dimension_type)\
            .replace('S_VAR_LEN_DATA_LENGTH_NAME', var_len_data_length_name)\
            .replace('S_VAR_LEN_DATA_LENGTH_TYPE', var_len_data_length_type)             
        self.handler.content += self.indentation.get_indented_str(field_def)
        self.gen_ostream_field_def(var_len_data_name)
        logging.debug('gen_variable_length_data_def: %s', var_len_data_name)            


    def gen_constructor(self):
        string_fields = []
        ct_args_list = []
        for type in self.handler.field_type_and_name:
            if(type[0] == 'char'):
                string_fields.append(type[1])
                ct_args_list.append('std::string_view ' + type[1])
            else:
                ct_args_list.append(' '.join(type))
        initilizer_args_list = []
        for type in self.handler.field_type_and_name:
            if(type[0] != 'char'):
                initilizer_args_list.append(type[1] + '_(' + type[1] + ')')

        ct_args = ', '.join(ct_args_list)
        initilizer_args = ', '.join(initilizer_args_list)
        str_assign = ''
        for field_name in string_fields:
            str_assign += field_name + '.copy(' + field_name + '_,' + field_name + '_size());'

        field_def = self.constructor_ct\
            .replace('S_MESSAGE_NAME', self.message_name)\
            .replace('S_ARGS_LIST', ct_args)\
            .replace('S_INITIALIZER_LIST', initilizer_args)\
            .replace('S_STRING_FIELDS_ASSIGN', str_assign)

        self.handler.content += self.indentation.get_indented_str(field_def)


    def gen_buffer_def(self, field_size):
        field_def = self.buffer_def_ct\
            .replace('S_FIELD_SIZE', str(field_size))
        self.handler.content += self.indentation.get_indented_str(field_def)
        logging.debug('gen_buffer_def')


    def __init__(self, handler, indentation, message_name, class_gen, namespace):
        self.handler = handler
        self.indentation = indentation
        self.namespace = namespace
        self.message_name = message_name
        self.class_gen = class_gen

        logging.debug('create FieldGen: %s', self.message_name)
        self.indentation.increment()
        
    def __del__(self):
        self.indentation.decrement()
        logging.debug('delete FieldGen: %s', self.message_name)


class MessageGen:
    def __init__(self, handler, message_name, message_id, schema, version, description, namespace):
        self.handler = handler
        self.message_name = message_name
        self.namespace = namespace

        logging.debug('create MessageGen:%s ', message_name)
        self.indentation = Indentaion(0)
        self.class_gen = ClassGen(handler = self.handler, indentation = self.indentation\
            , class_name = message_name)
        self.field_gen = FieldGen(handler = self.handler, indentation = self.indentation\
            , message_name = message_name, class_gen = self.class_gen, namespace = namespace)
        
        self.field_gen.gen_message_descriptor(message_name = message_name, message_id = message_id\
            , schema = schema, version = version, description = description)


    def __del__(self):
        logging.debug('delete MessageGen: %s', self.message_name)


