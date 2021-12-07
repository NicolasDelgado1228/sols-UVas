def ks_naive(v,w,C):
    return ks_aux(v,w,len(v),C)

def ks_aux(v,w,n,c):
    ans = None
    if n==0: ans = 0
    else:
        ans = ks_aux(v,w,n-1,c)
        if w[n-1]<=c: ans = max(ans,v[n-1]+ks_aux(v,w,n-1,c-w[n-1]))
    return ans
def ks_tab(v,w,N,C):
    tab = [[-1 for _ in range(C+1)] for _ in range(N+1)]
    for i in range(C+1): tab[0][i] = 0
    for n in range(1,N+1):
        for c in range(C+1):
            tab[n][c] = tab[n-1][c]
            if w[n-1]<=c: tab[n][c] = max(tab[n][c],v[n-1]+tab[n-1][c-w[n-1]])
    return tab[N][C]

def ks_tab_opt(v,w,N,C):
    tab_prev, tab_curr = [0 for _ in range(C+1)], [-1 for _ in range(C+1)]
    for n in range(1,N+1):
        for c in range(C+1):
            tab_curr[c] = tab_prev[c]
            if w[n-1]<=c: tab_curr[c] = max(tab_curr[c],v[n-1]+tab_prev[c-w[n-1]])
        tab_prev = tab_curr.copy()
    return tab_curr[C]
def main():
    v, w, c = [1,2,3,4,5], [4,1,5,3,2], 9
    print(ks_aux(v,w,len(v),c))
    print(ks_tab(v,w,len(v),c))
    print(ks_tab_opt(v,w,len(v),c))
    
main()