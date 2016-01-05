from sets import Set

def kahn_topological(adj_list_to, adj_list_from, ignore):
	sorted_order = []
	no_incoming_edges = set([x for x in xrange(10) if len(adj_list_to[x]) == 0 and x not in ignore])
	while len(no_incoming_edges) > 0:
		n = no_incoming_edges.pop()
		sorted_order.append(n)
		for m in adj_list_from[n]:
			adj_list_to[m].remove(n)
			if len(adj_list_to[m]) == 0:
				no_incoming_edges.add(m)
		adj_list_from[n] = Set()

	return sorted_order

def main():
	adj_list_to = [Set() for _ in xrange(10)]
	adj_list_from = [Set() for _ in xrange(10)]
	ignore = set([x for x in xrange(10)])
	with open("079_keylog.txt", "r") as f:
		for line in f:
			for i in xrange(len(line) - 2):
				u = int(line[i])
				v = int(line[i + 1])
				adj_list_to[v].add(u)
				adj_list_from[u].add(v)
				if u in ignore:
					ignore.remove(u)
				if v in ignore:
					ignore.remove(v)

	print kahn_topological(adj_list_to, adj_list_from, ignore)

if __name__ == '__main__':
	main()
