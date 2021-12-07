#include <bits/stdc++.h>
using namespace std;

int main(){
    int testCases, n;
    cin >> testCases;

    while(testCases--){
        cin >> n;
        cout << fabs((((((((n*567)/9)+7492)*235)/47)-498)%100)/10) << endl;
    }


    return 0;
}