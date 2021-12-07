#include <bits/stdc++.h>
using namespace std;

vector<int> toposort;

void topoDfs(vector<vector<int>> &G, vector<bool> &visited, int u){
    visited[u] = true;
    for(int i = 0 ; i < G[u].size() ; i++){
        int v = G[u][i];
        if(not visited[v]) topoDfs(G, visited, v);
    }
    toposort.push_back(u);
}

void getTopo(vector<vector<int>> &G){
    toposort.clear();
    int n = G.size();
    vector<bool> visited(n, false);
    for(int u = 0 ; u < n ; u++)
        if(not visited[u])
            topoDfs(G, visited, u);
}

vector<int> countPathsInDag(vector<vector<int>> &G, int s){
    getTopo(G);
    int n = G.size(), u, v, j;
    vector<int> paths(n, 0);
    paths[s] = 1;

    for(int i = toposort.size()-1 ; i >= 0 ; i--){
        u = toposort[i];
        for(j = 0 ; j < G[u].size() ; j++){
            v = G[u][j];
            paths[v] += paths[u];
        }
    }

    return paths;

}

int solve(vector<vector<int>> &G, vector<int> deaths, int s){
    vector<int> paths = countPathsInDag(G, s);
    int ans = 0;
    for(int i = 0 ; i < deaths.size() ; i++) ans += paths[deaths[i]];
    return ans;
}

int main(){
    int n, i, j, u, m, v;
    bool first = true;

    while(cin >> n){
        vector<vector<int>> G(n, vector<int>(0,0));
        vector<int> deaths;
        for(u = 0 ; u < n ; u++){
            cin >> m;
            if (m == 0) deaths.push_back(u);
            else{
                for(j = 0 ; j < m ; j++){
                    cin >> v;
                    G[u].push_back(v);
                }
            }
        }
        if(not first) cout << endl;
        first = false;
        cout << solve(G, deaths, 0) << endl;
    }
    return 0;
}
