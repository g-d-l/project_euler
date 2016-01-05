from sets import Set
'''
num = a | b | c | d
exp = num | exp + exp | exp / exp | exp - exp | exp * exp
'''
def recurse(available_nums, cached_nums):
	if len(available_nums) == 1:
		return available_nums

	t = tuple(available_nums)
	if t in cached_nums:
		return cached_nums[t]
	else:
		results = Set()
		for x in available_nums:
			remaining = [y for y in available_nums if y != x]
			choices = recurse(remaining, cached_nums)
			for c in choices:
				results.add(x + c)
				results.add(x * c)
				results.add(x - c)
				results.add(c - x)
				if abs(c) > 0.00001:
					results.add(x / c)
		cached_nums[t] = results
		return results

			


def find_longest_seq(nums, cached_nums):
	results = set([int(round(x)) for x in recurse(nums, cached_nums) if x > 0. and abs(round(x) - x) < 0.00001])
	results = sorted([x for x in results])
	if results[0] != 1:
		return 0
	index = 1
	while (results[index] == results[index - 1] + 1 or results[index] == results[index - 1]):
		index += 1
	return index


def main():
	cached_nums = {}
	
	lim = 10
	longest = 0
	longest_digits = None
	for a in xrange(1, lim):
		for b in xrange(a + 1, lim):
			for c in xrange(b + 1, lim):
				for d in xrange(c + 1, lim):
					lst = [float(a), float(b), float(c), float(d)]
					length = find_longest_seq(lst, cached_nums)
					if length > longest:
						longest = length
						longest_digits = lst
	print str([int(x) for x in longest_digits])

if __name__ == '__main__':
	main()


