class elt(object):
    def __init__(self, val):
        self.val = val
        self.starred = False
        self.primed = False
 

### STEP 3 ### 
def step_3(matrix, row_covs, col_covs):
    transpose = zip(*matrix)
    count = 0
    for i in range(len(transpose)):
        test = [x for x in transpose[i] if x.starred]
        if len(test) > 0:
            col_covs[i] = True
            count += 1
    if count == len(transpose):
        return matrix
    else:
        return step_4(matrix, row_covs, col_covs)


### STEP 4 ### 
def step_4(matrix, row_covs, col_covs):
    
    def find_uncov_zero(matrix, row_covs, col_covs):
        for r in range(len(matrix)):
            for c in range(len(matrix[r])):
                if matrix[r][c].val == 0 and not row_covs[r] and not col_covs[c]:
                    return r, c
        return -1, -1
     
    while True:
        r, c = find_uncov_zero(matrix, row_covs, col_covs)
        if r == -1:
            return step_6(matrix, row_covs, col_covs)
        else:
            matrix[r][c].primed = True
            col = -1
            for i in range(len(matrix[r])):
                if matrix[r][i].starred:
                    col = i
                    break
            if col != -1:
                row_covs[r] = True
                col_covs[col] = False
            else:
                return step_5(matrix, row_covs, col_covs, r, c)
     

### STEP 5 ### 
def step_5(matrix, row_covs, col_covs, r, c):
    def find_starred_zero(matrix, c):
        col = [matrix[i][c].starred for i in range(len(matrix))]
        for r in range(len(col)):
            if col[r] == 1:
                return r
        return None
         
    series = [[r, c]]
    next_r = find_starred_zero(matrix, c)
    next_c = c
    while next_r != None:
        series.append([next_r, next_c])
        for c in range(len(matrix[0])):
            if matrix[next_r][c].val == 0 and matrix[next_r][c].primed:
                next_c = c
                break
        series.append([next_r, next_c])
        next_r = find_starred_zero(matrix, next_c)
    
    primed = series[0:len(series):2]
    starred = series[1:len(series):2]

    for r, c in starred:
        matrix[r][c].starred = False
    for r, c in primed:
        matrix[r][c].starred = True
    
    for r in range(len(matrix)):
        for c in range(len(matrix[r])):
            matrix[r][c].primed = False
    
    row_covs = [False for x in range(len(matrix))]
    col_covs = [False for x in range(len(matrix[0]))]
    return step_3(matrix, row_covs, col_covs)
    
    
### STEP 6 ### 
def step_6(matrix, row_covs, col_covs):
    smallest = max([x for y in matrix for x in y])
    for r in range(len(matrix)):
        for c in range(len(matrix[r])):
            if not row_covs[r] and not col_covs[c]:
                if matrix[r][c].val < smallest:
                    smallest = matrix[r][c].val
                    
    for r in range(len(row_covs)):
        if row_covs[r]:
            for c in range(len(col_covs)):
                matrix[r][c].val += smallest
     
    for c in range(len(col_covs)):
        if not col_covs[c]:
            for r in range(len(row_covs)):
                matrix[r][c].val -= smallest
    
    return step_4(matrix, row_covs, col_covs)

def hungarian_algorithm(costs):
    k = min(len(costs), len(costs[0]))
    if len(costs) < len(costs[0]):
        costs = zip(*costs[::-1])
     
    matrix = [[elt(costs[i][j]) for j in range(len(costs[0]))] for i in range(len(costs))]

    ### STEP 1 ###
    for row in matrix:
        smallest = row[0].val
        for c in range(len(row)):
            if row[c].val < smallest:
                smallest = row[c].val
        for j in range(len(row)):
            row[j].val -= smallest

    ### STEP 2
    for r in range(len(matrix)):
        for c in range(len(matrix[r])):
            if matrix[r][c].val == 0:
                temp = [matrix[i][c] for i in range(len(matrix))]
                col = [x for x in temp if x.starred]
                row = [x for x in matrix[r] if x.starred]
                if (len(col) == 0) and (len(row) == 0):
                    matrix[r][c].starred = True
    
    row_covs = [False for x in range(len(matrix))]
    col_covs = [False for x in range(len(matrix[0]))]

    return step_3(matrix, row_covs, col_covs)



data = []
with open('345_input.txt', 'r') as f:
    data = f.readlines()
f.close()

costs = [[int(x) for x in row.split()] for row in data]

costs_temp = []
for row in costs:
	costs_temp.append(row[:])

maximum = max([x for y in costs for x in y])
for r in range(len(costs_temp)):
    for c in range(len(costs_temp[r])):
        costs_temp[r][c] = maximum - costs_temp[r][c]

result = hungarian_algorithm(costs_temp)

max_sum = 0
for r in range(len(result)):
    for c in range(len(row)):
        if result[r][c].starred:
            max_sum += costs[r][c]
            break

print(max_sum)
