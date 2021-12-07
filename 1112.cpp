#include <bits/stdc++.h>
using namespace std;

class comp{
public:
  bool operator()(const pair<int,int>& p1, const pair<int,int>& p2)const{
    return p1.second > p2.second;
  }
};


vector<int> dijkstra(vector<vector<pair<int,int>>> &G, int u){
    int n = G.size(), v, w, i;
    vector<int> visited(n, false), cost(n, 10000000);
    priority_queue<pair<int,int>, vector<pair<int,int>>, comp> pq;
    cost[u] = 0;  pq.push({u,0});

    while(not pq.empty()){
        pair<int,int> edge = pq.top(); pq.pop();
        u = edge.first; w = edge.second;
        if(not visited[u]){
            visited[u] = true;
            vector<pair<int,int>> adjacents = G[u];

            for(i = 0 ; i < adjacents.size() ; i++){
                edge = adjacents[i]; v = edge.first; w = edge.second;
                if(cost[u]+w < cost[v]){
                    cost[v] = cost[u]+w;
                    pq.push({v, cost[v]});
                }
            }
        }
    }

    return cost;
}



int main(){
    int cases, i, j, t, totalTime, s, n, m, u, v, w;
    bool first = true;
    cin >> cases;
    while(cases--){
        cin >> n >> t >> totalTime >> m;
        t--;
        vector<vector<pair<int,int>>> G(n, vector<pair<int,int>>(0,{-1,-1}));
        for(i = 0 ; i < m ; i++){
            cin >> u >> v >> w;
            u--;v--;
            G[u].push_back({v,w});
        }

        if(not first) cout << endl;
        first = false;
        int ans = 0;
        for(u = 0 ; u < n ; u++){
            vector<int> cost = dijkstra(G, u);
            if(cost[t] <= totalTime) ans++;

        }
        cout << ans << endl;
    }
    return 0;
}
