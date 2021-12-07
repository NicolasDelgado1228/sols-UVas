from sys import stdin

timeCnt, sccCnt = int(), int()

def dfsTarjan(G, low, time, stack, inStack, u):
    global timeCnt, sccCnt
    time[u] = timeCnt; timeCnt += 1; inStack[u] = True; stack.append(u)
    low[u] = time[u]

    for v in G[u]:
        if time[v] == -1:
            dfsTarjan(G, low, time, stack, inStack, v)
            low[u] = min(low[u], low[v])
        elif inStack[v]: low[u] = min(low[u], time[v])
    
    w = -1
    if low[u] == time[u]:
        sccCnt += 1
        while w != u: w = stack.pop(); inStack[w] = False

def tarjan(G):
    global timeCnt, sccCnt
    n = len(G)
    low, time, stack, inStack, timeCnt, sccCnt = [-1 for _ in range(n)], [-1 for _ in range(n)], [], [False for _ in range(n)], 0, 0
    for u in range(n):
        if time[u] == -1:
            dfsTarjan(G, low, time, stack, inStack, u)

def main():
    global timeCnt, sccCnt
    n, m = list(map(int, stdin.readline().split()))
    while n != 0 and m != 0:
        G = [[] for _ in range(n)]
        for i in range(m):
            u, v, p = list(map(int, stdin.readline().split()))
            u-=1;v-=1
            G[u].append(v)
            if p == 2: G[v].append(u)
        
        sccCnt, timeCnt = 0, 0
        tarjan(G)
        if sccCnt == 1: print(sccCnt)
        else: print(0)
            
        
        n, m = list(map(int, stdin.readline().split()))

main()