from sys import stdin
from math import log

class RMQ:
    def __init__(self, arr):
        n, k = len(arr), int(log(len(arr))/log(2))+1
        self.sparse = [[0 for _ in range(k)] for _ in range(n)]
        for i in range(n): self.sparse[i][0] = arr[i]

        j = 1
        while 1<<j <= n:
            i = 0
            while (i + (1 << j) - 1) < n:
                if self.sparse[i][j-1] < self.sparse[i+(1<<(j-1))][j-1]:
                    self.sparse[i][j] = self.sparse[i][j-1]
                else:
                    self.sparse[i][j] = self.sparse[i+(1<<(j-1))][j-1]
                i += 1
            j+=1

    def query(self, L, R):
        j = int(log(R-L+1)/log(2))
        if self.sparse[L][j] <= self.sparse[R-(1<<j) + 1][j]: return self.sparse[L][j]
        else: return self.sparse[R - (1 << j) + 1][j];


def main():
    pass

main()
