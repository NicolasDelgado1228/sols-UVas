from sys import stdin


def phi(ac, N, k, nums, memo):
	if(N == 0):
		ans = int(ac%k == 0)
	else:
		if(memo[ac%k][N-1] == -1):
			memo[ac%k][N-1] = int(phi(ac+nums[N-1], N-1, k, nums, memo) or phi(ac-nums[N-1], N-1, k, nums, memo))
		ans = memo[ac%k][N-1]		
	return ans

tab = [[-1 for _ in range(10001)] for _ in range(101)]

def main():
    global tab
	cases = int(stdin.readline())
	for case in range(cases):
		N, k = map(int, stdin.readline().split())
		nums = list(map(int, stdin.readline().split()))

		res = 0
        while(res <= k):
            for n in range(N+1):
                if(n == 0):
                    tab[res][n] = 0
                else:
                    tab[res][n] = (tab[res][n-1]+nums[n-1])%k == 0 or (tab[res][n-1]-nums[n-1])%k == 0 
            
            res += 1
		
		if(phi(0, N, k, nums, memo) == 1): print("Divisible")
		else: print("Not divisible")

main()