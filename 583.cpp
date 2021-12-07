#include <bits/stdc++.h>
using namespace std;

vector<int> primeDecompos(long long n){
  n = fabs(n);
  vector<int> primeFactors;

  long long pf = 2;
  while(n != 1 and pf*pf <= n){
    while(n%pf == 0){
      primeFactors.push_back(pf);
      n /= pf;
    }
    pf++;
  }

  if(n != 1) primeFactors.push_back(n);

  return primeFactors;
}


int main(){
  long long n;

  while(1){
    cin >> n;
    if(n == 0) break;

    vector<int> primeFactors = primeDecompos(n);
    cout << n << " = ";
    if(n < 0) cout << "-1 x ";
    cout << "";
    for(int i = 0 ; i < primeFactors.size() ; i++){
      cout << primeFactors[i];
      if(i < primeFactors.size()-1) cout << " x ";
    }
    cout << endl;
  }
  return 0;
}
