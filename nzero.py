from sys import stdin
r = stdin.readline
def main():
    cases = int(r())
    for case in range(cases):
        t = r().strip()
        n = len(t)
        ans = 0
        lo, hi = 0, n-1
        found = False
        for i in range(len(t)):
            if t[i] == "1": lo = i; found = True; break
        for i in range(len(t)-1,-1,-1):
            if t[i] == "1": hi = i; break
        onescnt = 0
        for x in t:
            if x == "1": onescnt+=1
        if not found or onescnt==1: print(0)
        else:
            i = lo
            while i<=hi:
                if t[i]=="0":
                    j, ac = i, 0
                    while j <=hi and t[j]=="0": ac+=1;j+=1
                    ans += ac
                    i = j
                i+=1

            print(ans)


main()