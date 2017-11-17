"""
hints:
1. brit lives in red House
2. swede keeps dog as Pet
3. dane drinks tea 
4. green house to the left of the white house next to it 
5. green owner drinks coffee
6. the person who smokes pall mall rears birds
7. the owner of the yellow house smokes Dunhill
8. the owner living in the house in the center drinks milk
9. the norwegian lives in the first house
10. the man who smokes blend lives next to the one who keeps cats 
11. the man who keeps horses lives next to the man who smokes dunhill 
12. the owner who smokes blue master drinks beer
13. the german smokes prince 
14. the norwegian lives next to the blue house
15. the man who smokes blend has a neigbor who drinks water
"""

"""Hints: return True if they apply. In street that is answer, all should apply, and be True"""
def hint1(street):
	"""brit lives in red House"""
	return street.getPersonBy("nationality", "brit")["house color"] == "red"

def hint2(street):
	"""swede keeps dog as Pet"""
	return street.getPersonBy("nationality", "swede")["pet"] == "dog"

def hint3(street):
	"""dane drinks tea """
	return street.getPersonBy("nationality", "dane")["beverage"] == "tea"

def hint4(street):
	"""green house to the left of the white house next to it """
	whiteHouse = street.getPersonBy("house color", "white")
	return street.hasLeftHouse(whiteHouse) and street.getLeftHouse(whiteHouse)["house color"] == "green"

def hint5(street):
	"""green owner drinks coffee"""
	return street.getPersonBy("house color", "green")["beverage"] == "coffee"

def hint6(street):
	"""the person who smokes pall mall rears birds"""
	return street.getPersonBy("cigar", "pall mall")["pet"] == "bird"

def hint7(street):
	"""the owner of the yellow house smokes Dunhill"""
	return street.getPersonBy("house color", "yellow")["cigar"] == "dunhill"

def hint8(street):
	"""the owner living in the house in the center drinks milk"""
	return street.getPersonBy("house number", "3")["beverage"] == "milk"

def hint9(street):
	"""the norwegian lives in the first house"""
	return street.getPersonBy("house number", "1")["nationality"] == "norwegian"

def hint10(street):
	"""the man who smokes blend lives next to the one who keeps cats """
	neighbors = street.getNeighbors(street.getPersonBy("cigar", "blend"))
	return any([neighbor["pet"] == "cat" for neighbor in neighbors])

def hint11(street):
	"""the man who keeps horses lives next to the man who smokes dunhill """
	neighbors = street.getNeighbors(street.getPersonBy("pet", "horse"))
	return any([neighbor["cigar"] == "dunhill" for neighbor in neighbors])

def hint12(street):
	"""the owner who smokes blue master drinks beer"""
	return street.getPersonBy("cigar", "blue master")["beverage"] == "beer"

def hint13(street):
	"""the german smokes prince """
	return street.getPersonBy("nationality", "german")["cigar"] == "prince"

def hint14(street):
	"""the norwegian lives next to the blue house"""
	neighbors = street.getNeighbors(street.getPersonBy("nationality", "norwegian"))
	return any([neighbor["house color"] == "blue" for neighbor in neighbors])

def hint15(street):
	"""the man who smokes blend has a neigbor who drinks water"""
	neighbors = street.getNeighbors(street.getPersonBy("cigar", "blend"))
	return any([neighbor["beverage"] == "water" for neighbor in neighbors])