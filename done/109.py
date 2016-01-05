def factorial(n):
	product = 1
	for i in xrange(2, n + 1):
		product *= i
	return product


def n_choose_k_replac(n, k):
	n1 = n + k - 1
	return factorial(n1) / (factorial(k) * factorial(n1 - k))



def main():	
	regions = [0 for _ in xrange(61)]
	for x in xrange(1, 21):
		regions[x] += 1
		regions[2 * x] += 1
		regions[3 * x] += 1
	regions[25] += 1
	regions[50] += 1

	max_score = 99
	num_throws = 3
	cache = [[[0 for _ in xrange(num_throws)] for _ in xrange(len(regions))] for _ in xrange(max_score + 1)]
	for points in xrange(len(regions)):
		cache[0][points][0] = 1
	for score in xrange(1, max_score + 1):
		for points in xrange(1, len(regions)):
			choices = regions[points]
			for throws in xrange(num_throws):
				cache[score][points][throws] += cache[score][points - 1][throws]
				if choices > 0:
					for t in xrange(1, throws + 1):
						if (t * points > score):
							break;
						cache[score][points][throws] += n_choose_k_replac(choices, t) * cache[score - t * points][points - 1][throws - t]

	result = 0
	for checkout in xrange(2, max_score + 1):
		for double in xrange(2, min(checkout + 1, 41), 2):
			for throws in xrange(num_throws):
				result += cache[checkout - double][len(regions) - 1][throws]
		if (checkout >= 50):
			for throws in xrange(num_throws):
				result += cache[checkout - 50][len(regions) - 1][throws]

	print result

if __name__ == '__main__':
	main()
