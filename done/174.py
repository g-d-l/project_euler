def main():
	t_max = 1000000
	factors = [1 for _ in xrange(t_max + 1)]
	for i in xrange(2, t_max + 1):
		for j in xrange(i, t_max + 1, i):
			factors[j] += 1

	l_counts = {}
	for t in xrange(4, t_max + 1, 4):
		npairs = factors[t / 4] / 2
		if npairs in l_counts:
			l_counts[npairs] += 1
		else:
			l_counts[npairs] = 1

	result = 0
	for n in xrange(1, 11):
		if n in l_counts:
			result += l_counts[n]

	print result

if __name__ == '__main__':
	main()

1, 32
