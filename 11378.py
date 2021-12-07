from sys import stdin
from math import sqrt
from sys import setrecursionlimit

setrecursionlimit(100000000)

r = stdin.readline



def dist(a, b): return max(abs(a[0]-b[0]), abs(a[1]-b[1]))

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
    return int(min_dist(points, 0, len(points)))
    


def main():
    line = r().strip()
    while line != "":
        N = int(line)
        points = list()
        for i in range(N): points.append(tuple(map(float, r().strip().split())))
        print(solve(points))
        line = r().strip()

main()