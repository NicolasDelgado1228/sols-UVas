#include <bits/stdc++.h>
using namespace std;

pair<int,int> getNum(string line){
    int i = 2;
    string num;
    while(i < line.length() and line[i] != ' ') {num.push_back(line[i++]);}
    return {stoi(num),i};
}

int main(){
    int cases, i, j, u, v, n;
    string line;
    cin >> cases;
    getline(cin, line);
    map<char,int> conv;
    for(i = 0 ; i < 26 ; i++) conv[(char)(65+i)] = i;

    while(cases--){
        line.clear();
        vector<string> input;
        while(1){
            getline(cin, line);
            if(line=="") break;
            input.push_back(line);
        }
        n = input.size();
        vector<int> time(n, -1);
        vector<vector<int>> G(n, vector<int>(0,0));
        for(i = 0 ; i < n ; i++){
            string inp = input[i];
            u = conv[inp[0]];
            pair<int,int> numAndStart = getNum(inp);
            time[u] = numAndStart.first;
            if(numAndStart.second+1<inp.length()){
                for(i = numAndStart.second+1 ; i < inp.length() ; i++){
                    v = conv[inp[i]];
                    G[v].push_back(u);
                }

            }
        }
        for(i = 0 ; i < G.size() ; i++){
            for(j = 0 ; j < G[i].size() ; j++){
                cout << G[i][j] << " ";
            }
            cout << endl;
        }


    }
    return 0;
}
