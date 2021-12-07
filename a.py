from sys import stdin
from math import ceil, floor

r = stdin.readline

def main():
	cases = int(r())
	for case in range(cases):
		x, y, a, b = map(int, r().strip().split())
		ans = (y-x)/(a+b)
		if ceil(ans)!=floor(ans): print(-1)
		else: print(int(ans))			

main()