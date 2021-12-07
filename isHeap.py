from sys import stdin
from heapq import heappush, heappop, heapify


def leftSon(i): return (2*i)+1
def rightSon(i): return (2*i)+2


def isHeap(heap, i):
    n, ans = len(heap), None
    if leftSon(i)>=n and rightSon(i)>=n: ans = True
    else:
        ans = heap[i]<heap[leftSon(i)] and heap[i]<heap[rightSon(i)]
        ans = ans and isHeap(leftSon(i)) and isHeap(rightSon(i))
    return ans


def main():
    from random import Random
    R = Random(2019)
    N = 100000
    for test_case in range(8):
        A = [R.randrange(1000) for i in range(N)]
        heapify(A)
        i = R.randrange(N)
        j = R.randrange(N)
        if R.randrange(2)==1: A[i], A[j] = A[j], A[i]
        print(isHeap(A, 0))

main()
