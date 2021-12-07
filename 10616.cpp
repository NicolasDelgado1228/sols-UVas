#include <bits/stdc++.h>
using namespace std;

int memo[21][201][11];
bool solved[21][201][11];

int solve(vector<int> &nums, int sum, int res, int n, int w, int d){
    if(w == 0 and res == 0)
        return 1;
    else if((w == 0 and res != 0) or n == 0)
        return 0;
    
    if(memo[res][n][w] != -1)
        return memo[res][n][w];

    int mod = (sum + nums[n-1])%d;
    mod < 0 ? mod = mod+d : mod = mod;
        
    memo[res][n][w] = solve(nums, sum + nums[n-1], mod, n-1, w-1, d) + solve(nums, sum, res, n-1, w, d);
   
    return memo[res][n][w];
}


 int main(){
    int N, queries, i, num, W, target, n, w, set = 1;

    while(true){
        cin >> N >> queries;
        if(N == 0 and queries == 0) break;
        else cout << "SET " << set++ << ":" << endl;
        vector<int> nums;
        for(i = 0 ; i < N ; i++){
            cin >> num;
            nums.push_back(num);
        }

        for(i = 1 ; i <= queries ; i++){
            cout << "QUERY " << i << ": ";
            cin >> target >> W;
            for(int i = 0 ; i < 20 ; i++)
                for(int j = 0 ; j < 201 ; j++)
                    for(int k = 0 ; k < 11 ; k++)
                        memo[i][j][k] = -1;
                    
                        
            cout << solve(nums, 0, 0, N, W, target) << endl;
        }
    }


    return 0;
}