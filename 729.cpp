#include <bits/stdc++.h>
using namespace std;


vector<vector<int>> nums;

int ones(vector<int> num){
    int res = 0;
    for(int i = 0 ; i < num.size() ; i++)
        if(num[i] == 1) res++;
    return res;
}

void backtrack(vector<int> num, int h, int i){
    int onesCnt = ones(num);
    if(onesCnt == h) {nums.push_back(num) ; return;}
    else if(i >= num.size() or onesCnt > h) return;

    num[i] = 1;
    backtrack(num, h, i+1);
    num[i] = 0;
    backtrack(num, h, i+1);
}



int main(){
    int cases, n, h;
    bool first = true;
    cin >> cases;

    while(cases--){
        if(not first) cout << endl;
        cin >> n >> h;
        nums.clear();
        vector<int> num;
        for(int i = 0 ; i < n ; i++) num.push_back(0);

        backtrack(num, h, 0);
        for(int i = nums.size()-1 ; i >= 0 ; i--){
            for(int j = 0 ; j < (nums[i]).size() ; j++)
                cout << nums[i][j];
            cout << endl;
        }
        first = false;
    }


    return 0;
}