#include <bits/stdc++.h>
using namespace std;

int F(int N, int T, int P, vector<vector<int>>& memo){
    int ans = memo[N][T];
    if(T/N < P) ans = 0;
    else if (N==1 and P<=T) ans = 1;
    else if(memo[N][T]==-1){
        ans = 0;
        for(int x = P ; x <= T ; x++)
            ans += F(N-1, T-x, P, memo);
        memo[N][T] = ans;
    }
    else ans = memo[N][T];
    return ans;
}

int main(){
    int N, T, P, cases;
    cin >> cases;
    while(cases--){
        cin >> N >> T >> P;
        vector<vector<int>> memo(N+1, vector<int>(T+1, -1));
        cout << F(N, T, P, memo) << endl;
    }
    return 0;
}