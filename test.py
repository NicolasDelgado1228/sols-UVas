from sys import stdin

r = stdin.readline

def main():
	line = r().strip()
	while line!="":
		n = int(line)
		A = list(map(int, r().strip().split()))
		line = r().strip()

main()