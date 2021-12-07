#include <bits/stdc++.h>
using namespace std;

class RMQ{
public:
    vector<vector<int>> sparse;
    RMQ(vector<int> &arr){
        int n = arr.size(), k = ((int)log2(arr.size()))+1;
        for(int i = 0 ; i < n ; i++) sparse.push_back(vector<int>(k,0));

        for (int i = 0; i < n; i++) sparse[i][0] = arr[i];

        for (int j = 1; (1 << j) <= n; j++) {
            for (int i = 0; (i + (1 << j) - 1) < n; i++) {
                if (sparse[i][j - 1] < sparse[i + (1 << (j - 1))][j - 1]) sparse[i][j] = sparse[i][j - 1];
                else sparse[i][j] = sparse[i + (1 << (j - 1))][j - 1];
            }
        }
    }

    int query(int L, int R){
        int j = (int)log2(R - L + 1);
        if (sparse[L][j] <= sparse[R - (1 << j) + 1][j]) return sparse[L][j];
        else return sparse[R - (1 << j) + 1][j];
    }
};

void dfs(vector<vector<pair<int,long long>>> &T, vector<bool> &visited, vector<int> &depths, vector<int> &circuit, vector<int> &firstOccurrence, vector<pair<int,long long>> &parent, vector<int> &disc, vector<int> &discInv, int u, int d, int &time){
    visited[u] = true;
    depths[u] = d;
    circuit.push_back(u);
    if(disc[u] == -1){
        firstOccurrence[u] = circuit.size()-1;
        discInv[time] = u;
        disc[u] = time++;
    }
    for(int i = 0 ; i < T[u].size() ; i++)
        if(not visited[T[u][i].first]){
            parent[T[u][i].first] = {u,T[u][i].second};
            dfs(T, visited, depths, circuit, firstOccurrence, parent, disc, discInv, T[u][i].first, d+1, time);
            circuit.push_back(u);
        }
}

vector<vector<int>> getVals(vector<vector<pair<int,long long>>> &T, vector<pair<int,long long>> &parent){
    int n = T.size(), time = 0;
    vector<bool> visited(n, false);
    vector<int> depths(n, -1), circuit, firstOccurrence(n, -1), disc(n,-1), discInv(n, -1);
    dfs(T, visited, depths, circuit, firstOccurrence, parent, disc, discInv, 0, 0, time);
    return {depths, circuit, firstOccurrence, disc, discInv};
}

long long buildPath(vector<vector<pair<int, long long>>> &T, vector<pair<int, long long>> &parent, int s, int t){
    int u, v;
    long long dist = 0;
    for(v = s ; v != t ; v = parent[v].first) {dist += parent[v].second;}
    return dist;
}

int main(){
    int n, i, u, w, querysCnt, v, L, R, lca;

    while(true){
        cin >> n;
        if(n == 0) break;
        vector<vector<pair<int, long long>>> T(n, vector<pair<int, long long>>(0,{0,0}));
        for(i = 1 ; i <=n-1 ; i++){
            cin >> u >> w;
            T[i].push_back({u,w});
            T[u].push_back({i,w});
        }
        vector<pair<int, long long>> parent(n,{-1,-1});
        vector<int> table;
        vector<vector<int>> temp = getVals(T, parent);
        vector<int> depths = temp[0], circuit = temp[1], firstOccurrence = temp[2], disc = temp[3], discInv = temp[4];
        for(i = 0 ; i < circuit.size() ; i++) table.push_back(disc[circuit[i]]);
        RMQ rmq = RMQ(table);
        /*
        for(i = 0 ; i < eulerPath.size() ; i++) cout << eulerPath[i] << " ";
        cout << endl;*/

        vector<long long> ans;
        cin >> querysCnt;
        while(querysCnt--){
            cin >> u >> v;
            L = min(firstOccurrence[u], firstOccurrence[v]); R = max(firstOccurrence[u], firstOccurrence[v]);
            lca = discInv[rmq.query(L,R)];

            ans.push_back(buildPath(T, parent, u, lca) + buildPath(T, parent, v, lca));
        }
        cout << ans[0];
        for(int i = 1 ; i < ans.size() ; i++) cout << " " << ans[i];
        cout << endl;

    }
    
    return 0;
}
