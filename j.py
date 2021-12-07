from sys import stdin

read = stdin.readline

def main():
	n = int(read())
	nums = list(map(int, read().strip().split()))
	nums.sort()
	ans, ac, smaller = 1, 1, nums[0]
	for i in range(1, n):
		if nums[i]-smaller <= 5: ac += 1
		else: ac, ans, smaller = 1, max(ans, ac), nums[i]
	ans = max(ans, ac)
	print(ans)

main()