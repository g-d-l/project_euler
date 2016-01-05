def find_cycle(x0, f):
    tortoise = f(x0)
    hare = f(f(x0))
    while tortoise != hare:
        tortoise = f(tortoise)
        hare = f(f(hare))
    
    tortoise = x0
    start = 0
    while tortoise != hare:
        tortoise = f(tortoise)
        hare = f(hare)
        start += 1
    
    period = 1
    hare = f(tortoise)
    while hare != tortoise:
        hare = f(hare)
        period += 1
    
    return start, period

def f(n):
    return (n * n) % 50515093

init = (290797 * 290797) % 50515093
start, period = find_cycle(init, f)
print(start, period)
