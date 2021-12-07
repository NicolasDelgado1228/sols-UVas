from sys import stdin


def getPosTeams(grades):
    N = len(grades):
    



def main():
    N, D = list(map(int, stdin.readline().split()))
    while N!=0 and D != 0:
        grades = list(map(int, stdin.readline().split()))
        groupsCnt = N//3

        states = getStates(N)
        for state in states: print(bin(state))

        #print(solve(grades, states, memo, 0, N))

        N, D = list(map(int, stdin.readline().split()))
main()