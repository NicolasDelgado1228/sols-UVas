from sys import stdin
import sys
sys.setrecursionlimit(1000000)

low, disc, bridges, timeCnt, parent, G = [], [], [], [], int(), []

def dfsBridges(u):
    global low, disc, bridges, timeCnt, G, parent
    disc[u] = timeCnt; timeCnt+=1
    low[u] = disc[u] 

    for v in G[u]:
        if disc[v] == -1:
            parent[v] = u
            dfsBridges(v)
            low[u] = min(low[u], low[v])
            if low[v] > disc[u]: bridges.append((min(u,v), max(u,v)))
        elif v != parent[u]:
            low[u] = min(low[u], disc[v])
            

def solve():
    global low, disc, bridges, timeCnt, G, parent
    n = len(G)
    low, disc, bridges, timeCnt, parent = [-1 for _ in range(n)], [-1 for _ in range(n)], [], 0, [-1 for _ in range(n)]
    for u in range(n):
        if disc[u] == -1: dfsBridges(u)
    return bridges

def main():
    global low, disc, bridges, timeCnt, G, parent
    n = stdin.readline()
    while n!= "":
        n = int(n)
        G = [[] for _ in range(n)]
        for v in range(n):
            description = stdin.readline().strip().split()
            for u in description[2:]: G[int(description[0])].append(int(u))
        
        solve()
        bridges.sort(key=lambda x: x[1])
        bridges.sort(key=lambda x: x[0])
        print(str(len(bridges))+ " critical links")
        for u, v in bridges: print(str(u) + " - " + str(v))
        print("")

        stdin.readline()
        n = stdin.readline()

main()