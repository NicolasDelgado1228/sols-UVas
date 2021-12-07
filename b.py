from sys import stdin

r = stdin.readline

def is_pali(x):
    n, ans = len(x), True
    for i in range(n//2): 
        if x[i]!=x[n-i-1]: ans = False; break
    return ans


def solve(A):
    i, j, mid = 0, 1, ""
    seq, words = [], 0
    for x in A:
        rev = x[::-1]
        pali = is_pali(x)
        if not pali and rev in A and rev not in seq:
            words+=1
            seq.append(x)
        elif pali: mid = x
    n = 2*words
    if mid!="": n+=1
    ans = ["" for _ in range(n)]
    for i in range(len(seq)):
        ans[i] = seq[i]
        ans[n-i-1] = seq[i][::-1]
    for i in range(n):
        if ans[i]=="": ans[i] = mid
    ans2 = ""
    for x in ans: ans2+=x
    return ans2

    

def main():
    n, sz = map(int, r().strip().split())
    A = set()
    for i in range(n): A.add(r().strip())
    
    ans = solve(A)
    print(len(ans))
    print(ans)
    
main()