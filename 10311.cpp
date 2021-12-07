#include <bits/stdc++.h>
using namespace std;

vector<long long int> primes;
#define N 10050


void sieve(){
	bitset<N> bs;
	bs.flip();

	for(long long int i = 2 ; i <= 10100 ; i++){
		if(not bs[i]) continue;
		for(long long int j = i*i ; j <= 10100 ; j += i)
			bs[j] = false;
		primes.push_back(i);
	}
}

bool isPrime(int n){
	if(n == 1) return false;
	for(int i = 0 ; primes[i]*primes[i] <= n ; i++)
		if(n%primes[i] == 0) return false;
	return true;
}



int main(){
	int n, found;
	sieve();

	while(cin >> n){

		if(n%2 != 0){
			if(isPrime(n-2) and n-2 > 0) cout << n << " is the sum of 2 and " << n-2 << "." << endl;
			else cout << n << " is not the sum of two primes!" << endl;
			continue;
		}
		found = 0;


		for(int i = (n/2)+1 ; i > 0 ; i--){
			if(isPrime(i) and isPrime(n-i) and n-i-i > 0){
				found = 1;
				cout << n << " is the sum of " << i << " and " << n-i << "." << endl;
				break;
			}
		}
				
		if(not found) cout << n << " is not the sum of two primes!" << endl;
	}

	return 0;
}