from sys import stdin
r = stdin.readline

def phi1(n, x, A, memo):
    ans = float("inf")
    if n == 0 and x < 0.0: ans = 0
    elif (n,x) in memo: ans = memo[(n,x)]
    elif n>0:ans = min(A[n-1]+phi(n-1,x-A[n-1],A,memo), phi(n-1,x,A,memo)); memo[(n,x)] = ans
    return ans

def phi2(N, X, A):
    tab = [[-1 for _ in range(X+2)] for _ in range(N+2)]
    for n in range(N+1):
        for x in range(X+1):
            print(n,x)
            if n == 0: tab[n][x] = 0
            elif n>0:tab[n][x] = min(A[n-1]+tab[n-1][x-A[n-1]], tab[n-1][x])
    return tab[N][X]


def main():
    n, i = map(int, r().strip().split())
    while n+i!=0:
        A = list()
        for j in range(n):
            num = r().strip()
            a = int(num[:-3])*100
            b = int(num[-2:])
            A.append(a+b)
        x = A[i-1]
        if x > 5000: print("100.00")
        else:
            memo = {}
            A[i-1] = 0
            res = phi2(n, 5000-x, A)
            print("%.2f" % (100.0*x/(x+res)))
        n, i = map(int, r().strip().split())
main()