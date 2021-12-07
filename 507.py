from sys import stdin



def main():
    global memo

    cases = int(input())
    case = 1
    while(cases != 0):
        routesCnt = int(input())-1
        ans = (0, 0, 0)
        ac = 0
        i = 0

        j = 0
        while(routesCnt != 0):
            route = int(stdin.readline().split()[0])
            if(route + ac < 0):
                ac = 0
                i = j+1
            else:
                ac += route
                if(ac > ans[0] or (ac == ans[0] and j-i > ans[2]-ans[1])):
                    ans = (ac, i, j)
            j += 1
        
            routesCnt -= 1

        if(ans[0] != 0):
            print("The nicest part of route " + str(case) + " is between stops " + str(ans[1]+1) + " and " + str(ans[2]+2))
        else:
            print("Route " + str(case) + " has no nice parts")
        case += 1
        cases -= 1



main()