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
 
def gen_primes(n):
    array = [True for x in range(n + 1)]
    array[0] = False
    array[1] = False
    for i in range(2, n + 1):
        if array[i]:
            for j in range(2 * i, n + 1, i):
                array[j] = False
    
    return array
    
n = 20000000
k = 15000000
is_prime = gen_primes(n)
primes = [i for i in range(n + 1) if is_prime[i]]

result = 0
for i in range(len(primes)):
    p = primes[i]
    exp_n = (n - digit_sum_base_p(n, p)) // (p - 1)
    exp_k = (k - digit_sum_base_p(k, p)) // (p - 1)
    exp_nk = ((n - k) - digit_sum_base_p(n - k, p)) // (p - 1)
    result += p * (exp_n - exp_k - exp_nk)

print(result)
