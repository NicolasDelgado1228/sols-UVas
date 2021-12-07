#include <bits/stdc++.h>
using namespace std;


vector<string> solutions;


void backtrack(vector<string> dict, int idx, string word, string rule, int pointer){
    if(idx > word.length()) return;

    if(rule[idx] == '#')
        for(int i = 0 ; i < dict.size() ; i++){
            string newWord;
            if(pointer + 1 < word.size())
                newWord = word.substr(0, pointer) + dict[i] + word.substr(pointer+1, word.length()-pointer+1);
            else{
                newWord = word.substr(0, pointer) + dict[i];
                solutions.push_back(newWord);
            }

            backtrack(dict, idx+1, newWord, rule, pointer+(dict[i]).size());
        }
    else if(rule[idx] == '0'){
        for(int i = 0 ; i < 10 ; i++){
            string newWord;
            if(pointer + 1 < word.size())
                newWord = word.substr(0, pointer) + to_string(i) + word.substr(pointer+1, word.length()-pointer+1);
            else{
                newWord = word.substr(0, pointer) + to_string(i);
                solutions.push_back(newWord);
            }

            backtrack(dict, idx+1, newWord, rule, pointer+1);
        }
    }
}

int main(){
    int dictCnt, rulesCnt;

    while(cin >> dictCnt){
        cout << "--" << endl;
        vector<string> dict, rules;
        solutions.clear();

        while(dictCnt--){
            string word;
            cin >> word;
            dict.push_back(word);
        }

        cin >> rulesCnt;
        while(rulesCnt--){
            string rule;
            cin >> rule;
            rules.push_back(rule);
            backtrack(dict, 0, rule, rule, 0);
        }

        for(int i = 0 ; i < solutions.size() ; i++)
            cout << solutions[i] << endl;
    }
    return 0;
}