"""helper functions"""
import functools
import operator


def extremes(obj):
	"""returns max and min of obj"""

	return (min(obj), max(obj))

def transpose(arr):
	"""transpose a 2d array"""

	return list(map(list, zip(*arr)))

def flattenList(l):
	"""flatten a list by one layer"""
	return functools.reduce(operator.concat, l)