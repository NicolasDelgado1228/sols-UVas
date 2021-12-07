#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, i, j, r;

    while(true){
        cin >> n;
        if(n == 0) break;
        map<string, int> conv;
        vector<string> places;
        for(i = 0 ; i < n ; i++){
            string node;
            cin >> node;
            places.push_back(node);
            conv[node] = i;
        }
        vector<vector<int>> G(n, vector<int>(0,0));
        cin >> r;
        for(i = 0 ; i < r ; i++){
            string uStr, vStr;
            cin >> uStr >> vStr;
            G[conv[uStr]].push_back(conv[vStr]);
            G[conv[vStr]].push_back(conv[uStr]);
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
