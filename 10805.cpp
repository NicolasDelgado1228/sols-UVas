#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> floydwarshall(vector<vector<int>> &G){
    int n = G.size(), i, j, k;
    vector<vector<int>> dist(n, vector<int>(n, 10000));
    for(i=0; i < n ; i++){
        for(j = 0 ; j < n ; j++){
            dist[i][j] = G[i][j];
            dist[j][i] = G[j][i];
        }
        dist[i][i] = 0;
    }

    for(k=0;k<n;k++)
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                if(dist[i][k]+dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k]+dist[k][j];
    return dist;

}
class comp{
public:
  bool operator()(const Node& p1, const Node& p2)const{
    return p1.cost > p2.cost;
  }
};

int main(){
    int cases, n, m, i, j, u, v, size, max1, max2;
    cin >> cases;

    while(cases--){
        cin >> n >> m;
        vector<vector<int>> G(n+m, vector<int>(n+m, 10000));
        size = n;
        for(i = 0 ; i < m ; i++){
            cin >> u >> v;
            G[u][size] = 1;
            G[size][u] = 1;
            G[v][size] = 1;
            G[size][v] = 1;
            size++;
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, comp> pq;
        vector<vector<int>> dist = floydwarshall(G);
        max1 = max2 = -1;
        for(i = 0 ; i < n ; i++){
            for(j = 0 ; j < n ; j++){
                if(dist[i][j] != 10000) priority_queue.push(dist[i][j]);
            }
        }
    }


    return 0;
}
