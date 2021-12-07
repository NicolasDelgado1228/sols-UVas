#include <bits/stdc++.h>
using namespace std;

void insertUV(vector<vector<int>> &graph, string links, map<int, bool> &visited){
  links.append(",");
  int indicator = links.find("-"), node = stoi(links.substr(0, indicator)) - 1, j = indicator+1;
  visited[node] = false;
  vector<int> aux;
  for(int i = j ; i < links.length() ; i++)
    if(links[i] == ',' and i != j){
      aux.push_back(stoi(links.substr(j, i-j))-1);
      j = i+1;
    }

  graph.push_back(aux);
}

bool bfs(vector<vector<int>> graph, int nodeA, int nodeB, map<int, int> &path, map<int, bool> &visited){
  int node;
  bool found = false;
  queue<int> queue;
  queue.push(nodeA);
  visited[nodeA] = true;

  while(not queue.empty() and not found){
    node = queue.front();
    vector<int> adjacents = graph[node];

    for(int i = 0 ; i < adjacents.size() ; i++){
      if(not visited[adjacents[i]]){
        visited[adjacents[i]] = true;
        path[adjacents[i]] = node;
        queue.push(adjacents[i]);
        if(adjacents[i] == nodeB) found = true;
      }
    }
    queue.pop();
  }

  if(found) return true;
  else return false;
}


int main(){
  int nodes, queries, nodeA, nodeB;
  while(cin >> nodes){
    vector<vector<int>> graph;
    map<int, bool> visited;
    cout << "-----" << endl;

    for(int i = 0 ; i < nodes ; i++){
      string links;
      cin >> links;
      insertUV(graph, links, visited);
    }

    cin >> queries;
    for(int i = 0 ; i < queries ; i++){
      cin >> nodeA >> nodeB;
      nodeA--;nodeB--;
      map<int, int> path;
      map<int, bool> visitedTemp = visited;

      if(bfs(graph, nodeA, nodeB, path, visitedTemp)){
        vector<int> pathNodes;
        int net = nodeB;
        while(net != nodeA){
          pathNodes.push_back(net);
          net = path[net];
        }
        cout << nodeA+1;

        for(int j = pathNodes.size()-1 ; j >= 0 ; j--)
          cout << " " << pathNodes[j]+1;
        cout << endl;
      }
      else
        cout << "connection impossible" << endl;
    }
  }

  return 0;
}
