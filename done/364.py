def get_powers(base, power, mod):
    powers = [0 for x in xrange(power + 1)]
    powers[0] = 1
    for i in xrange(1, power + 1):
        powers[i] = (base * powers[i - 1]) % mod
    return powers

def get_factorials(n, mod):
    factorials = [0 for x in xrange(n + 1)]
    factorials[0] = 1
    for i in xrange(1, n + 1):
        factorials[i] = (i * factorials[i - 1]) % mod
    return factorials

def get_inv_factorials(n, mod):
    inv_factorials = [0 for x in xrange(n + 1)]
    inv_factorials[0] = 1
    inv_factorials[1] = 1
    for i in xrange(2, n + 1):
        inv_factorials[i] = ((mod - mod // i) * inv_factorials[mod % i]) % mod
    for i in xrange(2, n + 1):
        inv_factorials[i] = (inv_factorials[i] * inv_factorials[i - 1]) % mod
    return inv_factorials

def n_choose_k(n, k, factorials, inv_factorials, mod):
    result = factorials[n] * inv_factorials[k] * inv_factorials[n - k]
    return result % mod

def solve(n, mod):
    powers2 = get_powers(2, n, mod)
    factorials = get_factorials(n, mod)
    inv_factorials = get_inv_factorials(n, mod)
    result = 0
    for b in xrange(4):
        ends = bin(b).count("1")
        n2 = n - ends
        for twos in xrange((n2 - 1) // 3 + 1):
            ones = n2 - 1 - 3 * twos
            if ones % 2 == 0:
                ones //= 2
                temp = n_choose_k(ones + twos, ones, factorials, inv_factorials, mod)
                temp *= factorials[ones + twos + 1]
                temp %= mod
                temp *= powers2[twos]
                temp %= mod
                temp *= factorials[twos + ends]
                temp %= mod
                temp *= factorials[ones + twos]
                temp %= mod
                result += temp
                result %= mod
    return result

print(solve(1000000, 100000007))
