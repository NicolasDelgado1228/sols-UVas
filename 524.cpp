#include <bits/stdc++.h>
using namespace std;

set<int> primes = {2,3,5,7,11,13,17, 19, 23, 29, 31, 37, 41, 43, 47};


bool isPrime(int n){
    if(primes.find(n) == primes.end()) return false;
    else return true;
}

bool in(int x, vector<int> ac){
    if(find(ac.begin(), ac.end(), x) == ac.end()) return false;
    else return true;
}

vector<vector<int>> results;

void backtrack(int n, vector<int> ac, vector<int> nums, int size){
    for(int i = 0 ; i< nums.size() ; i++){
        if(isPrime(n+nums[i]) and not in(nums[i], ac)){
            vector<int> aux = ac;
            aux.push_back(nums[i]);
            backtrack(nums[i], aux, nums, size);
        }
    }

    if(ac.size() == size and isPrime(ac[ac.size()-1]+1)) results.push_back(ac);
    
}


int main(){
    int n, c = 1;
    bool first = true;

    while(cin >> n){
        if(not first) cout << endl;
        first = false;
        vector<int> nums;
        for(int i = 2 ; i <= n ; i++)
            nums.push_back(i);
        
        vector<int> ac = {1};
        backtrack(1, ac, nums, n);

        cout << "Case " << c++ << ":" << endl;
        for(int i = 0 ; i < results.size() ; i++){
            cout << results[i][0];
            for(int j = 1 ; j < (results[i]).size() ; j++)
                cout << " " << results[i][j];
            cout << endl;;
        }
        results.clear();
            
    }
    return 0;
}