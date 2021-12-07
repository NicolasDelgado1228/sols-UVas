from sys import stdin
r = stdin.readline

def C_precal(N,K):
    tab = [[-1 for _ in range(K+1)] for _ in range(N+1)]
    for n in range(N+1):
        for k in range(K+1):
            if k == 0 or n == k or n < k: tab[n][k] = 1
            else: tab[n][k] = tab[n-1][k-1]+tab[n-1][k]
    return tab

C = C_precal(50,50)

def solve(a, b, n):
    global C
    ans = [a+("^"+str(n) if n!=1 else "")]
    for i in range(n-1,0,-1):
        ans.append(str(C[n][n-i])+"*"+a+("^"+str(i)if i!=1 else "")+"*"+b+("^"+str(n-i)if (n-i)!=1 else ""))
    ans.append(b+("^"+str(n) if n!=1 else ""))
    ans_str=""
    for x in ans: ans_str+=(x+"+")
    ans_str = ans_str[:-1]
    return ans_str


def main():
    cases = int(r())
    for case in range(1, cases+1):
        sentence = r().strip()
        aux = sentence.split("^")
        n = int(aux[-1])
        sentence = aux[0]
        sentence = sentence[:-1]
        sentence = sentence[::-1]
        sentence = sentence[:-1]
        sentence = sentence[::-1]
        sentence = sentence.split("+")
        print("Case",str(case)+":",solve(sentence[0], sentence[1], n))

main()