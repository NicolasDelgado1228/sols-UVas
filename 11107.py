from sys import stdin

class SuffixAutomaton:
	def __init__(self, s):
		self.edges, self.link, self.length, self.last, self.firstpos, self.clones = [dict()], [-1], [0], 0, [], []
		for i in range(len(s)):
			self.edges.append(dict())
			self.length.append(i+1)
			self.link.append(0)
			r, p = len(self.edges)-1, self.last
			self.clones.append((-1, r))
			while p >= 0 and s[i] not in self.edges[p]:
				self.edges[p][s[i]] = r
				p = self.link[p]
			if p != -1:

				q = self.edges[p][s[i]]
				if self.length[p] + 1 == self.length[q]: self.link[r] = q
				else:
					self.edges.append(self.edges[q].copy())
					self.length.append(self.length[p]+1)
					self.link.append(self.link[q])
					qq = len(self.edges)-1
					self.link[q] = qq
					self.link[r] = qq
					self.clones.append((qq, q))

					while p >= 0 and self.edges[p][s[i]] == q:
						self.edges[p][s[i]] = qq
						p = self.link[p]


			self.last = r
		
read = stdin.readline

toposort = list()

def topodfs(G, u, visited):
	global toposort
	visited[u] = True
	for c in G[u]:
		if not visited[G[u][c]]: topodfs(G, G[u][c], visited)
	toposort.append(u)

def longestPaths(G):
	n = len(G)
	toposort.reverse()
	cost, parent = [float("-inf") for _ in range(n)], [-1 for _ in range(n)] 
	cost[toposort[0]] = 0

	for u in toposort:
		for c in G[u]:
			v = G[u][c]
			if cost[u]+1 > cost[v]:
				cost[v] = cost[u]+1
				parent[v] = u
	return (cost, parent)

def build_str(G, state, parent):
	ans, v = "", state
	while v != -1:
		u = parent[v]
		for c in G[u]:
			if G[u][c] == v: ans += c
		v = u
	return ans




def solve(sa, N):
	global toposort
	G, toposort, length, strings, states, longest, ans = sa.edges, [], sa.length, [], [], None, []
	n = len(G)
	marksCnt, visited = [0 for _ in range(n)], [False for _ in range(n)]

	#Count marks cnt
	for u in range(n):
		for c in G[u]:
			if c == "$": marksCnt[u] += 1
	topodfs(G, 0, visited)
	print(toposort)
	for u in toposort:
		for c in G[u]:
			if c != "$": marksCnt[u] += marksCnt[G[u][c]]

	
	for i in range(1, n):
		if marksCnt[i] > N//2: strings.append((length[i], i))
	if len(strings) > 0:
		longest = max(strings)[0]
		for l, state in strings:
			cost, parent = longestPaths(G)
			if l == longest: states.append(state); ans.append(build_str(G, state, parent))
	print(states)


def main():
	global read
	while 1:
		n = int(read())
		if n == 0: break
		T = "xx$yy@"
		#for i in range(n): T += read().strip()+"$"
		sa = SuffixAutomaton(T)
		for line in sa.edges: print(line)
		solve(sa, n)


main()
