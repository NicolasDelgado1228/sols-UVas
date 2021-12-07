from sys import stdin
from math import sqrt
from sys import setrecursionlimit


r = stdin.readline


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
        ans = delta = min(left_ans, right_ans)
        #Now evaluate if the points of the ans are in diferent arrays
        i = mid-1
        while i >= lo and points[mid][0]-points[i][0] < delta:
            j = mid
            while j < hi and points[j][0]-points[i][0] < delta:
                ans = min(ans, dist(points[i], points[j]))
                j+=1
            i-=1
                
    return ans


def solve(points):
    points.sort()
    ans = min_dist(points, 0, len(points))
    return ans if ans < 10000 else -1


def main():
    n = int(stdin.readline())
    while n!=0:
        point = list()
        for _ in range(n):
            tok = stdin.readline().split()
            point.append((float(tok[0]), float(tok[1])))
        ans = solve(point)
        if ans != -1: print('{0:.4f}'.format(ans))
        else: print("INFINITY")
        n = int(stdin.readline())

main()