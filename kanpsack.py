from sys import stdin

r = stdin.readline

def phi(n, m, W, B):
    ans = int()
    if n == 0: ans = 0
    else:
        ans = phi(n-1,m,W,B)
        if m<=W[n-1]: ans = max(ans, phi(n-1,m-W[n-1],W,B)+B[n-1])
    return ans

def phi_tab(n, m, W, B):
    tab = [-1 for _ in range(n+1)]
    for i in range(n+1): tab[i] = 0
    for n in range(N+1):
        for m in range(M+1):
            tab[n] = tab[n-1]
            if m <= W[n]: tab[n] = max(tab[n], tab[n])

def main():
    pass

main()