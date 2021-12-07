from sys import stdin


visited, low, disc, time, artPoints, parent, isAp = list(), list(), list(), list(), list(), list(), list()
def dfsTar(G, u):
    global visited, low, disc, time, artPoints, parent, isAp
    disc[u] = time; low[u] = time; time+=1
    sonsCnt = 0

    for v in G[u]:
        if disc[v] == -1:
            sonsCnt += 1; parent[v] = u
            dfsTar(G, v)
            low[u] = min(low[u], low[v])
            if ((low[v] >= disc[u] and parent[u] != -1) or (sonsCnt > 1 and parent[u]==-1)) and not isAp[u]: artPoints.append(u); isAp[u] = True
        elif v != parent[u]: low[u] = min(low[u], disc[v])


def tarjan(G):
    global visited, low, disc, time, artPoints, parent, isAp
    n = len(G)
    artPoints, low, disc, time, parent, isAp = [], [-1 for _ in range(n)], [-1 for _ in range(n)], 0, [-1 for _ in range(n)], [False for _ in range(n)]
    for u in range(n):
        if disc[u] == -1:
            dfsTar(G, u)

def main():
    global visited, low, disc, time, artPoints, parent, isAp
    n, cityCnt, first = int(stdin.readline()), 1, True
    while n!=0:
        nodes, conv = list(), dict()
        for i in range(n):
            node = stdin.readline().strip()
            nodes.append(node)
            conv[node] = i
        G = [[] for _ in range(n)]
        r = int(stdin.readline())
        for i in range(r):
            uStr, vStr = stdin.readline().strip().split()
            G[conv[uStr]].append(conv[vStr])
            G[conv[vStr]].append(conv[uStr])

        tarjan(G)
        ans = [nodes[x] for x in artPoints]
        ans.sort()
        if not first: print("")
        first = False
        print("City map #" + str(cityCnt) + ": "+ str(len(artPoints)) +" camera(s) found")
        for artPoint in ans: print(artPoint)
        cityCnt += 1

        n = int(stdin.readline())

main()
