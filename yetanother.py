from sys import stdin
r = stdin.readline

def main():
    cases = int(r())
    for case in range(cases):
        A, B = map(int, r().strip().split())
        ans = 0
        b = 9
        i = 1
        while (10**i)-1 <= B: i+=1; ans+=A

        print(ans)

main()