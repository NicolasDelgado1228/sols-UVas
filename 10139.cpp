#include <bits/stdc++.h>
using namespace std;

int lagrande(long long n, long long p){
  long long d = 0;
  for(int i = 1 ; i <= log10(n)/log10(p) ; i++)
    d += floor(n/pow(p,i));

  return d;
}

bool solve(long long n, long long m){
  int pf = 2, pfCnt = 0;
  while(m != 1 and pf*pf <= m){
    while(m%pf == 0){
      pfCnt++;
      m /= pf;
    }
    if(pfCnt > lagrande(n, pf)) return false;
    pfCnt = 0;
    pf++;
  }

  if(m != 1 and lagrande(n, m) == 0) return false;

  return true;
}

int main(){
  int n, m;

  while(cin >> n >> m){
    if(solve(n, m)) cout << m << " divides " << n << "!" << endl;
    else cout << m << " does not divide " << n << "!" << endl;
  }




  return 0;
}
