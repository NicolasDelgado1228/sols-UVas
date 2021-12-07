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
		n = len(self.edges)
		self.firstpos = [0 for i in range(n)]
		for qq, q in self.clones:
			if qq == -1: self.firstpos[q] = self.length[q]-1
			else: self.firstpos[qq] = self.firstpos[q] 


def match(sa, string):
	u, i, G, n = 0, 0, sa.edges, len(string)
	while i < n and string[i] in G[u]: u = G[u][string[i]]; i+=1
	return (n==i, sa.firstpos[u]-n+1)


def main():
	lines = stdin.readlines()
	lines.reverse()
	while len(lines) > 0:
		N, Q = map(int, lines.pop().strip().split())
		T, volume = "", []

		for i in range(N):
			temp = lines.pop()			
			for c in temp:
				if c != "\n": volume.append(i); T += c
			volume.append(i); T+=" "

		sa = SuffixAutomaton(T)
		for i in range(Q):
			P = lines.pop().strip()
			matches, idx = match(sa, P)

			if matches: print(volume[idx]+1)
			else: print("n")




main()