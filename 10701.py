from sys import stdin

def build(pre, ino, pos, left, right):
    T = []
    if len(pre) > 0:
        T = [pre.pop(), [], []]
        if len(pre) > 0 and pos[T[0]] > pos[pre[-1]] and (left==None or pos[left]<pos[pre[-1]]):
            T[1] = build(pre, ino, pos, left, T[0])
        if len(pre) > 0 and pos[T[0]] < pos[pre[-1]] and (right==None or pos[right]>pos[pre[-1]]):
            T[2] = build(pre, ino, pos, T[0], right)
    return T

def getPosorder(T, ans):
    if T != []:
        getPosorder(T[1], ans)
        getPosorder(T[2], ans)
        ans.append(T[0])
    return ans

def main():
    cases = int(stdin.readline())
    for case in range(cases):
        n, preorder, inorder = stdin.readline().strip().split()
        pos = dict()
        for i in range(len(inorder)): pos[inorder[i]] = i
        preorder = [x for x in preorder]
        preorder.reverse()
        T = build(preorder, [x for x in inorder], pos, None, None)
        ansOrder = getPosorder(T, [])
        ans = ""
        for c in ansOrder: ans+=c
        print(ans)
main()
