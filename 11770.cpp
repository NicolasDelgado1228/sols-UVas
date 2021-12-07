#include <bits/stdc++.h>
using namespace std;

void dfsTarjan(vector<vector<int>> &graph, vector<int> &low, vector<int> &time, int &timeCnt, int u, int &sccCnt, vector<bool> &inStack, stack<int> &stack, vector<vector<int>> &sccs){
    int v;
    time[u] = timeCnt++; low[u] = time[u]; inStack[u] = true; stack.push(u);

    vector<int> adjacents = graph[u];
    for (int i = 0 ; i < adjacents.size() ; i++){
        v = adjacents[i]; 
        if(time[v] == -1){
            dfsTarjan(graph, low, time, timeCnt, v, sccCnt, inStack, stack, sccs);
            low[u] = min(low[u], low[v]);
        }
        else if(inStack[v]) low[u] = min(low[u], time[v]);
    }

    if (time[u] == low[u]){
        vector<int> scc;
        sccCnt++;
        do{
            scc.push_back(stack.top()); stack.pop(); inStack[scc[scc.size()-1]] = false;
        }while (scc[scc.size()-1] != u);
        sccs.push_back(scc);
    }
}


int tarjan(vector<vector<int>> graph){
    int sccCnt = 0, n = graph.size(), timeCnt = 0;
    vector<int> low(n, -1), time(n, -1);
    vector<bool> inStack(n,0);
    stack<int> stack;
    vector<vector<int>> sccs;

    for (int i = 0 ; i < graph.size() ; i++)
        if(low[i] == -1)
           dfsTarjan(graph, low, time, timeCnt, i, sccCnt, inStack, stack, sccs);
    
    return sccCnt;
}

void dfs(vector<vector<int>> &graph, vector<bool> &visited, int u){
    visited[u] = true;
    for (int i = 0 ; i < graph[u].size() ; i++)
        if (not visited[graph[u][i]]){
            visited[graph[u][i]] = true;
            dfs(graph, visited, graph[u][i]);
        }
}

void topoDfs(vector<vector<int>> &graph, vector<bool> &visited, int u, stack<int> &toposort){
    visited[u] = true;
    vector<int> adjacents = graph[u];
    for (int i = 0 ; i < adjacents.size() ; i++){
        int v = adjacents[i];
        if (not visited[v]){
            visited[v] = true;
            topoDfs(graph, visited, v, toposort);
        }
    }
    toposort.push(u);
}

int solve(vector<vector<int>> graph){
    int n = graph.size(), areas = 0, u;
    vector<bool> visited(n, false); stack<int> toposort;
    for (int u = 0 ; u < graph.size() ; u++){
        if (not visited[u]){
            topoDfs(graph, visited, u, toposort);
        }
    }

    for (int i = 0 ; i < visited.size() ; i++) visited[i] = false;
    while (not toposort.empty()){
        u = toposort.top(); toposort.pop();
        if (not visited[u]){
            dfs(graph, visited, u);
            areas++;
        }
    }
    return areas;
}

int main(){
    int cases, n, m, i, a, b, caseCnt = 1;

    cin >> cases;
    while(cases--){
        cin >> n >> m;
        vector<vector<int>> graph(n, vector<int>(0,0));

        for(i = 0 ; i < m ; i++){
            cin >> a >> b;
            a--;b--;
            graph[a].push_back(b);
        }
        cout << "Case " << caseCnt++ << ": " << solve(graph) << endl;
    }
    return 0;
}