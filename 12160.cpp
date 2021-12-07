#include <bits/stdc++.h>
using namespace std;

int sum(int a, int b){
  return (a+b)%10000;
}



int main(){
  int ini, fin, buttonsCnt, button, newComb, steps, cases = 1;
  bool found;

  while(1){
    cin >> ini >> fin >> buttonsCnt;
    if(ini == 0 and fin == 0 and buttonsCnt == 0) break;

    vector<int> buttons;
    while(buttonsCnt--){
      cin >> button;
      buttons.push_back(button);
    }

    found = false;
    pair<int,int> initial = make_pair(ini, 0);
    queue<pair<int,int>> queue;
    queue.push(initial);
    bool nums[10000];
    fill(nums, nums+10000, false);
    nums[initial.first] = true;

    while(not found and not queue.empty()){
      pair<int,int> node = queue.front();
      queue.pop();
      for(int i = 0 ; i < buttons.size() ; i++){
        newComb = sum(node.first, buttons[i]);
        if(newComb == fin){found = true; steps = node.second+1; break;}
        if(nums[newComb] == false){
          nums[newComb] = true;
          queue.push(make_pair(newComb, node.second+1));
        }
      }
    }

    if(found){
      cout << "Case " << cases++ << ": " << steps << endl;
    }
    else{
      cout << "Case " << cases++ << ": Permanently Locked" << endl;
    }
  }
  return 0;
}
