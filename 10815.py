from sys import stdin
r = stdin.readline

def main():
    temp = stdin.readlines()
    lines = list()
    for x in temp:
        if x!= "\n": 
            lines.append(x[:-1])
    
    for line in lines:
        line.split()
        print(line)


main()