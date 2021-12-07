from sys import stdin

r = stdin.readline

def prec_C(N, K):
    dp = [[-1 for _ in range(K+1)] for _ in range(N+1)]
    for n in range(N+1):
        for k in range(K+1):
            if (n==0 and k== 0) or (n>=0 and k==0) or n==k: dp[n][k] = 1
            elif n<k: dp[n][k] = 0
            else: dp[n][k] = dp[n-1][k-1]+dp[n-1][k]
    return dp


def main():
    cases = int(r())
    C = prec_C(100,100)
    for case in range(cases):
        k, n, a = map(int, r().strip().split())
        if n-(a*k)+k-1 < 0: print(0)
        else: print(C[n-(a*k)+k-1][k-1])

main()