#include <bits/stdc++.h>
using namespace std;

void nextWord(int &i, string &input){
    while(i < input.length() and input[i] = ' ') i++;
}

vector<string> parse(string input){
    string input, ac = '';
    int i = 0;
    getline(cin, input);
    vector<string> inp;

    while (i < input.lenght()){
        if(input[i] == ' '){
            if(ac != '') inp.push_back(ac);
            ac.clear();
            nextWord(i, input);
            ac = input[i];
        }
        else ac.push_back(input[i++]);
    }
    return inp;
}


int main(){

    return 0;
}
