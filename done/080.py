from decimal import *
getcontext().prec = 102
current = str(Decimal(2).sqrt())

squares = [x ** 2 for x in xrange(1,11)]
irrationals = [x for x in xrange(1,101) if x not in squares]
result = 0

for i in irrationals:
    current = str(Decimal(i).sqrt())
    result += int(current[0])
    for index in xrange(2, 101):
        result += int(current[index])

print result
