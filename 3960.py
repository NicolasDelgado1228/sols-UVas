def main():
    traduction = {"Kamen":"Rock", "Rock":"Rock", "Pierre":"Rock", "Stein":"Rock", "Ko":"Rock",
    "Piedra":"Rock", "Kamien":"Rock", "Guu":"Rock", "Roccia":"Rock", "Sasso":"Rock", "Koe":"Rock",
    "Nuzky":"Scissors", "Scissors":"Scissors", "Ciseaux":"Scissors", "Schere":"Scissors", "Ollo":"Scissors",
    "Tijera":"Scissors", "Nozyce":"Scissors", "Choki":"Scissors", "Forbice":"Scissors", "Olloo":"Scissors",
    "Papir":"Paper", "Paper":"Paper", "Feuille":"Paper", "Papier":"Paper", "Papir":"Paper", "Carta":"Paper", "Rete":"Paper",
    "Paa":"Paper", "Papier":"Paper", "Papel":"Paper"}


    end = False
    gameCnt = 1
    while(not end):
        country1, name1 = input().split()
        country2, name2 = input().split()
        points1, points2 = 0, 0

        while(True):

            option1 = input()
            if(option1 == "." or option1 == "-"):
                if(option1 == "."): end = True
                break
            option1, option2 = option1.split()
            inOp1 = option1 in traduction
            inOp2 = option2 in traduction

            if(not inOp1 and inOp2):
                points2 += 1
            elif(inOp1 and not inOp2):
                points1 += 1
            elif(inOp1 and inOp2):
                if(traduction[option1] == "Rock" and traduction[option2] == "Paper"):
                    points2 += 1
                elif(traduction[option1] == "Rock" and traduction[option2] == "Scissors"):
                    points1 += 1
                elif(traduction[option1] == "Scissors" and traduction[option2] == "Rock"):
                    points2 += 1
                elif(traduction[option1] == "Scissors" and traduction[option2] == "Paper"):
                    points1 += 1
                elif(traduction[option1] == "Paper" and traduction[option2] == "Rock"):
                    points1 += 1
                elif(traduction[option1] == "Paper" and traduction[option2] == "Scissors"):
                    points2 += 1


        print("Game #" + str(gameCnt) + ":")
        if(points1 == 1):
            print(name1 + ": 1 point")
        else:
            print(name1 + ": " + str(points1) + " points")
        if(points2 == 1):
            print(name2 + ": 1 point")
        else:
            print(name2 + ": " + str(points2) + " points")

        if(points1 == points2):
            print("TIED GAME")
        elif(points1 > points2):
            print("WINNER: " + str(name1))
        elif(points1 < points2):
            print("WINNER: " + str(name2))
        print("")
        gameCnt +=1


main()
