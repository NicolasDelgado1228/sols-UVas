from sys import stdin
import sys
sys.setrecursionlimit(100000)

bridges, low, disc, time, G, parent, edges = [], [], [], 0, [], [], []

def dfsBridges(u):
    global bridges, low, disc, time, G, parent, edges
    disc[u] = time; time+=1
    low[u] = disc[u]

    for v in G[u]:
        if not edges[u][v] and not edges[v][u]:
            print(u+1, v+1)
            edges[u][v], edges[v][u] = True, True
        if disc[v] == -1:
            parent[v] = u
            dfsBridges(v)
            low[u] = min(low[u], low[v])
            if low[v] > disc[u]: print(v+1,u+1)
        elif parent[u] != v: low[u] = min(low[u], disc[v])
        
            



def getBridges():
    global bridges, low, disc, time, G, parent, edges
    n = len(G)
    low, disc, time, parent = [-1 for _ in range(n)], [-1 for _ in range(n)], 0, [-1 for _ in range(n)]
    dfsBridges(0)

def main():
    global bridges, low, disc, time, G, parent, edges
    n, m = list(map(int, stdin.readline().strip().split()))
    case = 1
    while n!= 0 and m != 0:
        G = [[] for _ in range(n)]
        edges = [[False for _ in range(n)] for _ in range(n)]
        for edge in range(m):
            u, v = list(map(int, stdin.readline().strip().split()))
            u-=1;v-=1
            G[u].append(v); G[v].append(u)
        
        print(case); case += 1
        print("")
        getBridges()
        print("#")
        

        n, m = list(map(int, stdin.readline().strip().split()))

main()