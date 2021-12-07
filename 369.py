    from sys import stdin
    r = stdin.readline

    def C_precal(N,K):
        tab = [[-1 for _ in range(K+1)] for _ in range(N+1)]
        for n in range(N+1):
            for k in range(K+1):
                if k == 0 or n == k or n < k: tab[n][k] = 1
                else: tab[n][k] = tab[n-1][k-1]+tab[n-1][k]
        return tab

    C = C_precal(100,100)

    def main():
        n, m = map(int, r().strip().split())
        while n+m!=0:
            print(n,"things taken",m,"at a time is",C[n][m],"exactly.")
            n, m = map(int, r().strip().split())
    main()