from sys import stdin
r = stdin.readline

def solve(A):
    A.sort(reverse=True)
    ans = 1
    for i in range(1, len(A)):
        if not (A[i-1][0]>=A[i][0] and A[i-1][1]>=A[i][1]): ans+=1
    return ans


def main():
    line = r().strip()
    while line!="":
        n = int(line)
        A = list()
        for i in range(n): 
            x, y = map(int, r().strip().split())
            if x-y<0:
                piv = x
                x = y
                y = piv
            A.append((x,y))
        print(solve(A))
        line = r().strip()
main()