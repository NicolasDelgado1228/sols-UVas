#include <bits/stdc++.h>
using namespace std;

int main(){
    set<string> s;
    string word;
    while(cin >> word){
        s.insert(word);
        word.clear();
    }
    for(set<string>::iterator it = s.begin() ; it!=s.end() ; it++)
        cout << *it << endl;
    return 0;
}