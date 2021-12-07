from sys import stdin


def isPrefix(a, b):
    i, ans = 0, True
    while i < len(a) and ans:
        if a[i] != b[i]: ans = False
        i += 1
    return ans


def match(p, sa):
    t = sa.t
    lo, hi, n = -1, len(t)-1, len(t)
    while lo+1 < hi:
        mid = (lo+hi)>>1
        suffix = t[sa[mid]:]
        if suffix >= p: hi = mid
        else: lo = mid
    return (isPrefix(p, t[sa[hi]:]), hi)


class SuffixArray(list):
    def __init__(self, t):
        self.t = t
        self.n = len(t)
        sa = self.build()
        self[:] = sa
        return

    def assignRank(self, array, idx):
        temp = [list(x) for x in array]
        array[0][0] = 0
        for i in range(1, self.n):
            if temp[i][0] == temp[i-1][0] and temp[i][1] == temp[i-1][1]: array[i][0] = array[i-1][0]
            else: array[i][0] = array[i-1][0]+1
        rank = [0 for x in range(self.n)]
        for trip in array: rank[trip[2]] = trip[:2]
        for i in range(self.n):
            if array[i][2]+idx < self.n: array[i][1] = rank[array[i][2]+idx][0]
            else: array[i][1] = -1

    def build(self):
        array = []
        for i in range(self.n-1): array.append([ord(self.t[i]), ord(self.t[i+1]), i])
        array.append([ord(self.t[self.n-1]), -1, self.n-1])
        array.sort()

        i = 2
        while i < self.n:
            self.assignRank(array, i)
            array.sort()
            i = i<<1
        return [idx for r1, r2, idx in array]

    def print_it(self):
        for i in self:
            print(i, self.t[i:])
        return


def main():
	pass

main()