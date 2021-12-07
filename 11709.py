from sys import stdin
import sys
sys.setrecursionlimit(10000000)

low, disc, inStack, time, stack, sccCnt = [], [], [], 0, [], 0


def dfsTar(G, u):
    global low, disc, inStack, time, stack, sccCnt
    disc[u], low[u] = time, time
    stack.append(u); inStack[u] = True
    time += 1;

    for v in G[u]:
        if disc[v] == -1:
            dfsTar(G, v)
            low[u] = min(low[u], low[v])
        elif inStack[v]: low[u] = min(low[u], disc[v])

    if low[u] == disc[u]:
        sccCnt += 1
        while u != stack[-1]: inStack[stack[-1]] = False; stack.pop()
        inStack[u] = False
        stack.pop()

def tarjan(G):
    global low, disc, inStack, time, stack, sccCnt
    n = len(G)
    low, disc, inStack, time, stack, sccCnt = [-1 for _ in range(n)], [-1 for _ in range(n)], [False for _ in range(n)], 0, [], 0

    for u in range(n):
        if disc[u] == -1:
            dfsTar(G, u)

def main():
    global low, disc, inStack, time, stack, sccCnt
    n, m = list(map(int, stdin.readline().strip().split()))
    while n+m>0:
        node, pearson = dict(), []

        for i in range(n):
            pear = stdin.readline().strip()
            node[pear] = i
            pearson.append(pear)
        G = [[] for _ in range(n)]
        for i in range(m):
            u = node[stdin.readline().strip()]
            v = node[stdin.readline().strip()]
            G[u].append(v)

        tarjan(G)
        print(sccCnt)

        n, m = list(map(int, stdin.readline().strip().split()))

main()
