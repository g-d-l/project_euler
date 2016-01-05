s_costs = [0 for x in xrange(11)]

s_costs[0] = 6 * 2
s_costs[1] = 2 * 2
s_costs[2] = 5 * 2
s_costs[3] = 5 * 2
s_costs[4] = 4 * 2
s_costs[5] = 5 * 2
s_costs[6] = 6 * 2
s_costs[7] = 4 * 2
s_costs[8] = 7 * 2
s_costs[9] = 6 * 2
s_costs[10] = 0 * 2


m_trans_costs = [[0 for x in xrange(11)] for x in xrange(11)]

m_trans_costs[0][0] = 0
m_trans_costs[0][1] = 4
m_trans_costs[0][2] = 3
m_trans_costs[0][3] = 3
m_trans_costs[0][4] = 4
m_trans_costs[0][5] = 3
m_trans_costs[0][6] = 2
m_trans_costs[0][7] = 2
m_trans_costs[0][8] = 1
m_trans_costs[0][9] = 2
m_trans_costs[0][10] = 6

m_trans_costs[1][1] = 0
m_trans_costs[1][2] = 5
m_trans_costs[1][3] = 3
m_trans_costs[1][4] = 2
m_trans_costs[1][5] = 5
m_trans_costs[1][6] = 6
m_trans_costs[1][7] = 2
m_trans_costs[1][8] = 5
m_trans_costs[1][9] = 4
m_trans_costs[1][10] = 2

m_trans_costs[2][2] = 0
m_trans_costs[2][3] = 2
m_trans_costs[2][4] = 5
m_trans_costs[2][5] = 4
m_trans_costs[2][6] = 3
m_trans_costs[2][7] = 5
m_trans_costs[2][8] = 2
m_trans_costs[2][9] = 3
m_trans_costs[2][10] = 5

m_trans_costs[3][3] = 0
m_trans_costs[3][4] = 3
m_trans_costs[3][5] = 2
m_trans_costs[3][6] = 3
m_trans_costs[3][7] = 3
m_trans_costs[3][8] = 2
m_trans_costs[3][9] = 1
m_trans_costs[3][10] = 5

m_trans_costs[4][4] = 0
m_trans_costs[4][5] = 3
m_trans_costs[4][6] = 4
m_trans_costs[4][7] = 2
m_trans_costs[4][8] = 3
m_trans_costs[4][9] = 2
m_trans_costs[4][10] = 4

m_trans_costs[5][5] = 0
m_trans_costs[5][6] = 1
m_trans_costs[5][7] = 3
m_trans_costs[5][8] = 2
m_trans_costs[5][9] = 1
m_trans_costs[5][10] = 5

m_trans_costs[6][6] = 0
m_trans_costs[6][7] = 4
m_trans_costs[6][8] = 1
m_trans_costs[6][9] = 2
m_trans_costs[6][10] = 6

m_trans_costs[7][7] = 0
m_trans_costs[7][8] = 3
m_trans_costs[7][9] = 2
m_trans_costs[7][10] = 4

m_trans_costs[8][8] = 0
m_trans_costs[8][9] = 1
m_trans_costs[8][10] = 7

m_trans_costs[9][9] = 0
m_trans_costs[9][10] = 6

m_trans_costs[10][10] = 0

for i in xrange(11):
    for j in xrange(i):
        m_trans_costs[i][j] = m_trans_costs[j][i]

lower_bound = 10 ** 7
upper_bound = 2 * lower_bound

def digit_sum(n):
    result = 0
    ints = []
    while n > 0:
        r = n % 10
        result += r
        n -= r
        n /= 10
        ints.append(r)
    return result, ints
    
def calc_s_cost(grid, cost_table):
    result = 0
    for i in grid:
        for j in i:
            result += cost_table[j]
    return result

def calc_m_cost(grid, cost_table):
    result = 0
    for i in grid:
        result += cost_table[10][i[0]]
        for j in xrange(0, len(i) - 1):
            result += cost_table[i[j]][i[j + 1]]
        result += cost_table[i[len(i) - 1]][10]
    return result
            
        
    

numbers = [x for x in xrange(upper_bound)]
numbers[0] = 0
numbers[1] = 0
for i in xrange(2, upper_bound):
    if numbers[i] != 0:
        for j in xrange(2 * i, upper_bound, i):
            numbers[j] = 0

primes = numbers[lower_bound:]
primes = [x for x in primes if x != 0]

s_result = 0
m_result = 0

for p in primes:
    sequences = [[] for x in xrange(8)]
    digits = []
    done = False
    while not done:
        if p < 10:
            done = True
        p, digits = digit_sum(p)
        for i in xrange(len(digits)):
            sequences[i].append(digits[i])
    s_result += calc_s_cost(sequences, s_costs)
    m_result += calc_m_cost(sequences, m_trans_costs)

print s_result - m_result

