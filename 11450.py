from sys import stdin


def phi(clothes, res, n, memo):
    ans = res
    if(memo[res][n] != -1): ans = memo[res][n]
    elif(n > 0):
        ans = 1000000000
        totry = clothes[n-1]
        for cloth in totry:
            if(res-cloth >= 0):
                ans = min(ans, phi(clothes, res-cloth, n-1, memo))
        memo[res][n] = ans
        
    return ans



def main():
    cases = int(stdin.readline())
    for case in range(cases):
        budget, N = list(map(int, stdin.readline().split()))
        clothes = list()
        for i in range(N): clothes.append(list(map(int, stdin.readline().split()))[1:])
        
        memo = [[-1 for _ in range(N+1)] for _ in range(budget+1)]
        ans = budget-phi(clothes, budget, N, memo)
        if(ans < 0): print("no solution")
        else: print(ans)
main()