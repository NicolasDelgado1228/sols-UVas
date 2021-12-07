from sys import stdin
import math

numsFun, acumFun, acum, i, num = [-1], list(), 0, 0, 1

while(acum <= 2147483647):
    i += math.floor(math.log10(num))+1
    numsFun.append(i)
    num += 1
    acum+=i
    acumFun.append(acum)


def binsearch(fun, x, lo, hi):
    ans = -1
    if(lo < hi):
        while(lo+1 < hi):
            mid = (lo+hi)>>1
            if(fun[mid] <= x):
                lo = mid
            else:
                hi = mid
        ans = lo
    return ans



def main():
    cases = int(stdin.readline())
    for case in range(cases):
        i = int(stdin.readline())
        group = binsearch(acumFun, i, 0, len(acumFun))
        if(acumFun[group] == 1): print(1)
        else:
            if(i==acumFun[group]):group-=1

            i = i-acumFun[group]
            num = binsearch(numsFun, i, 0, len(numsFun))
            if(numsFun[num] != i): num+=1

            i = numsFun[num]-i
            num = str(num)[::-1]
            print(num[i])
main()