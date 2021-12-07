#include <bits/stdc++.h>
using namespace std;

pair<bool,vector<int>> bfs(vector<vector<int>> &G, vector<vector<int>>&flow, vector<vector<int>> &capacity, vector<int> &application, int s, int t){
    int n = G.size(), u;
    vector<int> parent(n, -1);
    vector<bool> visited(n, false);
    queue<int> q;

    q.push(s); visited[s] = true;

    while(not q.empty()){
        u = q.front();q.pop();
        for(int v = 0 ; v < G.size() ; v++){
            if(not visited[v] and G[u][v] == 1 and capacity[u][v]-flow[u][v] > 0){
                visited[v] = true;
                parent[v] = u;
                q.push(v);
            }
        }
    }

    return {visited[t], parent};
}

int edmondKarp(vector<vector<int>> &G, vector<vector<int>>&flow, vector<vector<int>> &capacity, vector<int> &application, int s, int t){
    pair<int,vector<int>> augPath = bfs(G, flow, capacity, application, s, t);
    int minFlow, u, v, maxFlow = 0;

    while(augPath.first){
        vector<int> parent = augPath.second;
        minFlow = 1000;
        for(v = t; v != s ; v = parent[v]){
            u = parent[v];
            minFlow = min(minFlow, capacity[u][v]-flow[u][v]);
        }
        for(v = t; v != s ; v = parent[v]){
            u = parent[v];
            flow[u][v] += minFlow;
            flow[v][u] -= minFlow;
            if(10 <= u and u <= 36 and 0 <= v and v <= 9) application[v] = u;

        }

        maxFlow += minFlow;

        augPath = bfs(G, flow, capacity, application, s, t);
    }

    return maxFlow;
}


int main(){
    int u, maxFlow, appsCnt = 0;
    string line;
    vector<vector<int>> G(39, vector<int>(39, 0));
    vector<vector<int>> flow(39, vector<int>(39, 0));
    vector<vector<int>> capacity(39, vector<int>(39, 0));
    vector<int> application(10, -1);

    map<char, int> conv;
    for(int i = 0 ; i <= 9 ; i++) conv[(char)i] = i;
    for(int i = 65 ; i <= 90 ; i++) conv[(char)i] = (i-65+10);
    while (getline(cin, line)) {
        if(line == ""){

            maxFlow = edmondKarp(G, flow, capacity, application, 37, 38);
            if(maxFlow != appsCnt) cout << "!" << endl;
            else{
                for(int i = 0 ; i < application.size(); i++){
                    if(application[i] == -1) cout << "_";
                    else cout << (char)(application[i]+55);
                }
                cout << endl;
            }
            for(int i = 0 ; i < G.size() ; i++)
                for(int j = 0 ; j < G.size() ; j++)
                    flow[i][j] = capacity[i][j] = G[i][j] = 0;
            for(int i = 0 ; i < 10 ; i++) application[i] = -1;
            appsCnt = 0;
        }
        else{
            u = conv[line[0]];
            appsCnt += line[1]-'0';
            capacity[37][u] = line[1]-'0';
            G[37][u] = G[u][37] = 1;
            for(int i = 3; i < line.length()-1 ; i++){
                G[u][line[i]-'0'] = G[line[i]-'0'][u] = capacity[u][line[i]-'0'] = 1;
                G[line[i]-'0'][38] = G[38][line[i]-'0'] = capacity[line[i]-'0'][38] = 1;
            }
        }
    }
    maxFlow = edmondKarp(G, flow, capacity, application, 37, 38);
    if(maxFlow != appsCnt) cout << "!" << endl;
    else{
        for(int i = 0 ; i < application.size(); i++){
            if(application[i] == -1) cout << "_";
            else cout << (char)(application[i]+55);
        }
        cout << endl;
    }
    return 0;
}
