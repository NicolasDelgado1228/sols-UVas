#include <bits/stdc++.h>
using namespace std;

int diamNode[2];

void dfs(vector<vector<int>> &T, vector<bool> &visited, vector<int> &parent, int u, int depth, int *forbidden, int *newE){
    visited[u] = true;
    if (depth > diamNode[1]){diamNode[0]=u; diamNode[1] = depth;}

    for(int i = 0 ; i < T[u].size() ; i++){
        int v = T[u][i];
        if(not visited[v] and not ((u==forbidden[0] and v == forbidden[1]) or (v==forbidden[0] and u == forbidden[1]))){
            parent[v] = u;
            dfs(T, visited, parent, v, depth+1, forbidden, newE);
        }
    }
    if(u==newE[0] and not visited[newE[1]]){
        parent[newE[1]] = u;
        dfs(T, visited, parent, newE[1], depth+1, forbidden, newE);
    }
    else if(u==newE[1] and not visited[newE[0]]){
        parent[newE[0]] = u;
        dfs(T, visited, parent, newE[0], depth+1, forbidden, newE);
    }
}

vector <int> diameter(vector<vector<int>> &T, int* forbidden, int* newE, int v){
    int n = T.size(), i, u;
    vector<bool> visited(n, false); diamNode[0] = -1; diamNode[1] = -1;
    vector<int> parent(n, -1), diam;
    dfs(T, visited, parent, v, 0, forbidden, newE);
    for(i = 0 ; i < n ; i++) {visited[i] = false; parent[i] = -1;}
    u = diamNode[0]; diamNode[0] = diamNode[1] = -1;
    dfs(T, visited, parent, u, 0, forbidden, newE);

    u = diamNode[0];
    do{
        diam.push_back(u);
        u = parent[u];
    }while(u != -1);
    return diam;
}


int main(){
    int cases, n, i, j, u, v, forbidden[2], newE[2], ans, res, forAns[2], newAns[2], c1, c2;
    cin >> cases;
    while(cases--){
        cin >> n;
        vector<vector<int>> T(n, vector<int>(0,0));
        vector<pair<int,int>> edges;
        for(i = 0 ; i < n-1 ; i++){
            cin >> u >> v;
            u--;v--;
            T[u].push_back(v);T[v].push_back(u);
            edges.push_back({u, v});
        }
        forbidden[0] = forbidden[1] = newE[0] = newE[1] = -1;
        vector<int> diam = diameter(T, forbidden, newE, 0);
        ans = diam.size()-1;
        for(i = 0 ; i < diam.size()-1 ; i++){
            u = forbidden[0] = diam[i]; v = forbidden[1] = diam[i+1];
            newE[0] = newE[1] = -1;
            vector<int> diamT1 = diameter(T, forbidden, newE, u), diamT2 = diameter(T, forbidden, newE, v);
            c1 = diamT1[diamT1.size()/2]; c2 = diamT2[diamT2.size()/2];
            newE[0] = c1; newE[1] = c2;
            vector<int> newDiameter =  diameter(T, forbidden, newE, c1);
            int z = newDiameter.size();
            if(z-1 < ans){
                ans = z-1;
                forAns[0] = forbidden[0]; forAns[1] = forbidden[1];
                newAns[0] = newE[0]; newAns[1] = newE[1];
            }
        }

        cout << ans << endl;
        cout << forAns[0]+1 << " " << forAns[1]+1 << endl;
        cout << newAns[0]+1 << " " << newAns[1]+1 << endl;

    }

    return 0;
}
