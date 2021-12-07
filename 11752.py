import math

def erato():
	sieve = [True for i in range(66000)]
	primes = [1]
	i = 2
	while(i < 66000):
		if(sieve[i]):
			j = i*i
			while(j < 66000):
				sieve[j] = False
				j+=i
			primes.append(i)
		i+=1
	return primes

def isPrime(n, primes):
	i = 1
	while(primes[i]**2 <= n):
		if(n%primes[i] == 0): return False
		i += 1
	return True


def main():
	primes = erato()
	supow = {1}

	for i in range(2, 65537):

		p = 4
		while(math.log(i, 2)*p < 64):
			if(not isPrime(p, primes)):
				supow.add(i**p)
			p += 1

	supow = list(supow)
	supow.sort()
	for i in supow:
		print(i)




main()