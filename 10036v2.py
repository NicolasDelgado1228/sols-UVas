from sys import stdin
import sys
sys.setrecursionlimit(100000500)

def phi(ac, N, k, nums, memo):
	if(N == 0):
		ans = int(ac%k == 0)
	else:
		if(memo[ac%k][N-1] == -1):
			memo[ac%k][N-1] = int(phi(ac+nums[N-1], N-1, k, nums, memo) or phi(ac-nums[N-1], N-1, k, nums, memo))
		ans = memo[ac%k][N-1]		
	return ans

def main():
	cases = int(stdin.readline())
	for case in range(cases):
		N, k = map(int, stdin.readline().split())
		nums = list(map(int, stdin.readline().split()))

		memo = [[-1 for _ in range(N+1)] for _ in range(k+1)]
		
		if(phi(0, N, k, nums, memo) == 1): print("Divisible")
		else: print("Not divisible")

main()