from sys import stdin, setrecursionlimit
setrecursionlimit(10000000)
from collections import deque

r = stdin.readline

def dfs_(G, vis, u):
	vis[u] = 1
	print(u)
	for v in G[u]:
		if vis[v] == 0:
			dfs_(G, vis, v)
	vis[u] = 2

def dfs(G):
	n = len(G)
	vis = [0 for _ in range(n)]
	for u in range(n):
		if vis[u] == 0: dfs_(G, vis, u)

def main():
	n = int(r())
	m = int(r())
	G = [[] for _ in range(n)]
	for i in range(m):
		u, v = map(int, r().strip().split())
		G[u].append(v); G[v].append(u)
	
	for x in G: print(x)
	dfs(G)

main()
