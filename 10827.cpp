#include <bits/stdc++.h>
using namespace std;

int main(){
    int cases, n, i, j, k, l, num, maxSum, ac, auxAc;

    cin >> cases;
    while(cases--){
        cin >> n;

        vector<vector<int>> matrix;
        for(i = 0 ; i < n ; i++){
            vector<int> row;
            matrix.push_back(row);
            for(j = 0 ; j < n ; j++){
                cin >> num;
                matrix[matrix.size()-1].push_back(num);
            }
        }

        maxSum = -562501;
        vector<vector<int>> memo(n, vector<int>(n, 0));
        for(i = 0 ; i < n ; i++){
            for(j = 0 ; j < n ; j++){
                for(k = 0 ; k < n ; k++){
                    ac = 0;
                    for(l = 0 ; l < n ; l++){
                        if(k == 0){
                            ac += matrix[(l+i)%n][(k+j)%n];
                            memo[(l+i)%n][(k+j)%n] = ac;
                            if(ac > maxSum) maxSum = ac;
                        }
                        else{
                            ac += matrix[(l+i)%n][(k+j)%n];
                            auxAc = ac + memo[(l+i)%n][(k+j-1)%n];
                            memo[(l+i)%n][(k+j)%n] = auxAc;
                            if(auxAc > maxSum) maxSum = auxAc;
                        }
                    }
                }
            }
        }

        cout << maxSum << endl;
    }


    return 0;
}