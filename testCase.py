import random

def intToBin(x):
    ans = []
    while x!=0:
        ans.append(x%2)
        x = x//2
    while len(ans) < 8: ans.append(0)
    ans.reverse()
    return ans

def toStr(ar):
    ans = ""
    for x in ar: ans += str(x)
    return ans

def main():
    for i in range(256):
        print(toStr(intToBin(i)), toStr(intToBin(random.randint(0,100))))

main()
