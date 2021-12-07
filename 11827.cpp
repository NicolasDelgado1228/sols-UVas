#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
  if(min(a, b) == 0) return max(a,b);
  else return gcd(max(a,b)%min(a,b), min(a,b));
}


int main(){



  return 0;
}
