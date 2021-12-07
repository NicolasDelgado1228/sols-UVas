#include <bits/stdc++.h>
using namespace std;



pair<int,vector<int>> bfs(vector<vector<int>> &G, vector<vector<int>> &capacity, vector<vector<int>> &flow, int s, int t){
    int n = G.size(), u, v, i;
    vector<bool> visited(n, false);
    queue<int> q; q.push(s); visited[s] = true;
    vector<int> parent(n, -1);

    while(not q.empty()){
        u = q.front();q.pop();
        for(i = G[u].size()-1 ; i >= 0 ; i--){
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

int edmondKarp(vector<vector<int>> &G, vector<vector<int>> &capacity, vector<vector<int>> &flow, vector<int> &problems, int problemsCnt, int s, int t){
    int maxFlow = 0, newFlow, u, v, i, j;
    pair<int,vector<int>> augPath = bfs(G, capacity, flow, s, t);
    while(augPath.first){
        vector<int> parent = augPath.second;
        newFlow = 100000000;
        for(v = t; v != s ; v = parent[v]){
            u = parent[v];
            newFlow = min(newFlow, capacity[u][v]-flow[u][v]);
        }
        maxFlow += newFlow;

        for(v = t; v != s ; v = parent[v]){
            u = parent[v];
            flow[u][v] += newFlow;
            flow[v][u] -= newFlow;
            if(u < problemsCnt and v >= problemsCnt) problems[u] = v;
        }

        augPath = bfs(G, capacity, flow, s, t);
    }

    return maxFlow;
}



int main(){
    int problemsCnt, categoriesCnt, n, s, t, i, u, v, j, cap, adCnt, total;

    while(true){
        cin >> categoriesCnt >> problemsCnt;
        if(problemsCnt == 0 and categoriesCnt == 0) break;
        n = problemsCnt+categoriesCnt+2;
        total = 0;
        vector<vector<int>> G(n, vector<int>(0,0));
        vector<vector<int>> capacity(n, vector<int>(n, 0));
        vector<vector<int>> flow(n, vector<int>(n, 0));
        vector<int> problems(problemsCnt, -1);
        s = problemsCnt+categoriesCnt;
        t = s+1;
        vector<int> capacities;
        for(i = 0 ; i < categoriesCnt ; i++){
            cin >> cap;
            capacities.push_back(cap);
            total += cap;
        }
        for(u = 0 ; u < problemsCnt ; u++){
            G[s].push_back(u);
            G[u].push_back(s);
            capacity[s][u] = capacity[u][s] = 1;
            cin >> adCnt;
            for(i = 0 ; i < adCnt ; i++){
                cin >> v;v--;
                v+=problemsCnt;
                G[u].push_back(v);
                G[v].push_back(u);
                capacity[v][u] = capacity[u][v] = 1;
            }
        }
        for(i = 0 ; i < categoriesCnt ; i++){
            cap = capacities[i];
            u = problemsCnt+i;
            G[u].push_back(t);
            G[t].push_back(u);
            capacity[t][u] = capacity[u][t] = cap;
        }

        if(edmondKarp(G, capacity, flow, problems, problemsCnt, s, t) != total) cout << 0 << endl;
        else{
            cout << 1 << endl;
            vector<vector<int>> ans(categoriesCnt, vector<int>(0,0));
            for(i = 0 ; i < problems.size() ; i++){
                if(problems[i] != -1){
                    ans[problems[i]-problemsCnt].push_back(i);
                }
            }
            for(i=0;i < ans.size() ; i++){
                cout << ans[i][0]+1;
                for(j = 1 ; j < ans[i].size() ; j++){
                    cout << " " << ans[i][j]+1;
                }
                cout << endl;
            }
        }

    }
    return 0;
}
