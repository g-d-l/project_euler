def solve(n):
    def recurse(m, a, b, saved):
        if saved[m][a][b] != -1:
            return saved[m][a][b]
        elif m == 0:
            saved[m][a][b] = 9 - (a + b)
            return saved[m][a][b]
        else:
            result = 0
            for d in range(0, 9 - (a + b) + 1):
                result += recurse(m - 1, d, a, saved)
            saved[m][a][b] = result
            return saved[m][a][b]
    
    saved = [[[-1 for x in range(10)] for y in range(10)] for z in range(n)]
    recurse(n - 1, 0, 0, saved)
    return(saved[n - 1][0][0])

print(solve(20))
