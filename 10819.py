from sys import stdin
r = stdin.readline

def dp(n, s, t, A, W, memo):
    if n == 0: ans = 0
    elif memo[n][s] == -1:
        ans = dp(n-1,s,t,A,W, memo)
        if s+A[n-1]>=2000 and s+A[n-1]<=(t+200):
            ans = max(ans, W[n-1]+dp(n-1,s+A[n-1],t,A,W,memo))
        elif s+A[n-1] <= t: ans = max(ans, W[n-1]+dp(n-1,s+A[n-1],t,A,W,memo))
        memo[n][s] = ans
    else: ans = memo[n][s]
    return ans 


def main():
    line = r().strip()
    while line != "":
        t, n = map(int, line.split())
        A, W = list(), list()
        for i in range(n):
            x, w = map(int, r().strip().split())
            A.append(x); W.append(w)
        memo = [[-1 for i in range(t+201)] for _ in range(n+1)]
        print(dp(n, 0, t, A, W, memo))
        line = r().strip()

main()