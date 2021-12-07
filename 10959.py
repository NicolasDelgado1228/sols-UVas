from sys import stdin
from queue import Queue

def bfs(graph, visited, ini):
    q, distances = Queue(), [0 for _ in range(len(graph))]
    q.put((ini, 0)); visited[ini] = True

    while(not q.empty()):
        val = q.get()
        node, dist = val[0], val[1]
        adjacents = graph[node]

        for adjacent in adjacents:
            if(not visited[adjacent]):
                visited[adjacent], distances[adjacent] = True, dist + 1
                q.put((adjacent, dist+1))
    
    return distances


def main():
    first = True
    cases = int(stdin.readline())
    for case in range(cases):
        stdin.readline()
        if(not first): print("")
        n, m = list(map(int, stdin.readline().split()))
        graph, visited = [[] for _ in range(n)], [False for _ in range(n)] 

        for edge in range(m):
            a, b = list(map(int, stdin.readline().split()))
            graph[a].append(b);graph[b].append(a)
        
        distances = bfs(graph, visited, 0)
        for dist in distances[1:]:
            print(dist)
        first = False

main()