from sys import stdin

def pi(s):
	n = len(s)
	pi = [0 for _ in range(n)]
	for i in range(1, n):
		j = pi[i-1]
		while j > 0 and s[i] != s[j]: j = pi[j-1]
		if s[i] == s[j]: j+= 1
		pi[i] = j
	return pi

def kmp(p, t):
	s = p + " " + t
	pi, idx = border(s), -1
	for i in range(len(p)+1, len(pi)):
		if pi[i] == len(p): idx = i-len(p)-1-len(p)+1; break
	return idx


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

		for i in range(Q):
			P = lines.pop().strip()
			ans = kmp(P, T)

			if ans != -1: print(volume[ans]+1)
			else: print("n")



main()