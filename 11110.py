from sys import stdin

delta = [(1,0),(-1,0),(0,-1),(0,1)]

def dfs(square, visited, i, j):
    global delta
    n, num, stack, ans = len(square), square[i][j]-1, [(i,j)], 0

    while len(stack) != 0:
        i, j = stack.pop()
        visited[i][j] = True
        ans += 1

        for deltaI, deltaJ in delta:
            di, dj = i+deltaI, j+deltaJ
            if 0 <= di < n and 0 <= dj < n and square[di][dj]-1 == num and not visited[di][dj]:
                visited[di][dj] = True
                stack.append((di,dj))
    return ans



def main():
    global delta
    n = int(stdin.readline())
    while n != 0:
        square = [[n for _ in range(n)] for _ in range(n)]
        for partition in range(1,n):
            line = list(map(int,stdin.readline().split()))
            k = 0
            while k < len(line)-1:
                i, j = line[k]-1, line[k+1]-1
                square[i][j] = partition; k += 2
            
        visitedNum, good, visited = [False for _ in range(n)], True, [[False for _ in range(n)] for _ in range(n)]
        for i in range(n):
            for j in range(n):
                if not visitedNum[square[i][j]-1]:
                    visitedNum[square[i][j]-1] = True
                    if dfs(square, visited, i, j) != n: good = False
        if good: print("good")
        else: print("wrong")
        
        n = int(stdin.readline())

main()