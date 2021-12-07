#include <bits/stdc++.h>
using namespace std;

#define N 100000

vector<long long> sieve(){
  bitset<N> bs;
  bs.flip();
  vector<long long> primes;

  for(long long i = 2 ; i <= 1000 ; i++){
    if(bs[i] == 0) continue;
    for(long long j = i*i ; j <= 1000 ; j += i) bs[j] = 0;
    primes.push_back(i);
  }

  return primes;
}

int sumFact(long long n, vector<long long> primes){
  int i = 0, sum = 1;
  while(n != 1 and primes[i]*primes[i] <= n){
    while(n%primes[i] == 0){
      n/=primes[i];
      sum += primes[i];
    }
    i++;
  }

  if(n != 1) sum += n;

  return sum;
}

vector<int> precalc(int n, vector<long long> primes){
  vector<int> sums;
  for(int i = n ; i >= 0 ; i--)
    sums.push_back(sumFact(i, primes));

  return sums;
}

int main(){
  vector<long long> primes = sieve();

  int n, cases = 1;
  while(1){
    cin >> n;
    if(n == 0) break;

    vector<int> pre = precalc(n, primes);
    int search = pre.size() - 1 - (find(pre.begin(),pre.end(),n)-pre.begin());
    if(search == pre.size()) cout << -1 << endl;
    else cout << "Case " << cases << ": " << search << endl;
    cases++;
  }

  return 0;
}
