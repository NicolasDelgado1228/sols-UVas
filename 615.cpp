#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <stack>
using namespace std;

void dfs(map<int, vector<int>> links, map<int, int> &linksCnt, int node, map<int, bool> &visited, stack<int>* stack){
  linksCnt[node] = linksCnt[node]+1;
  if(not visited[node]){
    visited[node] = true;

    for(int i = 0 ; i < links[node].size() ; i++)
      if(stack->empty() or stack->top() != links[node][i]){
        stack->push(node);
        dfs(links, linksCnt, links[node][i], visited, stack);
        stack->pop();
      }


  }


}



int main(){
  map<int, vector<int>> links;
  map<int, int> linksCnt;
  map<int, bool> visited;
  set<int> nodes;
  stack<int> stack;
  vector<int> results;
  int root, leaf, cases = 1;

  while(true){
    bool tree = true;
    cin >> root >> leaf;
    if(root < 0 or leaf < 0) break;

    //Fill the map of links
    if(root != 0 and leaf != 0){
      nodes.insert(root);
      nodes.insert(leaf);
      visited[root] = false;
      visited[leaf] = false;
      linksCnt[root] = 0;
      linksCnt[leaf] = 0;

      if(root == leaf)
        tree = false;

      //See if it exists in the map, if not, add it, if it exists, modify the adyacency list
      if(links.find(root) == links.end()){
        vector<int> leafs = {leaf};
        links[root] = leafs;
      }
      else{
        vector<int> newLeafs = links[root];
        newLeafs.push_back(leaf);
        links[root] = newLeafs;
      }
      if(links.find(leaf) == links.end()){
        vector<int> leafs = {root};
        links[leaf] = leafs;
      }
      else{
        vector<int> newLeafs = links[leaf];
        newLeafs.push_back(root);
        links[leaf] = newLeafs;
      }
    }

    else{
      if(links.empty())
        cout << "Case " << cases << " is a tree." << endl;
      else if(not tree)
        cout << "Case " << cases << " is not a tree." << endl;
      else{
        root = (links.begin())->first;


        //Se hace el recorrido sobre el arbol
        dfs(links, linksCnt, root, visited, &stack);

        //Se verifica que haya llegado una sola vez a cada nodo
        map<int, int>::iterator it = linksCnt.begin();
        for(it ; it != linksCnt.end() ; it++)
          if(it->second != 1)
            tree = false;

        if(tree)
          cout << "Case " << cases << " is a tree." << endl;
        else
          cout << "Case " << cases << " is not a tree." << endl;
      }



      cases++;
      links.clear();
      linksCnt.clear();
      results.clear();
      nodes.clear();
      visited.clear();
    }
  }

  return 0;
}
