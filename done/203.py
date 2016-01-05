def gen_primes(n):
    is_prime = [True for x in range(n + 1)]
    is_prime[0] = False
    is_prime[1] = False
    for i in range(2, n + 1):
        if is_prime[i]:
            for j in range(2 * i, n + 1, i):
                is_prime[j] = False
    
    primes = [x for x in range(n + 1) if is_prime[x]]
    return primes

def sum_digits_base_p(n, p):
    power = 1
    while power < n:
        power *= p
    
    result = 0
    while n > 0:
        if n >= power:
            digit = n // power
            n -= digit * power
            power //= p
            result += digit
        else:
            power //= p
    return result

def factorial(n1, n2):
    if n1 == n2:
        return 1
    else:
        return n1 * factorial(n1 - 1, n2)

def binom(n, k):
    k1 = max(k, n - k)
    k2 = n - k1
    return factorial(n, k1) // (factorial(k2, 0))

def factorial_exp(n, p):
    return (n - sum_digits_base_p(n, p)) // (p - 1)

rows = 51
saved = {}
result = 0
primes = gen_primes(rows)

for n in range(1, rows):
    cols = n // 2
    if cols % 2 == 0:
        cols += 1
    for k in range(cols + 1):
        val = binom(n, k)
        if val not in saved:
            for p in primes:
                exp_n = factorial_exp(n, p)
                exp_k = factorial_exp(k, p)
                exp_nk = factorial_exp(n - k, p)
                if exp_n > exp_k + exp_nk + 1:
                    break
            else:
                result += val
            saved[val] = 1

print(result)
