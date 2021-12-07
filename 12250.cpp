#include <bits/stdc++.h>
using namespace std;

int main(){
    map<string, string> trad = {{"HELLO","ENGLISH"}, {"HOLA","SPANISH"}, {"HALLO","GERMAN"}, {"BONJOUR","FRENCH"}, {"CIAO","ITALIAN"}, {"ZDRAVSTVUJTE","RUSSIAN"}};

    string word;
    int c = 1;
    while(true){
        cin >> word;
        if(word == "#") break;
        cout << "Case " << c++ << ": ";
        if(word != "HELLO" and word != "HOLA" and word != "HALLO" and word != "BONJOUR" and word != "CIAO" and word != "ZDRAVSTVUJTE") cout << "UNKNOWN" << endl;
        else cout << trad[word] << endl;
    }
   
    return 0;
}