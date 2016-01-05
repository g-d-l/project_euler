from sets import Set
import copy, itertools

'''
01
04
09
16
25
36
49
64
81


if digits satisfied:
	continue
else if only one in:
	recurse on that one if space
else if neither satisfied:
	recurse on both if space

if digits different:
	flip, repeat

'''

def can_represent(cube, n):
	if n in cube:
		return True
	elif n == 6 and 9 in cube:
		return True
	elif n == 9 and 6 in cube:
		return True
	return False


def recurse(cube1, cube2, numbers, index, arrangements):
	if index == len(numbers):
		open1 = 6 - len(cube1)
		open2 = 6 - len(cube2)
		choices1 = [x for x in range(10) if x not in cube1]
		choices2 = [x for x in range(10) if x not in cube2]
		for leftover1 in itertools.combinations(choices1, open1):
			for leftover2 in itertools.combinations(choices2, open2):
				for v in leftover1:
					cube1.add(v)
				for v in leftover2:
					cube2.add(v)
				t1 = tuple(cube1)
				t2 = tuple(cube2)
				if tuple([t2, t1]) not in arrangements:
					arrangements.add(tuple([t1, t2]))
				for v in leftover1:
					cube1.remove(v)
				for v in leftover2:
					cube2.remove(v)
		return

	ldig, rdig = numbers[index]
	loops = 1 if ldig == rdig else 2
	x = False
	for i in xrange(loops):
		new_cube1 = copy.copy(cube1)
		new_cube2 = copy.copy(cube2)
		if can_represent(cube1, ldig) and can_represent(cube2, rdig):
			recurse(new_cube1, new_cube2, numbers, index + 1, arrangements)
		elif not can_represent(cube1, ldig) and can_represent(cube2, rdig) and len(cube1) < 6:
			x = True
			new_cube1.add(ldig)
			recurse(new_cube1, new_cube2, numbers, index + 1, arrangements)
			if ldig == 6:
				new_cube1.remove(ldig)
				new_cube1.add(9)
				recurse(new_cube1, new_cube2, numbers, index + 1, arrangements)
			elif ldig == 9:
				new_cube1.remove(ldig)
				new_cube1.add(6)
				recurse(new_cube1, new_cube2, numbers, index + 1, arrangements)
		elif can_represent(cube1, ldig) and not can_represent(cube2, rdig) and len(cube2) < 6:
			x = True
			new_cube2.add(rdig)
			recurse(new_cube1, new_cube2, numbers, index + 1, arrangements)
			if rdig == 6:
				new_cube2.remove(rdig)
				new_cube2.add(9)
				recurse(new_cube1, new_cube2, numbers, index + 1, arrangements)
			elif rdig == 9:
				new_cube2.remove(rdig)
				new_cube2.add(6)
				recurse(new_cube1, new_cube2, numbers, index + 1, arrangements)
		elif not can_represent(cube1, ldig) and not can_represent(cube2, rdig) and len(cube1) < 6 and len(cube2) < 6:
			x = True
			new_cube1.add(ldig)
			new_cube2.add(rdig)
			recurse(new_cube1, new_cube2, numbers, index + 1, arrangements)
			if ldig == 6:
				new_cube1.remove(ldig)
				new_cube1.add(9)
				recurse(new_cube1, new_cube2, numbers, index + 1, arrangements)
			elif ldig == 9:
				new_cube1.remove(ldig)
				new_cube1.add(6)
				recurse(new_cube1, new_cube2, numbers, index + 1, arrangements)
			if rdig == 6:
				new_cube2.remove(rdig)
				new_cube2.add(9)
				recurse(new_cube1, new_cube2, numbers, index + 1, arrangements)
			elif rdig == 9:
				new_cube2.remove(rdig)
				new_cube2.add(6)
				recurse(new_cube1, new_cube2, numbers, index + 1, arrangements)
		
		ldig, rdig = rdig, ldig
	

def main():
	cube1 = Set()
	cube2 = Set()
	numbers = [str(x ** 2).zfill(2) for x in xrange(1,10)]
	numbers = [[int(c) for c in s] for s in numbers]
	index = 0
	arrangements = Set()
	recurse(cube1, cube2, numbers, index, arrangements)
	print len(arrangements)


if __name__ == '__main__':
	main()


