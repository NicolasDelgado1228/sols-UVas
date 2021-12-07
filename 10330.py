from sys import stdin
from collections import deque

def bfs(G, capacity, flow, s, t):
    n = len(G)
    visited, queue, parent = [False for _ in range(n)], deque(), [-1 for _ in range(n)]
    queue.append(s); visited[s] = True

    while len(queue)>0:
    	 u = queue.popleft()
    	 for v in G[u]:
    		 if not visited[v] and capacity[u][v]-flow[u][v] > 0:
    			 queue.append(v);
    			 visited[v] = True
    			 parent[v] = u
    return (visited[t], parent)

def edmondKarp(G, capacity, flow, s, t):
    maxFlow, augPath = 0, bfs(G, capacity, flow, s, t)

    while augPath[0]:
        parent = augPath[1]
        v, newFlow = t, float("inf")

        while v != s:
            u = parent[v]
            newFlow = min(newFlow, capacity[u][v]-flow[u][v])
            v = parent[v]
        maxFlow += newFlow
        v = t
        while v != s:
            u = parent[v]
            flow[u][v] += newFlow
            flow[v][u] -= newFlow
            v = parent[v]
        augPath = bfs(G, capacity, flow, s, t)
    return maxFlow





def main():
    N = int(stdin.readline())
    capacityReg = list(map(int, stdin.readline().strip().split()))
    M = int(stdin.readline())
    E = []
    node = None
    for i in range(M):
        u, v, c = list(map(int, stdin.readline().strip().split()))
        u-=1;v-=1
        node = N+i
        E.append((u,node,c));E.append((node,u,c))
        E.append((v, node, capacityReg[v]));E.append((node, v, capacityReg[v]))
    B, D = list(map(int, stdin.readline().strip().split()))
    node += 1
    s, t = -1, -2
    ints = list(map(int, stdin.readline().strip().split()))
    for i in range(B):
        u = ints[i];u-=1
        E.append((s, node, float("inf")));E.append((node, s, float("inf")))
        E.append((u, node, capacityReg[u]));E.append((node, u, capacityReg[u]))
        node += 1
    for i in range(B, B+D):
        u = ints[i];u-=1
        E.append((t, node, float("inf")));E.append((node, t, float("inf")))
        E.append((u, node, capacityReg[u]));E.append((node, u, capacityReg[u]))
        node += 1
    s, t = node-2, node-1
    G = [[] for _ in range(node)]
    capacity, flow = [[0 for _ in range(node)] for _ in range(node)], [[0 for _ in range(node)] for _ in range(node)]
    for u, v, cap in E:
        if u == -1: u = s
        if u == -2: u = t
        if v == -1: v = s
        if v == -1: v = t
        G[u].append(v);
        capacity[u][v] = cap
    for lin in G: print(lin)

    print(edmondKarp(G, capacity, flow, s, t))

main()
