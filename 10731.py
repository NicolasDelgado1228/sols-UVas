from sys import stdin

timeCnt = int()

def dfsTarjan(G, low, time, inStack, stack, sccs, u):
    global timeCnt
    time[u] = timeCnt ; timeCnt += 1; stack.append(u); inStack[u] = True
    low[u] = time[u]

    for v in G[u]:
        if time[v] == -1:
            dfsTarjan(G, low, time, inStack, stack, sccs, v)
            low[u] = min(low[u], low[v])
        elif inStack[v]: low[u] = min(low[u], time[v])
    
    if low[u] == time[u]:
        scc = list() ; w = -1
        while u != w:
            w = stack.pop()
            scc.append(w)
            inStack[w] = False
        sccs.append(sorted(scc))
            

def tarjan(G, low, time, inStack):
    global timeCnt
    n = len(G)
    for u in G: low[u] = -1; time[u] = -1; inStack[u] = False 
    stack, sccs, timeCnt = [], [], 0
    for u in G:
        if time[u] == -1:
            dfsTarjan(G, low, time, inStack, stack, sccs, u)
    return sccs


def main():
    global timeCnt
    n = int(stdin.readline()) ; first = True
    while(n != 0):
        G, low, time, inStack = dict(), dict(), dict(), dict()
        for ans in range(n):
            vertices = list(stdin.readline().strip().split())
            v = vertices[-1] ; G[v] = set()  
            for i in range(5):
                if G.get(vertices[i]) == None: G[vertices[i]] = set()
                low[vertices[i]] = -1; time[vertices[i]] = -1; inStack[vertices[i]] = False 
                if vertices[i] != v: G[v].add(vertices[i])
                

        ans = tarjan(G, low, time, inStack)
        
        ans.sort(key=lambda x:x[0])
        if not first: print("")
        else: first = False
        for scc in ans:
            sccStr = ""
            for comp in scc: sccStr += (comp + " ")
            sccStr = sccStr[:-1]
            print(sccStr)
        
        n = int(stdin.readline())
main()