from sys import stdin

inversions = 0
aux = [None for _ in range(500000)]

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
    n = int(stdin.readline().strip())
    while n!=0:
        num = [ int(stdin.readline()) for _ in range(n) ]
        inversionsCnt = 0
        mergeSort(num, 0, n)
        print(inversionsCnt)
        n = int(stdin.readline().strip())

main()