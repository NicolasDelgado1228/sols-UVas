#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;


int main(){
  int nc, nodeA, nodeB, ttl, node, cases = 1;

  while(true){
    scanf("%d", &nc);
    if(nc == 0) break;

    //Construimos el grafo
    map<int, vector<int>> graph;
    map<int, bool> visited;
    set<int, greater<int>> nodes;
    for(int i = 0 ; i < nc ; i++){
      cin >> nodeA >> nodeB;
      graph[nodeA].push_back(nodeB);
      graph[nodeB].push_back(nodeA);
      nodes.insert(nodeA);
      nodes.insert(nodeB);
      visited[nodeA] = false;
      visited[nodeB] = false;
    }

    while(true){
      cin >> nodeA >> ttl;
      if(nodeA == 0 and ttl == 0) break;

      map<int, int> distance;
      set<int, greater<int>> visitedNodes;

      queue<int> queue;
      int counter;
      if(graph.find(nodeA) != graph.end()){
        visited[nodeA] = true;
        distance[nodeA] = 0;
        queue.push(nodeA);
        counter = nodes.size()-1;
      }
      else{
        counter = nodes.size();
      }


      while(not queue.empty() and distance[queue.front()] < ttl){
        node = queue.front();
        vector<int> adjacents = graph[node];

        for(int i = 0 ; i < adjacents.size() ; i++){
          if(not visited[adjacents[i]]){
            visited[adjacents[i]] = true;
            distance[adjacents[i]] = distance[node] + 1;
            if(distance[adjacents[i]] <= ttl)
              counter--;
            queue.push(adjacents[i]);
          }
        }
        queue.pop();
      }

      map<int, bool>::iterator it = visited.begin();
      for(it ; it != visited.end() ; it++)
        it->second = false;

      cout << "Case " << cases << ": " << counter << " nodes not reachable from node " << nodeA << " with TTL = " << ttl << "." << endl;
      cases++;
    }
  }


  return 0;
}
