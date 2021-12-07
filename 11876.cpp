#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main(){
  int cases, a, b, i, j, divisores, inRangeCnt, k, back;

  cin >> cases;

  vector<int> serie = {1};
  for(i = 0 ; i < 70000 ; i++){
    divisores = 0;
    back = serie[serie.size()-1];

    for(j = 1 ; j <= ((int)sqrt(back)) ; j++){
      if(back%j == 0){
        if(back/j == j)
        divisores++;
        else
        divisores += 2;
      }
    }

    serie.push_back(back+divisores);
  }


  for(k=1 ; k <= cases ; k++){
    cin >> a >> b;

    cout << "Case " << k << ": " << upper_bound(serie.begin(), serie.end(), b) - lower_bound(serie.begin(), serie.end(), a) << endl;


  }

  return 0;
}
