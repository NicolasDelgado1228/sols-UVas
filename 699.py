from sys import stdin
import sys
sys.setrecursionlimit(10000000)

def parse(input):
    T = []
    if input[-1] != -1: T = [input.pop(), parse(input), parse(input)]
    else: input.pop()
    return T

def solve(T, leafs, pos):
    if T != []:
        if pos not in leafs: leafs[pos] = T[0]
        else: leafs[pos] += T[0]

        solve(T[1], leafs, pos-1)
        solve(T[2], leafs, pos+1)

def main():
    inputStr, input, case = stdin.readlines(), [], 1
    for inp in inputStr: input += list(map(int, inp.strip().split()))
    input.reverse()
    while len(input) > 1:
        T = parse(input)
        leafs = dict()
        solve(T, leafs, 0)
        ans = [(x, leafs[x]) for x in leafs]
        ans.sort()
        print("Case " + str(case) + ":"); case+=1
        ansStr = ""
        for pos, a in ans: ansStr += (str(a)+" ")
        print(ansStr[:-1])
        print("")
main()
