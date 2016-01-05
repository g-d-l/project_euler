from math import *

def gen_perf_sqrs(n):
	array = [False for x in range(n + 1)]
	lim = int(sqrt(n))
	for i in range(1, lim + 1):
		array[i ** 2] = True
	return array

def count_paths(n):
	perf_sqrs = gen_perf_sqrs(2 * n)
	memoized = [0 for x in range(n + 1)]
	memoized[0] = 1
	for x in range(n + 1):
		print x
		for y in range(1, n + 1):
			if not (perf_sqrs[x] and perf_sqrs[y] and perf_sqrs[x + y]):
				memoized[y] += memoized[y - 1]
				memoized[y] %= 1000000007
			else:
				memoized[y] = 0
	return memoized[n]

print(count_paths(10000000))
