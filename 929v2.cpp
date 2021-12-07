#include <bits/stdc++.h>
using namespace std;

class Node{
public:
  int i;
  int j;
  int cost;
  Node(int i, int j, int cost){
    this->i = i;
    this->j = j;
    this->cost = cost;
  }
};

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

class comp{
public:
  bool operator()(const Node& p1, const Node& p2)const{
    return p1.cost > p2.cost;
  }
};

int main(){
  int cases, rows, columns,  i, j, newCost;
  cin >> cases;

  while(cases--){
    cin >> rows >> columns;
    int maze[rows][columns], costs[rows][columns], visited[rows][columns];

    for(i = 0 ; i < rows ; i++)
      for(j = 0 ; j < columns ; j++){
        scanf("%d", *(maze+i)+j);
        costs[i][j] = -1;
        visited[i][j] = 0;
      }

    priority_queue<Node, vector<Node>, comp> pq;
    Node ini(0,0,maze[0][0]);
    pq.push(ini);
    costs[ini.i][ini.j] = maze[ini.i][ini.j];

    while(not pq.empty()){
      Node node = pq.top();
      pq.pop();

      if(visited[node.i][node.j]) continue;
      else visited[node.i][node.j] = 1;

      //cout << node.i << " " << node.j << endl;
      for(i = 0 ; i < 4 ; i++)
        if(node.i + dy[i] >= 0 and node.i + dy[i] <= rows-1 and node.j + dx[i] >= 0 and node.j + dx[i] <= columns-1){
          Node adjacent(node.i+dy[i], node.j+dx[i], maze[node.i+dy[i]][node.j+dx[i]]);
          newCost = costs[node.i][node.j] + adjacent.cost;
          if(costs[adjacent.i][adjacent.j] == -1 or newCost < costs[adjacent.i][adjacent.j]){
            costs[adjacent.i][adjacent.j] = newCost;
            adjacent.cost = newCost;
            pq.push(adjacent);
          }
        }
    }
    cout << costs[rows-1][columns-1] << endl;

  }
  return 0;
}
