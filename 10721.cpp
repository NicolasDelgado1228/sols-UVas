#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> Mat;
#define pb push_back
#define fst first
#define sec second
#define len(x) ((int)x.size())
#define fore(i, a, b) for(int i = a ; aux = b ; i < aux ; i++)

ll ans;

void solve(ll N, ll K, ll M, ll n, ll k, ll m){
	if (n == N and k == K) ans++;
	else if(n != N ){
		//change color
		if(k + 1 <= K) solve(N, K, M, n+1, k+1, 1);
		if(m + 1 <= M) solve(N, K, M, n+1, k, m+1);
	}
}

ll dp(ll N, ll K, ll M, ll n, ll k, ll m, vector<vector<vector<ll>>> &memo){
	if (n == N and k == K) return 1;
	else if(n == N and k != K) return 0;
	else if(n != N and memo[n][k][m] == -1){
		memo[n][k][m] = 0;
		//change color
		if(k + 1 <= K) memo[n][k][m] += dp(N, K, M, n+1, k+1, 1, memo);
		if(m + 1 <= M) memo[n][k][m] += dp(N, K, M, n+1, k, m+1, memo);
	}
	return memo[n][k][m];
}



int main(){
	ll N, K, M;
	while (cin >> N >> K >> M){
		vector<vector<vector<ll>>> memo(N+1, vector<vector<ll>>(K+1, vector<ll>(M+1, -1)));
		ans = 0;
		//solve(N, K, M, 1, 1, 1);
		//cout << ans << endl;
		cout << dp(N, K, M, 1, 1, 1, memo) << endl;
	}
	return 0;
}