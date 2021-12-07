from sys import stdin
from math import sqrt
from sys import setrecursionlimit

setrecursionlimit(100000000)

r = stdin.readline


MAX = 10000
AUX = [ None for _ in range(MAX) ] 

def mergeSort(a): 
    width = 1
    while width < len(a) - 1: 
        lo = 0
        while lo < len(a)-1: 
            mid = lo + width 
            hi = min((2*width) + lo, len(a))
            print(lo, mid, hi)
            merge(a, lo, mid, hi) 
            lo = lo + width*2
        width = 2*width 

def merge(A, low, mid, hi):
  for i in range(low, hi): AUX[i] = A[i]
  l,r,i = low,mid,low
  while i!=hi:
    if r==hi:
      A[i] = AUX[l]
      i,l = i+1,l+1
    elif l==mid:
      A[i] = AUX[r]
      i,r = i+1,r+1
    else:
      if AUX[l]<=AUX[r]:
        A[i] = AUX[l]
        i,l = i+1,l+1
      else:
        A[i] = AUX[r]
        i,r = i+1,r+1

def bin_lower(A, x, lo, hi):
    found = False
    while lo+1 < hi and not found:
        mid = (lo+hi)>>1
        if A[mid][0] == x: lo = mid; found = True
        elif A[mid][0] < x: lo = mid
        else: hi = mid
    return lo

def bin_upper(A, x, lo, hi):
    found = False
    while lo+1 != hi and not found:
        mid = (lo+hi)>>1
        if A[mid][0] == x: hi = mid; found = True
        elif A[mid][0] > x: hi = mid
        else: lo = mid
    return hi


def dist(a, b):
    x0, y0 = a
    x1, y1 = b
    return sqrt(((x1-x0)**2)+((y1-y0)**2))

def min_dist(points, lo, hi):
    ans = float()
    if lo+1==hi: ans = float("inf")
    elif lo+2 == hi: ans = dist(points[lo], points[lo+1])
    else:
        mid = (lo+hi)>>1
        left_ans, right_ans = min_dist(points, lo, mid), min_dist(points, mid, hi)
        delta = min(left_ans, right_ans)
        #Now evaluate if the points of the ans are in diferent arrays
        lb, rb = points[mid][0]-delta, points[mid][0]+delta
        l_idx = bin_upper(points, lb, lo-1, mid-1)
        r_idx = bin_lower(points, rb, mid, hi)
        ans = delta
        aux = list()
        for i in range(l_idx, mid): aux.append(points[i])
        for i in range(mid, r_idx+1): aux.append(points[i])
        for i in range(len(aux)):
            for j in range(i+1,len(aux)):
                ans = min(ans, dist(aux[i], aux[j]))
                
    return ans


def solve(points):
    mergesort(points, 0, len(points))
    ans = min_dist(points, 0, len(points))
    return ans if ans < 10000 else -1


def main():
    n = int(r())
    while n:
        points = list()
        for i in range(n): points.append(tuple(map(float, r().strip().split())))
        ans = solve(points)
        
        if ans != -1: print("%.4f" % ans)
        else: print("INFINITY")
        n = int(r())

main()