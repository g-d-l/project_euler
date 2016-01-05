length = 50

def g(d, l):
    grid = [-1 for x in range(d + 1)]
    
    def f(d, l):
        if grid[d] != -1:
            return grid[d]
            
        if d < l:
            grid[d] = 0
            return grid[d]
        else:
            grid[d] = f(d - l, l) + f(d - 1, l) + 1
            return grid[d]
        
    return f(d, l)
    
    
print g(length, 2) + g(length, 3) + g(length, 4)
