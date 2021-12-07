from sys import stdin
import sys
sys.setrecursionlimit(1000000)

toposorts, haveTopo = list(), bool()

def solve(G, inDegree, ans, n):
    global toposorts, haveTopo
    if n == len(G): toposorts.append(ans)
    elif haveTopo:
        haveTopo = False
        for u in range(len(G)):
            if inDegree[u] == 0:
                haveTopo = True
                newAns = ans.copy(); newAns.append(u)
                inDeg = inDegree.copy(); inDeg[u] -= 1
                for v in G[u]: inDeg[v]  -= 1
                solve(G, inDeg, newAns, n+1)
                

def main():
    global toposorts, haveTopo
    cases, first = int(stdin.readline()), True
    for case in range(cases):
        stdin.readline()
        vertices = stdin.readline().strip().split()
        charToInt, n = dict(), len(vertices)
        for i in range(len(vertices)): charToInt[vertices[i]] = i
        edges = stdin.readline().strip().split()
        G, inDeg = [[] for _ in range(n)], [0 for _ in range(n)]
        for edge in edges: G[charToInt[edge[0]]].append(charToInt[edge[2]]); inDeg[charToInt[edge[2]]]+=1
        
        haveTopo, toposorts = True, []
        solve(G, inDeg, [], 0)
        if not first: print("")
        first = False
        if haveTopo:
            answers = list()
            for topo in toposorts:
                ans = ""
                for v in topo: ans += (vertices[v])
                answers.append(ans)
            answers.sort()
            for answer in answers:
                ans = ""
                for v in answer: ans += (v + " ")
                print(ans[:-1])
        else: print("NO") 

    

main() 