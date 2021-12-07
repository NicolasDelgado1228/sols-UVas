#include <iostream>
#include <cmath>
using namespace std;

long long H(int n){
  long long res = 0, lim = floor(sqrt(n));
  for( int i = 1; i <= lim; i++ ){
    res += n/i;
    if(i != n/i)
      res += i*((n/i) - (n/(i+1)));
  }
return res;
}

int main(){
  int cases;
  cin >> cases;

  while(cases--){
    int n;
    cin >> n;
    cout << H(n) << endl;
  }
  return 0;
}
