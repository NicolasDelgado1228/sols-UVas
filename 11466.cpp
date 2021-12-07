#include <bits/stdc++.h>
using namespace std;


long long lpd(long long n){
  n = fabs(n);
  long long largest = -1;
  int divCnt = 0;

  long long pf = 2;
  while(n != 1 and pf*pf <= n){

    while(n%pf == 0){
      if(pf > largest){
        largest = pf;
        divCnt++;
      }
      n/=pf;
    }
    pf++;
  }

  if(n!=1){
    divCnt++;
    if(pf > largest) largest = n;
  }


  if(divCnt > 1) return largest;
  else return -1;
}


int main(){
  long long n;

  while(1){
    cin >> n;
    if(n == 0) break;

    cout << lpd(n) << endl;
  }



  return 0;
}
