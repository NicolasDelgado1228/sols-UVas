from sys import stdin

def solve(arr, lo, hi):
    if lo+1

r = stdin.readline
def main():
    arr = list(map(int, r().strip().split()))
    while arr != []:
        ans = ac = 0
        for i in range(len(arr)):
            ac += arr[i]
            if ac <= 0: ac = 0
            ans = max(ac, ans)
        print(max(ac, ans))
        arr = list(map(int, r().strip().split()))

main()