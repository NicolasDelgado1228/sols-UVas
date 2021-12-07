from sys import stdin
import sys
sys.setrecursionlimit(10000000500)

#solved[N][res]
divided, found = bool(), bool()
def phi(ac, N, k, res, solved, nums):
	global found, divided
	if(not found and not solved[N][res]):
		solved[N][res] = True
		if(N == 0 and res == 0):
			found, divided = True, True
		elif(N > 0):
			newSum = ac+nums[N-1]
			res = newSum%k
			phi(newSum, N-1, k, res, solved, nums)
			newSum = ac-nums[N-1]
			res = newSum%k
			phi(newSum, N-1, k, res, solved, nums)


def main():
	global found, divided
	cases = int(stdin.readline())
	for case in range(cases):
		N, k = map(int, stdin.readline().split())
		nums = list(map(int, stdin.readline().split()))

		divided, found = False, False
		solved = [[False for _ in range(k)] for _ in range(N+1)]
		phi(0, N, k, -1, solved, nums)
		if(divided): print("Divisible")
		else: print("Not divisible")

main()