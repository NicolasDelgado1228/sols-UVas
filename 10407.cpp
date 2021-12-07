#include <bits/stdc++.h>
using namespace std;


int gcd(int a, int b){
  if(min(a, b) == 0) return max(a, b);
  else return gcd(max(a, b)%min(a, b), min(a, b));
}

int multiGcd(vector<int> nums){
  int result = nums[0];
  for(int i = 1 ; i < nums.size() ; i++) result = gcd(result, nums[i]);
  return result;
}



int main(){
  int num, n;
  bool out, first;

  while(1){
    vector<int> nums;
    out = false;
    first = true;
    while(1){
      cin >> num;
      if(num == 0 and first == true) {out = true; break;}
      else if(num == 0) break;

      if(first) n = num;
      else{
        nums.push_back(fabs(num-n));
        n = num;
      }
      first = false;
    }

    if(out) break;
    cout << multiGcd(nums) << endl;
  }


  return 0;
}
