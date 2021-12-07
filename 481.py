from sys import stdin
r = stdin.readline

"""
LIS - O(n²)
def dp(n, A, tab):
    ans = tab[n]
    if n == 1: ans = min(A)
    elif ans==float("inf"):
        for i in range(len(A)):
            if dp(n-1, A, tab) < A[i]:
                ans = min(ans, A[i])
    tab[n] = ans
    return ans
"""
"""
LIS - O(nlogn)
def dp(A):
    N = len(A)
    tab = [float("inf") for _ in range(N+1)]
    tab[0] = float("-inf")
    for i in range(N):
        idx = upper(tab, A[i], 1, N+1)
        if tab[idx-1]<A[i]: tab[idx] = min(tab[idx], A[i])
    return tab
"""
def upper(A, x, lo, hi):
    lo-=1;hi-=1
    while lo+1 < hi:
        mid = (lo+hi)>>1
        if A[mid]>=x: hi = mid
        else: lo = mid
    return hi

def dp(A):
    N = len(A)
    tab, parent, idx = [float("inf") for _ in range(N+1)], [-1 for _ in range(N)], [-1 for _ in range(N+1)]
    tab[0] = float("-inf")
    for i in range(N):
        j = upper(tab, A[i], 1, N+1)
        if tab[j-1]<A[i] and A[i] < tab[j]:
            tab[j] = A[i]
            idx[j] = i
            parent[i] = idx[j-1]
        
    return tab, idx, parent

def solve(A):
    tab, idx, parent = dp(A)
    lis_n, i = 0, 1
    while tab[i]!=float("inf"): lis_n+=1;i+=1
    u, ans = idx[lis_n], []
    while u != -1:
        ans.append(A[u])
        u = parent[u]
    ans.reverse()
    return ans

def main():
    A = list()
    line = r().strip()
    while line!="": A.append(int(line)); line = r().strip()
    N = len(A)
    tab = [float("inf") for _ in range(N+1)]
    tab[0] = float("-inf")
    ans = solve(A)
    print(len(ans))
    print("-")
    for x in ans: print(x)

main()