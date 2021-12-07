
def eratoSieve():
	bs = [True for i in range(100000000)]
	primes = [1]
	i = 2
	while(i < 100000000):
		if(bs[i]):
			j = i*i
			while(j < 100000000):
				bs[j] = False
				j += i
			primes.append(i)

		i += 1

	return primes



def main():
	primes = erato()
	print(len(primes))

main()
