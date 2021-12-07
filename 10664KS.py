from sys import stdin
import sys
sys.setrecursionlimit(100000) 


def solve(nums, weights, ac, weight, n):
    if(n == 0 or weight == 0):
        ans = ac
    else:
        ans = solve(nums, weights, ac, weight, n-1)
        if(weights[n-1] <= weight):
            ans = max(ans, solve(nums, weights, ac+nums[n-1], weight-weights[n-1], n-1))
    return ans


def main():
    cases = int(input())
    for case in range(cases):
        nums = list(map(int, input().split()))
        summation = sum(nums)

        if(summation % 2 != 0):
            print("NO")
        else:
            weight = summation//2
            ans = solve(nums, nums, 0, weight, len(nums))
            if(ans == weight):
                print("YES")
            else:
                print("NO")

main()