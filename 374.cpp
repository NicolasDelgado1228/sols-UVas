#include <bits/stdc++.h>
using namespace std;

long long  power(long long a, long long b, long long mod){
    if(b == 0) return 1;


    if(b%2 != 0) return (a*power((a*a)%mod, (b-1)/2, mod))%mod;
    else return power((a*a)%mod, b/2, mod);
}


int main(){
	long long b, p, m;

	while(cin >> b >> p >> m){
		cout << power(b%m, p, m) << endl;
	}
    

    return 0;
}