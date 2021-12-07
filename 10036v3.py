from sys import stdin
import heapq

def bfs(graph, visited, u):
    visited[ini], pq, time, father, timePassed = 1, [], 0, u, [0 for _ in range(len(graph))]
    heapq.heappush(pq, (0, u, father))

    while len(pq) != 0:
        w, u, father = heapq.heapop()
        time += (w-timePassed); timePassed[father] = w

        for v, w in graph[ini]:
            if visited[v] == 0: visited[v] = 1; pq.heappush((w, v, u))

        visited[u] = 2
    return time


def main():
    global lastEdge
    n, m = list(map(int, stdin.readline().split()))
    case = 1
    while(n != 0 or m != 0):
        graph, visited, ans = [[] for _ in range(n)], [0 for _ in range(n)], 0

        for edge in range(m):
            u, v, w = list(map(int, stdin.readline().split()))
            graph[u-1].append((v-1,w))
            graph[v-1].append((u-1,w))


        first = False
        time = bfs(graph, visited, 0)
        print(time)
        print("")
        
        n, m = list(map(int, stdin.readline().split()))

main()