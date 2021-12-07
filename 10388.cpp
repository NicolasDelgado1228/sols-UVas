def repetidos(word):
    repetidos = 0
    i = 0
    while(i < len(word)):
        j = 0
        while(j < len(word)):
            if(i != j and word[i] == word[j]): repetidos += 1
            j += 1
        i += 1

    return repetidos

def main():
    facts = [1]
    last = 1
    for i in range(1, 21):
        facts.append(last*i)
        last = last*i

    cases = int(input())
    for i in range(1, cases+1):
        word = input()
        print("Data set %d: %d" % (i, facts[len(word)]facts[repetidos(word)]))

main()
