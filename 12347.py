from sys import stdin

def build(preorder, left, right):
    T = []
    if len(preorder)>0:
        T = [preorder.pop(), [], []]
        if(len(preorder)>0 and preorder[-1]<T[0] and (right == None or preorder[-1]>right)): T[1] = build(preorder, T[0], right)
        if(len(preorder)>0 and (left==None or left>preorder[-1]>T[0])):
            T[2] = build(preorder, left, T[0])
    return T

def getPosorder(T):
    pos = []
    if T != []: pos = getPosorder(T[1]) + getPosorder(T[2]) + [T[0]]
    return pos


def main():
    preorder, postorder = list(), list()
    n = stdin.readline()
    while(n!=""):
        preorder.append(int(n))
        n = stdin.readline()
    preorder.reverse()
    T = build(preorder, None, None)
    for u in getPosorder(T): print(u)



main()
