from sys import stdin
import sys
sys.setrecursionlimit(100000) 


maximum = int()
solved = list()
nums = list()

def solve(i, acum):
    global maximum, solved, nums
    if(acum > maximum):
        maximum = acum
    if(i != len(nums)):
        solve(i+1, acum*nums[i])
        if(not solved[i]):
            solved[i] = True
            solve(i+1, nums[i])




def main():
    global maximum, solved, nums
    while(True):
        try:
            nums = list(map(int, input().split()))
            nums = nums[:len(nums)-1]
            solved = [False for x in nums]
            maximum = 0

            if(len(nums) > 0):
                maximum = nums[0]
                solve(1, nums[0])
            print(maximum)


        except EOFError:
            break

main()