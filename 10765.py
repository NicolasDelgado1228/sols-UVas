from sys import stdin
import sys
sys.setrecursionlimit(1000000)
timeCnt = int()

def dfs(G, low, time, parent, pigeonVals, u):
    global timeCnt
    time[u] = timeCnt; low[u] = timeCnt; timeCnt += 1
    subTreeCnt = 0

    for v in G[u]:
        if time[v] == -1:
            subTreeCnt += 1 ; parent[v] = u
            dfs(G, low, time, parent, pigeonVals, v)
            low[u] = min(low[u], low[v])
            if (parent[u] == -1 and subTreeCnt > 1) or (low[v] >= time[u] and parent[u] != -1): pigeonVals[u] += 1
        elif parent[u] != v:
            low[u] = min(low[u], time[v])
    


def getPigeonVals(G):
    global timeCnt
    n = len(G)
    low, time, parent, pigeonVals, timeCnt = [-1 for _ in range(n)], [-1 for _ in range(n)], [-1 for _ in range(n)], [1 for _ in range(n)], 0
    dfs(G, low, time, parent, pigeonVals, 0)
    return pigeonVals

def main():
    global timeCnt
    n, m = list(map(int, stdin.readline().split()))
    while(n != 0 and m != 0):
        G = [[] for _ in range(n)]
        u, v = list(map(int, stdin.readline().split()))
        while(u != -1 and v != -1):
            if u < n and v < n: G[u].append(v); G[v].append(u)
            u, v = list(map(int, stdin.readline().split()))

        pigeonValues = getPigeonVals(G) 
        ans = [(idx, pigeonValues[idx]) for idx in range(len(pigeonValues))]
        ans.sort(key=lambda x: x[0])
        ans.sort(key=lambda x: x[1], reverse=True)
        for i in range(m): print(ans[i][0], ans[i][1])
        print("")
    
        n, m = list(map(int, stdin.readline().split()))
    return 0;
main()