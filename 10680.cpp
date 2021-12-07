#include <bits/stdc++.h>
using namespace std;

#define N 1105

vector<long long> sieve(){
  bitset<N> bs;
  bs.flip();
  vector<long long> primes;

  for(long long i = 2 ; i <= 1100 ; i++){
    if(bs[i] == 0) continue;
    for(long long j = i*i ; j <= 1100 ; j+=i) bs[j] = 0;
    primes.push_back(i);
  }

  return primes;
}

map<int, int> mcm(int n){
  vector<long long> primes = sieve();
  int idx = 0, exp;
  map<int, int> lcm;
  lcm[1] = 1;

  for(int i = 0 ; primes[i]<=n ; i++){
    int j = 0;
    while(pow(primes[i],j) <= n) j++;
    lcm[primes[i]] = j-1;
  }

  return lcm;
}


int main(){
  int n;

  while(1){
    cin >> n;
    if(n == 0) break;

    map<int,int> lcm = mcm(n);
    map<int,int>::iterator it = lcm.begin();
    int num = 1;
    int twos = 0, fives = 0;
    for(it ; it != lcm.end() ; it++){
      if(it->first != 2 and it->first != 5)
        num *= pow(it->first,it->second);
      else if(it->first == 2) twos+=it->second;
      else if(it->first == 5) fives+=it->second;
    }

    if(twos > fives)
      num *= pow(2, twos-fives);
    else if(fives > twos)
      num *= pow(5, fives-twos);

    cout << num%10 << endl;


  }


  return 0;
}
