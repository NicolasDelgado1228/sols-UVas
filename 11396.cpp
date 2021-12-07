#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, a, b, edgesCnt, visitedEd, i;
    bool allUnv;

    while(true){
        cin >> n;
        if(n == 0) break;
        vector<vector<int>> G(n, vector<int>(0, 0));
        vector<bool> visited(n, false);
        map<pair<int,int>, bool> visitedEdges;
        edgesCnt = visitedEd = 0;


        cin >> a >> b;
        do{
            a--;b--;
            G[a].push_back(b);
            G[b].push_back(a);
            visitedEdges[{a, b}] = false;
            visitedEdges[{b, a}] = false;
            cin >> a >> b;
            edgesCnt++;
        }while(a != 0 and b != 0);

        if(edgesCnt % 3 != 0){
            cout << "NO" << endl;
            continue;
        }
        
        queue<int> queue;
        queue.push(0);
        
        while(not queue.empty()){
            int node = queue.front();
            queue.pop();

            if(visited[node]) continue;
            else visited[node] = true;

            allUnv = true;
            vector<int> adjacents = G[node];
            for(i = 0 ; i < adjacents.size() ; i++){
                if(visitedEdges[{node, adjacents[i]}])
                    allUnv = false;
                queue.push(adjacents[i]);
            }

            if(allUnv){
                edgesCnt -= 3;
                for(i = 0 ; i < adjacents.size() ; i++){
                    visitedEdges[{node, adjacents[i]}] = true;
                    visitedEdges[{adjacents[i], node}] = true;
                }
            }
        }

        if(edgesCnt == 0) cout << "YES" << endl;
        else cout << "NO" << endl;
    }


    return 0;
}