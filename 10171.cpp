#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> floydWarshall(vector<vector<pair<int,int>>> &G, map<pair<char,char>, char> &types, char type, map<int,char> &intToChar){
    int n = G.size(), i, j, k;
    vector<vector<int>> dist(n, vector<int>(n,1000));
    for(i = 0 ; i < n ; i++){
        for(j = 0 ; j < G[i].size() ; j++){
            if(types[{intToChar[i], intToChar[G[i][j].first]}] == type) dist[i][G[i][j].first] = G[i][j].second;
        }
        dist[i][i] = 0;
    }

    for(k = 0 ; k < n ; k++)
        for(i = 0 ; i < n ; i++)
            for(j = 0 ; j < n ; j++){
                char a = intToChar[i], b = intToChar[j], c = intToChar[k];
                if(types.find({a,c}) != types.end() and types.find({c,b}) != types.end() and types.find({a,b}) != types.end() and types[{a,c}]==type and types[{c,b}]==type and types[{a,b}]==type){
                    if(dist[i][k] + dist[k][j] < dist[i][j])
                        dist[i][j] = dist[i][k] + dist[k][j];
                    
                }
                    
            }
    return dist;
}

int main(){
    int i, edgesCnt, j, weight, n, young, elder, ans;
    while(true){
        char from, to;
        set<char> vertices;
        map<pair<char,char>, int> weights;
        map<pair<char,char>, char> types;
        cin >> edgesCnt;
        if(edgesCnt == 0) break;
        for(i = 0 ; i < edgesCnt ; i++){
            char type, dir, u, v;
            cin >> type >> dir >> u >> v; cin >> weight;
            vertices.insert(u); vertices.insert(v);
            weights[{u,v}] = weight;
            types[{u,v}] = type;
            types[{u,u}] = types[{v,v}] = 'x';
            if(dir == 'B'){
                weights[{v,u}] = weight;
                types[{v,u}] = type;
            }
        }
        n = vertices.size(); i = 0;
        map<char,int> charToInt; map<int,char> intToChar;
        set<char>::iterator it = vertices.begin();
        for(it ; it != vertices.end() ; it++){
            charToInt[*it] = i;
            intToChar[i++] = *it;
        }
        vector<vector<pair<int,int>>> G(n, vector<pair<int,int>>(0,{0,0}));
        map<pair<char,char>, int>::iterator it1 = weights.begin();
        for(it1 ; it1 != weights.end() ; it1++){
            pair<char,char> node = it1->first; weight = it1->second;
            G[charToInt[node.first]].push_back({charToInt[node.second], weight});
        }
        cin >> from >> to;
        young = charToInt[from]; elder = charToInt[to];


        vector<vector<int>> distsYoung = floydWarshall(G, types, 'Y', intToChar);
        vector<vector<int>> distsElder = floydWarshall(G, types, 'M', intToChar);
        
        

        ans = 1000;
        vector<char> answers;
        for(i = 0 ; i < n ; i++){
            char place = intToChar[i];
            if(types.find({from, place}) != types.end() and types.find({to, place}) != types.end() and distsYoung[young][i]+distsElder[elder][i] == ans)
                answers.push_back(place);
            else if(types.find({from, place}) != types.end() and types.find({to, place}) != types.end() and distsYoung[young][i]+distsElder[elder][i] < ans){
                ans = distsYoung[young][i]+distsElder[elder][i];
                answers.clear();
                answers.push_back(place);
            }
        }
        if(ans == 1000) cout << "You will never meet." << endl;
        else{
            cout << ans;
            for(i = 0 ; i < answers.size() ; i++) cout << " " << answers[i];
            cout << endl;
        }
        
    }
    return 0;
}