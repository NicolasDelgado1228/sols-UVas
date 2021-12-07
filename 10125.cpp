#include <bits/stdc++.h>
using namespace std;

long long d;



bool cmp(long long &a, long long &b){
    return a > b;
}

int main(){
    long long n, i, num, j, k;
    cin >> n;

    while(n != 0){
        vector<long long> nums;
        set<long long> numsSet;

        for(i = 0 ; i < n ; i++){
            cin >> num;
            nums.push_back(num);
            numsSet.insert(num);
        }

        sort(nums.begin(), nums.end(), cmp);

        d = -536870913;

        for(i = 0 ; i < )
        
        if(d == -536870913) cout << "no solution" << endl;
        else cout << d << endl;


        cin >> n;
    }

    return 0;
}