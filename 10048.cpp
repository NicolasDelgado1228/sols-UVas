#include <bits/stdc++.h>
using namespace std;


class Edge{
    public:
    int nodeA, nodeB, weight;
    Edge(int na, int nb, int w){
        nodeA = na;nodeB = nb; weight = w;
    }
};

bool comp(Edge &e1, Edge &e2){
    return e1.weight < e2.weight;
}


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
        if(parent[x] == x) return x;
        else return find(parent[x]);
    }
};

bool found;
int maxVal;

void dfs(vector<vector<pair<int,int>>> &graph, vector<bool> &visited, int from, int to, int max){
    if(not visited[from] and not found){
        visited[from] = true;

        if(from == to){
            found = true;
            maxVal = max;
        }

        vector<pair<int,int>> adjacents = graph[from];
        for(int i = 0 ; i < adjacents.size() and not found ; i++){
            if(adjacents[i].second > max) max = adjacents[i].second;
            dfs(graph, visited, adjacents[i].first, to, max);
        }

    }
}

int main(){
    int n, m, q, i, nodeA, nodeB, weight, node, ans, c = 1, first = true;

    while(true){
        cin >> n >> m >> q;
        if(n == 0 and m == 0 and q == 0) break;
        if(not first) cout << endl;
        cout << "Case #" << c++ << endl;
        vector<Edge> graph;
        vector<vector<pair<int,int>>> mst(n, vector<pair<int,int>>(0, {0,0}));

        for(i = 0 ; i < m ; i++){
            cin >> nodeA >> nodeB >> weight;
            nodeA--;nodeB--;
            Edge edge(nodeA, nodeB, weight);
            graph.push_back(edge);
        }


        //Kruskal's algorithm for find and build the mst
        sort(graph.begin(), graph.end(), comp);
        dforest forest(n);
        for(i = 0 ; i < graph.size() ; i++){
            if(forest.find(graph[i].nodeA) != forest.find(graph[i].nodeB)){
                mst[graph[i].nodeA].push_back({graph[i].nodeB, graph[i].weight});
                mst[graph[i].nodeB].push_back({graph[i].nodeA, graph[i].weight});
                forest.un(graph[i].nodeA, graph[i].nodeB);
            }
        }



        //A bfs in the tree from source to destiny for each query
        for(i = 0 ; i < q ; i++){
            vector<bool> visited(n, false);
            cin >> nodeA >> nodeB;
            nodeA--;nodeB--;

            maxVal = -1;
            found = false;
            dfs(mst, visited, nodeA, nodeB, -1);
            if(found)
                cout << maxVal << endl;
            else
                cout << "no path" << endl;
        }
        first = false;

    }


    return 0;
}
