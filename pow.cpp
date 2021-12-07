#include <bits/stdc++.h>
using namespace std;

long long  power(int a, int b, int mod){
    if(b == 0) return 1%mod;
    if(b == 1) return a%mod;

    if(b%2 != 0) return (a%mod)*power(a*a, b/2);
    else return power(a*a, b/2);
}


int main(){



    return 0;
}