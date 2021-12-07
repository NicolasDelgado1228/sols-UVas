def combs():
    solutions = [1, 3]
    for i in range(2000):
        n1 = solutions[len(solutions)-1]
        n2 = solutions[len(solutions)-2]
        solutions.append(n1+n2+(2*(n1-n2)))
    return solutions




def main():
    solutions = combs()
    while(1):
        n = int(input())
        if(n == 0): break

        print(solutions[n-1])

main()
