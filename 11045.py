from sys import stdin
from collections import deque

def bfs(G, capacity, flow, s, t):
    n = len(G)
    visited, parent = [False for _ in range(n)], [-1 for _ in range(n)]
    queue = deque([s]); visited[s] = True

    while len(queue) > 0:
        u = queue.popleft()
        for v in G[u]:
            if not visited[v] and capacity[u][v]-flow[u][v] > 0:
                visited[v] = True
                queue.append(v)
                parent[v] = u
    return (visited[t], parent)

def edmondKarp(G, capacity, flow, s, t):
    maxFlow, augPath = 0, bfs(G, capacity, flow, s, t)

    while augPath[0]:
        parent, v, newFlow = augPath[1], t, float("inf")
        v = t
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
    cases = int(stdin.readline().strip())
    for case in range(cases):
        shirtsCnt, peopleCnt = list(map(int, stdin.readline().strip().split()))
        G, capacity, flow = [[] for _ in range(peopleCnt+8)], [[0 for _ in range(peopleCnt+8)] for _ in range(peopleCnt+8)], [[0 for _ in range(peopleCnt+8)] for _ in range(peopleCnt+8)]
        conv = {"XS":peopleCnt, "S":peopleCnt+1, "M":peopleCnt+2,"L":peopleCnt+3,"XL":peopleCnt+4,"XXL":peopleCnt+5}
        XS, S, M, L, XL, XXL, s, t = peopleCnt, peopleCnt+1, peopleCnt+2, peopleCnt+3, peopleCnt+4, peopleCnt+5, peopleCnt+6, peopleCnt+7

        for u in range(peopleCnt):
            G[u].append(s)
            G[s].append(u)
            capacity[u][s] = capacity[s][u] = 1
            shirts = stdin.readline().strip().split()
            for shirt in shirts:
                if G[conv[shirt]] == []:
                    G[conv[shirt]].append(t)
                    G[t].append(conv[shirt])
                    capacity[conv[shirt]][t] = capacity[t][conv[shirt]] = shirtsCnt//6
                G[u].append(conv[shirt])
                G[conv[shirt]].append(u)
                capacity[conv[shirt]][u] = 1
                capacity[u][conv[shirt]] = 1

        if edmondKarp(G, capacity, flow, s, t) == peopleCnt: print("YES")
        else: print("NO")

main()
