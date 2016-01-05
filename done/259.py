from sets import Set


def recurse(i, j, nums, cache):
	if i == j:
		cache[i][i] = Set()
		cache[i][i].add(nums[i])
		return cache[i][i]
	elif i + 1 == j:
		cache[i][j] = Set()
		a, b = nums[i], nums[j]
		cache[i][j].add(a + b)
		cache[i][j].add(a * b)
		cache[i][j].add(float(a) / float(b))
		cache[i][j].add(a - b)
		cache[i][j].add(10. * a + b)
		return cache[i][j]

	elif cache[i][j] != None:
		return cache[i][j]
	else:
		results = Set()
		for k in xrange(i, j):
			left = recurse(i, k, nums, cache)
			right = recurse(k + 1, j, nums, cache)
			for a in left:
				for b in right:
					v = a + b
					if abs(v) <= 0.0000000001:
						v = 0.
					results.add(v)

					v = a * b
					if abs(v) <= 0.0000000001:
						v = 0.
					results.add(v)

					v = a - b
					if abs(v) <= 0.0000000001:
						v = 0.
					results.add(v)

					if b != 0.0 :
						v = float(a) / float(b)
						if abs(v) <= 0.0000000001:
							v = 0.
						results.add(v)
						
		chars = [str(n) for n in nums[i:j + 1]]
		concat = int(''.join(chars))
		results.add(concat)
		cache[i][j] = results
		return cache[i][j]

def main():
	lower = 1
	upper = 9
	nums = range(lower, upper + 1)
	cache = [[None for _ in xrange(upper + 1)] for _ in xrange(upper)]
	recurse(lower - 1, upper - 1, nums, cache)
	integers = Set()
	for x in cache[lower - 1][upper - 1]:
		if x > 0.5 and abs(round(x) - x) <= 0.00000001:
			integers.add(int(round(x)))
	total = sum(list(integers))
	print total


if __name__ == '__main__':
	main()


