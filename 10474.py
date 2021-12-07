from sys import stdin

r = stdin.readline

aux = [None for _ in range(100000)]

def merge(nums, lo, hi):
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
            nums[k] = aux[j]
            j+=1
        else:
            nums[k] = aux[i]
            i+=1
        k += 1

def mergeSort(nums, lo, hi):
    if(hi-lo > 1):
        mid = (hi+lo)//2

        mergeSort(nums, lo, mid)
        mergeSort(nums, mid, hi)
        merge(nums, lo, hi)


def binsearch(arr, x, lo, hi):
    while lo+1 != hi:
        mid = (lo+hi)>>1
        if arr[mid] >= x: hi = mid
        else: lo = mid
    return arr[hi] == x, hi


def main():
    N, Q = map(int, r().strip().split())
    case = 1
    while N+Q > 0:
        arr = []
        for i in range(N): arr.append(int(r()))
        mergeSort(arr, 0, N)
        print("CASE#", str(case) + str(":"))
        for query in range(1, Q+1):
            x = int(r())
            found, idx = binsearch(arr, x, -1, len(arr)-1)
            if found:
                print(str(x)+" found at "+str(idx+1))
            else:
                print(str(x)+" not found")

        N, Q = map(int, r().strip().split())
        case+=1


        

main()