def gen_primes_composites(n):
    is_prime = [True for x in range(n + 1)]
    is_prime[0] = False
    is_prime[1] = False
    for i in range(2, n + 1):
        if is_prime[i]:
            for j in range(2 * i, n + 1, i):
                is_prime[j] = False
    primes = [x for x in range(n + 1) if is_prime[x]]
    composities = [x for x in range(2, n + 1) if not is_prime[x]]
    return primes, composities
 
def digital_root(n):
    while n >= 10:
        digit_sum = 0
        while n > 0:
            digit = n % 10
            digit_sum += digit
            n = (n - digit) // 10
        n = digit_sum
    return n
 
def longest_com_subseq_indices(a, b):
    def recurse(a, i, b, j, grid):
        if i >= len(a) or j >= len(b):
            return []
        elif grid[i][j] != -1:
            return grid[i][j]
        elif a[i] == b[j]:
            result = recurse(a, i + 1, b, j + 1, grid)
            result.append([i, j])
            grid[i][j] = result
            return grid[i][j]
        else:
            down = recurse(a, i + 1, b, j, grid)
            right = recurse(a, i, b, j + 1, grid)
            if len(down) > len(down):
                grid[i][j] = down
            else:
                grid[i][j] = down
            return grid[i][j]
     
    grid = [[-1 for x in range(len(b))] for y in range(len(a))]
    result = recurse(a, 0, b, 0, grid)
    return result[::-1]
    '''
    def backtrace(a, i, b, j, grid):
        if i < 0 or j < 0:
            return []
        elif a[i] == b[j]:
            rest = backtrace(a, i - 1, b, j - 1, grid)
            rest.append([i, j])
            return rest
        else:
            if grid[i][j - 1] > grid[i - 1][j]:
                return backtrace(a, i, b, j - 1, grid)
            elif grid[i][j - 1] < grid[i - 1][j]:
                return backtrace(a, i - 1, b, j, grid)
            else:
                left = backtrace(a, i, b, j - 1, grid)
                up = backtrace(a, i - 1, b, j, grid)
                if len(left) > len(up):
                    return left
                else:
                    return up
    for r in grid:
        print(r)
    return backtrace(a, len(a) - 1, b, len(b) - 1, grid)
    '''

n = 10
primes, composites = gen_primes_composites(20 * n)
primes = primes[:n]
composites = composites[:n]
for i in range(n):
    primes[i] = digital_root(primes[i])
    composites[i] = digital_root(composites[i])

indices = longest_com_subseq_indices(primes, composites)
print(indices)
super_int = [0 for x in range(2 * n - len(indices))]
p = 0
c = 0
i = 0
x = 0
while True:
    if p >= n:
        for j in range(c, n):
            super_int[x] = composites[j]
            x += 1
        break
    elif c >= n:
        for j in range(p, n):
            super_int[x] = composites[j]
            x += 1
        break
    elif i >= len(indices) or (p < indices[i][0] and c < indices[i][1]):
        if primes[p] < composites[c]:
            super_int[x] = primes[p]
            p += 1
        else:
            super_int[x] = composites[c]
            c += 1
        x += 1
    elif p == indices[i][0]:
        for j in range(c, indices[i][1] + 1):
            super_int[x] = composites[j]
            x += 1
        p += 1
        c = indices[i][1] + 1
        i += 1
    elif c == indices[i][1]:
        for j in range(p, indices[i][0] + 1):
            super_int[x] = primes[j]
            x += 1
        c += 1
        p = indices[i][0] + 1
        i += 1

result = 0
for i in range(len(super_int)):
    result = result * 10 + super_int[i]

print(result)

'''
357

2     3 5   7 248152
46891 3 5 6 7 9

2357246891352679
2357246891352679
235724 8 1 52
     4689135 679

'''
