from sys import stdin

def square(n): return n**2


def binsearch(f, lo, hi, x):
    ans = 0
    if(lo < hi):
        while(lo+1 < hi):
            mid = (hi+lo)//2
            if(x >= f(mid)):
                lo = mid
            else:
                hi = mid

        ans = lo

    return ans



def main():
    cases = int(stdin.readline())
    for case in range(cases):
        a, b = map(int, stdin.readline().split())
        dif = b-a

        ans = binsearch(square, 0, 47000, dif)
        if(ans == 0): print(0)
        elif(ans**2 == dif): print((ans*2)-1)
        else:
            dif = dif-(ans**2)
            if(dif%ans==0): print((ans*2)-1 + (dif//ans))
            else: print((ans*2)+(dif//ans))

main()