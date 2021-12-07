from sys import stdin

def getCost(consumption):
    ans = 0
    if consumption >= 100:
        ans += (2*100)
        if consumption >= 10000:
            ans += (3*9900)
            if consumption >= 1000000:
                ans += (5*990000)
                if consumption > 1000000: ans += ((consumption-1000000)*7)
            else: ans += (consumption-10000)*5
        else: ans += ((consumption-100)*3)
    else: ans += ((consumption-0)*2)
    return ans


def guessCons(cost):
    lo, hi = 0, cost
    while lo+1 < hi:
        mid = (lo+hi)//2
        if getCost(mid) <= cost: lo = mid
        else: hi = mid
    return lo

def guessAns(ans, cons, dif):
    lo, hi = 0, ans
    while lo+1 < hi:
        mid = (lo+hi)//2
        neighborCons = cons-mid 
        if abs(getCost(neighborCons)-getCost(mid)) >= dif: lo = mid
        else: hi = mid
    return lo


def main():
    A, B = list(map(int, stdin.readline().split()))
    while A != 0 and B != 0:
        maxCons = guessCons(A)
        ans = (maxCons//2)+1
        print(getCost(guessAns(ans, maxCons, B)))

        A, B = list(map(int, stdin.readline().split()))

main()