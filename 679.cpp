#include <iostream>
#include <cmath>
using namespace std;

int main(){
  int testCases, drops, depth, i, j, node;

  cin >> testCases;

  while(testCases--){
    cin >> depth >> drops;

    node = 1;
    for(i = 0 ; i < depth-1 ; i++){

      if(drops%2 == 0){
        node = (node*2) + 1;
        drops /= 2;
      }
      else{
        node *= 2;
        drops = (drops/2)+1;
      }
    }

    cout << node << endl;
  }

  cin >> testCases;

  return 0;
}
