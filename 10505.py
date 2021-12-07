from sys import stdin
from collections import deque

isBip, blackCnt, whiteCnt = bool(), int(), int()


def solve(G, invited):
    global isBip, blackCnt, whiteCnt
    N = len(G)
    colors, isBip, blackCnt, whiteCnt, ans = dict(), True, 0, 0, 0
    for key in G: colors[key] = -1 
    for u in G:
        if colors[u] == -1:
            bfs(G, u, colors, invited)
            if isBip: ans += max(whiteCnt, blackCnt)
            whiteCnt, blackCnt, isBip = 0, 0, True
    
    if ans == -1: ans = 0
    return ans


def bfs(G, u, colors, invited):
    global isBip, blackCnt, whiteCnt
    N, queue = len(G), deque()
    queue.append((u, 1))
    colors[u] = 1
    while len(queue) != 0:
        u, color = queue.popleft()
        nextColor = int(not color)
        if color==0 and u < invited: blackCnt+=1
        elif u < invited: whiteCnt+=1
        for v in G[u]:
            if colors[v] == -1: colors[v] = nextColor; queue.append((v,nextColor))
            elif colors[v] != nextColor: isBip = False
    
def main():
    global isBip, blackCnt, whiteCnt
    cases = int(stdin.readline())
    for case in range(cases):
        stdin.readline()
        N = int(stdin.readline())
        edges, n = list(), N

        G = dict()
        for u in range(N):
            line = list(map(int, stdin.readline().split()))
            if G.get(u) == None: G[u] = []
            if line[0] != 0:
                for v in line[1:]:
                    v -= 1
                    if v < N:
                        if v not in G[u]: G[u].append(v)
                        if G.get(v) == None: G[v] = [u]
                        elif u not in G[v]: G[v].append(u)
            
        print(solve(G, N))
main()