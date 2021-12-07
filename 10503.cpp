#include <bits/stdc++.h>
using namespace std;

bool solution;

pair<int,int> allowedFirst(pair<int,int> a, pair<int,int> b){
    if(a.second == b.first) return b;
    else if(a.second == b.second) return make_pair(b.second, b.first);
    else return make_pair(-1,-1);
}

pair<int,int> allowedLast(pair<int,int> a, pair<int,int> b){
    if(a.first == b.first) return make_pair(b.second, b.first);
    else if(a.first == b.second) return b;
    else return make_pair(-1,-1);
}


void backtrack(vector<pair<int,int>> available, int spaces, pair<int,int> first, pair<int,int> last, int maze[][100]){
    if(solution == true) return;
    if(spaces == 0 and first.second == last.first) {solution = true; return;}
    if(spaces == 0) return;



    for(int i = 0 ; i < available.size() ; i++){
        pair<int,int> ans = allowedFirst(first, available[i]);
        if(ans.first != -1 and maze[available[i].first][available[i].second]){
            maze[ans.first][ans.second] -= 1;
            maze[ans.second][ans.first] -= 1;
            backtrack(available, spaces-1, ans, last, maze);
            maze[ans.first][ans.second] += 1;
            maze[ans.second][ans.first] += 1;
        }
    }
}




int main(){
    int spaces, piecesCnt, a, b;

    while(1){
        cin >> spaces;
        if(spaces == 0) break;


        cin >> piecesCnt;
        pair<int,int> first, last;
        cin >> a >> b;
        first = make_pair(a,b);
        cin >> a >> b;
        last = make_pair(a,b);
        vector<pair<int,int>> pieces;
        int maze[100][100];

        for(int i = 0 ; i < 100 ; i++)
            for(int j = 0 ; j < 100 ; j++){
                maze[i][j] = 0;
            }


        for(int i = 0 ; i < piecesCnt ; i++){
            cin >> a >> b;
            maze[a][b] += 1;
            maze[b][a] += 1;
            pieces.push_back(make_pair(a,b));
        }

        set<pair<int,int>> used;
        solution = false;
        backtrack(pieces, spaces, first, last, maze);

        if(solution) cout << "YES" << endl;
        else cout << "NO" << endl;
    }


    return 0;
}