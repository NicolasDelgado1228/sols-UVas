from sys import stdin

class SegmentTree:
    def __init__(self, arr):
        self.nar = len(arr)
        self.nt = self.nar*4
        self, i = [None for _ in range(self.nt)], 0
        for idx in range(self.nt-self.nar, self.nt): self[idx] = arr[i]; i+=1
        print(self)    






def main():
    st = SegmentTree([3,1,7,2,4,2,1])

main()