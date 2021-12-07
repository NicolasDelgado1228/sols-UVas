#include <bits/stdc++.h>
using namespace std;



int main(){
  long long n, k;

  while(cin >> n >> k){
    long double sum1 = 0, sum2 = 0;

    if(n-k > k){
      for(long long i = n-k+1 ; i <= n ; i++) sum1 += log10(i);
      for(long long i = 1 ; i <= k ; i++) sum2 += log10(i);
    }
    else{
      for(long long i = k+1 ; i <= n ; i++) sum1 += log10(i);
      for(long long i = 1 ; i <= n-k ; i++) sum2 += log10(i);
    }

    cout << floor(sum1-sum2) + 1 << endl;
  }


  return 0;
}
