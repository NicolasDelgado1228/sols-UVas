#include <iostream>
#include <algorithm>
#include <list>
#include <queue>
using namespace std;


int main(){
  while(true){
    int n, i, number, cost, a, b;

    cin >> n;
    if(n == 0) break;

    priority_queue<int, vector<int>, greater<int>> numbers;
    for(i = 0 ; i < n ; i++){
      cin >> number;
      numbers.push(number);
    }

    cost = 0;
    while(numbers.size() > 1){
      a = numbers.top();
      numbers.pop();
      b = numbers.top();
      numbers.pop();

      cost += a+b;
      numbers.push(a+b);
    }

    cout << cost << endl;
  }
  return 0;
}
