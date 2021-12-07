#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> v[10001];
int n, m, visit[10001], com[10001], t;
int dfs(int x, int p){
	int vx = visit[x] = ++t;
	com[x] = 1;
	for(int i = 0; i < v[x].size(); i++){
		int y = v[x][i];
		if(y == p) continue;
		if(visit[y]){
			vx = min(vx, visit[y]);
		}
		else{
			int vy = dfs(y, x);
			vx = min(vx, vy);
			if(vy >= visit[x])
				com[x]++;
		}
	}
	return vx;
}
bool cmp(const pair<int, int> A, const pair<int, int> B) {
	if(A.second > B.second)
		return true;
	if(A.second == B.second && A.first < B.first)
		return true;
	return false;
}
int main(){
	while(cin >> n >> m, n+m){
		memset(visit, 0, sizeof(visit));
		for(int i = 0; i < n; i++)
			v[i].clear();
		int a, b;
		while(cin >> a >> b, a+b > 0){
			v[a].push_back(b);
			v[b].push_back(a);
		}
		dfs(0, 0);
		com[0]--;
		vector<pair<int, int> > ct;
		for(int i = 0; i < n; i++)
			ct.push_back(make_pair(i, com[i]));
		sort(ct.begin(), ct.end(), cmp);
		for(int i = 0; i < m; i++)
			printf("%d %d\n", ct[i].first, ct[i].second);
		putchar(10);
	}
	return 0;
}