from sys import stdin

def floydWarshall(dist):
    n = len(dist)
    for k in range(n):
        for i in range(n):
            for j in range(n):
                if dist[i][k] + dist[k][j] < dist[i][j]:
                    dist[i][j] = dist[i][k] + dist[k][j]


def main():
    edgesCnt = int(stdin.readline())
    while edgesCnt != 0:
        nodes, inputs = set(), list()
        for i in range(edgesCnt):
            inp = stdin.readline().strip().split()
            nodes.add(inp[2]); nodes.add(inp[3])
            inputs.append(inp)

        s, t = stdin.readline().strip().split(); nodes.add(s); nodes.add(t)
        n, charToInt, intToChar, i = len(nodes), dict(), dict(), 0
        vertices = list()
        for v in nodes: vertices.append(v)
        vertices.sort()
        for v in vertices:
            charToInt[v], intToChar[i] = i, v
            i += 1
        distYoung, distElder = [[1000 for _ in range(n)] for _ in range(n)],  [[1000 for _ in range(n)] for _ in range(n)]
        for option, direct, a, b, weight in inputs:
            u, v = charToInt[a], charToInt[b]
            distYoung[u][u], distYoung[v][v], distElder[u][u], distElder[v][v] = 0, 0, 0, 0
            if option == "Y":
                distYoung[u][v] = int(weight)
                if direct == "B": distYoung[v][u] = int(weight)
            else:
                distElder[u][v] = int(weight)
                if direct == "B": distElder[v][u] = int(weight)

        for i in range(n):
            distElder[i][i] = 0
            distYoung[i][i] = 0
        i, j = charToInt[s], charToInt[t]
        
        
        
        floydWarshall(distElder); floydWarshall(distYoung)
        ans, answers = 1000, []
        for k in range(n):
            if distYoung[i][k]+distElder[j][k] < ans:
                ans = distYoung[i][k]+distElder[j][k]
                answers = [intToChar[k]]
            elif distYoung[i][k]+distElder[j][k] == ans: answers.append(intToChar[k])
        answers.sort()
        if ans != 1000:
            print(ans, end='')
            ans = ""
            for v in answers: ans+= (" "+v)
            print(ans)
        else: print("You will never meet.")
            
        edgesCnt = int(stdin.readline())

main()