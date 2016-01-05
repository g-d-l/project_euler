
'''
cache[length][ends_in][hit 0?][hit 9?]

98765432101
89876543210
10123456789


126461847755
 64203722859
'''
def main():
	digits = range(10)
	max_len = 40
	cache = [[[[0 for _ in xrange(2)] for _ in xrange(2)] for _ in digits] for _ in xrange(max_len + 1)]
	
	for d in digits:
		cache[1][d][0][0] = 1
		cache[1][d][0][1] = 0
		cache[1][d][1][0] = 0
		cache[1][d][1][1] = 0

	cache[1][0][0][0] = 0
	cache[1][0][0][1] = 0
	cache[1][0][1][0] = 0
	cache[1][0][1][1] = 0

	cache[1][9][0][0] = 0
	cache[1][9][0][1] = 1
	cache[1][9][1][0] = 0
	cache[1][9][1][1] = 0

	for l in xrange(2, max_len + 1):

		cache[l][0][0][0] = 0
		cache[l][0][0][1] = 0
		cache[l][0][1][0] = cache[l - 1][1][1][0] + cache[l - 1][1][0][0]
		cache[l][0][1][1] = cache[l - 1][1][1][1] + cache[l - 1][1][0][1]

		for d in xrange(1, 9):
			cache[l][d][0][0] = cache[l - 1][d - 1][0][0] + cache[l - 1][d + 1][0][0]
			cache[l][d][0][1] = cache[l - 1][d - 1][0][1] + cache[l - 1][d + 1][0][1]
			cache[l][d][1][0] = cache[l - 1][d - 1][1][0] + cache[l - 1][d + 1][1][0]
			cache[l][d][1][1] = cache[l - 1][d - 1][1][1] + cache[l - 1][d + 1][1][1]


		cache[l][9][0][0] = 0
		cache[l][9][0][1] = cache[l - 1][8][0][1] + cache[l - 1][8][0][0]
		cache[l][9][1][0] = 0
		cache[l][9][1][1] = cache[l - 1][8][1][1] + cache[l - 1][8][1][0]

	result = 0
	for l in xrange(10, max_len + 1):
		for d in digits:
			result += cache[l][d][1][1]
			
	print result


if __name__ == '__main__':
	main()