#include <bits/stdc++.h>
using namespace std;

class comp{
public:
  bool operator()(const pair<int,int>& p1, const pair<int,int>& p2)const{
    return p1.second > p2.second;
  }
};

vector<int> dijkstra(vector<vector<pair<int,int>>> &G, int s){
    int n = G.size();
    vector<int> visited(n, false), costs(n, -1);
    priority_queue<pair<int,int>, vector<pair<int,int>>, comp> pq;
    costs[s] = 0;
    pq.push(make_pair(s, 0));

    while(not pq.empty()){
        pair<int,int> node = pq.top(); pq.pop();
        if(visited[node.first]) continue;
        else visited[node.first] = true;
        vector<pair<int,int>> adjacents = G[node.first];

        for(int i = 0 ; i < adjacents.size() ; i++){
            if(costs[adjacents[i].first] == -1 or node.second+adjacents[i].second < costs[adjacents[i].first]){
                costs[adjacents[i].first] = node.second+adjacents[i].second;
                pq.push(make_pair(adjacents[i].first, node.second+adjacents[i].second));
            }
        }
    }

    return costs;
}

int main(){


    return 0;
}
