#include <bits/stdc++.h>
using namespace std;


int answer, found;

void backtrack(int s, int d, int ac, int sCnt, int depth){
    if(depth == 12){ if(ac >= answer){ answer = ac; found = true;} return;}
    if(sCnt == 4) return;

    cout << ac << endl;

    backtrack(s, d, ac + s, sCnt+1, depth+1);
    backtrack(s, d, ac - d, sCnt, depth +1);
}


int main(){
    int s, d;

    while(cin >> s >> d){
        answer = 0;
        found = false;
        backtrack(s, d, 0, 0, 0);

        if(found) cout << answer << endl;
        else cout << "Deficit" << endl;

    }
    return 0;
}