from sys import stdin
from collections import deque
import sys
sys.setrecursionlimit(1000000000)


def getNum(input):
    i, ans = 0, ""
    if input[0]=="-":
        input.popleft()
        while 48 <= ord(input[0]) <= 59: ans += input.popleft()
        ans = int(ans)
        ans*=-1
    else:
        while 48 <= ord(input[0]) <= 59: ans += input.popleft()
        ans = int(ans)
    return ans


def parse(input):
    T = []
    if input[0]=='(' and input[1]==')': input.popleft(); input.popleft()
    else:
        input.popleft()
        num = int(getNum(input))
        T = [num, parse(input), parse(input)]
        input.popleft()
    return T

def solve(T, ac, x):
    global parenCnt
    ans = False
    if T != []:
        if (T[1] == [] and T[2] == []) and ac+T[0] == x: ans = True
        elif not (T[1] == [] and T[2] == []): ans = solve(T[1], ac+T[0], x) or solve(T[2], ac+T[0], x)
    return ans


def main():
    global parenCnt
    inputTemp = stdin.buffer.read()
    input = deque([chr(x) for x in inputTemp if chr(x)!= '\n' and chr(x)!=' '])
    while len(input) > 0:
        x = getNum(input)
        if solve(parse(input), 0, x): print("yes")
        else: print("no")
main()
