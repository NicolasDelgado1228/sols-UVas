#include <bits/stdc++.h>
using namespace std;


vector<string> movements;

void backtrack(vector<string> maze, pair<int,int> pos, vector<string> ac, string allowed, int m, int n, pair<int,int> last){
    if(maze[pos.first][pos.second] == '#') {movements = ac; return;}


    if(pos.first-1 >= 0 and not (pos.first-1 == last.first and pos.second == last.second) and allowed.find(maze[pos.first-1][pos.second]) != string::npos){
        vector<string> aux = ac;
        aux.push_back("forth");
        backtrack(maze, make_pair(pos.first-1, pos.second), aux, allowed, m, n, pos);
    }

    if(pos.second-1 >= 0 and not (pos.first == last.first and pos.second-1 == last.second) and allowed.find(maze[pos.first][pos.second-1]) != string::npos){
        vector<string> aux = ac;
        aux.push_back("left");
        backtrack(maze, make_pair(pos.first, pos.second-1), aux, allowed, m, n, pos);
    }

    if(pos.second+1 < n and not (pos.first == last.first and pos.second+1 == last.second) and allowed.find(maze[pos.first][pos.second+1]) != string::npos){
        vector<string> aux = ac;
        aux.push_back("right");
        backtrack(maze, make_pair(pos.first, pos.second+1), aux, allowed, m, n, pos);
    }

}

int main(){
    int cases, m, n;
    cin >> cases;

    while(cases--){
        vector<string> maze;
        cin >> m >> n;
        pair<int,int> ini, fin;

        for(int i = 0 ; i < m ; i++){
            string row;
            cin >> row;
            if(row.find("#") != string::npos) fin = make_pair(i, row.find("#"));
            else if(row.find("@") != string::npos) ini = make_pair(i, row.find("@"));
            maze.push_back(row);
        }
            
        movements.clear();
        vector<string> aux;
        backtrack(maze, ini, aux, "IEHOVA#", m, n, make_pair(-1000,-1000));

        cout << movements[0];
        for(int i = 1 ; i < movements.size() ; i++)
            cout << " " << movements[i];
        cout << endl;
    }


    return 0;
}