import itertools
from sets import Set

class Cube(object):
    def __init__(self, x0, y0, z0, dx, dy, dz):
        self.x0 = x0
        self.y0 = y0
        self.z0 = z0
        self.dx = dx
        self.dy = dy
        self.dz = dz
        self.group = None

    def __str__(self):
        return str(self.x0) + " " + str(self.y0) + " " + str(self.z0) + " " + \
        str(self.dx) + " " + str(self.dy) + " " + str(self.dz)

def lag_fib_seq(n):
    array = [(100003 - 200003 * k + 300007 * k * k * k) % 1000000 for k in range(1, 56)]
    k = 0
    while k < n:
        if k < 55:
            yield array[k]
            k += 1
        else:
            s_k = array[(k - 24) % 55] + array[k % 55]
            s_k %= 1000000
            array[k % 55] = s_k
            yield s_k
            k += 1




def check_overlap(a, b):
    a_x1 = a.x0
    a_y1 = a.y0
    a_z1 = a.z0
    a_x2 = a.x0 + a.dx
    a_y2 = a.y0 + a.dy
    a_z2 = a.z0 + a.dz
    b_x1 = b.x0
    b_y1 = b.y0
    b_z1 = b.z0
    b_x2 = b.x0 + b.dx
    b_y2 = b.y0 + b.dy
    b_z2 = b.z0 + b.dz

    if a_x1 < b_x2 and a_x2 > b_x1 and a_y1 < b_y2 and a_y2 > b_y1 and a_z1 < b_z2 and a_z2 > b_z1:
        return True
    return False    


def get_overlap_cube(c1, c2):
    if c1 == None or c2 == None or not check_overlap(c1, c2):
        return None

    x0 = 0
    y0 = 0
    z0 = 0
    dx = 0
    dy = 0
    dz = 0

    if c2.x0 > c1.x0:
        x0 = c2.x0
        dx = min(c1.x0 + c1.dx - c2.x0, c2.dx)
    else:
        x0 = c1.x0
        dx = min(c2.x0 + c2.dx - c1.x0, c1.dx)

    if c2.y0 > c1.y0:
        y0 = c2.y0
        dy = min(c1.y0 + c1.dy - c2.y0, c2.dy)
    else:
        y0 = c1.y0
        dy = min(c2.y0 + c2.dy - c1.y0, c1.dy)

    if c2.z0 > c1.z0:
        z0 = c2.z0
        dz = min(c1.z0 + c1.dz - c2.z0, c2.dz)
    else:
        z0 = c1.z0
        dz = min(c2.z0 + c2.dz - c1.z0, c1.dz)

    return Cube(x0, y0, z0, dx, dy, dz)


def group_vol(group):
    sums = []
    for n in xrange(1, len(group) + 1):
        total = 0
        for subgroup in itertools.combinations(group, n):
            #print subgroup
            if len(subgroup) == 1:
                total += subgroup[0].dx * subgroup[0].dy * subgroup[0].dz
            else:
                intersection_cube = get_overlap_cube(subgroup[0], subgroup[1])
                for c in xrange(2, len(subgroup)):
                    #print intersection_cube, '...', n
                    intersection_cube = get_overlap_cube(intersection_cube, subgroup[c])
                #print intersection_cube, ',,,', n
                if intersection_cube != None:
                    total += intersection_cube.dx * intersection_cube.dy * intersection_cube.dz
        sums.append(total)

    result = 0
    #print sums
    for i in xrange(0, len(sums), 2):
        result += sums[i]
    for i in xrange(1, len(sums), 2):
        result -= sums[i]

    return result





def main():
    ncubes = 50000
    #cubes = [Cube(0, 0, 0, 10, 10, 10), Cube(1, 1, 1, 10, 10, 10), Cube(1, 1, 1, 10, 10, 10), Cube(10, 10, 10, 2, 2, 2)]
    seq = [x for x in lag_fib_seq(ncubes * 6)]
    cubes = [Cube(seq[i] % 10000, seq[i + 1] % 10000, seq[i + 2] % 10000, 1 + seq[i + 3] % 399, 1 + seq[i + 4] % 399, 1 + seq[i + 5] % 399) for i in range(0, 6 * ncubes, 6)]

    groups = []

    for c1, c2 in itertools.combinations(cubes, 2):

        if not (c1.group != None and c2.group != None) and check_overlap(c1, c2):
            if c1.group != None:
                c1.group.add(c2)
                c2.group = c1.group
            elif c2.group != None:
                c2.group.add(c1)
            else:
                group = Set()
                group.add(c1)
                group.add(c2)
                c1.group = group
                c2.group = group
                groups.append(group)

    print len(groups)
    total = 0
    for c in cubes:
        if c.group == None:
            total += c.dx * c.dy * c.dz

    print len(groups)
    for g in groups:
        total += group_vol(g)

    print total


if __name__ == '__main__':
    main()



