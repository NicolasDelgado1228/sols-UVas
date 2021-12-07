from sys import stdin
import sys
sys.setrecursionlimit(1000000000)

deepest, mostDeep, parent = tuple(), list(), list()

def dfs(T, u, visited, depth):
    global deepest, mostDeep, parent
    visited[u] = True
    if depth > deepest[1]: deepest = (u, depth); mostDeep = [u]
    elif depth == deepest[1]: mostDeep.append(u)

    for v in T[u]:
        if not visited[v]:
            parent[v] = u
            dfs(T, v, visited, depth+1)

def solve(T):
    global deepest, mostDeep, parent
    n = len(T)
    visited, deepest, mostDeep, parent = [False for _ in range(n)], (-1, -1), [], [-1 for _ in range(n)]
    dfs(T, 0, visited, 0)
    visited, deepest, mostDeep, parent, ex1 = [False for _ in range(n)], (-1, -1), [], [-1 for _ in range(n)], deepest[0]
    dfs(T, ex1, visited, 0)
    ex2 = deepest[0]
    u, diameter = parent[ex2], [ex2]
    while parent[u] != -1: diameter.append(u); u = parent[u]
    diameter.append(u)
    visited, deepest, mostDeep = [False for _ in range(n)], (-1, -1), []
    dfs(T, ex2, visited, 0)
    best = [diameter[len(diameter)//2]]
    visited, deepest, mostDeep = [False for _ in range(n)], (-1, -1), []
    dfs(T, best[0], visited, 0)
    worst = mostDeep
    if len(diameter)%2==0:
        best.append(diameter[(len(diameter)//2)-1])
        visited, deepest, mostDeep, inWorst = [False for _ in range(n)], (-1, -1), [], [False for i in range(n)]
        for i in worst: inWorst[i] = True
        dfs(T, best[1], visited, 0)
        for x in mostDeep:
            if not inWorst[x]: worst.append(x); inWorst[x] = True

    return (best, worst)



def main():
    global deepest, mostDeep, parent
    n = stdin.readline()
    while n != "":
        n = int(n)
        T = [[] for _ in range(n)]
        for u in range(n):
            inp = list(map(int, stdin.readline().strip().split()))
            for v in inp[1:]:
                if v > u: T[u].append(v-1); T[v-1].append(u)

        best, worst = solve(T)
        best.sort(); worst.sort()
        print("Best Roots  :", end='')
        for root in best: print(" " + str(root+1), end='')
        print("")
        print("Worst Roots :", end='')
        for root in worst: print(" " + str(root+1), end='')
        print("")
        n = stdin.readline()
main()
