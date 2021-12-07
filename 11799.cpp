#include <bits/stdc++.h>
using namespace std;

int main(){
    int t, n, max, s, c = 1;

    cin >> t;
    while(t--){
        max = -1;
        cin >> n;
        while(n--){
            cin >> s;
            if(s > max) max = s;
        }
        cout << "Case " << c++ << ": " << max << endl;
    }


    return 0;
}