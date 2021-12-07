from sys import stdin
import collections


def bfs(graph, visited, u):
    q = collections.deque()
    q.append(u)
    visited[u], maxFriends, social = True, 0, u

    while len(q) != 0:
        u = q.popleft()
        print(u, graph[u])
        hisFriends = 0
        

        for v in graph[u]:
            if not visited[v]:
                hisFriends += 1
                visited[v] = True
                q.append(v)
        if(hisFriends > maxFriends): maxFriends, social = len(graph[u]), u
    return (maxFriends, social)


def main():
    N, G = int(stdin.readline()), []
    for E in range(N): G.append(list(map(int, stdin.readline().split()))[1:])
    cases = int(stdin.readline())
    print(G)

    for case in range(cases):
        u, visited = int(stdin.readline()), [False for _ in range(N)]
        ans = bfs(G, visited, u)
        if(ans[0] == 0): print(0)
        else: print(str(ans[0]) + " " + str(ans[1]))





main()