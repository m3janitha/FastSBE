import argparse
import logging
import logging.handlers
import os

from Parser import Parser

parser = argparse.ArgumentParser(description='Optional app description')

parser.add_argument('log_file', type=str\
	, help='log file name', default='log.txt')
parser.add_argument('schema_file', type=str\
	, help='schema file name')
parser.add_argument('out_folder', type=str\
	, help='output folder')
parser.add_argument('override_namespace', type=str, nargs='?'\
	, help='optional override namespace')

args = parser.parse_args()

print('log_file:', args.log_file)
print('schema_file:', args.schema_file)
print('out_folder:', args.out_folder)
print('override_namespace:', args.override_namespace)

logging.basicConfig(filename=args.log_file, level=logging.DEBUG\
			, format='%(asctime)s,%(msecs)d %(levelname)-8s [%(filename)s:%(lineno)d] %(message)s'\
			, datefmt='%Y-%m-%d:%H:%M:%S')

handler = logging.handlers.RotatingFileHandler(filename=args.log_file, mode='w', backupCount=5)

logging.debug('schema_file: %s', args.schema_file)
logging.debug('out_folder: %s', args.out_folder)
logging.debug('override_namespace: %s', args.override_namespace)

if not os.path.exists(args.out_folder):
    os.makedirs(args.out_folder)

parser = Parser(schema_file = args.schema_file
	, out_folder = args.out_folder\
	, override_namespace = args.override_namespace)

# parser = Parser(schema_file = 'example-schema.xml'\
# 	, out_folder = "gen"\
# 	, override_namespace = "test::sbe")
