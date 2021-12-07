#include <bits/stdc++.h>
using namespace std;


pair<bool, vector<int>> bfs(vector<vector<int>> &G, vector<vector<int>> &capacity, vector<vector<int>> &flow, int s, int t){
    int n = G.size(), v, u;
    vector<bool> visited(n, false);
    vector<int> parent(n, -1);
    queue<int> q;
    visited[s] = true; q.push(s);

    while(not q.empty()){
        u = q.front(); q.pop();

        for(int i = 0 ; i < G[u].size() ; i++){
            v = G[u][i];
            if(not visited[v] and capacity[u][v]-flow[u][v] > 0){
                visited[v] = true;
                parent[v] = u;
                q.push(v);
            }
        }
    }

    return {visited[t], parent};
}

int edmondKarp(vector<vector<int>> &G, vector<vector<int>> &capacity, vector<vector<int>> &flow, int s, int t){
    int maxFlow = 0, newFlow, u, v;
    pair<bool, vector<int>> temp = bfs(G, capacity, flow, s, t);

    while(temp.first){
        vector<int> parent = temp.second;
        newFlow = 100000000; v = t;
        while(parent[v] != -1){
            u = parent[v];
            newFlow = min(newFlow, capacity[u][v]-flow[u][v]);
            v = parent[v];
        }
        maxFlow += newFlow;

        v = t;
        while(parent[v] != -1){
            u = parent[v];
            flow[u][v] +=newFlow;
            flow[v][u] -=newFlow;
            v = parent[v];
        }

        temp = bfs(G, capacity, flow, s, t);
    }

    return maxFlow;
}

int main(){
    int n, s, t, c, i, j, u, v, cap, net = 1;

    while(true){
        cin >> n;
        if(n == 0) break;
        vector<vector<int>> G(n, vector<int>(0,0));
        vector<vector<int>> capacity(n, vector<int>(n, 0));
        vector<vector<int>> flow(n, vector<int>(n, 0));
        cin >> s >> t >> c;
        s--;t--;
        for(i = 0 ; i < c ; i++){
            cin >> u >> v >> cap;
            u--;v--;
            G[u].push_back(v);
            G[v].push_back(u);
            capacity[u][v] = capacity[v][u] += cap;
        }

        cout << "Network " << net++ << endl;
        cout << "The bandwidth is " << edmondKarp(G, capacity, flow, s, t) << "." << endl << endl;

    }
    return 0;
}
