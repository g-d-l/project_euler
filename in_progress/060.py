def gen_primes(n):
    array = [True] * n
    array[0] = False
    array[1] = False
    for i in range(n):
        if array[i] == True:
            for j in range(2 * i, n, i):
                array[j] = False
    return array
 
def is_prime(n, prime_bool):
    if n < len(prime_bool):
        return prime_bool[n]
    elif n == 2 or n == 3:
        return True
    elif n < 2 or n % 2 == 0:
        return False
    elif n < 9:
        return True
    elif n % 3 == 0:
        return False
    r = int(n ** 0.5)
    f = 5
    while f <= r:
        if n % f == 0:
            return False
        if n % (f + 2) == 0:
            return False
        f += 6
    return True 
 
def concat(a, b):
    return int(str(a) + str(b))
     
def check_cat_primes(choices1, choices2, prime_bool, is_prime_pair):
    for i in range(len(choices1)):
        for j in range(len(choices2)):
            a = min(choices1[i], choices2[j])
            b = max(choices1[i], choices2[j])
            c = is_prime_pair.get((a, b))
            if c != None and c == False:
                return False
            result = (is_prime(concat(choices1[i], choices2[j]), prime_bool) and is_prime(concat(choices2[j], choices1[i]), prime_bool))
            is_prime_pair[(a, b)] = result
            if not result:
                return False
    return True
 
def recurse(set_cache, k, prime_bool, primes, is_prime_pair):
    print(k)
    if set_cache[k] != None:
        return set_cache[k]
    elif k == 1:
        set_cache[k] = primes
        return set_cache[k]
    elif k == 2:
        set_cache[k] = merge_and_check(primes, primes, True)
        return set_cache[k]
    else:
        k1 = k // 2
        k2 = k - k1
        set1 = recurse(set_cache, k1, prime_bool, primes, is_prime_pair)
        set2 = recurse(set_cache, k2, prime_bool, primes, is_prime_pair)
        set_cache[k] = merge_and_check(set1, set2, False)
        return set_cache[k]
 
def merge_and_check(set1, set2, no_dups):
    result = []
    for i in range(len(set1)):
        for j in (range(i, len(set2)) if no_dups else
range(len(set2))):
            if check_cat_primes(set1[i], set2[j], prime_bool, is_prime_pair):
                result.append(set1[i] + set2[j])
    return result    
 
 
upper_bound = 10000
k = 5
set_cache = [None] * (k + 1)
prime_bool = gen_primes(upper_bound + 1)
primes = [[i] for i in range(upper_bound) if prime_bool[i]]
is_prime_pair = {}

choices = recurse(set_cache, k, prime_bool, primes, is_prime_pair)
print(choices)
