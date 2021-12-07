from sys import stdin

read = stdin.readline

di1, di2 = [-1, -1, -1], [1, 1, 1]
dj1, dj2 = [-1, 0, 1], [-1, 0, 1]

def main():
    global di1, di2, dj1, dj2
    n, Q = map(int, read().strip().split())
    maze = [[False for _ in range(n)], [False for _ in range(n)]]
    blocked_cnt = 0
    for q in range(Q):
        i, j =  map(int, read().strip().split())
        i-=1;j-=1
        have_lava = maze[i][j]
        ad_cnt = 0
        if i == 1:
            for k in range(len(di1)):
                d_i = i + di1[k]
                d_j = j + dj1[k]
                #print(d_i, d_j) 
                if 0<=d_i<2 and 0<=d_j<n and maze[d_i][d_j]: ad_cnt += 1
        else:
            for k in range(len(di1)):
                d_i = i + di2[k]
                d_j = j + dj2[k]
                #print(d_i, d_j)
                if 0<=d_i<2 and 0<=d_j<n and maze[d_i][d_j]: ad_cnt += 1
                
        if have_lava: blocked_cnt-=ad_cnt
        else: blocked_cnt+=ad_cnt
        if blocked_cnt == 0: print("Yes")
        else: print("No")
        maze[i][j] = not maze[i][j]


main()