from sys import stdin
r = stdin.readline

def phi(n):
    ans = int()
    if n == 0: ans = 1
    else:
        ans = 0
        for i in range(1,n+1): ans+=phi(n-i)
    return ans


def main():
    n = r().strip()
    while n!= "":
        n = int(n)
        print(phi(n))
        n = r().strip()
main()