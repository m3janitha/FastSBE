import argparse
import logging
import logging.handlers

from Parser import Parser

logging.basicConfig(filename='log.txt', level=logging.DEBUG\
			, format='%(asctime)s,%(msecs)d %(levelname)-8s [%(filename)s:%(lineno)d] %(message)s'\
			, datefmt='%Y-%m-%d:%H:%M:%S')

handler = logging.handlers.RotatingFileHandler(filename='log.txt', mode='w', backupCount=5)

#parser = argparse.ArgumentParser(description='Optional app description')

#parser.add_argument('output_dir', type=str\
#	, help='output directory')
#parser.add_argument('override_namespace', type=str, nargs='?'\
#	, help='optional override namespace')

#args = parser.parse_args()

#print(args.output_dir)
#print(args.override_namespace)

#parser = Parser(output_dir = args.output_dir\
#	, override_namespace = args.override_namespace)

parser = Parser(output_dir = "gen"\
	, override_namespace = "test::sbe")
