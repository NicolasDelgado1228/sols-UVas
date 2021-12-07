#include<bits/stdc++.h>
using namespace std;

int bfs(vector<vector<int>>&G, vector<int> &color, int n, int s){
    queue<pair<int,int>> q;
    q.push({s,1}); color[s] = 1;
    int pos = 1, ans;
    vector<int> visited;
    while(not q.empty() and pos){
        pair<int,int> node = q.front();q.pop();
        int u = node.first, c = node.second;
        visited.push_back(u);
        for(int v: G[u]){
            if(color[v] == 0){
                color[v] = c==1?2:1;
                q.push({v,color[v]});
            }
            else if(color[v]==c) pos=0;
        }
    }
    int blacks=0,whites=0;
    for(int u: visited){
        if(color[u]==1) whites++;
        else blacks++;
    }
    if(pos==0) ans=-1;
    else{
        if(min(blacks,whites)==0) ans = max(blacks,whites);
        else ans = min(blacks,whites);
    }
    return ans;
}

int solve(vector<vector<int>>&G, int n){
    int blacks=0,whites=0,ans = 0, temp;
    vector<int> color(n,0);
    bool pos = true;
    for(int u = 0 ; u < n && pos; u++)
        if(color[u] == 0){
            temp = bfs(G, color,n,u);
            if(temp==-1)ans=-1,pos=false;
            else ans+=temp;
        }
    return ans;
}

int main(){
    int n,m,u,v,cases;
    cin >> cases;
    while(cases--){
        cin >> n >> m;
        vector<vector<int>> G(n,vector<int>());
        for(int i = 0 ; i < m ; i++){
            cin >> u >> v;
            G[u].push_back(v); G[v].push_back(u);
        }
        cout << solve(G, n) << endl;
    }
    return 0;
}