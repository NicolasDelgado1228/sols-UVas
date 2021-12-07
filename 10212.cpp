#include <bits/stdc++.h>
using namespace std;


long long lagrendeFormula(long long n){
    long long twos = 0, fives = 0;

    for(long long i = 1 ; i <= log10(n)/log10(2) ; i++)
        twos += floor(n/pow(2,i));
    
    for(long long i = 1 ; i <= log10(n)/log10(5) ; i++)
        fives += floor(n/pow(5,i));
    
    return min(twos, fives);
}
/*
long long modulo(long long n, long long p, long long m){
    if(p == 1) return 1;

    if(p%2 != 0) (n%m)*modulo((n*n)%m, (p-1)/2, m);
    else modulo((n*n)%m, p/2, m);
}*/

long long purify(long long n, long long& tens){
    while(n%10 == 0){
        n/=10;
        tens--;
    }
    return n;
}

int main(){
    long long n, r, tensN, tensD, tens;
    long long res;

    while(cin >> n >> r){
        tensN = lagrendeFormula(n);
        tensD = lagrendeFormula(n-r);
        
        tens = tensN-tensD;

        long long num = 1;
        vector<long long> nums;
        for(long long i = n-r+1 ; i <= n ; i++){
            nums.push_back(purify(i, tens));
        }
        long long aux = nums.size();
        
       while(nums.size() > 1){
            vector<long long> aux;
            long long i = 0;
            for(i ; i < nums.size()-1 ; i+=2){
                aux.push_back(purify(nums[i]*nums[i+1], tens)%10);
            }
            if(i == nums.size()-1) aux.push_back(nums[nums.size()-1]%10);
            for(int j = 0 ; j < aux.size() ; j++) cout << aux[j] << " ";
            cout << endl;
            nums.clear();
            nums = aux;
        }
        
        cout << (nums[0])%10 << endl;
        

    }



    return 0;
}