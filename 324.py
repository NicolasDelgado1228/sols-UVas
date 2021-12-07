def main():
    facts = [1]
    last = 1
    for i in range(1, 368):
        facts.append(i*last)
        last = i*last

    while(True):
        freq = [0, 0 ,0 ,0 ,0, 0, 0, 0, 0, 0]
        n = int(input())
        if(n == 0): break

        fact = facts[n]
        while(fact):
            freq[fact%10] += 1
            fact //= 10

        print(str(n) + "! --")
        print("(0)%4d   (1)%4d   (2)%4d   (3)%4d   (4)%4d" % (freq[0], freq[1], freq[2], freq[3], freq[4]))
        print("(5)%4d   (6)%4d   (7)%4d   (8)%4d   (9)%4d" % (freq[5], freq[6], freq[7], freq[8], freq[9]))
main()
