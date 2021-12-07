#include <bits/stdc++.h>
using namespace std;
#define N 3505

vector<long long> sieve(){
  bitset<N> bs;
  bs.flip();
  vector<long long> primes;

  for(long long i = 2 ; i <= 3500 ; i++){
    if(bs[i] == 0) continue;
    for(long long j = i*i ; j <= 3500 ; j+=i) bs[j] = 0;
    primes.push_back(i);
  }

  return primes;
}

map<int,int> facto(int n, vector<long long> primes){
  int i = 0, expCnt;
  map<int,int> fact;
  while(n != 1 and primes[i]*primes[i] <= n){
    expCnt = 0;
    while(n%primes[i] == 0){
      n/=primes[i];
      expCnt++;
    }
    fact[primes[i]] = expCnt;
    i++;
  }

  if(n != 1) fact[n] = 1;

  return fact;
}

int buildNum(map<int,int> factoA, map<int,int> factoB){
  int num = 1;
  map<int,int>::iterator it1 = factoA.begin();
  for(it1 ; it1 != factoA.end() ; it1++) if(factoB.find(it1->first) == factoB.end()) return -1;
  map<int,int>::iterator it = factoB.begin();
  for(it ; it != factoB.end() ; it++){
    if(factoA.find(it->first) != factoA.end() and it->second-factoA[it->first] < 0) return -1;
    else if(factoA.find(it->first) != factoA.end() and it->second-factoA[it->first] > 0) num*=pow(it->first,it->second);
    else if(factoA.find(it->first) == factoA.end()) num*=pow(it->first,it->second);
  }

  return num;
}

int main(){
  vector<long long> primes = sieve();
  int a, b, cases;
  cin >> cases;

  while(cases--){
    cin >> a >> b;

    map<int,int> factoA = facto(a, primes), factoB = facto(b, primes);
    int num = buildNum(factoA, factoB);

    if(num == -1) cout << "NO SOLUTION" << endl;
    else cout << num << endl;
  }



  return 0;
}
