#include <bits/stdc++.h>
using namespace std;

#define N 20000005
vector<pair<long long,long long>> sieve(){
  long long prime = 2;
  vector<pair<long long,long long>> twins;
  bitset<N> bs;
  bs.flip();

  for(long long i = 2 ; i <= 19000000 ; i++){
    if(not bs[i]) continue;
    for(long long j = i*i ; j <= 19000000 ; j += i) bs[j] = 0;
    if(i-2 == prime) twins.push_back(make_pair(prime, i));
    prime = i;
  }

  return twins;

}

int main(){
  long long n;

  vector<pair<long long,long long>> twins = sieve();

  while(cin >> n){
    pair<long long, long long> twin = twins[n-1];
    cout << "(" << twin.first << ", " << twin.second << ")" << endl;
  }


  return 0;
}
