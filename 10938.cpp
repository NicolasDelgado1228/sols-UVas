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
                if (sparse[i][j - 1] < sparse[i + (1 << (j - 1))][j - 1])
                    sparse[i][j] = sparse[i][j - 1];
                else
                    sparse[i][j] = sparse[i + (1 << (j - 1))][j - 1];
            }
        }
    }

    int query(int L, int R){
        int j = (int)log2(R - L + 1);
        if (sparse[L][j] <= sparse[R - (1 << j) + 1][j]) return sparse[L][j];
        else return sparse[R - (1 << j) + 1][j];
    }
};

void dfs(vector<vector<int>> &T, vector<bool> &visited, vector<int> &depths, vector<int> &circuit, vector<int> &firstOccurrence, vector<int> &parent, vector<int> &disc, vector<int> &discInv, int u, int d, int &time){
    visited[u] = true;
    depths[u] = d;
    circuit.push_back(u);
    if(disc[u] == -1){
        firstOccurrence[u] = circuit.size()-1;
        discInv[time] = u;
        disc[u] = time++;
    }
    for(int i = 0 ; i < T[u].size() ; i++)
        if(not visited[T[u][i]]){
            parent[T[u][i]] = u;
            dfs(T, visited, depths, circuit, firstOccurrence, parent, disc, discInv, T[u][i], d+1, time);
            circuit.push_back(u);
        }
}

vector<vector<int>> getVals(vector<vector<int>> &T){
    int n = T.size(), time = 0;
    vector<bool> visited(n, false);
    vector<int> depths(n, -1), circuit, firstOccurrence(n, -1), parent(n,-1), disc(n,-1), discInv(n, -1);
    dfs(T, visited, depths, circuit, firstOccurrence, parent, disc, discInv, 0, 0, time);
    return {depths, circuit, firstOccurrence, parent, disc, discInv};
}



int main(){
    int n, i, j ,u, v, querysCnt, lca, L, R, x;
    while(true){
        cin >> n;
        if(n == 0) break;
        vector<vector<int>> T(n, vector<int>(0,0));
        map<pair<int,int>, bool> visEdge;
        for(i = 0 ; i < n-1 ; i++){
            cin >> u >> v;
            u--;v--;
            T[u].push_back(v);T[v].push_back(u);
            visEdge[{u,v}] = visEdge[{v,u}] = false;
        }


        vector<vector<int>> temp = getVals(T);
        vector<int> circuit = temp[1], depths = temp[0], firstOccurrence = temp[2], parent = temp[3], table, disc = temp[4], discInv = temp[5];
        for(i = 0 ; i < circuit.size() ; i++) table.push_back(disc[circuit[i]]);
        RMQ rmq = RMQ(table);


        cin >> querysCnt;
        while(querysCnt--){
            cin >> u >> v;
            u--;v--;
            L = min(firstOccurrence[u], firstOccurrence[v]); R = max(firstOccurrence[u], firstOccurrence[v]);
            lca = discInv[rmq.query(L, R)];
            //for(i = 0 ; i < circuit.size() ; i++) cout << circuit[i] << " ";
            //cout << endl;
            
            if(((depths[u]-depths[lca]) + (depths[v]-depths[lca]))%2 == 0){
                if(depths[u]>depths[v]) x = u;
                else x = v;
                for(i = 0 ; i < (((depths[u]-depths[lca]) + (depths[v]-depths[lca]))/2) ; i++) x = parent[x];
                cout << "The fleas meet at " << x+1 << "." << endl;
            }
            else{
                if(depths[u]>depths[v]) x = u;
                else x = v;
                for(i = 0 ; i < (((depths[u]-depths[lca]) + (depths[v]-depths[lca]))/2) ; i++) x = parent[x];
                cout << "The fleas jump forever between " << min(x, parent[x])+1 << " and " << max(x, parent[x])+1 << "." << endl;
            }

        }
    }
    return 0;
}
