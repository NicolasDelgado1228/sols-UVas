#include <bits/stdc++.h>
using namespace std;

void dfsTarjan(map<char,set<char>> &G, map<char,int> &time, map<char,int> &low, stack<char> &stack, vector<vector<char>> &ans, map<char, bool> &inStack, int &timeCnt,  char u){
    time[u] = low[u] = timeCnt++; stack.push(u); inStack[u] = true;
    set<char> adjacents = G[u];
    set<char>::iterator it = adjacents.begin();
    for(it ; it != adjacents.end() ; it++){
        char v = *it;
        if (low[v] == -1){
            dfsTarjan(G, time, low, stack, ans, inStack, timeCnt, v);
            low[u] = min(low[u], low[v]);
        }
        else if(inStack[v]) low[u] = min(low[u], time[v]);
    }

    if(low[u]==time[u]){
        vector<char> scc;
        while(stack.top() != u){scc.push_back(stack.top()) ; inStack[stack.top()] = false; stack.pop();}
        scc.push_back(stack.top()); inStack[stack.top()] = false; stack.pop();
        ans.push_back(scc);
    }
}


vector<vector<char>> tarjan(map<char,set<char>> G){
    int n = G.size();
    int timeCnt = 0;
    map<char,int> time, low;
    map<char, bool> inStack;
    stack<char> stack;
    vector<vector<char>> ans;
    map<char, set<char>>::iterator it = G.begin();
    for(it ; it != G.end() ; it++){time[it->first] = -1;low[it->first] = -1;inStack[it->first] = false;}
    it = G.begin();
    for(it ; it != G.end() ; it++){
        char u = it->first;
        if(time[u] == -1){
            dfsTarjan(G, time, low, stack, ans, inStack, timeCnt, u);
        }
    }
        
    
    return ans;
}

int main(){
    int n, i, j;

    while(true){
        cin >> n;
        if(n == 0) break;
        map<char, set<char>> G;
        for (i = 0 ; i < n ; i++){
            vector<char> adjacents;
            for (j = 0 ; j < 6 ; j++){
                char letter;
                cin >> letter; adjacents.push_back(letter);
            }
            char letter = adjacents[5];
            for (j = 0 ; j < 5 ; j++)
                if(adjacents[j] != letter) G[letter].insert(adjacents[j]);
        }

        vector<vector<char>> sccs = tarjan(G);
        for(i = 0; i < sccs.size() ; i++){
            for(j = 0 ; j < sccs[i].size() ; j++) cout << sccs[i][j] << " ";
            cout << endl;
        }

    }
    return 0;
}