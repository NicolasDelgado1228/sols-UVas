#include <bits/stdc++.h>
using namespace std;

int main(){
    int cases;
    cin >> cases;

    while(cases--){
        string word;
        cin >> word;

        if(word.size() == 5) cout << 3 << endl;
        else{
            if(word[0] == 't' or word[1] == 'w' or word[2] == 'o') cout << 2 << endl;
            else cout << 1 << endl;
        }
    }


    return 0;
}