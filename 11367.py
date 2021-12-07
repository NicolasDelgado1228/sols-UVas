from sys import stdin
from heapq import heappush, heappop


def dijkstra(G, s, t, gasPrice, cap):
    n = len(gasPrice)
    visited, cost = [[False for _ in range(cap+1)] for _ in range(n)], [[float("inf") for _ in range(cap+1)] for _ in range(n)]
    pq, cost[s][0] = [(0, (s,0))], 0

    while len(pq) > 0:
        w, state = heappop(pq)
        u, fuel = state
        if u == t and fuel == 0: break
        if not visited[u][fuel]:
            visited[u][fuel] = True

            adjacents = G[u]
            if fuel < cap and w+gasPrice[u] < cost[u][fuel+1]:
                cost[u][fuel+1] = w+gasPrice[u]
                heappush(pq, (w+gasPrice[u], (u, fuel+1)))

            for v, dist in adjacents:
                if fuel-dist >= 0 and w < cost[v][fuel-dist]:
                    cost[v][fuel-dist] = w
                    heappush(pq, (w, (v, fuel-dist)))
    return cost



def main():
    inp = stdin.readline().strip()
    while inp != "":
        n, m = list(map(int, inp.split()))
        G = [[] for _ in range(n)]
        price = list(map(int, stdin.readline().split()))
        for i in range(m):
            u, v, w = list(map(int, stdin.readline().split()))
            G[u].append((v,w))
            G[v].append((u,w))
        querysCnt = int(stdin.readline().strip())
        for query in range(querysCnt):
            c, s, t = list(map(int, stdin.readline().split()))
            cost = dijkstra(G, s, t, price, c)
            if cost[t][0] == float("inf"): print("impossible")
            else: print(cost[t][0])

        inp = stdin.readline().strip()

main()
