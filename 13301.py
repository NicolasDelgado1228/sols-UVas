from sys import stdin
import sys
sys.setrecursionlimit(1000000)

timeCnt, sccCnt = int(), int()

def dfs(G, low, time, inStack, stack, u):
    global timeCnt, sccCnt
    inStack[u] = True; stack.append(u)
    time[u] = timeCnt; low[u] = time[u] ; timeCnt += 1

    for v in G[u]:
        if time[v] == -1:
            dfs(G, low, time, inStack, stack, v)
            low[u] = min(low[u], low[v])
        elif inStack[v]: low[u] = min(low[u], time[v])
    
    if time[u] == low[u]:
        sccCnt += 1; w = -1
        while w != u:
            w = stack.pop()
            inStack[w] = False 

def tarjan(G):
    global timeCnt, sccCnt
    n = len(G)
    low, time, inStack, stack, timeCnt, sccCnt = [-1 for _ in range(n)], [-1 for _ in range(n)], [False for _ in range(n)], [], 0, 0
    for u in range(n):
        if time[u] == -1:
            dfs(G, low, time, inStack, stack, u)

def main():
    global timeCnt, sccCnt
    descript = stdin.readline().strip()
    while descript != "":
        n, m = list(map(int, descript.split()))
        G = [[] for _ in range(n)]

        for edge in range(m):
            line = list(map(int, stdin.readline().strip().split()))
            if line[0] == 1: G[line[1]-1].append(line[2]-1)
            else:
                i = 1
                while i < line[0]:
                    G[line[i]-1].append(line[i+1]-1)
                    G[line[i+1]-1].append(line[i]-1)
                    i += 1
        tarjan(G)
        if sccCnt > 1: print("NO")
        else: print("YES")
                    

        descript = stdin.readline().strip()

main()