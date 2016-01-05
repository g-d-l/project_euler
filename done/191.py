days = 30

grid = [[-1 for x in range(2)] for x in range(days + 1)]

def f(d, a):
    if d >= 0 and grid[d][a] != -1:
        return grid[d][a]

    if d < 0:
        grid[d][a] = 0
        return 0
    elif d == 0:
        grid[d][a] = 1
        return 1
    elif d == 1:
        if a > 0:
            grid[d][a] = 3
            return 3
        else:
            grid[d][a] = 2
            return 2
    elif d == 2:
        if a > 0:
            grid[d][a] = f(d - 1, a - 1) + f(d - 1, a) + f(d - 2, a - 1) + f(d - 2, a) + 1
            return grid[d][a]
        else:
            grid[d][a] = f(d - 1, a) + f(d - 2, a) + 1
            return grid[d][a]
    else:
        if a > 0:
            grid[d][a] = f(d - 1, a - 1) + f(d  - 1, a) + f(d - 2, a - 1) + f(d - 2, a) + f(d - 3, a - 1) + f(d - 3, a)
            return grid[d][a]
            
        else:
            grid[d][a] = f(d  - 1, a) + f(d - 2, a) + f(d - 3, a)
            return grid[d][a]
            
print (f(30, 1))
