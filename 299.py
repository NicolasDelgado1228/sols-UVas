from sys import stdin

inversions = 0
aux = [None for _ in range(25000)]

def merge(nums, lo, hi):
    global inversionsCnt
    for x in range(lo, hi): aux[x] = nums[x]
    mid = (hi+lo)//2
    i, j, k = lo, mid, lo

    while(k < hi):
        if(i == mid):
            nums[k] = aux[j]
            j+=1
        elif(j == hi):
            nums[k] = aux[i]
            i+=1
        elif(aux[i] > aux[j]):
            inversionsCnt += mid-i
            nums[k] = aux[j]
            j+=1
        else:
            nums[k] = aux[i]
            i+=1
        k += 1

def mergeSort(nums, lo, hi):
    global inversionsCnt
    if(hi-lo > 1):
        mid = (hi+lo)//2
        mergeSort(nums, lo, mid)
        mergeSort(nums, mid, hi)
        merge(nums, lo, hi)



def main():
    global inversionsCnt
    cases = int(stdin.readline())

    for case in range(cases):
        n = int(stdin.readline())
        nums = list(map(int, stdin.readline().split()))

        inversionsCnt = 0
        mergeSort(nums, 0, len(nums))
        print("Optimal train swapping takes " + str(inversionsCnt) + " swaps.")
        


main()