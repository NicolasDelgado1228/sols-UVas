from collections import deque

def getIdx(binaryNum, bitsCnt):
    base = 1 << ((bitsCnt)-1)
    i = 0
    while(True):
        if(binaryNum & (base >> i) != 0): return i
        else: i+=1


def possibleStates(state, rooms, lights, restrictedStates):
    states = list()
    #create the possible states result of changing from room
    adjacents = rooms[getIdx(state[1], len(rooms))]
    ini = 1 << (len(rooms)-1)
    for adjacent in adjacents:
        if(state[0] & (ini >> adjacent) != 0):
            newState = (state[0], ini >> adjacent)
            if(not restrictedStates.intersection({newState})): states.append(newState) #Si la intersection es vacia
    #Create the possible states result of switching on/off lights
    adjacents = lights[getIdx(state[1], len(rooms))]
    for adjacent in adjacents:
        newState = (state[0]^(ini >> adjacent), state[1])
        if(not restrictedStates.intersection({newState})):  states.append(newState)    #Si la intersection es vacia

    return states

def stepsInterpreter(steps, roomsCnt):
    stepsRes = list()
    i = len(steps)-1
    base = 1 << (roomsCnt-1)
    while(i > 0):
        #Si cambio de cuarto
        if(steps[i][0] != steps[i-1][0]):
            j = getIdx(steps[i][0] ^ steps[i-1][0], roomsCnt)
            if(steps[i][0] & (base >> j) != 0 and steps[i-1][0] & (base >> j) == 0): stepsRes.append("Switch off light in room " + str(j+1) + ".")
            else: stepsRes.append("Switch on light in room " + str(j+1) + ".")
        else:
            stepsRes.append("Move to room " + str(getIdx(steps[i-1][1], roomsCnt)+1) + ".")
        i-=1
    return stepsRes

#Debe retornar una ruta(diccionario) con un booleano diciendo si se pudo llegar al estado final
#En caso de que no se pueda, el dict es vacio
def bfs(rooms, lights, iniState):
    path = dict()
    queue = deque()
    queue.append(iniState)
    restrictedStates = {iniState}

    if(iniState == (1, 1)): return [path, True]
    #queue = (state, restrictedState, nodeNumber)

    while(queue):
        state = queue[0]
        restrictedStates.add(queue[0])
        adjacents = possibleStates(state, rooms, lights, restrictedStates)
        #print(str(state) + "-> " + str(adjacents))
        for ad in adjacents:
            restrictedStates.add(ad)
            path[ad] = state
            #if it found the final state
            if(ad == (1, 1)):
                return [path, True]

            else:
                queue.append(ad)

        queue.popleft()

    return [{}, False]

def main():
    villaNumber = 1
    while(True):
        r, d, s = map(int, input().split())
        if(r == 0 and d == 0 and s == 0): break
        #Build the rooms and lights graphs
        rooms = list()
        lights = list()
        links = list()
        for i in range(r):
            lights.append([])
            rooms.append([])
        for i in range(d):
            r1, r2 = map(int, input().split())
            r1 -= 1
            r2 -= 1
            links.append((r1, r2))
        #Build the rooms graph
        links.reverse()
        for link in links:
            rooms[link[0]].append(link[1])
            rooms[link[1]].append(link[0])
        #Build the lights graph
        for i in range(s):
            l1, l2 = map(int, input().split())
            if(l1 != l2):
                l1-=1
                l2-=1
                lights[l1].append(l2)
        input()

        iniState = (1 << r-1, 1 << r-1)  #(100, 100)
        finState = (1, 1)
        #print(possibleStates(iniState, rooms, lights, {iniState}))
        print("Villa #" + str(villaNumber))
        res = bfs(rooms, lights, iniState)
        if(res[1] == finState[1]):
            steps = [finState]
            step = finState
            while(step != iniState):
                step = res[0][step]
                steps.append(step)

            steps = stepsInterpreter(steps, r)
            print("The problem can be solved in " + str(len(steps)) + " steps:")
            for s in steps:
                print("- " + s)

        else:
            print("The problem cannot be solved.")
        print("")

        villaNumber += 1
main()
