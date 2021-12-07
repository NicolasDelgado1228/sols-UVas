from sys import stdin

def binsearch(fun, lo, hi, x):
    ans = 0
    if(lo < hi):
        while(lo+1 < hi):
            mid = (lo+hi)//2
            if(fun[mid] <= x):
                lo = mid
            else:
                hi = mid
        if(lo+1 < len(fun) and fun[lo] < x): ans = fun[lo+1]
        else: ans = fun[lo]
    return ans



def main():
    sequence = stdin.readline()
    functions = dict()
    
    for i in range(len(sequence)):
        char = sequence[i]
        if(functions.get(char) == None): functions[char] = [i]
        else: functions[char].append(i)
    

    cases = int(stdin.readline())
    for case in range(cases):
        sub = stdin.readline()

        i, idx, match, firstMatch, first, last = 0, 0, True, True, -1, -1
        while(i < len(sub)-1 and match):
            char = sub[i]
            fun = functions.get(char)
            if(fun == None): match = False
            else:
                num = binsearch(fun, 0, len(fun), idx)

                

                if(num < idx): match = False
                else:
                    if(firstMatch):
                        first = num
                        firstMatch = False
                    last = num
                    idx = num+1

            i += 1

        if(match): print("Matched " + str(first) + " " + str(last))
        else: print("Not matched")

main()