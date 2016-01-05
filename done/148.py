def dec_to_base_n(x, n):
    val = []
    power = 1
    while power < x:
        power *= n
    power //= n;
    while x > 0:
        digit = x // power
        val.append(digit)
        x -= digit * power
        power //= 7
    return val

def summation(n):
    return (n * (n + 1)) // 2

rows = 1000000000
mod = 7
val = dec_to_base_n(rows, mod)
powers = [1 for x in range(len(val))]
for i in range(len(powers) - 2, -1, -1):
    powers[i] = powers[i + 1] * summation(mod)

result = 0
multiplier = 1
for i, e in enumerate(val):
    x = multiplier * powers[i] * summation(e)
    result += x
    if e != 0:
        multiplier *= e + 1
print(result)
