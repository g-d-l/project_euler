def g(n):
    grid = [-1 for x in range(n + 1)]
    
    def f(n):
        if grid[n] != -1:
            return grid[n]
        elif n < 2:
            grid[n] = 1
            return grid[n]
        else:
            result = 0
            for i in range(1, min(5, n + 1)):
                result += f(n - i)
            grid[n] = result
            return grid[n]
    
    return f(n)

print (g(50))
