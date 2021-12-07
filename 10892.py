import math


def getDivisors(n):
    divs = list()
    for i in range(1, int(math.pow(n, 0.5)) + 1):
        if(n%i == 0): divs.append(int(i))
        if(n%i == 0 and n/i != i): divs.append(int(n/i))
    return divs

def mcd(a, b):
    if(min(a, b) == 0): return max(a, b)
    else: return mcd(max(a, b)%min(a, b), min(a, b))

def main():

    while(1):
        n = int(input())
        if(n == 0): break

        divisors = getDivisors(n)


        card = 1
        for i in range(len(divisors)):
            for j in range(len(divisors)):
                if(i != j and ((divisors[i]*divisors[j])/mcd(divisors[i], divisors[j])) == n): card += 1

        card = math.ceil(card/2)
        print(n, card)


main()
