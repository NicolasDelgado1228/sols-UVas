class dforest(object):
  def __init__(self, size=100):
    """create an empty disjoint forest"""
    self.__parent = [ i for i in range(size) ]
    self.__rank = [ 0 for _ in range(size) ]

  def __str__(self):
    return str(self.__parent)
  
  def find(self, x):
    if self.__parent[x]!=x: self.__parent[x] = self.find(self.__parent[x])
    return self.__parent[x]

  def union(self, x, y):
    rx,ry = self.find(x),self.find(y)
    if rx!=ry:
      krx,kry = self.__rank[rx],self.__rank[ry]
      if krx>=kry:
        self.__parent[ry] = rx
        if krx==kry: self.__rank[rx] += 1
      else:
        self.__parent[rx] = ry



def main():
    cases = int(input())
    first = True
    input()

    for case in range(cases):
        if(not first):
            print("")
        n = int(input())
        forest = dforest(n)

        correct = 0
        wrong = 0

        while(1):
            try:
                line = input().split()
                if(len(line) == 0):
                    break
                option = line[0]
                line = [line[0], int(line[1])-1, int(line[2])-1]
                if(option == "c"):
                    forest.union(int(line[1]), int(line[2]))
                else:
                    if(forest.find(int(line[1])) == forest.find(int(line[2]))):
                        correct += 1
                    else:
                        wrong += 1
            except EOFError:
                break
        
        first = False
        
        print(str(correct) + "," + str(wrong))


main()