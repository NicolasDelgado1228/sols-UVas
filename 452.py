from sys import stdin

topo = []

def topoDfs(G, visited, u):
    global topo
    visited[u] = True
    for v in G[u]:
        if not visited[v]:
            topoDfs(G, visited, v)
    topo.append(u)

def toposort(G):
    global topo
    n, visited, topo = len(G), dict(), []
    for u in G: visited[u] = False
    for u in G:
        if not visited[u]:
            topoDfs(G, visited, u)
    topo.reverse()

def solve(G, time):
    global topo
    toposort(G)
    longestPath = dict()
    for u in G: longestPath[u] = time[u]


    for u in topo:
        for v in G[u]:
            if longestPath[u]+time[v] > longestPath[v]:
                longestPath[v] = longestPath[u]+time[v]

    return longestPath[ max(longestPath, key=longestPath.get)]


def main():
    cases, first = int(stdin.readline()), True
    stdin.readline()
    for case in range(cases):
        lines, G = list(), dict()
        while(True):
            line = stdin.readline().strip()
            if(line == ""): break
            lines.append(line.split())
            G[line[0]] = []
        time = dict()
        for line in lines:
            u, t = line[0], line[1]
            time[u] = int(t)
            if len(line)>2:
                adjacents = line[2]
                for v in adjacents: G[v].append(u)
        if not first: print("")
        first = False
        print(solve(G, time))

main()
