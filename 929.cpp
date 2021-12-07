#include <bits/stdc++.h>
using namespace std;


class comp{
public:
  bool operator()(const pair<pair<int,int>,int>& p1, const pair<pair<int,int>,int>& p2)const{
    return p1.second > p2.second;
  }
};

vector<pair<pair<int,int>,int>> getAdjacents(int maze[][1000], int rows, int columns, int i, int j){
  vector<pair<pair<int,int>,int>> adjacents;
  pair<pair<int,int>, int> pos;

  if(i > 0){pos = make_pair(make_pair(i-1, j), maze[i-1][j]);adjacents.push_back(pos);}
  if(i < rows-1){pos = make_pair(make_pair(i+1, j), maze[i+1][j]);adjacents.push_back(pos);}
  if(j > 0){pos = make_pair(make_pair(i, j-1), maze[i][j-1]);adjacents.push_back(pos);}
  if(j < columns-1) {pos = make_pair(make_pair(i, j+1), maze[i][j+1]);adjacents.push_back(pos);}

  return adjacents;
}



int main(){
  int mazesCnt, rows, columns;
  cin >> mazesCnt;

  while(mazesCnt--){
    cin >> rows >> columns;
    int maze[1000][1000];
    map<pair<int,int>, int> costs;
    map<pair<int,int>, bool> visited;

    for(int i = 0 ; i < rows ; i++)
      for(int j = 0 ; j < columns ; j++){
        scanf("%d", *(maze+i)+j);
        costs[make_pair(i, j)] = -1;
        visited[make_pair(i, j)] = false;
      }

    pair<int,int> end = make_pair(rows-1,columns-1);

    priority_queue<pair<pair<int,int>,int>, vector<pair<pair<int,int>,int>>, comp> pq;
    pair<pair<int,int>,int> ini = make_pair(make_pair(0,0),maze[0][0]);
    pq.push(ini);
    costs[ini.first] = ini.second;

    //El problema puede estar en que meto muchas veces el mismo numero a la pila
    while(not pq.empty()){
      pair<pair<int,int>,int> node = pq.top();
      pq.pop();
      if(visited[node.first]) continue;
      else visited[node.first] = true;
      vector<pair<pair<int,int>,int>> adjacents = getAdjacents(maze, rows, columns, (node.first).first, (node.first).second);
      for(int i = 0 ; i < adjacents.size() ; i++){
        int cost = costs[node.first] + (adjacents[i]).second;
        if(costs[adjacents[i].first] == -1 or cost < costs[adjacents[i].first]){
          pair<int,int> aux = adjacents[i].first;
          costs[aux] = cost;
          pq.push(make_pair(aux, cost));
        }
      }
    }

    cout << costs[end] << endl;

  }


  return 0;
}
