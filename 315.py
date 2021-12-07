def artPoints(graph, visited, disc, low, parent, isAp, u):
    global time, artPointsCnt
    visited[u] = True
    disc[u] = time
    time += 1
    low[u] = disc[u]
    childrens = 0

   
    for v in graph[u]:
        if(not visited[v]):
            childrens += 1
            parent[v] = u
            artPoints(graph, visited, disc, low, parent, isAp, v)

            low[u] = min(low[u], low[v])
            if((low[v] >= disc[u] and parent[u] != -1 and not isAp[u]) or (parent[u] == -1 and childrens > 1 and not isAp[u])):
                artPointsCnt += 1
                isAp[u] = True
        elif(parent[u] != v):
            low[u] = min(low[u], disc[v])



def main():
    global time, artPointsCnt
    while(True):
        N = int(input())
        if(N == 0): break
        
        graph = [[] for i in range(N)]
        time = 0

        #Build the graph
        while(True):
            line = list(map(int,input().split()))
            i = 1
            while(i < len(line)):
                graph[line[0]-1].append(line[i]-1)
                graph[line[i]-1].append(line[0]-1)
                i += 1
            
            if(line[0] == 0): break

        
        artPointsCnt = 0
        artPoints(graph, [False for i in range(N)], [-1 for i in range(N)], [-1 for i in range(N)], [-1 for i in range(N)], [False for i in range(N)], 0)
        print(artPointsCnt)
        


main()