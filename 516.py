def sieve():
    primes = []
    bitset = [True for x in range(33005)]
    i = 1
    while(i <= 33000):
        i+=1
        if(not bitset[i]): continue
        j = i*i
        while(j <= 33000):
            bitset[j] = False
            j += i
        primes.append(i)

    return primes



def primePowers(n, primes):
    pPows = list()
    exponents = dict()
    i = 0
    e = 0
    first = True
    while(n != 1 and primes[i]**2 <= n):
        if(n%primes[i] == 0):
            if(first):
                pPows.append(primes[i])
                exponents[primes[i]] = 1
                first = False
            else:
                exponents[primes[i]] += 1
            n /= primes[i]
        else:
            first = True
            i += 1

    if(n != 1 and len(pPows) > 0 and n == pPows[len(pPows)-1]):
        exponents[pPows[len(pPows)-1]] += 1
    elif(n != 1):
        pPows.append(int(n))
        exponents[int(n)] = 1

    res = list()
    pPows.sort(reverse = True)
    for i in pPows:
        res.append(i)
        res.append(exponents[i])

    return res



def getNum(code):
    num = 1
    i = 0
    while(i < len(code)-1):
        num *= (code[i]**code[i+1])
        i += 2
    return num



def main():
    primes = sieve()
    while(1):
        nums = input()
        if(nums == "0"): break

        nums = list(map(int, nums.split()))
        res = primePowers(getNum(nums)-1, primes)

        print(res[0],res[1], end= '', flush = True)
        i = 2
        while(i < len(res)-1):
            print(" " + str(res[i]) + " " + str(res[i+1]), end= '', flush = True)
            i += 2

        print("")




main()
