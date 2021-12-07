#include <bits/stdc++.h>
using namespace std;

int inversions;
vector<int> aux(100000, 0);


void merge(vector<int> &nums, int lo, int hi){
  for(int i = lo ; i < hi ; i++){
    aux[i] = nums[i];
  }
  int mid = (hi+lo)/2;
  int i = lo, j = mid, k = lo;

  while(k < hi){
    if(i == mid){
      nums[k] = aux[j];
      j+=1;
    }
    else if(j == hi){
      nums[k] = aux[i];
      i+=1;
    }
    else if(aux[i] > aux[j]){
      inversions += (mid - i);
      nums[k] = aux[j];
      j+=1;
    }
    else{
      nums[k] = aux[i];
      i+=1;
    }
    k += 1;
  }
}

void mergeSort(vector<int> &nums, int lo, int hi){
  if(hi-lo > 1){
    int mid = (hi+lo)/2;
    mergeSort(nums, lo, mid);
    mergeSort(nums, mid, hi);
    merge(nums, lo, hi);
  }
}



int main(){
  int n, num;
  while(true){
    cin >> n;
    if(n == 0) break;
    vector<int> nums;
    for(int i = 0 ; i < n ; i++){
      cin >> num;
      nums.push_back(num);
    }
    inversions = 0;
    mergeSort(nums, 0, nums.size());
    if(inversions%2==0) cout << "Carlos" << endl;
    else cout << "Marcelo" << endl;
  }
  return 0;
}