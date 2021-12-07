from sys import stdin
from random import random
from math import log2

def left(i): return (2*i)+1
def right(i): return (2*i)+2
def parent(i): return (i-1)//2

def build(array, i):
    n = len(array)
    if not (left(i) >= n and right(i) >= n):
        build(array, left(i))
        build(array, right(i))
        array[i] = min(array[left(i)], array[right(i)])


class SegmentTree(list):
    def __init__(self, array):
        self.n = len(array); N = 1; self.k = 0
        while N < self.n: N*=2; self.k+=1
        st = [None]*(2*N-1)
        st[N-1:] = array
        self[:] = st
        print(self)
        build(self, 0)

    def update(self, i, x):
        i = (2**self.k)-1+i
        self[i] = x;

        while i != 0:
            par = parent(i)
            sis = right(par) if i%2!=0 else left(par)
            self[par] = min(self[i], self[sis])
            i = par
        print(self)

    def getAux(self, i, j, lo, hi):
        mid, ans = (lo+hi)>>1, None

        if
        elif j < mid: ans = self.getAux(i, j, lo, mid)
        elif i >= mid: ans = self.getAux(i, j, mid, hi)
        else: ans = min(self.getAux(i, mid, lo, hi), self.getAux(mid, j, lo, hi))
        return ans


    def get(self, i, j):
        return self.getAux(i, j, 0, self.n)



def main():
    st = SegmentTree([-1,0, 5, -2])
    print(st)
    print(st.get(1, 2))

    """
    R = Random(2019) ; X_MAX = 10**3 ; n = 2**16
    A = [R.randrange(-X_MAX,X_MAX) for i in range(n)]
    Q = []
    for _ in range(10**4):
        if R.randrange(2)== 0:
            i = R.randrange(n)
            j = R.randrange(i+1, n+1)
            Q.append(('get', i, j))
        else:
            i = R.randrange(n)
            x = R.randrange(-X_MAX, X_MAX)
            Q.append(('update', i, x))
    ans = []
    st = SegmentTree(A)
    for inst, i, j in Q:
        if inst == 'update': st.update(i, j)
        if inst=='get': ans.append(st.get(i,j))
    """

main()
