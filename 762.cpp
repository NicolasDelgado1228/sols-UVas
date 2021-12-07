#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <string>
using namespace std;
/*
void insertLink(map<string, vector<string>> &graph, string nodeA, string nodeB){
  if(graph.find(nodeA) != graph.end()){
    vector<string> aux = graph[nodeA];
    aux.push_back(nodeB);
    graph[nodeA] = aux;
  }
  else{
    vector<string> adj = {nodeB};
    graph[nodeA] = adj;
  }
}
*/
int main(){
  int linksCnt;
  bool first = true;

  while(cin >> linksCnt){
    map<string, vector<string>> graph;
    map<string, bool> visited;
    map<string, string> path;
    bool found = false;

    if(not first) cout << endl;

    //Input
    for(int i = 0 ; i < linksCnt ; i++){
      string nodeA, nodeB;

      cin >> nodeA >> nodeB;
      graph[nodeA].push_back(nodeB);
      graph[nodeB].push_back(nodeA);
      visited[nodeA] = false;
      visited[nodeB] = false;
    }

    string nodeA, nodeB;
    cin >> nodeA >> nodeB;

    //search with BFS

    queue<string> queue;
    queue.push(nodeA);
    visited[nodeA] = true;
    cout << nodeA << endl;

    while(not queue.empty()){
      string node = queue.front();
      vector<string> adjacents = graph[node];

      for(int i = 0 ; i < adjacents.size() ; i++){
        if(not visited[adjacents[i]]){
          path[adjacents[i]] = node;
          visited[adjacents[i]] = true;

          if(adjacents[i] == nodeB){
            found = true;
            break;
          }

          queue.push(adjacents[i]);
        }
      }

      if(found) break;

      queue.pop();
    }


    //Print the route

    if(not found)
      cout << "No route" << endl;
    else{
      vector<string> route;
      string city = nodeB;

      while(city != nodeA){
        route.push_back(city);
        city = path[city];
      }
      route.push_back(nodeA);



      for(int i = route.size()-1 ; i > 0 ; i--)
        cout << route[i] << " " << route[i-1] << endl;

    }


    first = false;
  }


  return 0;
}
