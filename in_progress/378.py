def count_divisors(n):
    count = 0
    for i in range(1, n + 1):
        if n % i == 0:
            count += 1
    return count

def count_inc_subseqs(array, k):
    print(array)
    s = max(array)
    dp = [[0 for x in range(k + 1)] for y in range(len(array))]
    num = [0 for x in range(s + 1)]
    for i in range(len(array)):
        dp[i][1] = 1
    for p in range(2, k + 1):
        num = [0 for x in range(len(array))]
        for i in range(2, len(array)):
            num[array[i - 1]] += dp[i - 1][p - 1]
            for j in range(1, array[i]):
                dp[i][p] += num[j]
    result = 0
    for i in range(len(array)):
        result += dp[i][k]
    return result

n = 1000
array = [count_divisors((n * (n + 1)) // 2) for n in range(n + 1)]
array.remove(0)
print(count_inc_subseqs(array[::-1], 3))
