from sys import stdin
import sys
sys.setrecursionlimit(100000) 


def solve(nums, weights, ac, weight, n, memo):
    if(n == 0 or weight == 0):
        memo[n][weight] = ac
    else:
        ans = memo[n][weight]
        if(ans == -1):
            memo[n][weight] = solve(nums, weights, ac, weight, n-1, memo)
            if(weights[n-1] <= weight):
                memo[n][weight] = max(memo[n][weight], solve(nums, weights, ac+nums[n-1], weight-weights[n-1], n-1, memo))
    return memo[n][weight]


def main():
    cases = int(input())
    for case in range(cases):
        nums = list(map(int, input().split()))
        summation = sum(nums)
        memo = [[-1 for x in range(summation+1)] for i in range(len(nums)+1)]

        if(summation % 2 != 0):
            print("NO")
        else:
            weight = summation//2
            ans = solve(nums, nums, 0, weight, len(nums), memo)
            if(ans == weight):
                print("YES")
            else:
                print("NO")

main()