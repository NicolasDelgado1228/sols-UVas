from sys import stdin


delta = [(1,0), (0,1), (1,1), (-1,0), (0,-1), (-1,-1), (1,-1), (-1,1)]


def dfs(grid, visited, ini):
    global delta
    visited[ini[0]][ini[1]], stack, ans = True, [(ini[0],ini[1])], 1

    while len(stack) != 0:
        i, j = stack.pop()

        for deltaI, deltaJ in delta:
            di, dj = i+deltaI, j+deltaJ 
            if(0 <= di < len(grid) and 0 <= dj < len(grid[0]) and not visited[di][dj] and grid[di][dj] == '1'):
                ans += 1
                stack.append((di,dj))
                visited[di][dj] = True
    return ans

    

def main():
    global delta
    cases, first = int(stdin.readline()), True; stdin.readline()

    for case in range(cases):        
        if(not first): print("")
        line, grid, first = stdin.readline()[:-1], list(), False

        while(line != ""):
            grid.append(line)
            line = stdin.readline()[:-1]
        visited = [[False for _ in range(len(grid[0]))] for _ in range(len(grid))]

        i, maximum = 0, 0
        while(i < len(grid)):
            j = 0
            while(j < len(grid[0])):
                if(not visited[i][j] and grid[i][j] == '1'):
                    visited[i][j] = True
                    maximum = max(maximum, dfs(grid, visited, (i, j)))
                j += 1    
            i += 1

        print(maximum)

main()