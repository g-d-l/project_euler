def digit_sum(n):
    result = 0
    while n > 0:
        d = n % 10
        result += d
        n = n // 10
    return result

def no_zero(n):
    if '0' in str(n):
        return False
    else:
        return True

n = 9
grid = [[0 for x in range(n)] for y in range(n)]
for i in xrange(111111111, -1, -1):
    if no_zero(i) and digit_sum(i) == n:
        x = i
        c = n - 1
        while x > 0:
            grid[x % 10 - 1][c] += 1
            c -= 1
            x //= 10

for r in grid:
    print(r)
    
'''
13
1, 12, 67, 232, 562, 1024, 1486, 1816, 1981, 2033, 2040, 2040, 2040, 
0, 1, 11, 56, 176, 386, 638, 848, 968, 1013, 1021, 1021, 1021, 
0, 0, 1, 10, 46, 130, 256, 382, 466, 502, 511, 511, 511, 
0, 0, 0, 1, 9, 37, 93, 163, 219, 247, 255, 256, 256, 
0, 0, 0, 0, 1, 8, 29, 64, 99, 120, 127, 128, 128, 
0, 0, 0, 0, 0, 1, 7, 22, 42, 57, 63, 64, 64, 
0, 0, 0, 0, 0, 0, 1, 6, 16, 26, 31, 32, 32, 
0, 0, 0, 0, 0, 0, 0, 1, 5, 11, 15, 16, 16, 
0, 0, 0, 0, 0, 0, 0, 0, 1, 4, 7, 8, 8, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 

12
1, 11, 56, 176, 386, 638, 848, 968, 1013, 1021, 1021, 1021, 
0, 1, 10, 46, 130, 256, 382, 466, 502, 511, 511, 511, 
0, 0, 1, 9, 37, 93, 163, 219, 247, 255, 256, 256, 
0, 0, 0, 1, 8, 29, 64, 99, 120, 127, 128, 128, 
0, 0, 0, 0, 1, 7, 22, 42, 57, 63, 64, 64, 
0, 0, 0, 0, 0, 1, 6, 16, 26, 31, 32, 32, 
0, 0, 0, 0, 0, 0, 1, 5, 11, 15, 16, 16, 
0, 0, 0, 0, 0, 0, 0, 1, 4, 7, 8, 8, 
0, 0, 0, 0, 0, 0, 0, 0, 1, 3, 4, 4, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,

11

[1, 10, 46, 130, 256, 382, 466, 502, 511, 511, 511]
[0, 1, 9, 37, 93, 163, 219, 247, 255, 256, 256]
[0, 0, 1, 8, 29, 64, 99, 120, 127, 128, 128]
[0, 0, 0, 1, 7, 22, 42, 57, 63, 64, 64]
[0, 0, 0, 0, 1, 6, 16, 26, 31, 32, 32]
[0, 0, 0, 0, 0, 1, 5, 11, 15, 16, 16]
[0, 0, 0, 0, 0, 0, 1, 4, 7, 8, 8]
[0, 0, 0, 0, 0, 0, 0, 1, 3, 4, 4]
[0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 2]
[0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
[0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]


10
[1, 9, 37, 93, 163, 219, 247, 255, 256, 256]
[0, 1, 8, 29, 64, 99, 120, 127, 128, 128]
[0, 0, 1, 7, 22, 42, 57, 63, 64, 64]
[0, 0, 0, 1, 6, 16, 26, 31, 32, 32]
[0, 0, 0, 0, 1, 5, 11, 15, 16, 16]
[0, 0, 0, 0, 0, 1, 4, 7, 8, 8]
[0, 0, 0, 0, 0, 0, 1, 3, 4, 4]
[0, 0, 0, 0, 0, 0, 0, 1, 2, 2]
[0, 0, 0, 0, 0, 0, 0, 0, 1, 1]
[0, 0, 0, 0, 0, 0, 0, 0, 0, 0]

9
[1, 8, 29, 64, 99, 120, 127, 128, 128]
[0, 1, 7, 22, 42, 57, 63, 64, 64]
[0, 0, 1, 6, 16, 26, 31, 32, 32]
[0, 0, 0, 1, 5, 11, 15, 16, 16]
[0, 0, 0, 0, 1, 4, 7, 8, 8]
[0, 0, 0, 0, 0, 1, 3, 4, 4]
[0, 0, 0, 0, 0, 0, 1, 2, 2]
[0, 0, 0, 0, 0, 0, 0, 1, 1]
[0, 0, 0, 0, 0, 0, 0, 0, 1]
'''
