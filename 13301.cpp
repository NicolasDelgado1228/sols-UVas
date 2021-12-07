#include <bits/stdc++.h>
using namespace std;

vector<int> tSort;

class dforest{
    public:
    int n, setsCnt;
    vector<int> rank;
    vector<int> parent;

    dforest(int n){
        this->n = setsCnt = n;
        for(int i = 0 ; i < n ; i++){
            rank.push_back(0);
            parent.push_back(i);
        }
    }

    void un(int a, int b){
        a = find(a);
        b = find(b);
        int rankA, rankB;
        if(a != b){
            rankA = rank[a];
            rankB = rank[b];
            if(rankA < rankB){
                parent[a] = b;
            }
            else{
                parent[b] = a;
                if(rankA == rankB) rank[a] += 1;
            }
        }
    }

    int find(int x){
        if(parent[x] == x)
            return x;
        else{
            return find(parent[x]);
        }
    }
};

void topoSort(vector<vector<int>> &G, vector<bool> &visited, int node){
    if(not visited[node]){
        visited[node] = true;
        vector<int> adjacents = G[node];

        for(int i = 0 ; i < adjacents.size() ; i++)
            topoSort(G, visited, adjacents[i]);
        tSort.push_back(node);
    }
}

void dfs(vector<vector<int>> &G, vector<bool> &visited, int node){
    if(not visited[node]){
        visited[node] = true;
        vector<int> adjacents = G[node];

        for(int i = 0 ; i < adjacents.size() ; i++)
            dfs(G, visited, adjacents[i]);
    }
}

int main(){
    int n, m, i, option, a, b, j, node, scc, last, num;

    while(cin >> n >> m){
        dforest forest(n);

        vector<pair<int,int>> links;

        for(i = 0 ; i < m ; i++){
            cin >> option;
            if(option == 1){
                cin >> a >> b;
                a--;b--;
                links.push_back(make_pair(a, b));
            }
            else{
                cin >> a >> b;
                a--;b--;
                forest.un(a, b);
                last = b;
                for(j = 2 ; j < option ; j++){
                    cin >> num;
                    num--;
                    forest.un(last, num);
                    last = num;
                }
            }
        }

        //build the abstract graph
        vector<bool> visited1(n, false);
        vector<bool> visited2(n, false);
        vector<vector<int>> G(n, vector<int>(0, 0));
        vector<vector<int>> G2(n, vector<int>(0, 0));
        for(i = 0 ; i < links.size() ; i++){
            G[forest.find(links[i].first)].push_back(forest.find(links[i].second));
            G2[forest.find(links[i].second)].push_back(forest.find(links[i].first));
        }

            
        
        tSort.clear();
        //assign the order
        for(i = 0 ; i < n ; i++){
            node = forest.find(i);
            if(not visited1[node]){
                topoSort(G, visited1, node);
            }
        }

        //count the scc
        scc = 0;
        for(i = tSort.size()-1 ; i >= 0 ; i--){
            node = forest.find(tSort[i]);
            if(not visited2[node]){
                dfs(G2, visited2, node);
                scc++;
            }
        }


        if(scc == 1) cout << "YES" << endl;
        else cout << "NO" << endl;


    }
    return 0;
}