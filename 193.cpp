#include <bits/stdc++.h>
using namespace std;

vector<int> nodes;
vector<bool> visitedAux;
int maxNodes;

bool invariant(vector<vector<int>> G, int node, vector<bool> colors){
    vector<int> adjacents = G[node];
    for(int i = 0 ; i < adjacents.size() ; i++)
        if(colors[adjacents[i]] == false) return false;
    return true;
}

void solve(vector<vector<int>> G, vector<int> nodesAc, int nodesCnt, vector<bool> colors, int i){
    if(nodesCnt > maxNodes){
        maxNodes = nodesCnt;
        nodes.clear();
        nodes = nodesAc;
    }

    if(i == colors.size()) return;

    //Not colored in i
    solve(G, nodesAc, nodesCnt, colors, i+1);
    
    //Colored in i
    if(invariant(G, i, colors)){
        vector<int> auxNodesAc = nodesAc;
        vector<bool> auxColors = colors;  
        auxColors[i] = false;
        auxNodesAc.push_back(i);
        solve(G, auxNodesAc, nodesCnt+1, auxColors, i+1);
    }
    

}

int main(){
    int graphsCnt, n, edges, a, b;
    cin >> graphsCnt;

    while(graphsCnt--){
        cin >> n >> edges;

        vector<vector<int>> G;
        for(int i = 0 ; i < n ; i++){
            vector<int> aux;
            G.push_back(aux);
        }

        while(edges--){
            cin >> a >> b;
            a--;b--;
            G[a].push_back(b);
            G[b].push_back(a);
        }

        visitedAux.clear();
        for(int i = 0 ; i < 101 ; i++) visitedAux.push_back(false);
        nodes.clear();
        vector<int> aux;
        maxNodes = 0;

        
        vector<bool> colors;
        for(int i = 0 ; i < n ; i++) colors.push_back(true);
        solve(G, aux, 0, colors, 0);

        cout << maxNodes << endl;
        cout << nodes[0]+1;
        for(int i = 1 ; i < nodes.size() ; i++)
            cout << " " << nodes[i]+1;
        cout << endl;
        
    }

    return 0;
}
