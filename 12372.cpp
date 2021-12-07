#include <bits/stdc++.h>
using namespace std;

int main(){
    int c, w, d, l, cases = 1;
    bool good = true;
    cin >> c;

    while(c--){
        cin >> w >> d >> l;
        if(w > 20 or d > 20 or l > 20) cout << "Case " << cases++ << ": bad" << endl;
        else cout << "Case " << cases++ << ": good" << endl;
    }


    return 0;
}