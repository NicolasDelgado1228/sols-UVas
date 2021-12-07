#include <bits/stdc++.h>
using namespace std;

void lis(vector<int> &nums, int N){
	int ans = -1;
	if(N > 0){
		for(int i = 0 ; i < N ; i++){
			if(fabs(nums[N-1], nums[i]) <= 5)
				ans = max(lis(nums, N-1)+1)
		}
	}
}


int main(){
	int n, u, i;
	vector<int> nums;
	cin >> n;
	for(int i = 0 ; i < n ; i++){
		cin >> u;
		nums.push_back(u);
	}
	return 0;
}