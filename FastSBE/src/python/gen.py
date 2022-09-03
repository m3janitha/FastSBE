import xml.etree.ElementTree as ET
from MessageGen import MessageGen

field_types = {
	"int8"	: "std::int8_t",
	"uint8"	: "std::uint8_t",
	"int16"	: "std::int16_t",
	"uint16": "std::uint16_t",
	"int32"	: "std::int32_t",
	"uint32": "std::uint32_t",
	"int64"	: "std::int64_t",
	"uint64": "std::uint64_t",
	"char"	: "char"
	}

defult_minimum = {
	"int8"	: 0,
	"uint8"	: -1,
	"int16"	: 0,
	"uint16": -1,
	"int32"	: 0,
	"uint32": -1,
	"int64"	: 0,
	"uint64": -1,
	"char"	: 0,
}

defult_maximum = {
	"int8"	: 100,
	"uint8"	: 100,
	"int16"	: 100,
	"uint16": 100,
	"int32"	: 100,
	"uint32": 100,
	"int64"	: 100,
	"uint64": 100,
	"char"	: 255,
}

defult_null = {
	"int8"	: 100,
	"uint8"	: 100,
	"int16"	: 100,
	"uint16": 100,
	"int32"	: 100,
	"uint32": 100,
	"int64"	: 100,
	"uint64": 100,
	"char"	: 255,
}

def is_numeric(type):
	numeric_types = {"int8", "uint8", "int16", "uint16", "int32", "uint32", "int64", "uint64" }
	if type in numeric_types:
		return True
	else:
		return False
	
tree = ET.parse('example-schema.xml')
root = tree.getroot()

include_list = ["cstdint", "string", "string_view", "ostream"]

schema_id = root.attrib['id']
schema_version = root.attrib['version']
print('schema_id:' , schema_id, ' schema_version:', schema_version)

namespaces = {'sbe': 'http://fixprotocol.io/2016/sbe'}

def get_numeric_attrib_of_primitive(type):
	min_value = defult_minimum[premitive_type]
	max_value = defult_maximum[premitive_type]
	null_value = defult_null[premitive_type]
		
	if('minValue' in type):
		min_value = type['minValue']
	if('maxValue' in type):
		max_value = type['maxValue']
	if('nullValue' in type):
		null_value = type['nullValue']

	return min_value, max_value, null_value

types = root.find('types')

defined_types = {}
for type in types:
	print (type.tag, type.attrib)
	type_name = type.attrib['name']
	defined_types.update({type_name : type.attrib})

	premitive_type = type.attrib['primitiveType']
	
	#if(is_numeric(premitive_type) == True):
	#	(min_value, max_value, null_value) = get_numeric_attrib_of_primitive(type)
	#	print('types:', min_value, max_value, null_value)


for message in root.iterfind('sbe:message', namespaces):
	message_name = message.attrib['name']
	message_id = message.attrib['id']
	message_description = message.attrib['description']
	print('message_name:' , message_name, ' message_id:', message_id, ' message_description:', message_description)
		
	msg_gen = MessageGen(message_name = message_name\
		, message_id = message_id\
		, schema = schema_id\
		, version = schema_version\
		, description = message_description\
		, namespace = "test::sbe")

	msg_gen.gen_includes(tab_index = 0, include_list = include_list)
	msg_namespace = msg_gen.GenNameSpace(message_gen = msg_gen, tab_index = 0)
	msg_class = msg_gen.GenClass(message_gen = msg_gen, tab_index = 0)
	msg_gen.gen_message_descriptor(tab_index = 0)
	
	for field in message.iterfind('field', namespaces):
		field_name = field.attrib['name']
		field_id = field.attrib['id']
		field_type = field.attrib['type']

		if(is_numeric(field_type) == True):
			msg_gen.gen_numeric_field_def(tab_index = 0\
				, message_name = message_name\
				, field_type = field_types[field_type]\
				, field_id = field_id\
				, field_name = field_name\
				, min = defult_minimum[premitive_type]\
				, max = defult_maximum[premitive_type]\
				, null = defult_null[premitive_type])
		elif (field_type in defined_types):
			type = defined_types[field_type]
			primitive_type = type['primitiveType'] 
			if(is_numeric(primitive_type) == True):
				(min_value, max_value, null_value) = get_numeric_attrib_of_primitive(type)
				msg_gen.gen_numeric_field_def(tab_index = 0\
					, message_name = message_name\
					, field_type = field_types[primitive_type]\
					, field_id = field_id\
					, field_name = field_name\
					, min = min_value\
					, max = max_value\
					, null = null_value)



#msg_gen = MessageGen(message_name = "NewOrder", id = 1, schema = 3, version = 4, description = "new order message", namespace = "test::sbe")
#msg = msg_gen.generate_message()
#file = open("NewOrder.h",'w').write(msg)

print("end")


