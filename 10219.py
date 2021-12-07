import math


def summation(i, n):
    sum = 0
    for i in range(i, n+1):
        sum += math.log10(i)
    return sum

while(True):
    try:
        n, k = map(int, input().split())
        sum = 0
        for i in range(n-k+1, n+1):
            sum += math.log10(i)
        for i in range(1, k+1):
            sum -= math.log10(i)

        print(math.floor(sum)+1)


    except EOFError:
        break
