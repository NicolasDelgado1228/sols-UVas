def fact(n):
    res = 1
    i = 1
    while(i <= n):
        res *= i
        i += 1
    return res


def main():
    while(True):
        try:
            n = int(input())
            print(str(n)+"!")
            print(fact(n))
        except EOFError:
            break

main()
