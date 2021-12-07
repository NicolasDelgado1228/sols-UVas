
def gcd(a, b):
    if(min(a,b) == 0): return max(a,b)
    else: return gcd(max(a,b)%min(a,b), min(a,b))


def main():
    cases = int(input())

    while(cases):
        nums = list(map(int, input().split()))
        max = -1

        for i in range(len(nums)):
            for j in range(len(nums)):
                if(i != j):
                    newVal = gcd(nums[i], nums[j])
                    if(newVal > max): max = newVal
        print(max)




        cases -= 1


main()
