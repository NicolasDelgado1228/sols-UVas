#include <bits/stdc++.h>
using namespace std;


vector<int> bfs(vector<vector<int>> &G){
	int n = G.size(), u, d;
	vector<int> depth(n, 0);
	queue<pair<int,int>> q;
	vector<bool> visited(n, false);
	visited[0] = true; q.push({0,0});

	while (not q.empty()){
		pair<int,int> temp = q.front();q.pop();
		u = temp.first; d = temp.second;
		depth[u] = d;

		for(int i = 0 ; i < G[u].size() ; i++){
			if(not visited[G[u][i]]){
				visited[G[u][i]] = true;
				q.push({G[u][i], d+1});
			}
		}
	}
	return depth;
}

vector<vector<int>> T;

void dfs(vector<vector<int>> &G, int u, vector<bool> &visited){
	visited[u] = true;
	for(int i = 0 ; i < G[u].size() ; i++){
		int v = G[u][i];
		if(not visited[v]){
			T[u].push_back(v);
			dfs(G, v, visited);
		}
	}
}

void buildRooted(vector<vector<int>> &G){
	int n = G.size();
	vector<bool> visited(n, false);
	T.clear();
	dfs(G, 0, visited);
}



vector<int> bfsFromList(vector<vector<int>> &G, vector<int> &parent){
	queue<int> q;
	int n = parent.size(), i = 1, j;
	vector<int> cost(n, 0);
	buildRooted(G);
	q.push(0);

	while (not q.empty()){
		
	}
}


int main(){
	int n, u, v;
	cin >> n;
	vector<vector<int>> G(n, vector<int>(0,0));
	for(int i = 0 ; i < n-1 ; i++){
		cin >> u >> v;
		u--;v--;
		G[u].push_back(v);G[v].push_back(u);
	}
	vector<int> per;
	for(int i = 0 ; i < n ; i++){
		cin >> u;
		per.push_back(--u);
	}
	vector<int> depth = bfs(G);
	if(solve(per, depth)) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}