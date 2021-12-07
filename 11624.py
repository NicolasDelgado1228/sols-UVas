from sys import stdin
import collections 

delta = [(1,0),(-1,0),(0,1),(0,-1)]

def simulate(fireSim, maze, visited, q):
    global delta
    n, m = len(maze), len(maze[0])

    while not len(q) == 0:
        i, j, time = q.popleft()

        for deltaI, deltaJ in delta:
            di, dj = i+deltaI, deltaJ+j
            if 0 <= di < n and 0 <= dj < m and maze[di][dj] != "#" and not visited[di][dj]:
                visited[di][dj] = True
                fireSim[di][dj] = time+1
                q.append((di, dj, time+1))

    
def bfs(maze, fireSim, ini, visited):
    global delta
    q, time, found, ans, n, m = collections.deque(), 0, False, -1, len(maze), len(maze[0])
    q.append((ini[0], ini[1], time))
    visited[ini[0]][ini[1]] = True

    while(not len(q) == 0 and not found):
        node = q.popleft()
        cell, time, adjacents = (node[0], node[1]), node[2], list()
        if cell[0] == n-1 or cell[0] == 0 or cell[1] == 0 or cell[1] == m-1: ans = time+1; found = True
        else:
            i, j = cell
            if i+1 <= n-1: adjacents.append((i+1,j))
            if i-1 >= 0: adjacents.append((i-1,j))
            if j+1 <= m-1: adjacents.append((i,j+1))
            if j-1 >= 0: adjacents.append((i,j-1))

            for adjacent in adjacents:
                i, j = adjacent
                if not visited[i][j] and maze[i][j] == "." and (fireSim[i][j]==-1 or fireSim[i][j] > time+1):
                    visited[i][j] = True
                    q.append((i, j, time+1))
    if not found: ans = -1
    return ans


def main():
    global delta
    cases = int(stdin.readline())
    for case in range(cases):
        maze = list()
        n, m = list(map(int, stdin.readline().split()))
        for row in range(n): maze.append(stdin.readline()[:-1])
        
        #Simulation
        fireSim, i, visited, vis, q = [[-1 for _ in range(m)] for _ in range(n)], 0, [[False for _ in range(m)] for _ in range(n)], [[False for _ in range(m)] for _ in range(n)], collections.deque()
        while(i < n):
            j = 0
            while(j < m):
                if(maze[i][j] == "F"): vis[i][j] = True; q.append((i,j,0))
                elif maze[i][j] == "J": ini = (i, j)
                j += 1
            i += 1
        simulate(fireSim, maze, vis, q)
        ans = bfs(maze, fireSim, ini, visited)
        if(ans == -1): print("IMPOSSIBLE")
        else: print(ans)

        
        

main()