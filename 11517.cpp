#include <bits/stdc++.h>
using namespace std;

vector<int> arr;
int N;

pair<int,int> phi(int left, int i, vector<vector<pair<int,int>>> &memo){
    pair<int,int> ans;
    if(left <= 0 or i == N) return {0,0};
    else if(memo[left][i] == make_pair(-1,-1)){
        pair<int,int> ans1 = phi(left-arr[i], i+1, memo), ans2 = phi(left, i+1, memo);
        if(1+ans1.first < ans2.second) memo[left][i] = {ans1.first+1, ans1.second+arr[i]};
        else memo[left][i] = {ans2.first, ans2.second};
        cout << left << " " << i << " = " << memo[left][i].first << ", " << memo[left][i].second << endl;
    }  
    return memo[left][i];
}

int main(){ 
    int left, x, cases, n;
    cin >> cases;
    while(cases--){
        cin >> left;
        cin >> n;
        N = n;
        arr.clear();
        for(int i = 0 ; i < n ; i++){
            cin >> x;
            arr.push_back(x);
        }
        vector<vector<pair<int,int>>> memo(left+1, vector<pair<int,int>>(n+1, {-1,-1}));
        pair<int,int> ans = phi(left, 0, memo);
        cout << ans.second << " " << ans.first << endl;
    }
    return 0;
}