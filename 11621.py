from sys import stdin

def fun(c, j): return c*(3**j)

def binsearch(f, lo, hi, x, c):
    ans = -1
    while(lo+1<hi):
        mid = (hi+lo)//2
        if(x >= f(c, mid)):
            lo = mid
        else:
            hi = mid
    ans = f(c, lo)
    if(ans < x): ans = f(c, lo+1)
    return ans

def main():
    m = int(stdin.readline())
    while(m!=0):
        ans = 10000000000
        for i in range(0, 33):
            c = 2**i
            ans = min(ans, binsearch(fun, 0, 21, m, c))
        
        print(ans)

        m = int(stdin.readline())
        

main()