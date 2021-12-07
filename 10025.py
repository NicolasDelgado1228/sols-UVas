from sys import stdin

def trian(n): return (n*(n+1))//2
def bytwo(n): return 2*n

def binsearch(f, lo, hi, k):
    ans = None
    if(lo < hi):
        while(lo+1 < hi):
            mid = (hi+lo)//2
            if(k >= f(mid)):
                lo = mid
            else:
                hi = mid

        ans = lo
    return ans


def main():
    N, first = int(stdin.readline()), True
    for case in range(N):
        if(not first): print("")
        first = False
        stdin.readline()
        k = abs(int(stdin.readline()))

        n = binsearch(trian, 1, 45000, k)
        if(trian(n) < k): n += 1
         
        dif = trian(n)-k
        
        if(dif%2 == 0): print(n)
        else:
            dif = trian(n+1)-k
            ans = binsearch(bytwo, 1, n+1, dif)
            if(ans*2==dif):
                print(n+1)
            else:print(n+2)
        


main()