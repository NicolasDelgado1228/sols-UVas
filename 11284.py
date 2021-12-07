from sys import stdin, setrecursionlimit
setrecursionlimit(100000000)

r = stdin.readline

def floyd_warshall(M):
    n = len(M)
    dist = M.copy()
    for i in range(n): dist[i][i] = 0

    for k in range(n):
        for i in range(n):
            for j in range(n):
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j])
    return dist

def tsp(S, C, dist, stores, saving, memo):
    n, ans, store = len(stores), int(), stores[C]
    if (2**n)-1 == S: ans = saving[C]-dist[store][0]
    elif memo[S][C] == float("-inf"):
        ans = saving[C]-dist[store][0]
        for i in range(n):
            if ((1<<(n-i-1)) & S == 0):
                ans = max(ans, tsp(S|(1<<(n-i-1)), i,dist,stores,saving,memo)+saving[C]-dist[store][stores[i]])
        memo[S][C] = ans
    else: ans = memo[S][C]
    return ans


def main():
    cases = int(r())
    for case in range(cases):
        r()
        n, m = map(int, r().strip().split())
        G = [[float("inf") for _ in range(n+1)] for _ in range(n+1)]
        for i in range(m):
            u, v, w = map(str, r().strip().split())
            u, v = map(int, [u,v])
            w = w.split(".")
            w = (int(w[0])*100)+int(w[1])
            G[u][v] = G[v][u] = min(G[u][v], w)

        dist = floyd_warshall(G)
        #for x in dist: print(x)

        
        stores, saving, s_cnt = [0], [0], int(r())
        for i in range(s_cnt):
            store, sav = r().strip().split()
            sav = sav.split(".")
            sav = (int(sav[0])*100)+int(sav[1])
            stores.append(int(store)); saving.append(sav)

        memo = [[float("-inf") for _ in range(s_cnt+1+1)] for _ in range((2**(s_cnt+1))+1)]

        ans = tsp(1<<(s_cnt), 0, dist, stores, saving, memo)
        if ans > 0:
            ans/=100
            print("Daniel can save $"+"%.2f"%ans)
        else: print("Don't leave the house")
        
        
        

main()