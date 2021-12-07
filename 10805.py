from sys import stdin
from collections import deque


diamNode = tuple()
def bfs(G, u):
    global diamNode
    n = len(G)
    visited, queue, found = [False for _ in range(n)], deque(), False
    queue.append((u,0))

    while len(queue) > 0:
        u, depth = queue.popleft()
        visited[u] = True
        if depth > diamNode[1]: diamNode = (u, depth)

        for v in G[u]:
            if not visited[v]:
                queue.append((v, depth+1))

def diameter(G):
    global diamNode
    diamNode, n = (-1,-1), len(G)
    visited = [False for _ in range(n)]

    bfs(G, 0)
    u = diamNode[0]
    print(u)
    diamNode, visited = (-1,-1), [False for _ in range(n)]
    bfs(G, u)
    return diamNode[1]

def main():
    global diamNode
    cases = int(stdin.readline())
    for case in range(cases):
        n, m = list(map(int, stdin.readline().strip().split()))
        G = [[] for _ in range(n)]
        for edge in range(m):
            u, v = list(map(int, stdin.readline().strip().split()))
            G[u].append(v); G[v].append(u);

        print(diameter(G))

main()
