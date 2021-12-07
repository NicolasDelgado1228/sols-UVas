#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> solutions;

int getN(string input){
    if(input.size() < 10) return input.size();
    else return 9 + (input.size()-9)/2;
}

void solve(string input, int n, int pos, vector<string> solution, string ac){
    if(pos == input.length()){
        solutions.push_back(solution);
        return;
    }
    cout << ac << endl;

    if(ac != "" and stoi(ac) <= n) solution.push_back(ac);
    else if(ac != "" and stoi(ac) > n) return;
    ac.clear();
    ac = "";

    ac.push_back(input[pos]);
    solve(input, n, pos+1, solution, ac);
    ac.push_back(input[pos+1]);
    solve(input, n, pos+2, solution, ac);
    
}

int main(){
    string input;

    while(cin >> input){
        string aux = "";
        vector<string> auxSol;
        solve(input, getN(input), 0, auxSol, aux);
        cout << "hey" << endl;
        for(int i = 0 ; i < (solutions[0]).size() ; i++){
            cout << solutions[0][i] << endl;
        }
    }

    return 0;
}