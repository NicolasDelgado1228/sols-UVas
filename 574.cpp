#include <bits/stdc++.h>
using namespace std;

set<vector<int>> solutions;

void solve(vector<int> nums, int i, int n, int sum, vector<int> ac){
    if(sum == n){ solutions.insert(ac); return;}
    if(i == nums.size() or sum > n) return;


    vector<int> aux = ac;
    aux.push_back(nums[i]);

    solve(nums, i+1, n, sum + nums[i], aux);
    solve(nums, i+1, n, sum, ac);
}

int main(){
    int n, numsCnt, num;
    
    while(true){
        cin >> n >> numsCnt;
        if(n == 0 and numsCnt == 0) break;

        vector<int> nums;
        for(int i = 0 ; i < numsCnt ; i++){
            cin >> num;
            nums.push_back(num);
        }

        solutions.clear();
        vector<int> aux;
        solve(nums, 0, n, 0, aux);

        

        cout << "Sums of " << n << ":" << endl;

        if(solutions.size() > 0){
            set<vector<int>>::iterator it = solutions.end();
            it--;
            for(it ; it != solutions.begin() ; it--){
                cout << (*it)[0];
                for(int j = 1 ; j < (*it).size() ; j++){
                    cout << "+" << (*it)[j];
                }
                cout << endl;
            }
            cout << (*solutions.begin())[0];
            for(int j = 1 ; j < (*solutions.begin()).size() ; j++){
                cout << "+" << (*solutions.begin())[j];
            }
            cout << endl;
        }
        else{
            cout << "NONE" << endl;
        }
        
    }

    return 0;
}