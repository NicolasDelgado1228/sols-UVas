def main():
    nums = [1, 5, 10, 25, 50]
    tab = [[0 for x in range(30001)] for i in range(6)]

    for n in range(6):
        for target in range(30001):
            if(target == 0):
                tab[n][target] = 1
            elif(n == 0):
                tab[n][target] = 0
            else:
                tab[n][target] = tab[n-1][target]
                if(target - nums[n-1] >= 0):
                    tab[n][target] += tab[n][target - nums[n-1]]

    while(True):
        try:
            num = int(input())

            
            
            ans = tab[5][num]
            if(ans == 1):
                print("There is only 1 way to produce " + str(num) + " cents change.")
            else:
                print("There are " + str(ans) + " ways to produce " + str(num) + " cents change.")


        except EOFError:
            break

main()