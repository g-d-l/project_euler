from fractions import Fraction

def gen_blum_blum(n):
    result = [0 for x in range(n)]
    s = 290797
    for i in range(n):
        s = (s * s) % 50515093
        result[i] = s % 500
    
    return result

def find_point(x1, y1, x2, y2, x3, y3, x4, y4):
    if x1 == x2:
        m = Fraction(y4 - y3, x4 - x3)
        y = m * (x1 - x3) + y3
        return Fraction(x1), y
    elif x3 == x4:
        m = Fraction(y2 - y1, x2 - x1)
        y = m * (x3 - x1) + y1
        return Fraction(x3), y
    else:
        m1 = Fraction(y2 - y1, x2 - x1)
        b1 = y1 - m1 * x1
        m3 = Fraction(y4 - y3, x4 - x3)
        b3 = y3 - m3 * x3
        x = (b3 - b1) / (m1 - m3)
        y = x * m1 + b1
        return x, y

def cross_prod(vx, vy, ux, uy):
    return vx * uy - ux * vy

def opposite_sides(x1, y1, x2, y2, x3, y3, x4, y4):
    cp1 = cross_prod(x3 - x1, y3 - y1, x3 - x4, y3 - y4)
    cp2 = cross_prod(x3 - x2, y3 - y2, x3 - x4, y3 - y4)
    if cp1 * cp2 < 0:
        return True
    else:
        return False

def true_intersect(x1, y1, x2, y2, x3, y3, x4, y4, found):
    if opposite_sides(x1, y1, x2, y2, x3, y3, x4, y4) and opposite_sides(x3, y3, x4, y4, x1, y1, x2, y2):
        x, y = find_point(x1, y1, x2, y2, x3, y3, x4, y4)
        if not found.has_key((x, y)):
            found[(x, y)] = 1
            return True
    return False


limit = 5000
count = 0
points = gen_blum_blum(limit * 4)
found = {}
for i in range(0, limit * 4, 4):
    for j in range(i + 4, limit * 4, 4):
        if true_intersect(points[i], points[i + 1], points[i + 2], points[i + 3], points[j], points[j + 1], points[j + 2], points[j + 3], found):
            count += 1

print(count)
