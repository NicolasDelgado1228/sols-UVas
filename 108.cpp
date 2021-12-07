#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, i, j, num, maxSum, k, l, sum, rectSum;

    while(cin >> n){
        vector<vector<int>> matrix, memo;

        //creates the matrix
        for(i = 0 ; i < n ; i++){
            vector<int> row;
            matrix.push_back(row);
            memo.push_back(row);
            for(j = 0 ; j <  n ; j++){
                cin >> num;
                matrix[matrix.size()-1].push_back(num);
                memo[memo.size()-1].push_back(0);
            }
        }

        maxSum = -12700001;
        for(i = 0 ; i < n ; i++){
            for(j = 0 ; j < n ; j++){
                for(k = j ; k < n ; k++){
                    sum = 0;
                    for(l = i ; l < n ; l++){
                        sum += matrix[l][k];
                        if(k-j > 0)
                            rectSum = sum + memo[l][k-1];
                        else
                            rectSum = sum;
                        memo[l][k] = rectSum;
                        if(rectSum > maxSum)
                            maxSum = rectSum;
                    
                    }
                }
            }
        }

        cout << maxSum << endl;
    }


    return 0;
}