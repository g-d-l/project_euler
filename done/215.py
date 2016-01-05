import copy

def gen_rows(length):

	rows = []

	def recurse(holes, length, i, rows):
		if (i > length):
			return
		elif (i == length):
			rows.append(holes & (1 << length - 1) - 2)
		else:
			two = holes | 1 << (i + 2)
			three = holes | 1 << (i + 3)
			recurse(two, length, i + 2, rows)
			recurse(three, length, i + 3, rows)

	recurse(0, length, 0, rows)
	return rows


def matrix_multiply(a, b, c):
	dim1 = len(a)
	dim2 = len(b[0])
	dim3 = len(a[0])
	for i in xrange(dim1):
		for j in xrange(dim2):
			c[i][j] = 0
			for k in xrange(dim3):
				c[i][j] += a[i][k] * b[k][j]



def main():
	width = 32
	height = 10
	rows = gen_rows(width)
	nrows = len(rows)
	print nrows
	matrix = [[0 for _ in xrange(nrows)] for _ in xrange(nrows)]
	for i in xrange(nrows):
		for j in xrange(i):
			if rows[i] & rows[j] == 0:
				matrix[i][j] = 1
				matrix[j][i] = 1

	vector = [[1] for _ in xrange(nrows)]
	intermediate = copy.deepcopy(vector)
	for h in xrange(height - 1):
		matrix_multiply(matrix, intermediate, vector)
		for i in xrange(len(vector)):
			for j in xrange(len(vector[0])):
				intermediate[i][j] = vector[i][j]

	print sum([x[0] for x in vector])


if __name__ == '__main__':
	main()
