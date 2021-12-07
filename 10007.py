def fact(n):
    res = 1

    for i in range (1, n+1):
        res *= i
    return res

def catalan(n):
    return fact(n)*(fact(2*n)//(fact(n+1)*fact(n)))


def main():

    while(True):
        n = int(input())
        if(n == 0):
            break

        ans = catalan(n)
        print(int(res))

main()
