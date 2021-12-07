from sys import stdin
import sys
sys.setrecursionlimit(100000) 



def main():
    cases = int(input())
    for case in range(cases):
        nums = list(map(int, input().split()))
        summation = sum(nums)
        weights = nums

        if(summation % 2 != 0):
            print("NO")
        else:
            W = summation//2
            tab = [[0 for x in range(W+1)] for i in range(len(nums)+1)]
            
            for n in range(len(nums)+1):
                for weight in range(W+1):
                    if(n == 0 or weight == 0):
                        tab[n][weight] = 0
                    else:
                        tab[n][weight] = tab[n-1][weight]
                        if(weights[n-1] <= weight):
                            tab[n][weight] = max(tab[n][weight], tab[n-1][weight-weights[n-1]]+nums[n-1])
            if(tab[len(nums)][W] == W):
                print("YES")
            else:
                print("NO")

main()