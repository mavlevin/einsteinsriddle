"""different kinds of generators to create streets by different algorithms"""

import itertools
import random 
import street
from utils import transpose, flattenList

kProperties = {
	"house color" : ["blue", "green", "red", "white", "yellow"],
	"nationality" : ["brit", "dane", "german", "norwegian", "swede"],
	"beverage" : ["beer", "coffee", "milk", "tea", "water"],
	"cigar" : ["blue master", "dunhill", "pall mall", "prince", "blend"],
	"pet" : ["cat", "bird", "dog", "fish", "horse"],
	"house number" : [str(i) for i in range(1, 6)]
}

def generateRandomStreet():
	"""generates a random street"""
	while True:
		currentStreet = kProperties.values()
		list(map(random.shuffle, currentStreet)) # need to list this otherwise it won't run the shuffle
		currentStreet = transpose(currentStreet)
		people = [dict(zip(kProperties.keys(), person)) for person in currentStreet] 
		yield street.Street(people) 

def generateIterativeStreet():
	"""iterates throught all the valid street options *MOST EFFECIENT*"""
	charts = [list(itertools.permutations(values)) for values in kProperties.values()]
	product = itertools.product(*charts)
	for currentStreet in product:
		currentStreet = transpose(currentStreet)
		people = [dict(zip(kProperties.keys(), person)) for person in currentStreet] 
		yield street.Street(people)
	raise(NotImplementedError("didn't implement street exhaustion handeling"))

def generateAStreet():
	"""
	picks all the combinations of 5 people from all the possible people.
	Then makes sure its a legal combination
	"""
	def isUniqueProperties(street):
		allCurrentStreetValues = flattenList(street)
		for name, valueOptions in kProperties.items():
			for option in valueOptions:
				if option not in allCurrentStreetValues:
					return False
		return True

	allPossiblePeople = list(itertools.product(*kProperties.values()))
	allStreets = itertools.combinations(allPossiblePeople, 5)
	for currentStreet in allStreets:
		if isUniqueProperties(currentStreet):			
			people = [dict(zip(kProperties.keys(), person)) for person in currentStreet] 
			yield street.Street(people)
	raise(NotImplementedError("didn't implement street exhaustion handeling"))