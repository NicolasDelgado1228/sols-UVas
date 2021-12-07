from sys import stdin



def SuffixAutomaton(s):
	edges = []
	link = []
	length = []
	last = int()
	edges.append(dict())
	link.append(-1)
	length.append(0)
	last = 0

	for i in range(len(s)):
		edges.append(dict())
		length.append(i+1)
		link.append(0)
		r = len(edges) - 1

		p = last
		while p >= 0 and s[i] not in edges[p]:
			edges[p][s[i]] = r
			p = link[p]
		if p != -1 and s[i] in edges[p]:
			q = edges[p][s[i]]
			if length[p]+1 == length[q]:
				link[r] = q
			else:
				edges.append(edges[q])
				length.append(length[p]+1)
				link.append(link[q])
				qq = len(edges)-1

				link[q] = qq
				link[r] = qq

				while p >= 0 and edges[p][s[i]] == q:
					edges[p][s[i]] = qq
					p = link[p]
		last = r
	return (edges, link, length)

def main():
	sa = SuffixAutomaton("Foundations.TheRoleOfAlgorithmsInComputing.GettingStarted.Theorem.SortingAlgorithms.TheHeapsort.Quicksort.")
	
main()