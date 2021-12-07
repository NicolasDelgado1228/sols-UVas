from sys import stdin
import heapq
 

def solve(graph, visited, source):
    #bfs with heapq
    pq, time, father, dist, w, a, b = [], 0, 0, [None for _ in range(len(graph))], 0, 1, -1
    dist[source] = 0
    heapq.heappush(pq, (w, source, father))

    while len(pq) != 0:
        w, u, father = heapq.heappop(pq)
        if not visited[u]:
            visited[u], dist[u] = True, w
            if dist[u] > time: time = dist[u]; a = u+1
            elif dist[u] == time: a = min(a, u+1)
            time = max(time, dist[u])

            for v, w in graph[u]:
                heapq.heappush(pq, (w+dist[u], v, u))
    
    pair = False
    for u in range(len(graph)):
        for v, w in graph[u]:
            if time < dist[u]+((w-abs(dist[u]-dist[v]))/2):
                a, b, pair = max(u+1,v+1), min(v+1, u+1), True
                time = dist[u]+((w-abs(dist[u]-dist[v]))/2)
            elif time == dist[u]+((w-abs(dist[u]-dist[v]))/2) and pair == True:
                if min(a,b) == min(u+1,v+1) and max(a,b) > max(u+1,v+1): a, b = max(u+1,v+1), min(v+1, u+1)
                elif min(a,b) > min(u+1,v+1): a, b = max(u+1,v+1), min(v+1, u+1)
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

        
        time, a, b = solve(graph, visited, 0)
        print("System #" + str(case)); case += 1
        if b == -1: print("The last domino falls after %.1f seconds, at key domino %d."%(time, a))
        else: print("The last domino falls after %.1f seconds, between key dominoes %d and %d."%(time, b, a))
        print("")
        

        n, m = list(map(int, stdin.readline().split()))
 
main()


