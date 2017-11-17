"""A potential street in Einsteins riddle"""

from utils import extremes
import street_generators

class Street(object):
	"""A potential street in Einsteins riddle"""

	def __init__(self, people):
		"""assumes people has unique properties"""		
		self.people = people
	
	def getPersonBy(self, propertyName, propertyValue):
		for person in self.people:
			if person[propertyName] == propertyValue:
				return person
		raise(KeyError("didn't find person {} = {} in street: {}".format(propertyName, propertyValue, self)))

	def hasLeftHouse(self, person):
		houseNumberPropertyName = "house number"
		houseNumber = person[houseNumberPropertyName]
		minHouseNumber, maxHouseNumber = [str(x) for x in extremes([int(i) for i in street_generators.kProperties[houseNumberPropertyName]])]
		return houseNumber != minHouseNumber

	def getLeftHouse(self, person):
		houseNumberPropertyName = "house number"
		houseNumber = person[houseNumberPropertyName]
		if self.hasLeftHouse(person):
			return self.getPersonBy(houseNumberPropertyName, str(int(houseNumber) - 1))
		raise(KeyError("Person {} doesn't have a left house in street {}".format(person, self)))

	def hasRightHouse(self, person):
		houseNumberPropertyName = "house number"
		houseNumber = person[houseNumberPropertyName]
		minHouseNumber, maxHouseNumber = [str(x) for x in extremes([int(i) for i in kProperties[houseNumberPropertyName]])]
		return houseNumber != maxHouseNumber

	def getRightHouse(self, person):
		houseNumberPropertyName = "house number"
		houseNumber = person[houseNumberPropertyName]
		if self.hasRightHouse(person):
			return self.getPersonBy(houseNumberPropertyName, str(int(houseNumber) - 1))
		raise(KeyError("Person {} doesn't have a right house in street {}".format(person, self)))

	def getNeighbors(self, person):
		neighbors = []
		if self.hasLeftHouse(person):
			neighbors.append(self.getLeftHouse(person))
		if self.hasRightHouse(person):
			neighbors.append(self.getRightHouse(person))
		return neighbors

	def __str__(self):
		return str(self.people)