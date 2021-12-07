#include <bits/stdc++.h>
using namespace std;

int main(){
    int cases;
    cin >> cases;

    while(cases--){
        string code;
        cin >> code;

        if(code == "1" or code == "4" or code == "78") cout  << '+' << endl;
        else if(code[code.size()-1] == '5' and code[code.size()-2] == '3') cout << "-" << endl;
        else if(code[0] == '9' and code[code.size()-1] == '4') cout << "*" << endl;
        else if(code[0] == '1' and code[1] == '9' and code[2] == '0') cout << "?" << endl;
        else cout << '?' << endl;
    }

    return 0;
}