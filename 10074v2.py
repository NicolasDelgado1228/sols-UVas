from sys import stdin

r = stdin.readline

def area(rec): return abs(rec[0][0]-rec[1][0])*abs(rec[0][1]-rec[1][1])

def phi(n, m, M):
    dp = [[(-1,-1) for _ in range(m)] for _ in range(n)]
    for i in range(m): 
        if M[0][i] == 0: dp[0][i] = (0,i) 
    for i in range(1,n):
        if M[i][0] == 0: 
            if M[i-1][0] == 0: dp[i][0] = (dp[i-1][0])
            else: dp[i][0] = (i,0)
            

    for i in range(1, n):
        for j in range(1, m):
            if M[i][j] == 0:
                if M[i-1][j]==0 and M[i][j-1] == 0 and M[i-1][j-1] == 0:
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1], dp[i-1][j-1])
                elif M[i-1][j]==0 and M[i][j-1] == 0:
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1])#(max(dp[i-1][j][0],dp[i][j-1][0]), max(dp[i-1][j][1],dp[i][j-1][1]))
                elif M[i-1][j] == 0:
                    dp[i][j] = (min(dp[i-1][j][0],i), max(dp[i-1][j][1], j))
                elif M[i][j-1] == 0:
                    dp[i][j] = (max(dp[i][j-1][0],i), min(dp[i][j-1][1], j))
                else: dp[i][j] = (i,j)
    for i in dp: print(*i)
    ans = 0
    for i in range(n):
        for j in range(m):
            if M[i][j] == 0: 
                ans = max(ans, area(((i+1,j+1),(dp[i][j][0],dp[i][j][1]))))
    return ans


def main():
    while 1:
        n, m = map(int, r().strip().split())
        if n+m == 0: break
        mat = []
        for i in range(n): mat.append(list(map(int, r().strip().split())))
        ans = phi(n,m,mat)
        print(ans)
main()