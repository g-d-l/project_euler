import time

# -1: TBD, 0: in progress, 1: part of amicable chain, 
# 2: not part of amicable chain
class elt(object):
    def __init__(self, val):
        self.val = val
        self.status = -1

def unload_chain(chain, status, divisor_sums):
    for x in chain:
        divisor_sums[x].status = status

limit = 1000000
divisor_sums = [elt(0) for x in xrange(limit + 1)]
divisor_sums[1].val = 1

for i in xrange(1, limit / 2 + 1):
    for j in xrange(2 * i, limit + 1, i):
        divisor_sums[j].val += i

max_chain_len = 0
chain_rep = 0

for x in xrange(1, limit + 1):
    current = x
    chain = []
    while True:
        if current > limit:
            unload_chain(chain, 2, divisor_sums)
            break
        elif divisor_sums[current].status != -1:
            if divisor_sums[current].status == 0:
                cutoff = chain.index(current)
                tail = chain[:cutoff]
                loop = chain[cutoff:]
                unload_chain(tail, 2, divisor_sums)
                unload_chain(loop, 1, divisor_sums)
                if len(loop) > max_chain_len:
                    max_chain_len = len(loop)
                    chain_rep = current
            else:
                unload_chain(chain, 2, divisor_sums)
            break
        elif len(chain) > 0 and divisor_sums[current].val == chain[0]:
            chain.append(current)
            unload_chain(chain, 1, divisor_sums)
            if len(chain) > max_chain_len:
                max_chain_len = len(chain)
                chain_rep = current
        else:
            chain.append(current)
            divisor_sums[current].status = 0
            current = divisor_sums[current].val

chain_min = chain_rep
for i in xrange(max_chain_len):
    if chain_rep < chain_min:
        chain_min = chain_rep
    chain_rep = divisor_sums[chain_rep].val

print chain_min
