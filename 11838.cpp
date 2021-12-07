#include <bits/stdc++.h>
using namespace std;

vector<int> topoSort;

void topoDfs(vector<vector<int>> &G, vector<bool>& visited, int node){
    if(not visited[node]){
        vector<int> adjacents = G[node];
        visited[node] = true;

        for(int i = 0 ; i < adjacents.size() ; i++)
            topoDfs(G, visited, adjacents[i]);
        topoSort.push_back(node);
    }
}

void dfs(vector<vector<int>> &G, vector<bool>& visited, int node){
    if(not visited[node]){
        vector<int> adjacents = G[node];
        visited[node] = true;

        for(int i = 0 ; i < adjacents.size() ; i++)
            dfs(G, visited, adjacents[i]);
    }
}

int main(){
    int n, m, a, b, c, i, scc;

    while(true){
        cin >> n >> m;
        if(n == 0 and m == 0) break;

        vector<vector<int>> G(n,vector<int>(0, 0));
        vector<vector<int>> invG(n, vector<int>(0, 0));

        for(i = 0 ; i < m ; i++){
            cin >> a >> b >> c;
            a--;b--;
            if(c == 1){
                G[a].push_back(b);
                invG[b].push_back(a);
            }
            else{
                G[a].push_back(b);
                G[b].push_back(a);
                invG[a].push_back(b);
                invG[b].push_back(a);
            }
        }
        vector<bool> visitedG(n, false);
        vector<bool> visitedInvG(n, false);

        //Kosaraju's algorithm
        topoSort.clear();
        
        //setup order
        for(i = 0 ; i < n ; i++)
            if(not visitedG[i])
                topoDfs(G, visitedG, i);
            
        
        scc = 0;

        for(i = topoSort.size()-1 ; i >= 0 ; i--){
            if(not visitedInvG[topoSort[i]]){
                dfs(invG, visitedInvG, topoSort[i]);
                scc++;
            }
        }

        if(scc == 1) cout << 1 << '\n';
        else cout << 0 << '\n';

    }

    return 0;
}