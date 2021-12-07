from sys import stdin
from heapq import heappop, heappush


def dijkstra(G, stations):
    n = len(G)
    pq, cost, visited = [], [float("inf") for _ in range(n)], [False for _ in range(n)]
    for station in stations: heappush(pq, (0, station)); cost[station] = 0
    while len(pq) > 0:
        time, u =heappop(pq)
        if not visited[u]:
            visited[u] = True
            for v, w in G[u]:
                if w+cost[u] < cost[v]:
                    cost[v] = w+cost[u]
                    heappush(pq, (cost[v], v))
    return cost

def solve(time, isBank):
    furthestDist, banks = -1, []
    for i in range(len(isBank)):
        if isBank[i] and time[i] > furthestDist: furthestDist = time[i]
    for i in range(len(time)):
        if time[i] == furthestDist and isBank[i]: banks.append(i)
    return (furthestDist, banks)

def main():
    inp = stdin.readline().strip()
    while inp != "":
        N, M, B, P = map(int, inp.split())
        G = [[] for _ in range(N)]
        for i in range(M):
            u, v, t = map(int, stdin.readline().strip().split())
            G[u].append((v,t)); G[v].append((u,t))
        isBank, stations = [False for _ in range(N)], []
        banks = list(map(int, stdin.readline().strip().split()))
        for i in range(len(banks)): isBank[banks[i]] = True
        if P > 0: stations = list(map(int, stdin.readline().strip().split()))
        furthestDist, ans = solve(dijkstra(G, stations), isBank)
        print(len(ans), "*" if furthestDist==float("inf") else furthestDist)
        print(*ans)
        inp = stdin.readline().strip()




main()
