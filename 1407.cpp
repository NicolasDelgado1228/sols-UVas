#include<bits/stdc++.h>
using namespace std;

int main(){
  int n, b, a, c, node, queries, query, cases = 1, visitedCnt, maxDist;

  while (1) {
    cin >> n;
    if(n == 0) break;
    map<int, vector<pair<int, int>>> tree;   //[[(1, 2), (2, 1)], [(3, 1), (4, 5)]]
    map<int, bool> visited;

    //Create the tree
    for(int i = 0 ; i < n-1 ; i++){
      cin >> b >> a >> c;
      tree[a].push_back(make_pair(b, c));
      tree[b].push_back(make_pair(a, c));
      visited[b] = visited[a] = false;
    }


    cin >> queries;
    while(queries--){
      visitedCnt = 0;
      cin >> query;


    }


    cases++;
  }


  return 0;
}
