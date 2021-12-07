testCases = int(input())
first = True
for i in range(testCases):
    input()
    if(not first):
        print("")
    roads, queries = map(int, input().split())

    graph = {}

    #Creatre the graph
    for j in range(roads):
        nodeA, nodeB = map(str, input().split())
        nodeA = nodeA[0]
        nodeB = nodeB[0]

        if(nodeA not in graph):
            graph[nodeA] = [nodeB]
        else:
            graph[nodeA].append(nodeB)
        if(nodeB not in graph):
            graph[nodeB] = [nodeA]
        else:
            graph[nodeB].append(nodeA)

    for j in range(queries):
        visited = dict()
        for node in graph:
            visited[node] = False
        nodeA, nodeB = map(str, input().split())
        nodeA = nodeA[0]
        nodeB = nodeB[0]

        route = dict()
        queue = list()

        queue.append(nodeA)
        visited[nodeA] = True
        found = False

        #BFS
        queueSize = len(queue)
        while(queueSize != 0):
            node = queue[0]
            adjacents = graph[node]

            for adjacent in adjacents:
                if(not visited[adjacent]):
                    route[adjacent] = node
                    visited[adjacent] = True
                    if(adjacent == nodeB):
                        found = True
                        break
                    queue.append(adjacent)
                    queueSize += 1
            if(found):
                break
            queue.pop(0)
            queueSize-=1

        #Follow the path
        path = city = nodeB
        while(city != nodeA):
            city = route[city]
            path = city + path

        print(path)
    first = False
