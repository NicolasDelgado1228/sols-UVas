from sys import stdin
from sys import stdout
from sys import setrecursionlimit

setrecursionlimit(10**8)

def solve(n):
    ans = True
    m = len(n)-2
    r = int(float(n)*(10**m))
    c, cent, cnt = 10**m, True, 0 
    sol =  0
    while(cent and cnt<100):
        r *= 3
        sol = r//c
        r = r%c
        if sol == 1:
            cent  = False
            ans = False
        cnt += 1
    return ans


def main():
    line = stdin.readline().strip()
    while(line[0] != 'E'):
        if(float(line) == 1.0 or float(line) == 0.0):
            stdout.write("MEMBER\n")
        else:
            stdout.write("MEMBER\n") if solve(line) else stdout.write("NON-MEMBER\n")
        
        line = stdin.readline().strip()
main()