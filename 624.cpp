#include <bits/stdc++.h>
using namespace std;

vector<int> s;
int m;

void solve(vector<int> tracks, int N, int i, int ac, vector<int> used){
    if(ac > N or i > tracks.size()) return;

    if(ac > m){
        m = ac;
        s.clear();
        s = used;
    }

    vector<int> aux = used;
    aux.push_back(tracks[i]);

    solve(tracks, N, i+1, ac+tracks[i], aux);
    solve(tracks, N, i+1, ac, used);
}



int main(){
    int N, tracksCnt, track;

    while(cin >> N){
        cin >> tracksCnt;
        vector<int> tracks;

        while(tracksCnt--){
            cin >> track;
            tracks.push_back(track);
        }

        s.clear();
        m = 0;
        vector<int> used;

        solve(tracks, N, 0, 0, used);

        for(int i = 0 ; i < s.size() ; i++)
            cout << s[i] << " ";
        
        cout << "sum:" << m << endl;


    }

    return 0;
}