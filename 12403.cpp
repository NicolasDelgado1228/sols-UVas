#include <bits/stdc++.h>
using namespace std;

int main(){
    int cases, money = 0;
    cin >> cases;
    cin.ignore();

    while(cases--){
        string action;
        getline(cin, action);
        if(action == "report") cout << money << endl;
        else money += stoi(action.substr(7, action.size()-7));
    }
    return 0;
}