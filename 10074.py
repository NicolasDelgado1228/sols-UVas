from sys import stdin

r = stdin.readline

def maxa_hist(arr):
    stack, i, ans = list(), 0, float("-inf")
    while i < len(arr):
        if len(stack)==0 or stack[-1][0]<=arr[i]: stack.append((arr[i], i)); i+=1
        else:
            h, idx = stack.pop()
            ans = max(ans, h*((i-stack[-1][1]-1) if len(stack)>0 else i)) 
    while len(stack)>0:
        h, idx = stack.pop()
        ans = max(ans, h*((i-stack[-1][1]-1) if len(stack)>0 else i)) 
    return ans

"""
def phi(n, M, H):
    ans = int()
    if n==1: ans = maxa_hist(H[0])
    else: ans = max(maxa_hist(H[n-1]), phi(n-1,M,H))
    return ans
"""

def phi(H):
    ans = float("-inf")
    for h in H: ans = max(maxa_hist(h), ans)
    return ans


def main():
    while 1:
        n, m = map(int, r().strip().split())
        if n+m == 0: break
        M = []
        for i in range(n): M.append(list(map(int, r().strip().split())))
        H = [[0 for _ in range(m)] for _ in range(n)]
        for i in range(m):
            if M[0][i]==0: H[0][i] = 1
        for i in range(1,n):
            for j in range(m):
                if M[i][j] == 0: H[i][j] = 1+H[i-1][j]
        print(phi(H))
main()