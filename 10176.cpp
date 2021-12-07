#include <bits/stdc++.h>
using namespace std;

long long modulo(long long a , long long b, long long m){
    if(b == 0) return 1;


    if(b%2 != 0) return (a*modulo((a*a)%m, (b-1)/2, m))%m;
    else return modulo((a*a)%m, b/2, m);
}


int main(){
    string bin;
    while(cin >> bin){
        while(bin[bin.length()-1] != '#'){
            string aux;
            cin >> aux;
            bin += aux;
        }

        bin.erase(bin.end()-1);
        reverse(bin.begin(), bin.end());

        long long sum = 0;
        for(int i = 0 ; i < bin.length() ; i++){
            if(bin[i] == '1') sum += modulo(2, i, 131071);
        }

        if(sum % 131071 == 0) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

   


    return 0;
}