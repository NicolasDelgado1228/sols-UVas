#include <bits/stdc++.h>
using namespace std;

int main(){
    int cases, n, min, max, num;
    cin >> cases;

    while(cases--){
        cin >> n;
        min = 1000000; max = -1;
        while(n--){
            cin >> num;
            if(num < min) min = num;
            if(num > max) max = num;
        }

        cout << ((max-((max-min)/2))*2) + ((((max-min)/2)-min)*2) << endl;
    }


    return 0;
}