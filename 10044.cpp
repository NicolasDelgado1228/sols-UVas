#include <bits/stdc++.h>
using namespace std;

void parser(string paper, map<string, vector<string>> &graph, map<string, bool> &visited, map<string, int> &dist){
  int i = 0, j;
  vector<string> strings;
  while(i < paper.size() and paper[i] == ' ') i++;
  j = i;
  while(i < paper.size()){
    if(paper[i] == '.' and (paper[i+1] == ',' or paper[i+1] == ':' or paper[i+1] == ' ')){
      string extract = paper.substr(j, i+1-j);
      strings.push_back(extract);
      visited[extract] = false;
      dist[extract] = -1;
      if(paper[i+1] == ':') break;
      i += 1;
      while(i < paper.size() and (paper[i] == ' ' or paper[i] == ',')) i++;
      j = i;
    }
    else
      i++;
  }

  for(i = 0 ; i < strings.size() ; i++)
    for(j = 0 ; j < strings.size() ; j++)
      graph[strings[i]].push_back(strings[j]);
}

int main(){
  int scenarios, p, n, sCnt = 1;
  cin >> scenarios;

  while(scenarios--){
    cout << "Scenario " << sCnt << endl;
    cin >> p >> n;
    map<string, vector<string>> graph;
    map<string, int> distances;
    map<string, bool> visited;
    cin.clear();
    cin.ignore();
    for(int i = 0 ; i < p ; i++){
      string paper;
      getline(cin, paper);
      parser(paper, graph, visited, distances);
    }

    //BFS saving the ditances from Erdos to all the nodes
    queue<string> queue;
    queue.push("Erdos, P.");
    distances["Erdos, P."] = 0;
    visited["Erdos, P."] = true;

    while(not queue.empty()){
      string node = queue.front();
      vector<string> adjacents = graph[node];

      for(int i = 0 ; i < adjacents.size() ; i++){
        if(not visited[adjacents[i]]){
          if(distances[adjacents[i]] == -1)
            distances[adjacents[i]] = 0;
          visited[adjacents[i]] = true;
          queue.push(adjacents[i]);
          distances[adjacents[i]] = distances[node] + 1;
        }
      }
      queue.pop();
    }

    for(int k = 0 ; k < n ; k++){
      string query;
      getline(cin, query);
      int i = 0;
      while(i < query.length() and query[i] == ' ') i++;
      string search = query.substr(i, query.length() - i);

      if(distances[search] == -1 or distances[search] == 0)
        cout << query << " infinity" << endl;
      else
        cout << query << " " << distances[search] << endl;
    }
    sCnt++;

  }


  return 0;
}
