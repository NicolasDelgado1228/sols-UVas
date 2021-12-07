#include<bits/stdc++.h>
using namespace std;

#define N 10000000
vector<long long int> primes;

void erato(){
	bitset<N> bs;
	bs.flip();
	primes.push_back(1);

	for(long long i = 2 ; i <= 1000000 ; i++){
		if(not bs[i]) continue;
		for(long long j = i*i ; j <=1000000 ; j+= i){
			bs[j] = false;
		}
		primes.push_back(i);
	}
}

bool isPrime(int n){
	if(n == 1) return false;
	for(int i = 1 ; primes[i]*primes[i] <= n ; i++)
		if(n%primes[i] == 0) return false;
	return true;
}

int main(){
	long long int l, u, c1, c2, j1, j2, max, min, i;
	bool first;
	erato();

	while(cin >> l >> u){
		bool adjacentPrimes = false;
		pair<int, int> closest;
		pair<int, int> distant;
		min = 100000000;
		max = -1;
		first = true;

		for(i = l ; i <= u ; i++){

			if(isPrime(i)){
				if(first){ 
					c1 = j1 = i;
					first = false;
				}
				else{
					adjacentPrimes = true;
					c2 = j2 = i;
					if(c2-c1 < min){
						min = c2-c1;
						closest.first = c1;
						closest.second = c2;
					}
					c1 = c2;
					if(j2-j1 > max){
						max = j2-j1;
						distant.first = j1;
						distant.second = j2;
					}
					j1 = j2;
				}
			}
		}
		if(adjacentPrimes) cout << closest.first << "," << closest.second << " are closest, " << distant.first << "," << distant.second << " are most distant." << endl;
		else cout << "There are no adjacent primes." << endl;
	}

	return 0;
}