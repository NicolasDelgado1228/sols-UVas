#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <string>
using namespace std;

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

map<string, string> bfs(map<string, vector<string>> graph, string nodeA, string nodeB){
  map<string, bool> visited;
  map<string, vector<string>>::iterator it = graph.begin();

  for(it ; it != graph.end() ; it++)
    visited[it->first] = false;

  queue<string> queue;
  map<string, string> paths;
  queue.push(nodeA);
  visited[nodeA] = true;

  bool found = false;
  string path;

  while(not queue.empty()){
    string node = queue.front();
    vector<string> adjacents = graph[node];

    for(int i =  0 ; i < adjacents.size() ; i++){
      if(not visited[adjacents[i]]){

        if(adjacents[i] == nodeB){
          path = node;
          found = true;
          break;
        }
        queue.push(adjacents[i]);
        visited[adjacents[i]] = true;
        paths[adjacents[i]] = node;

      }
    }

    if(found) break;

    queue.pop();
  }

  if(found){
    paths[nodeB] = path;
    return paths;
  }
  else{
    map<string,string> notFound = {{"No route", "No route"}};
    return notFound;
  }

}

int main(){
  int linksCnt;
  bool first = true;

  while(cin >> linksCnt){
    map<string, vector<string>> graph;

    if(not first) cout << endl;

    for(int i = 0 ; i < linksCnt ; i++){
      string nodeA, nodeB;

      cin >> nodeA >> nodeB;
      insertLink(graph, nodeA, nodeB);
      insertLink(graph, nodeB, nodeA);
    }

    string nodeA, nodeB;
    cin >> nodeA >> nodeB;

    map<string, string> path = bfs(graph, nodeA, nodeB);

    if(path.find("No route") != path.end())
      cout << "No route" << endl;
    else{
      vector<string> cities;
      string city = nodeB;
      while(path.find(city) != path.end()){
        cities.push_back(city);
        city = path[city];
      }
      cities.push_back(nodeA);

      for(int i = cities.size()-1 ; i > 0 ; i--)
        cout << cities[i] << " " << cities[i-1] << endl;

    }

    first = false;

  }


  return 0;
}
