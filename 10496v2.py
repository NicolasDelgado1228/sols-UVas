from sys import stdin

def solve(beepers, i, visited, dist, left, ini, memo):
    if(left == 0):
        return dist + abs(beepers[i][0]-ini[0]) + abs(beepers[i][1]-ini[1]) 
    else:
        leftDist, actual = 100000000000, beepers[i]
        for j in range(len(beepers)):
            if(not (visited & (1<<len(beepers)-j-1))):
                beeper = beepers[j]
                leftDist = min(leftDist, solve(beepers, j, visited ^ (1<<len(beepers)-j-1), dist+abs(beeper[0]-actual[0])+abs(beeper[1]-actual[1]), left-1, ini, memo))
        return leftDist

def main():
    cases = int(stdin.readline())
    for case in range(cases):
        n, m = list(map(int, stdin.readline().split()))

        ini = tuple(map(int, stdin.readline().split()))
        beepersCnt, beepers = int(stdin.readline()), [ini]
        for b in range(beepersCnt): beepers.append(tuple(map(int, stdin.readline().split())))
        visited = 1 << (len(beepers)-1)

        memo = [[-1 for _ in range(2**len(beepers))] for _ in range(len(beepers))]

        print("The shortest path has length " + str(solve(beepers, 0, visited, 0, beepersCnt, ini, memo)))
main()