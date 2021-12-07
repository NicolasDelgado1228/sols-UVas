from sys import stdin

def main():
    string = stdin.readline()[:-1]
    oc = dict()
    for char in string:
        if(oc.get(char) == None): oc[char] = 1
        else: oc[char] += 1
    
    
    even = True
    for char in oc:
        if oc[char]%2!=0: even = False

    odd = True
    for char in oc:
        if oc[char]%2==0: odd = False
    
    if(even): print(0)
    elif(odd): print(1)
    else: print(2)
main()