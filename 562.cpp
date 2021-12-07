#include <bits/stdc++.h>
using namespace std;


int main(){
    int cases, n, i, num, bag1, j, maxSum, N, W, w;

    cin >> cases;
    for(int c = 0 ; c < cases ; c++){
        cin >> N;
        vector<int> nums;
        maxSum = 0;
        for(i = 0 ; i < N ; i++){
            cin >> num;
            maxSum += num;
            nums.push_back(num);
        }

        W = maxSum/2;

        vector<vector<int>> tab(N+1, vector<int>(W+1, 0));
        

        for(n = 0 ; n <= N ; n++){
            for(w = 0 ; w <= W ; w++){
                if(n == 0 or w == 0)
                    tab[n][w] = 0;
                else{
                    tab[n][w] = tab[n-1][w];
                    if(nums[n-1] <= w)
                        tab[n][w] = max(tab[n][w], tab[n-1][w-nums[n-1]] + nums[n-1]);
                }
            }
        }

        cout << fabs(tab[N][W] - maxSum+tab[N][W]) << endl;
    }



    return 0;
}