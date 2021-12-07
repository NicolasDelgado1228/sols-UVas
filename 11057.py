from sys import stdin

r = stdin.readline

def fun(a, b): return b-a

def lower_bin(arr, x, lo, hi):
    while lo+1 != hi:
        mid = (lo+hi)>>1
        if arr[mid] <= x: lo = mid
        else: hi = mid
    return lo

def solve(arr, x):
    arr.sort()
    ans = tuple()
    for i in range(len(arr)-1):
        fst = arr[i]
        target = x-fst
        snd = arr[lower_bin(arr, target, i+1, len(arr))]
        if snd+fst == x: ans = (fst, snd)
    return ans


def main():
    n, first = r(), True
    while n != "":
        n = int(n)
        arr = list(map(int, r().strip().split()))
        x = int(r())
        a, b = solve(arr, x)
        print("Peter should buy books whose prices are", a, "and", str(b) + ".")
        print("")
        r()
        n = r().strip()

main()