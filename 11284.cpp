#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> 



int main(){
    int scenarios, n, m, u, v;
    double w;
    cin >> scenarios;
    for(int scenario = 0; scenario < scenarios ; scenario++){
        cin >> n >> m;
        vector<vector<pair<int,int>>> G(n, vector<pair<int,int>>(0, {0,0}));
        for(int edge = 0; edge < m ; edge++){
            cin >> u >> v >> w;
            G[u].push_back({v,w});G[v].push_back({u,w});
        }
    }

    return 0;
}