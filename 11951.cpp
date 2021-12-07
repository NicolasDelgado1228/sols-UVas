#include <bits/stdc++.h>
using namespace std;

int main(){
    long long cases, n, c = 1, m, budget, i, j, k, l, num, maxArea, minCost, height, width, acum, area, auxAcum;
    cin >> cases;

    while(cases--){
        cin >> n >> m >> budget;
        vector<vector<long long>> matrix, memo;

        for(i = 0 ; i < n ; i++){
            vector<long long> row;
            matrix.push_back(row);
            memo.push_back(row);
            for(j = 0 ; j < m ; j++){
                cin >> num;
                matrix[matrix.size()-1].push_back(num);
                memo[matrix.size()-1].push_back(num);
            }
        }

        maxArea = minCost = 0;

        for(i = 0 ; i < n ; i++){
            for(j = 0 ; j < m ; j++){
                for(k = j ; k < m ; k++){
                    width = 1 + k-j;
                    acum = 0;
                    for(l = i ; l < n ; l++){
                        height = 1 + l-i;
                        acum += matrix[l][k];
                        auxAcum = acum;
                        if(k-j != 0)
                            auxAcum += memo[l][k-1];
                        memo[l][k] = auxAcum;

                        area = width*height;
                        if(auxAcum <= budget and area >= maxArea){
                            if(area == maxArea and auxAcum < minCost){
                                maxArea = area;
                                minCost = auxAcum;
                            }
                            else if(area > maxArea){
                                maxArea = area;
                                minCost = auxAcum;
                            }
                        }
                    }
                }
            }
        }

        cout << "Case #" << c++ << ": " << maxArea << " " << minCost << endl;
    }

    return 0;
}