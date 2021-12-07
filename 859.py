from sys import stdin
from queue import Queue

delta, ans = [(1,0),(0,1),(0,-1),(2,0,1,0),(2,2,1,1),(2,-2,1,-1),(0,-2,0,-1),(0,2,0,1)], list()

MAX = 100
AUX = [ None for _ in range(MAX) ]

def mergesort(A, low, hi, comp):
    if low+1<hi:
        mid = low+((hi-low)>>1)    # mid = (low+hi)//2
        mergesort(A, low, mid, comp)
        mergesort(A, mid, hi, comp)
        merge(A, low, mid, hi, comp)

def merge(A, low, mid, hi, comp):
    for i in range(low, hi): AUX[i] = A[i]
    i,l,r = low,low,mid
    while i!=hi:
        if l==mid: A[i],r = AUX[r],r+1
        elif r==hi:
            A[i],l = AUX[l],l+1
        else:
            if comp(AUX[l],AUX[r]): A[i],l = AUX[l],l+1
            else: A[i],r = AUX[r],r+1
        i += 1

def comp(a, b):
    if a[0]==b[0]: return a[1] < b[1]
    else: return a[0] > b[0]



def bfs(grid, ini, visited):
    global delta, ans
    i, j = ini
    q = Queue()
    q.put((i,j,0))
        
    while not q.empty():
        i, j, steps = q.get()
        #jumps
        for deltaI, deltaJ, deltaPi, deltaPj in delta[3:]:
            di, dj, dpi, dpj = i+deltaI, j+deltaJ, i+deltaPi, j+deltaPj
            if 0 <= di < len(grid) and 0 <= dj < len(grid[0]) and grid[di][dj] == 0 and grid[dpi][dpj] != 0 and visited[di][dj] == 0:
                visited[di][dj] = 1
                q.put((di, dj, steps+1))
                ans.append((di+1, dj+1, steps+1))


def main():
    global delta, ans
    line, first = stdin.readline(), True
    while(line != ""):
        if(not first): print("")
        first = False
        ans = list()
        lines, columns = list(map(int, line.split()))
        grid = [[0 for _ in range(columns)] for _ in range(lines)]
        visited = [[0 for _ in range(columns)] for _ in range(lines)]

        for column in range(4*columns):
            i, j = list(map(int, stdin.readline().split()))
            i = i-1;j = j-1
            grid[i][j] = 1
        i, j = list(map(int, stdin.readline().split()))
        i = i-1; j = j-1

        #steps        
        for deltaI, deltaJ in delta[:3]:
            di, dj = i+deltaI, j+deltaJ
            if 0 <= di < len(grid) and 0 <= dj < len(grid[0]) and grid[di][dj] == 0 and visited[di][dj] == 0:
                ans.append((1+di, 1+dj, 1))
                visited[di][dj] = 1
        

        
        bfs(grid, (i,j), visited)
        mergesort(ans, 0, len(ans), comp)
        for triple in ans:
            trip = str()
            for t in triple: trip += str(t) + " "
            print(trip[:-1])

        line = stdin.readline() 

main()