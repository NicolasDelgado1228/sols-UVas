#include <bits/stdc++.h>
using namespace std;

pair<bool, vector<int>> bfs(vector<vector<int>> &G, vector<vector<int>> &capEdge, vector<vector<int>> &flowEdge, vector<int> &flowNode, vector<int> &capNode, int s, int t){
    int n = G.size(), u, v;
    vector<int> parent(n, -1);
    vector<bool> visited(n, false);
    queue<int> q; q.push(s); visited[s] = true;

    while(not q.empty()){
        u = q.front(); q.pop();
        for(int i = 0 ; i < G[u].size() ; i++){
            v = G[u][i];
            if(not visited[v] and capEdge[u][v] - flowEdge[u][v] > 0 and ((v==s or v== t) or capNode[v] - flowNode[v] > 0)){
                parent[v] = u;
                visited[v] = true;
                q.push(v);
            }
        }
    }

    return {visited[t], parent};
}

int edmondKarp(vector<vector<int>> &G, vector<vector<int>> &capEdge, vector<vector<int>> &flowEdge, vector<int> &flowNode, vector<int> &capNode, int s, int t){
    int maxflowEdge = 0, newFlow, u, v;
    pair<bool, vector<int>> augPath = bfs(G, capEdge, flowEdge, flowNode, capNode, 0, t);

    while(augPath.first){
        vector<int> parent = augPath.second;
        newFlow = 100000000;
        for(v = t ; v != s ; v = parent[v]){
            u = parent[v];
            newFlow = min(newFlow, capEdge[u][v]-flowEdge[u][v]);
            if(v != t) newFlow = min(newFlow, capNode[v]-flowNode[v]);
        }
        maxflowEdge += newFlow;

        for(v = t ; v != s ; v = parent[v]){
            u = parent[v];
            flowEdge[u][v] += newFlow;
            flowEdge[v][u] -= newFlow;
            if(v != t) flowNode[v] += newFlow;
        }

        augPath = bfs(G, capEdge, flowEdge, flowNode, capNode, 0, t);
    }
    return maxflowEdge;
}


int main(){
    int n, m, u, v, i, j, c, t, temp;
    while(true){
        cin >> n >> m;
        if(n +m == 0) break;

        vector<vector<int>> G(n, vector<int>(0,0));
        vector<vector<int>> capEdge(n, vector<int>(n, 0)), flowEdge(n, vector<int>(n, 0));
        vector<int> capNode(n, 0), flowNode(n,0);
        for(i = 0 ; i < n-2; i++){
            cin >> u >> c; u--;
            capNode[u] = c;
        }
        for(i = 0 ; i < m ; i++){
            cin >> u >> v >> c; u--;v--;
            G[u].push_back(v);
            G[v].push_back(u);
            capEdge[v][u] = capEdge[u][v] = c;
        }




        cout << edmondKarp(G, capEdge, flowEdge, flowNode, capNode, 0, n-1) << endl;
    }
    return 0;
}
