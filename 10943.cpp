#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> solve(int k, int N){
	vector<vector<int>> memo(k+1, vector<int>(N+1, -1));
	for(int i = 0 ; i < k+1 ; i++){
		for(int j = 0 ; j < N +1; j++){
			int ans = memo[i][j];
			if(i == 0 and j == 0) ans = 1;
			else if(i == 0 and j > 0) ans = 0;
			else if (memo[i][j] == -1){
				ans = 0;
				for(int l = 0 ; l <= j ; l++)
					ans = (memo[i-1][j-l]%1000000 + ans%1000000)%1000000;
			}
			memo[i][j] = ans;
		}
	}
	
	return memo;
}


int main(){
	while(1){
		int N, k;
		cin >> N >> k;
		if(N+k == 0) break;
		vector<vector<int>> memo = solve(k, N);
		cout << memo[k][N] << endl;
	}
	return 0;
}