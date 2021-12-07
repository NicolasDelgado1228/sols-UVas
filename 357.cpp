#include <bits/stdc++.h>
using namespace std;




int main(){
    int target;

    int nums[5] = {1, 5, 10, 25, 50};
    long long table[6][30001];
    memset(table, 0, sizeof(table));

    for(int n = 0 ; n <= 5 ; n++){
        for(int target = 0 ; target <= 30001 ; target++){
            if(target == 0)
                table[n][target] = 1;
            else if(n == 0)
                table[n][target] = 0;
            else{
                table[n][target] = table[n-1][target];
                if(target-nums[n-1] >= 0)
                    table[n][target] += table[n][target - nums[n-1]];
            }
        }
    }

    while(cin >> target){
        long long ans = table[5][target];
        if(ans == 1)
            cout << "There is only 1 way to produce " << target << " cents change." << endl;
        else
            cout << "There are " << ans << " ways to produce " << target << " cents change." << endl;
    }


    return 0;
}