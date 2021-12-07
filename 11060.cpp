#include <bits/stdc++.h>
using namespace std;

class comp{
public:
  bool operator()(const int& p1, const int& p2)const{
    return p1 > p2;
  }
};



vector<int> toposort(vector<vector<int>> &graph, vector<int> &indegrees, vector<bool> &visited){
    vector<int> toposort;

    priority_queue<int, vector<int>, comp> queue;
    for(int i = 0 ; i < indegrees.size() ; i++)
        if(indegrees[i] == 0)
            queue.push(i);
    
    while(not queue.empty()){
        int node = queue.top();
        queue.pop();
        if(visited[node]) continue;
        visited[node] = true;
        toposort.push_back(node);

        vector<int> adjacents = graph[node];
        for(int i = 0 ; i < adjacents.size() ; i++){
            indegrees[adjacents[i]] -= 1;
            if(indegrees[adjacents[i]] == 0){
                queue.push(adjacents[i]);
            }
        }
    }

    return toposort;
}

int main(){
    int n, m, i, c = 1;

    while(cin >> n){
        vector<string> beverages;
        vector<int> indegrees(n, 0);
        for(i = 0 ; i < n ; i++){
             string beverage;
             cin >> beverage;
             beverages.push_back(beverage);
        }

        map<string, int> conversor;
        for(i = 0 ; i < beverages.size() ; i++)
            conversor[beverages[i]] = i;
        
        vector<vector<int>> graph(n, vector<int>(0, 0));
        vector<bool> visited(n, false);

        cin >> m;
        for(i = 0 ; i < m ; i++){
            string b1, b2;
            cin >> b1 >> b2;
            graph[conversor[b1]].push_back(conversor[b2]);
            indegrees[conversor[b2]] += 1;
        }

        vector<int> topo = toposort(graph, indegrees, visited);
        

        cout << "Case #" << c++ << ": Dilbert should drink beverages in this order:";
        for(i = 0 ; i < topo.size() ; i++)
            cout << " " << beverages[topo[i]];
        
        cout << "." << endl << endl;
    }


    return 0;
}