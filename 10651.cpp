def getPos(line):
	positions = list()

	while(line.find("-oo") != -1 or line.find("oo-") != -1):
		if(line.find("-oo-") != -1):
			positions.append((line.find("-oo-"), "-oo"))
			positions.append((line.find("-oo-")+1, "oo-"))
			line = line[:line.find("-oo-")]+line[line.find("-oo-")+3:]
		elif(line.find("-oo") != -1):
			positions.append((line.find("-oo"), "-oo"))
			line = line[:line.find("-oo")]+line[line.find("-oo")+3:]
		elif(line.find("oo-") != -1):
			positions.append((line.find("oo-"), "oo-"))
			line = line[:line.find("oo-")]+line[line.find("oo-")+3:]
	return positions



def solve(line, positions):
	if(len(positions) == 0):
		os = 0
		for c in line:
			if(c == "o"):
				os+=1
		return os

	for pos in positions:
		if(pos[1] == "-oo"):
			aux = line
			aux = list(aux)
			aux[pos[0]] = 'o'
			aux[pos[0]+1] = '-'
			aux[pos[0]+2] = '-'
			new = ""
			for i in aux:
				new += i

			return solve(new, getPos(new))
		else:
			aux = line
			aux = list(aux)
			aux[pos[0]] = '-'
			aux[pos[0]+1] = '-'
			aux[pos[0]+2] = 'o'
			new = ""
			for i in aux:
				new += i
			return solve(new, getPos(new))

def main():
	cases = int(input())

	while(cases != 0):
		line = input()

		print(solve(line, getPos(line)))




		cases -= 1
main()