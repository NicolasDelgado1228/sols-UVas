#include <bits/stdc++.h>
using namespace std;

int main(){
    int participants, budget, maxBudget, availableBedsCnt, cost, costPerPer, hotels, weeks, i, j, minCost;

    while(cin >> participants >> budget >> hotels >> weeks){
        minCost = 100000000;

        for(i = 0 ; i < hotels ; i++){
            cin >> costPerPer;
            for(j = 0 ; j < weeks ; j++){
                cin >> availableBedsCnt;
                if(participants <= availableBedsCnt){
                    cost = participants*costPerPer;
                    if(cost < minCost and cost <= budget) minCost = cost;
                }
            }
        }

        if(minCost == 100000000) cout << "stay home" << endl;
        else cout << minCost << endl;
    }


    return 0;
}