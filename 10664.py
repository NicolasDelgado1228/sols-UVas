from sys import stdin
import sys
sys.setrecursionlimit(100000) 

def solve(n, wCar1, wCar2):
    global nums, memo, solved

    if(wCar1 == wCar2):
        return True
    if(n == -1):
        return False
    
    if(not solved[n][wCar2]):
        memo[n][wCar2] = solve(n-1, wCar1, wCar2) or solve(n-1, wCar1-nums[n], wCar2 + nums[n])
        solved[n][wCar2] = True
    
    return memo[n][wCar2]




def main():
    global nums, memo, solved
    cases = int(input())
    for case in range(cases):
        nums = list(map(int, input().split()))
        wCar1 = 0
        for num in nums:
            wCar1 += num
        
        n = len(nums)
        memo = [[0 for x in range(200)] for i in range(n)]
        solved = [[False for x in range(200)] for i in range(n)]

        if(solve(n-1, wCar1, 0)):
            print("YES")
        else:
            print("NO")
main()