
moves = 0


def solve(line, balls):
    global moves
    if(balls < moves):
        moves = balls
    i = 0
    while(i < len(line)-2):
        if(line[i] == 'o' and line[i+1] == 'o' and line[i+2] == '-'):
            mod = line[:i] + "--o"
            if(i < len(line)-3):
                mod = mod + line[i+3:]

            

            solve(mod, balls-1)
        if(line[i] == '-' and line[i+1] == 'o' and line[i+2] == 'o'):
            mod = line[:i] + "o--"
            if(i < len(line)-3):
                mod = mod + line[i+3:]
            

            solve(mod, balls-1)
        i+=1


def main():
    global moves
    n = int(input())

    while(n != 0):
        line = input()
        moves = line.count('o')
        solve(line, moves)
        print(moves)
        n-=1

main()