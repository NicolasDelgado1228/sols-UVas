from sys import stdin
from queue import Queue

def bfs(grid, visited):
    q, count = Queue(), 1
    q.put((0,0))
    visited[0][0] = True

    while(not q.empty()):
        cell, adjacents = q.get(), list()
        i, j = cell[0], cell[1]
        if(i < len(grid)-1): adjacents.append((1+i,j))
        if(j < len(grid[0])-1): adjacents.append((i,j+1))
        if(i + 1 < len(grid) and j + 1 < len(grid[0])): adjacents.append((i+1, j+1))
        

        for adjacent in adjacents:
            i, j = adjacent[0], adjacent[1]
            if(grid[i][j] == '1' and not visited[i][j]):
                count += 1
                q.put((i,j))
                visited[i][j] = True
    
    return count


def main():
    cases, first = int(stdin.readline()), True; stdin.readline()
    for case in range(cases):        
        if(not first): print("")
        first = False
        line, grid = stdin.readline()[:-1], list()

        while(line != ""):
            grid.append(line)
            line = stdin.readline()[:-1]
        visited = [[False for _ in range(len(grid[0]))] for _ in range(len(grid))]

        i, j, maximum = 0, 0, -1
        while(i < len(grid)):
            while(j < len(grid[0])):
                if(not visited[i][j] and grid[i][j] == '1'): maximum = max(maximum, bfs(grid, visited))
                j += 1    
            i += 1

        print(maximum)

main()