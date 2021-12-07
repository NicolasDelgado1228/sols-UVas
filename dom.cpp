#include <bits/stdc++.h>
#ifdef DEMETRIO
#define deb(...) fprintf(stderr,__VA_ARGS__)
#define deb1(x) cerr << #x << " = " << x << endl
#else
#define deb(...) 0
#define deb1(x) 0
#endif
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define len(t) t.length()
#define SZ(x) ((int)x.size())
using namespace std;
typedef long long ll;
typedef vector<int> vi;

vi toposort;

void dfs(vector<vector<int>> &G, vector<bool> &visited, int u){
    visited[u] = true;
    fore(i, 0, G[u].size())
        if(not visited[G[u][i]])
            dfs(G, visited, G[u][i]);
    toposort.pb(u);
}

int solve(vector<vector<int>> &G){
    int n = G.size(), ans = 0;
    vector<bool> visited(n, false);
    toposort.clear();
    fore(i, 0, n)
        if(not visited[i]){
            dfs(G, visited, i);
            
        }
            
    fore(i, 0, n) visited[i] = false;
    for(int i = n-1 ; i >= 0 ; i--){
        int u = toposort[i];
        if(not visited[u]){
            dfs(G, visited, u);
            ans++;
        }
    }
    return ans;
}

int main(){
    int cases, n, m, u, v;
    cin >> cases;
    while(cases--){
        cin >> n >> m;
        vector<vector<int>> G(n, vector<int>());
        fore(i, 0, m){
            cin >> u >> v;
            u--;v--;
            G[u].pb(v);
        }
        cout << solve(G) << endl;
    }
    return 0;
}