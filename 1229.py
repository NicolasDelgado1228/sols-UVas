from sys import stdin
import sys
sys.setrecursionlimit(100000)

timeCnt = int()

def dfsTarjan(G, low, time, inStack, stack, inDict, u):
    global timeCnt
    stack.append(u); inStack[u] = True
    low[u] = timeCnt; time[u] = timeCnt; timeCnt += 1

    for v in G[u]:
        if time[v] == -1:
            dfsTarjan(G, low, time, inStack, stack, inDict, v)
            low[u] = min(low[u], low[v])
        elif inStack[v]: low[u] = min(low[u], time[v])

    components = list()
    if time[u] == low[u]:
        w = -1
        while w != u:
            w = stack.pop() ; inStack[w] = False
            components.append(w)
    if len(components) > 1:
        for comp in components: inDict[comp] = True


def tarjan(G):
    global timeCnt
    n = len(G)
    low, time, inStack, stack, timeCnt, inDict = [-1 for _ in range(n)], [-1 for _ in range(n)], [False for _ in range(n)], [], 0, [False for _ in range(n)] 
    for u in range(n):
        if time[u] == -1:
            dfsTarjan(G, low, time, inStack, stack, inDict, u)
    return inDict

def dfs(G, visited, u):
    visited[u] = True
    for v in G[u]:
        if not visited[v]:
            dfs(G, visited, v)

def solve(G, inDict):
    n = len(G)
    visited = [False for i in range(n)]

    for u in range(n):
        if inDict[u] and not visited[u]:
            dfs(G, visited, u)
    return visited

def main():
    global timeCnt
    n = int(stdin.readline())
    while n != 0:
        G = [set() for _ in range(n)]
        strToVer = dict()
        verToStr = dict()
        lines = []
        for u in range(n):
            line = stdin.readline().strip().split()
            strToVer[line[0]] = u; verToStr[u] = line[0]
            lines.append(line)
        for u in range(len(lines)):
            line = lines[u]
            for v in line[1:]: G[u].add(strToVer[v])
        inDict = tarjan(G)
        visited = solve(G, inDict)
        
        subDict = [verToStr[v] for v in range(n) if visited[v]]
        print(len(subDict))
        subDict.sort()
        ans = ""
        for word in subDict: ans += word + " "
        print(ans[:-1])

        n = int(stdin.readline())

main()