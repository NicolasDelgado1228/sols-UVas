#include <bits/stdc++.h>
using namespace std;

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

    vector<int> getParents(){
        return parent;
    }
};

int main(){
    int n, m, i, a, b, relsCnt, casesCnt = 1;

    while(true){
        cin >> n >> m;
        if(n == 0 and m == 0) break;

        dforest forest(n);
        for(i = 0 ; i < m ; i++){
            cin >> a >> b;
            forest.un(a, b);
        }
        vector<int> parents = forest.getParents();
        relsCnt = 0;
        for(i = 0 ; i < parents.size() ; i++)
            if(parents[i] == i) relsCnt++;
        cout << "Case " << casesCnt++ << ": " << relsCnt << endl;
    }


    return 0;
}