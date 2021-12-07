#include <bits/stdc++.h>
using namespace std;

vector<long long> divisors(long long n){
  vector<long long> divs;

  for(long long i = 1 ; i <= pow(n, 0.5) ; i++){
    if(n%i == 0){
      divs.push_back(i);
      if(n/i != i) divs.push_back(n/i);
    }
  }
  return divs;
}

long long mcd(long long a, long long b){
  if(min(a, b) == 0) return max(a, b);
  else return mcd(max(a, b)%min(a, b), min(a, b));
}


int main(){
  long long n, card;

  while(1){
    cin >> n;
    if(n == 0) break;

    vector<long long> divs = divisors(n);

    card = 0;

    for(long long i = 0 ; i < divs.size() ; i++)
      for(long long j = 0 ; j < divs.size() ; j++)
        if(i != j and ((divs[i]*divs[j])/mcd(divs[i], divs[j])) == n) card++;

    cout << n << " " << card/2 + 1 << endl;

  }




  return 0;
}
