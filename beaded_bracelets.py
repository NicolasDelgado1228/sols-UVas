from sys import setrecursionlimit
from sys import stdin
from math import log2, floor, ceil, pi
import cmath
setrecursionlimit(1000000)

def fft_(A, inverse):
    n = len(A)
    if n!= 1:
        A0, A1 = [A[i] for i in range(0,n,2)], [A[i] for i in range(1,n,2)]
        fft_(A0, inverse); fft_(A1, inverse) #Get A0 and A1 in the sample form (point-value)
        theta = 2*pi/n*(-1 if inverse else 1)
        w, wn = complex(1), complex(cmath.cos(theta), cmath.sin(theta))
        #Combine all the values with the form A(x) = A0(x^2)+xA1(x^2)
        for i in range(n//2):
            A[i] = A0[i] + w*A1[i]
            A[i+(n//2)] = A0[i] - w*A1[i] #The "-" here is bec of wn^(k+(n//2))=-wn^k
            if inverse:
                A[i]/=2
                A[i+(n//2)]/=2
            w = w*wn

def poly_mult(A, B):
    n = max(len(A), len(B))
    for i in range(n-len(A)): A.append(0)
    for i in range(n-len(B)): B.append(0)
    for i in range(n): A.append(0); B.append(0)
    
    fft(A, False); fft(B, False)
    C = list()
    for i in range(len(A)): C.append(A[i]*B[i])
    fft(C, True)
    return [round(C[i].real) for i in range(len(C))]

def fft(A, inverse):
    l = log2(len(A))
    if ceil(l)!=floor(l):
        for i in range((2**(floor(l)+1))-len(A)): A.append(0)
    fft_(A, inverse)
    
r = stdin.readline

def convolution(A, B):
    n = max(len(A), len(B))
    for i in range(n-len(A)): A.append(0)
    for i in range(n-len(B)): B.append(0)
    B.reverse()
    return poly_mult(A, B)

def solve(s, t, n):
    """
    The solution consist of a convolution between the binarys a and b. We have to count
    the number of zeros in the range [n, 2n)
    """
    A, B = list(), list()
    for i in range(n): t += t[i]
    for i in range(len(s)):
        if s[i] == "R": A.append(1)
        else: A.append(0)
    for i in range(len(t)):
        if t[i] == "R": B.append(1)
        else: B.append(0)
    conv, ans = convolution(A, B), 0

    for i in range(n, 2*n):
        if conv[i] == 0: ans+=1
    return ans

def main():
    line = r()
    while line != "":
        n = int(line)
        s = r().strip()
        t = r().strip()
        print(solve(s, t, n))

        line = r()
main()