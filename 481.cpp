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

int dp(int n, vi &A, vi& parent, vi& memo){
    int ans = memo[n], pos_ans;
    if(ans == -1){
        ans = 0;
        fore(i, 0, n){
            pos_ans = dp(i, A, parent, memo);
            if(pos_ans > ans and A[i] < A[n]){
                ans = pos_ans;
                parent[n] = i;
            }
        }
        ans++;
        memo[n] = ans;
    }
    return ans;
}

vi solve(vi& A){
    int N = len(A), mx = -1;
    vi memo(N, -1), parent(N, -1), ans;
    dp(N-1, A, parent, memo);
    fore(i, 0, N) mx = max(mx, memo[i]);
    bool found = false;
    for(int i = N-1 ; not found and i>=0; i--){
        if(memo[i] == mx){
            found = true;
            int u;
            for(u = i ; parent[u]!=-1 ; u = parent[u]) ans.pb(A[u]);
            ans.pb(A[u]);
        }
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main(){
    vi A;
    int x;
    while (cin >> x){
        A.pb(x);
    }
    vi ans = solve(A);
    cout << len(ans) << endl << "-" << endl;
    fore(i, 0, len(ans)) cout << ans[i] << endl;
    return 0;
}