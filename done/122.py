def addition_chain(n):
    
    def backtrack(power, depth, cost, path):
        if (power > n or depth > cost[power]):
            pass
        else:
            cost[power] = depth;
            path[depth] = power;
            for i in range(depth, -1, -1):
                backtrack(power + path[i], depth + 1, cost, path);

    cost = [x for x in range(n + 1)]
    path = [0 for x in range(n + 1)]
    backtrack(1, 1, cost, path)
    return cost

limit = 200
costs = addition_chain(limit)
print(sum(costs) - limit)
