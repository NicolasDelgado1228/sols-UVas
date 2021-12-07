#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> eulerCirPath;

void eulerCircuit(vector<vector<int>> &graph, vector<vector<int>> &visited, int node, int &n, vector<bool> &visNode){
    if(not visNode[node]){
        n--;
        visNode[node] = true;
    }
    vector<int> adjacents = graph[node];

    for(int i = 0 ; i < adjacents.size() ; i++){
        if(visited[node][adjacents[i]] > 0){

            visited[node][adjacents[i]]--;
            visited[adjacents[i]][node]--;
            eulerCircuit(graph, visited, adjacents[i], n, visNode);

            eulerCirPath.push_back({node, adjacents[i]});

        }
    }
}



int main(){
    int cases, a, b, edges, i, n, start;
    bool isEulerian, first = true;


    cin >> cases;
    for(int c = 1 ; c <= cases ; c++){
        vector<vector<int>> graph(50, vector<int>(0,0));
        vector<bool> isNode(50, false);
        vector<int> degree(50, 0);
        vector<vector<int>> visited(50, vector<int>(50, 0));
        vector<bool> visNode(50, false);
        n = 0;

        if(not first) cout << endl;

        start = -1;
        cin >> edges;
        for(i = 0 ; i < edges ; i++){
            cin >> a >> b;
            if(start == -1) start = a-1;
            a--;b--;
            graph[a].push_back(b);
            graph[b].push_back(a);
            if(not isNode[a]){
                n++;
                isNode[a] = true;
            }
            if(not isNode[b]){
                n++;
                isNode[b] = true;
            }
            degree[a]++; degree[b]++;
            visited[a][b]++;
            visited[b][a]++;
            visNode[a] = visNode[b] = false;
        }

        //check if is an eulerian circuit
        isEulerian = true;
        for(i = 0 ; i < 50 and isEulerian ; i++)
            if(isNode[i] and degree[i]%2 != 0)
                isEulerian = false;


        cout << "Case #" << c << endl;
        if(not isEulerian)
            cout << "some beads may be lost" << endl;
        else{
            eulerCirPath.clear();
            eulerCircuit(graph, visited, start, n, visNode);

            if(not n)
                for(i = 0 ; i < eulerCirPath.size() ; i++)
                    cout << eulerCirPath[i].second + 1 << " " << eulerCirPath[i].first + 1 << endl;
            else
                cout << "some beads may be lost" << endl;
        }
        first = false;
    }

    return 0;
}
