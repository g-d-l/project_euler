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

def trial(foo, limit, k, a, b, c, d, e, f):
    series = continued_fraction(k)
    convergence = 1
    f = ith_convergent(series, convergence)
    m, n = f.numerator, f.denominator
    while m * m - k * n * n != 1:
        convergence += 1
        f = ith_convergent(series, convergence)
        m, n = f.numerator, f.denominator

    p = m
    q = -1 * c * n
    r = a * n
    s = m * b + n
    k = int((c * d * (p + s - 2) + e * (b - b * m + 2 * a * c * n)) / (4 * a * c - b * b))
    l = int((d * (b - b * m - 2 * a * c * n) + a * e * (p + s - 2)) / (4 * a * c - b * b) + d * n)
    
    x = 1
    while not is_square(x * x  + foo(x) * foo(x)):
        x += 1
    L = int(math.sqrt(x * x  + foo(x) * foo(x)))
    count = 1
    choices = [[foo(x), L]]
    while count < limit:
        x_temp = x
        L_temp = L
        x = p * x_temp + q * L_temp + k
        L = r * x_temp + s * L_temp + l
        count += 1
        choices.append([x, L])
    return choices

def minus(x):
    return 2 * x - 1

def plus(x):
    return 2 * x + 1
    
limit = 12
choices = trial(minus, limit, 5, 5, 0, -1, -4, 0, 1) + trial(plus, limit, 5, 5, 0, -1, 4, 0, 1)

choices.sort(key=lambda x: x[0])
choices = choices[:limit]
L_sum = 0
for triangle in choices:
    L_sum += triangle[1]
print(choices)
print(L_sum)
