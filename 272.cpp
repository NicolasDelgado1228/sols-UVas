#include <bits/stdc++.h>
using namespace std;

int main(){
    string quote;
    int i;
    bool left = true;

    while(getline(cin, quote)){
        string line = "";

        for(i = 0 ; i < quote.size() ; i++){
            if(left and quote[i] == '"') {line += "``";left = false;}
            else if(not left and quote[i] == '"'){line += "''";left = true;}
            else line += quote[i];
        }

        if(line != "") cout << line << endl;
    }


    return 0;
}