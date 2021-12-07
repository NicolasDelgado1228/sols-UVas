#include <bits/stdc++.h>
using namespace std;

int lis(vector<int> &nums, int n){
    if(n == 0) return 0;
    else{
        int ans = 1;
        for(int j = 0 ; j < n ; j++)
            if(nums[j] < nums[n])
                ans = max(ans, lis(nums, j)+1);
        return ans;
    }
}



int main(){
    int cases, n, i, num;

    cin >> cases;
    while(cases--){
        cin >> n;
        vector<int> nums;
        for(i = 0 ; i < n ; i++){
            cin >> num;
            nums.push_back(num);
        }

        vector<int> tabLis(n+1, 0), tabLds(n+1,0);
    }


    return 0;
}