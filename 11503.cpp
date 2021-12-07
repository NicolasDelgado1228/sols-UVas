#include <bits/stdc++.h>
using namespace std;


class dforest{
    public:
    int n, setsCnt;
    vector<int> rank;
    vector<int> parent;
    vector<int> size;

    dforest(int n){
        this->n = setsCnt = n;
        for(int i = 0 ; i < n ; i++){
            rank.push_back(0);
            size.push_back(1);
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
                size[b] += size[a];
                size[a] = 0;
                cout << size[b] << endl;
            }
            else{
                parent[b] = a;
                size[a] += size[b];
                size[b] = 0;
                cout << size[a] << endl;
                if(rankA == rankB) rank[a] += 1;
            }
        }
        else
            cout << size[a] << endl;
    }

    int find(int x){
        if(parent[x] == x)
            return x;
        else{
            return find(parent[x]);
        }
    }
};


int main(){
    int cases, n, i;

    cin >> cases;
    while(cases--){
        cin >> n;
        vector<pair<string,string>> relations;
        set<string> names;
        while(n--){
            string a, b;
            cin >> a >> b;
            relations.push_back({a, b});
            names.insert(a);
            names.insert(b);
        }
        map<string, int> conversor;
        set<string>::iterator it = names.begin();
        i = 0;
        for(it ; it != names.end() ; it++)
            conversor[*it] = i++;
        
        dforest forest(names.size());
        for(i = 0 ; i < relations.size() ; i++)
            forest.un(conversor[relations[i].first], conversor[relations[i].second]);
            
    }


    return 0;
}