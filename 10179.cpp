#include <bits/stdc++.h>
using namespace std;
#define N 32005

vector<long long> sieve(){
  bitset<N> bs;
  bs.flip();
  vector<long long> primes;

  for(long long i = 2 ; i <= 32000 ; i++){
    if(bs[i] == 0) continue;
    for(long long j = i*i ; j <= 32000 ; j+=i) bs[j] = 0;
    primes.push_back(i);
  }

  return primes;
}

int eulerPhi(long n, vector<long long> primes){
  int i = 0;
  double phi = n;
  while(n != 1 and primes[i]*primes[i] <= n){
    if(n%primes[i] == 0) phi*=((double)1-(double)((double)1/(double)primes[i]));
    while(n%primes[i] == 0) n/=primes[i];
    i++;
  }
  if(n != 1) phi*=(1-(double)((double)1/(double)n));

  return phi;
}



int main(){
  long n;
  vector<long long> primes = sieve();
  while(1){
    cin >> n;
    if(n == 0) break;

    cout << eulerPhi(n,primes) << endl;
  }





  return 0;
}
