from sys import stdin

def possible(target, dist, kTar):
    N = len(dist)
    k = 0
    i = 0
    ac = 0
    consistent = True
    while i < N and consistent:
        if ac + dist[i] <= target:
            ac += dist[i] ; i +=1
        else:
            k+=1 ; ac = 0
            if k > kTar: consistent = False
    ans = bool()
    if not consistent: ans = False
    else: ans = k<=kTar
    
    return ans


def bisec(nums, k):
    lo, hi, mx = 0, sum(nums)+1, max(nums)
    while lo+1 < hi:
        mid = (lo+hi)//2
        if mid < mx: lo = mid
        elif possible(mid, nums, k): hi = mid
        else: lo = mid
    return hi

def main():
    inp = stdin.readline()
    while inp != "":
        inp = list(map(int, inp.split()))
        N, k = inp
        nums = list()
        for i in range(N+1): nums.append(int(stdin.readline()))

        print(bisec(nums, k))

        inp = stdin.readline()
main()