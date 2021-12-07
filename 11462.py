from sys import stdin

def main():
    n = int(stdin.readline())
    while n != 0:
        n = int(n)
        nums = list(map(int, stdin.readline().split()))
        numsCnt = [0 for _ in range(101)]
        for num in nums: numsCnt[num] += 1


        ans = list()
        for i in range(len(numsCnt)):
            if numsCnt[i]>0:
                while numsCnt[i]:
                    ans.append(i)
                    numsCnt[i]-=1
        ansStr = ""
        for a in ans: ansStr += (str(a) + " ")
        print(ansStr[:-1])
        n = int(stdin.readline())

main()
