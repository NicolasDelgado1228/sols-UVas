#include <bits/stdc++.h>
using namespace std;


vector<vector<int>> floydWarshall(vector<vector<int>> &G){
    int n = G.size();
    vector<vector<int>> dist(n, vector<int>(n, 100000000));
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < G[i].size() ; j++){
            dist[i][G[i][j]] = 1;
        }
        dist[i][i] = 0;
    }
    
               
        
    
    for(int k = 0 ; k < n ; k++)
        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < n ; j++){
                if(dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
                
    return dist;
            
}

int main(){
    int c = 1, a, b, n, i, total, v;
    bool exit, first;

    while(true){
        exit = false; first = true;
        n = -1;
        set<int> vertices;
        vector<pair<int,int>> edges;
        while(true){
            cin >> a >> b;
            if(a==0 and b == 0 and first) exit = true;
            if(a == 0 and b == 0) break;
            first = false;
            edges.push_back({a,b});
            vertices.insert(a);vertices.insert(b);
        }
        n = vertices.size();
        v = 0;
        map<int,int> conversor;
        set<int>::iterator it = vertices.begin();
        for(it ; it != vertices.end() ; it++) conversor[*it] = v++;
        if(exit) break;
        vector<vector<int>> G(n, vector<int>(0,0));
        for(i = 0 ; i < edges.size() ; i++){
            G[conversor[edges[i].first]].push_back(conversor[edges[i].second]);
        }
        vector<vector<int>> dist = floydWarshall(G);
        total = 0;
        for(int i = 0 ; i < dist.size() ; i++)
            for(int j = 0 ; j < dist[i].size() ; j++){
                if(i != j) total += dist[i][j];
            }
        printf("Case %d: average length between pages = %.3lf clicks\n", c++, (double)((double)total/(double)(n*(n-1))));
    }

    return 0;
}