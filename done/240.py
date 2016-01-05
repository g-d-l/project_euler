def factorial(n):
    if n == 0:
        return 1
    else:
        return n * factorial(n - 1)

def n_choose_k(n, k):
    return factorial(n) // (factorial(k) * factorial(n - k))

def distributions(n, k, m):
    def recurse(n, k, kcount, m, grid):
        if grid[n][k] != -1:
            return grid[n][k]
        elif n == 0:
            grid[n][k] = 1
            return grid[n][k]
        elif k >= kcount:
            return 0
        else:
            result = 0
            for b in range(min(n + 1, m + 1)):
                result += recurse(n - b, k + 1, kcount, m, grid)
            grid[n][k] = result
            return grid[n][k]
    
    grid = [[-1 for x in range(k + 1)] for y in range(n + 1)]
    return recurse(n, 0, k, m, grid)

def int_pow(base, power):
    if power == 0:
        return 1
    else:
        return base * int_pow(base, power - 1)

ndice = 20
nsides = 12
topn = 10
top_sum = 70

result = 0

for topmin in range(1, nsides + 1):
    for ntopmin in [x for x in range(1, topn + 1) if (top_sum - x * topmin >= (topn - x) * (topmin + 1) and top_sum - x * topmin <= (topn - x) * nsides)]:
        upper_sum = top_sum - ntopmin * topmin
        for extramins in range((ndice - topn) + 1):
            lower_arrangements = int_pow(topmin - 1, ndice - topn - extramins)
            upper_arrangements = n_choose_k(topn + extramins, extramins + ntopmin) * distributions(upper_sum - (topn - ntopmin) * (topmin + 1), topn - ntopmin, nsides - (topmin + 1))
            g = lower_arrangements * upper_arrangements * n_choose_k(ndice, topn + extramins)
            result += g
            
            
print(result)
