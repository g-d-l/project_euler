import sys

def recurse(powers, base, power):
    if power == 1:
        return base
    else:
        exp = recurse(powers, base, power - 1)
        exp %= len(powers)
        return powers[exp]

powers = [1]
start = 1777
base = 1777
power = 1855
mod = int(10 ** 8)
while base != powers[0]:
    powers.append(base)
    base *= start
    base %= mod

sys.setrecursionlimit(power + 1)
print(recurse(powers, start, power))
