from sys import stdin
import collections 

def findLast(x, weights):
    ans = -1
    for u in weights:
        if(weights[u] == x): ans = u
    return ans 

def bfs(graph, visited, ini):
    queue, u, w, inQueue, time, visited[ini], weights, father, a, b, between = collections.deque(), ini, 0, list(), 0, 1, dict(), ini, -1, -1, False
    for adjacent in graph[u]: inQueue.append((adjacent[0], father)); weights[adjacent[0]] = adjacent[1]; visited[adjacent[0]] = 1


    while len(queue) != 0 or len(inQueue) != 0:
        if len(queue) == 0:
            maxW = 0
            for v, father in inQueue: maxW = max(maxW, weights[v])
            if not between: a, b = findLast(maxW, weights)+1, -1
            for v, father in inQueue:
                if visited[v] == 1: queue.append((v, weights[v]-maxW, father))
            inQueue = list()
            time += maxW
        else:
            u, w, father = queue.popleft()        
            for adjacent in graph[u]:
                v, weight = adjacent
                if visited[v] == 0:
                    visited[v] = 1; inQueue.append((v, u)); weights[v], between = weight+w, False
                elif visited[v] == 1 and v != father:
                    weights[v] = weight+w
                elif v != father:
                    weights[u] = (w+weights[u])/2
                    weights[v], a, b, between = weights[u], v+1, u+1, True
                    inQueue.append((v, u))
            visited[u] = 2
    return (time, a, b)



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
        time, a, b = bfs(graph, visited, 0)
        print("System #" + str(case));case+=1
        if b == -1: print("The last domino falls after %.1f seconds, at key domino %d."%(time, a))
        else: print("The last domino falls after %.1f seconds, between key dominoes %d and %d."%(time, a, b))
        print("")
        
        n, m = list(map(int, stdin.readline().split()))

main()