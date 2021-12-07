import random
import sys
sys.setrecursionlimit(100000000)
from collections import deque

random.seed(1993)

diamNode = list()
def dfs(G, visited, u, depth):
    global diamNode
    visited[u] = True
    if depth > diamNode[1]: diamNode = (u, depth)
    for v in G[u]:
        if not visited[v]:
            dfs(G, visited, v, depth+1)

def getDiameter(G):
    global diamNode
    n = len(G)
    visited, diamNode = [False for _ in range(n)], [-1,-1]
    dfs(G, visited, 0, 0)
    source = diamNode[0]
    visited, diamNode = [False for _ in range(n)], [-1,-1]

    dfs(G, visited, source, 0)
    return diamNode[1]


def genTree(n):
    E = []
    sqrt = int(n**0.5)
    cnt = 0
    dq = deque([0])
    while len(E) < n-1:
        u = dq.popleft()
        n_u = random.randint(0, sqrt)
        if n_u== 0 and len(dq)==0: n_u = 1
        for i in range(n_u):
            E.append((u,i+1+cnt))
            if len(E) > n-1: break
            dq.append(i+1+cnt)
        cnt += n_u
    return E

def main():
    global diamNode
    E, n = genTree(10**6), (10**6)+1
    G = [[] for _ in range(n)]
    for u, v in E: G[u].append(v); G[v].append(u)

    print(getDiameter(G))

main()
