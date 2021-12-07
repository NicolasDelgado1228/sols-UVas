#include <bits/stdc++.h>
using namespace std;

string ans;
bool found;

void backtrack(vector<int> bars, int i, int acum, int res){
    if(acum == res) {ans = "YES"; found = true; return;}
    else if(acum > res or i > bars.size() or found) return;


    backtrack(bars, i+1, acum+bars[i], res);
    backtrack(bars, i+1, acum, res);
    
}


int main(){
    int cases, barsCnt, bar, res;
    cin >> cases;


    while(cases--){
        cin >> res;
        cin >> barsCnt;
        vector<int> bars;

        //Crea el arreglo de los bars
        while(barsCnt--){
            cin >> bar;
            bars.push_back(bar);
        }

        found = false;
        backtrack(bars, 0, 0, res);

        if(ans == "") cout << "NO" << endl;
        else cout << "YES" << endl;
        ans.clear();

    }
    return 0;
}