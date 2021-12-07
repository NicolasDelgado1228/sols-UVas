MAX = 100000
AUX = [ None for _ in range(MAX) ] 

def mergesort(A):
    size = 1
    while size <= len(A):
        lo = 0
        while lo < len(A):
            mid = min(len(A), lo+size)
            hi = min(mid+size, len(A))
            merge(A, lo, mid, hi)
            lo = hi
        size*=2


def merge(A, low, mid, hi):
    for i in range(low, hi): AUX[i] = A[i]
    l,r,i = low,mid,low
    while i!=hi:
        if r==hi:
            A[i] = AUX[l]
            i,l = i+1,l+1
        elif l==mid:
            A[i] = AUX[r]
            i,r = i+1,r+1
        else:
            if AUX[l]<=AUX[r]:
                A[i] = AUX[l]
                i,l = i+1,l+1
            else:
                A[i] = AUX[r]
                i,r = i+1,r+1

a = [5,4,3,2,1]
 
"""
def mergesort(A, low, hi):
  if low+1<hi:
    mid = low+((hi-low)>>1)
    mergesort(A, low, mid)
    mergesort(A, mid, hi)
    merge(A, low, mid, hi)
"""
