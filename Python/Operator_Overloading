#!/usr/bin/python

import math

class Vector:
	def __init__(self, a, b):
		self.a = a
		self.b = b
	def __str__(self):
		return "Vector (%d, %d)"%(self.a, self.b)
	def __add__(self, other):
		return Vector(self.a+other.a, self.b+other.b)
	def __sub__(self, other):
		return Vector(self.a-other.a, self.b-other.b)
	def __mul__(self, other):
		return Vector(self.a*other.a, self.b*other.b)
	def __floordiv__(self, other):
		return self.a / self.b
	def __mod__(self, other):
		return self.a % self.b
	def __divmod__(self, other):
		return self.a % self.b
	def __pow__(self, other):
		return math.pow(self.a, other.a)
	def __lshift__(self, other):
		return self.a << other.a
	def __rshift__(self, other):
		return self.a >> other.a
	def __and__(self, other):
		return self.a & other.a
	def __xor__(self, other):
		return self.a ^ other.a
	def __or__(self, other):
		return self.a | other.a
	 		
if __name__ == '__main__':
	v1 = Vector(2, 10)
	v2 = Vector(5, -2)
	print v1+v2
	print v1*v2
	print v1 | v2
	print v1 << v2
	print v1 & v2
