from fractions import Fraction
import math

def is_square(n):
    root = int(math.sqrt(n))
    if root * root == n:
        return True
    else:
        return False

def continued_fraction(n):
    series = []
    m = 0
    d = 1
    a = int(math.sqrt(n))
    series.append(a)
    while a != 2 * series[0]:
        m = d * a - m
        d = int((n - m * m) / d)
        a = int((series[0] + m) / d)
        series.append(a)
    return series
    
def ith_convergent(series, i):
    def recurse(series, i, end):
        if i == end:
            return Fraction(series[i % len(series)])
        else:
            return Fraction(series[i % len(series)]) + 1 / recurse(series, i + 1, end)
    
    result = Fraction(series[0])
    if i > 0:
        result += 1 / recurse(series[1:], 0, i - 1)
    return result

max_x = -1
max_x_d = -1
limit = 1000
for d in range(2, limit + 1):
    if not is_square(d):
        series = continued_fraction(d)
        convergence = 1
        f = ith_convergent(series, convergence)
        x, y = f.numerator, f.denominator
        while x * x - d * y * y != 1:
            convergence += 1
            f = ith_convergent(series, convergence)
            x, y = f.numerator, f.denominator
        if x > max_x:
            max_x = x
            max_x_d = d
    
print(max_x_d)
