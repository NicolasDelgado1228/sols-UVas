from sys import stdin
import math


class dforest(object):
  """implements an union-find with path-compression and ranking"""

  def __init__(self, size=10):
    self.__parent = [ i for i in range(size) ]
    self.__rank = [ 1 for _ in range(size) ]
    self.__csize = [ 1 for _ in range(size) ]
    self.__ccount = self.__size = size
    self.n = size

  def __str__(self):
    """return the string representation of the forest"""
    return str(self.__parent)

  def __len__(self):
    """return the number of elements in the forest"""
    return self.__size

  def csize(self, x):
    """return the number of elements in the component of x"""
    return self.__csize[self.find(x)]

  def ccount(self):
    """return  the numnber of components"""
    return self.__ccount

  def find(self, x):
    """return the representative of the component of x"""
    if self.__parent[x]!=x:
      self.__parent[x] = self.find(self.__parent[x])
    return self.__parent[x]

  def union(self, x, y):
    """computes the union of the components of x and y, if they are different"""
    fx,fy = self.find(x),self.find(y)
    if fx!=fy:
      rx,ry = self.__rank[fx],self.__rank[fy]
      if rx>ry:
        self.__parent[fy] = fx
        self.__csize[fx] += self.__csize[fy]
      else:
        self.__parent[fx] = fy
        self.__csize[fy] += self.__csize[fx]
        if rx==ry:
          self.__rank[fy] += 1
      self.__ccount -= 1
      self.n -= 1


def dist(c1, c2):
    x1, y1 = c1; x2, y2 = c2
    return math.sqrt(((x2-x1)**2)+((y2-y1)**2))


def kruskal(G, forest, dotsDic):
    G.sort()

    mst = 0
    for distance, u, v in G:
        u = dotsDic[u]; v = dotsDic[v]
        if forest.find(u) != forest.find(v):
            mst += distance
            forest.union(u,v)
    return mst


def main():
    cases = int(stdin.readline())
    for case in range(1, cases+1):
        n, r = map(int, stdin.readline().strip().split())
        states = dforest(n)
        dots, dotsDic = list(), dict()
        for i in range(n):
            inp = tuple(map(int, stdin.readline().strip().split()))
            dots.append(inp)
        edges = list()
        for i in range(len(dots)):
            if dots[i] not in dotsDic:
                dotsDic[dots[i]] = i

        roadEdges, railroadsEdges = list(), list()
        i = 0
        while i < len(dots):
            j = i+1
            while j < len(dots):
                c1, c2 = dots[i], dots[j]
                distance = dist(c1, c2)
                if distance <= r:
                    states.union(dotsDic[c1], dotsDic[c2])
                    roadEdges.append((distance, c1, c2))
                else: railroadsEdges.append((distance, c1, c2))
                j += 1
            i += 1

        forest = dforest(n)

        print("Case #" + str(case) + ":", states.n, round(kruskal(roadEdges, forest, dotsDic)), round(kruskal(railroadsEdges, forest, dotsDic)))


main()
