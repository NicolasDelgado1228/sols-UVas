#include <bits/stdc++.h>
using namespace std;

vector<int> erato(){
  vector<int> primes = {1};
  bitset<32000> bs;
  bs.flip();

  for(int i = 2 ; i <= 32000 ; i++){
    if(not bs[i]) continue;
    for(int j = i*i ; j <= 32000 ; j+=i)
      bs[j] = 0;
    primes.push_back(i);
  }

  return primes;
}

int divisorsCnt(int num){
  int pf = 1, divCnt = 1, powers;
  vector<int> primes = erato();

  while(num != 1 and primes[pf] <= pow(num, 0.5)){
    powers = 0;
    while(num%primes[pf] == 0){
      num /= primes[pf];
      powers++;
    }
    pf++;
    divCnt *= (powers+1);
  }
  if(num != 1) divCnt*=2;

  return divCnt;
}


int main(){
  int cases, lower, upper, maxDivCnt, i, val, valDivs;
  cin >> cases;

  while(cases--){
    cin >> lower >> upper;
    maxDivCnt = divisorsCnt(lower);
    val = lower;
    for(i = lower ; i <= upper ; i++){
      valDivs = divisorsCnt(i);
      if(valDivs > maxDivCnt){ maxDivCnt = valDivs; val = i;}
    }
    cout << "Between " << lower << " and " << upper << ", " << val << " has a maximum of " << maxDivCnt << " divisors." << endl;
  }
  return 0;
}
