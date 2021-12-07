from sys import stdin

rows,cols,plot = None,None,None
delta = [ (-1, -1), (-1, 0), (-1, 1), (0, -1), (0, 1), (1, -1), (1, 0), (1, 1) ]

def dfs(row, col, visited):
  stack = [ (row, col) ] ; visited[row][col] = 1
  while len(stack)!=0:
    r,c = stack.pop()
    for dr,dc in delta:
      tmpr,tmpc = r+dr,c+dc
      if 0<=tmpr<rows and 0<=tmpc<cols and visited[tmpr][tmpc]==0 and plot[tmpr][tmpc]=='@':
        stack.append((tmpr, tmpc)) ; visited[tmpr][tmpc] = 1
    visited[r][c] = 2

def solve():
  ans = 0
  visited = [ [ 0 for _ in range(cols) ] for _ in range(rows) ]
  for r in range(rows):
    for c in range(cols):
      if visited[r][c]==0 and plot[r][c]=='@':
        dfs(r, c, visited)
        ans += 1
  return ans

def main():
  global rows,cols,plot
  rows,cols = map(int, stdin.readline().split())
  while rows!=0:
    plot = [ stdin.readline().strip() for _ in range(rows) ]
    # print(plot)
    print(solve())
    rows,cols = map(int, stdin.readline().split())

main()