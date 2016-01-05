def digit_sum_base_p(n, p):
    power = 1
    while power <= n:
        power *= p
    power //= p
    result = 0
    while power >= 1:
        digit = n // power
        n -= digit * power
        result += digit
        power //= p
    
    return result

def check(i, j, k, exps_2, exps_5, limit):
    if exps_2[i] + exps_2[j] + exps_2[k] + 5 > exps_2[limit]:
        return False
    elif exps_5[i] + exps_5[j] + exps_5[k] + 5 > exps_5[limit]:
        return False
    return True

limit = 200000
exps_2 = [0 for x in range(limit + 1)]
exps_5 = [0 for x in range(limit + 1)]

for i in range(limit + 1):
    exps_2[i] = (i - digit_sum_base_p(i, 2))
    exps_5[i] = (i - digit_sum_base_p(i, 5)) // 4



result = 0
for i in range(limit // 3 + 1):
    j = i
    k = limit - i - j
    if check(i, j, k, exps_2, exps_5, limit):
        result += 3
    rest = limit - i
    if rest % 2 == 0:
        j = rest // 2
        k = j
        if check(i, j, k, exps_2, exps_5, limit):
            result += 3
    for j in range(i + 1, i + rest // 2):
        k = limit - i - j
        if check(i, j, k, exps_2, exps_5, limit):
            result += 6

print(result)
