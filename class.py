def bin_lower(A, x):
    lo, hi = 0, len(A)
    while lo+1 < hi:
        mid = (lo+hi)>>1
        if A[mid] <= x: lo = mid
        else: hi = mid
    return A[lo] == x

def bin_upper(A, x):
    lo, hi = -1, len(A)-1
    while lo+1 != hi:
        mid = (lo+hi)>>1
        if A[mid] >= x: hi = mid
        else: lo = mid
    return hi