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

series = continued_fraction(2)
convergence = 1
f = ith_convergent(series, convergence)
x, y = f.numerator, f.denominator
while x * x - 2 * y * y != 1:
    convergence += 1
    f = ith_convergent(series, convergence)
    x, y = f.numerator, f.denominator

p = x
q = y
r = 2 * y
s = x
k = int((-1 * -2 * (p + s - 2) + (-2 * 2 * -1 * y)) / (4 * 2 * -1))
l = int((-2 * (-2 * 2 * -1 * y) + 2 * (p + s - 2)) / (4 * 2 * -1) + -2 * y)

b = 15
t = 21
limit = 1000000000000
while t <= limit:
    b_temp = b
    t_temp = t
    b = p * b_temp + q * t_temp + k
    t = r * b_temp + s * t_temp + l

print(b)
