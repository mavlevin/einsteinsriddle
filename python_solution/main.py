import pprint 

from street import Street
from street_generators import generateRandomStreet, generateIterativeStreet, generateAStreet
from hints import *

LIMITED_VERSION_MODE = True
INFO = True

def print_warning():
	print "*" * 30
	print "Notice: python is a really slow language, for results in our lifetime use the CPP solution"
	print "*" * 30

def main():
	"""
	solve einsteins riddle
	"""

	print_warning()

	# list of functions that need to be true
	hints = [func for name,func in globals().items() if "hint" in name]
	maxTries = 1000000
	# the generation algorithm to use
	# one of generateRandomStreet, generateIterativeStreet, generateAStreet
	streetGenerator = generateIterativeStreet
	printAmmount = maxTries / 10

	print("{} requirments to pass".format(len(hints)))
	if LIMITED_VERSION_MODE:
		print("Limited version mode. trying up to {}".format(maxTries))

	for streetCount, street in enumerate(streetGenerator()):
		if INFO and streetCount % printAmmount == 0:
			print("tried {} streets".format(streetCount))
		for hint in hints:
			if not hint(street):
				break
		else:
			print("found answer:")
			pprint.pprint(street.people)
			break

		if LIMITED_VERSION_MODE and streetCount == maxTries:
			print("reached max :(")
			break
	
if __name__ == '__main__':
	main()