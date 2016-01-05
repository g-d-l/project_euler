def r_max(n):
    if n % 2 == 1:
        return n * (n - 1)
    else:
        return n * (n - 2)

result = 0
for a in range(3, 1001):
    result += r_max(a)

print(result)
