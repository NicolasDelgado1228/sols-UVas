#include <bits/stdc++.h>
using namespace std;

bool isDag;

void toposort(vector<vector<int>> &graph, vector<int> &visited, int node, stack<int> &order){
    if(visited[node] == 0 and isDag){
        visited[node] = 1;

        vector<int> adjacents = graph[node];
        for(int i = 0 ; i < adjacents.size() ; i++)
            toposort(graph, visited, adjacents[i], order);
        order.push(node);
        visited[node] = 2;
    }
    else if(visited[node] == 1){
        isDag = false;
        return;
    }
}

int main(){
    int n, m, i, a, b;

    while(true){
        cin >> n >> m;
        if(n == 0 and m == 0) break;

        vector<vector<int>> graph(n, vector<int>(0,0));
        vector<int> visited(n, 0);

        for(i = 0 ; i < m ; i++){
            cin >> a >> b;
            a--;b--;
            graph[a].push_back(b);
        }

        isDag = true;
        stack<int> order;
        for(i = 0 ; i < n ; i++)
            if(visited[i] == 0)
                toposort(graph, visited, i, order);
    

        if(isDag) 
            while(not order.empty()){
                cout << order.top() + 1 << endl;
                order.pop();
            }
        else
            cout << "IMPOSSIBLE" << endl;
        
    }


    return 0;
}