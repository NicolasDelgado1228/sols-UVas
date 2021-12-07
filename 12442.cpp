#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> pi;
typedef vector<vector<int>> G;
#define fst first
#define snd second
#define pb(x) push_back(x)
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define len(vec) vec.size()

int solve(vector<vi> &G){
    int n = len(G);
}

int main(){
    int n, u, v, cases, c = 1;
    cin >> cases;
    while(cases--){
        cin >> n;
        vector<vi> G(n,vi());
        fore(i, 0, n){
            cin >> u >> v;
            u--;v--;
            G[u].pb(v);
        }
        cout << "Case " << c << ": " << solve(G) << endl;
    }
    return 0;
}