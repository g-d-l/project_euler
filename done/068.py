import itertools
from sets import Set


def main():

	ngon = 5
	values = range(1, 11)
	triples = [[0, 0, 0] for _ in xrange(ngon)]
	result = ''
	for assignment in itertools.permutations(range(1, 10), ngon):
		for i in xrange(ngon - 1):
			triples[i][1], triples[i][2] = assignment[i], assignment[i + 1]
		triples[ngon - 1][1], triples[ngon - 1][2] = assignment[ngon - 1], assignment[0]
		pair_sums = [sum(x) for x in triples]
		seen = Set()
		has_dups = False
		for ps in pair_sums:
			if ps in seen:
				has_dups = True
				break
			else:
				seen.add(ps)
		if has_dups:
			continue
		if max(pair_sums) > min(pair_sums) + 9:
			continue
		externals = [x for x in values if x not in assignment]
		line_sum = sum(pair_sums) / ngon + sum(externals) / len(externals)
		for i in xrange(ngon):
			triples[i][0] = line_sum - pair_sums[i]

		start_index = pair_sums.index(max(pair_sums))
		ordered = [str(x) for sublist in triples[start_index:] + triples[:start_index] for x in sublist]
		str_form = ''.join(ordered)
		if str_form > result:
			result = str_form

		for triple in triples:
			triple[0] = 0

	print result



if __name__ == '__main__':
	main()
