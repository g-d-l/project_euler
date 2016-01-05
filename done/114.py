def g(m, n):
    grid = [-1 for x in range(n + 1)]
    
    def f(m, n):
        if grid[n] != -1:
            return grid[n]
        elif n < m:
            grid[n] = 1
            return grid[n]
        else:
            result = f(m, n - 1)
            for i in range(m, n + 1):
                result += f(m, n - i - 1)
            grid[n] = result
            return grid[n]
    
    return f(m, n)

print (g(3, 50))
