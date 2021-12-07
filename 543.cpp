#include <bits/stdc++.h>
using namespace std;

#define N 1000200


pair<vector<int>,bitset<N>> sieve(){
  bitset<N> bs;
  bs.flip();
  vector<int> primes;

  for(long long i = 2 ; i <= 1000010 ; i++){
    if(not bs[i]) continue;
    for(long long j = i*i ; j <= 1000010 ; j += i) bs[j] = 0;
    primes.push_back(i);
  }

  return make_pair(primes,bs);
}


int main(){
  int n, maxDist, i;
  pair<vector<int>,bitset<N>> primes = sieve();

  while(1){
    cin >> n;
    if(n == 0) break;

    i = 0;
    while((primes.first)[i] < n){
      if(primes.second[n-primes.first[i]]){
        cout << n << " = " << min(n-primes.first[i],primes.first[i]) << " + " << max(n-primes.first[i],primes.first[i]) << endl;
        break;
      }
      i++;
    }
  }


  return 0;
}
