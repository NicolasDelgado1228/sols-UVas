from sys import stdin


def phi(x, y, r, s, n, k, memo):
    ans = 0
    if x == (2*n) and y == 0 and r == 0: ans = 1
    elif memo[x][y][r][s]==-1:
        ans = 0
        if s==1:
            if y < n and x < (2*n): ans+=phi(x+1,y+1,r,1,n,k, memo)
            if y>0 and x < (2*n):
                if y==k and r>0: ans+=phi(x+1,y-1,r-1,0,n,k, memo)
                elif y!=k: ans+=phi(x+1,y-1,r,0,n,k, memo)
        else:
            if y>0 and x < (2*n): ans += phi(x+1,y-1,r,0, n, k, memo)
            if x < (2*n): ans += phi(x+1,y+1,r,1, n, k, memo)
        memo[x][y][r][s] = ans
    else: ans = memo[x][y][r][s]
    return ans


def main():
    r = stdin.readline
    line = r().strip()
    while line!="":
        n, r, k = map(int, line.split())
        memo = [[[[-1,-1] for _ in range(r+1)] for _ in range(n+1)] for _ in range((n*2)+1)]
        print(phi(0, 0, r, 1, n, k, memo))
        line = stdin.readline().strip()
main()