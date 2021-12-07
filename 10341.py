from sys import stdin
import math


def binsearch(f, a, b, p, q, r, s, t, u):
    ans, found, i = -1, False, 0
    while(i < 30):
        mid = (a+b)/2
        y = f(p, q, r, s, t, u, mid)
        if(y > 0):
            a = mid
        else:
            b = mid
        i+=1
    return b


def function(p,q,r,s,t,u,x):
    return (p*math.pow(2.71828182845904, -1*x))+(q*math.sin(x))+(r*math.cos(x))+(s*math.tan(x))+(t*(x**2))+u

def main():
    constants = stdin.readline()
    while(constants!=""):
        constants = list(map(int, constants.split()))
        p,q,r,s,t,u = constants
        ans = binsearch(function, 0, 1, p,q,r,s,t,u)
        if(round(function(p,q,r,s,t,u,ans),4) == 0): print("%.4f" % (ans))
        else: print("No solution")


        constants = stdin.readline()

main()
