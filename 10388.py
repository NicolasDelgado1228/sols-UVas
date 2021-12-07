def letterFrequency(word):
    visited = [False for i in range(len(word))]
    freq = {word[i]:1 for i in range(len(word))}
    i = 0
    while(i < len(word)):
        j = 0
        while(j < len(word)):
            if(not visited[i] and i != j and word[i] == word[j]): 
                freq[word[j]] += 1
                visited[j] = True
            j += 1
        i += 1
    return freq

def productFacts(freq, facts):
    product = 1
    for i in freq:
        product*=facts[freq[i]]
    return product


def main():
    facts = [1]
    last = 1
    for i in range(1, 21):
        facts.append(last*i)
        last = last*i

    cases = int(input())
    for i in range(1, cases+1):
        word = input()
        print("Data set %d: %d" %(i, facts[len(word)]//productFacts(letterFrequency(word), facts)))

main()
