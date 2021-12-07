#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;


int main(){
  int y, yearsCnt, i, max, upper, lower, ini, fin, limit;

  while(cin >> y){
    int years[100000];
    ini = fin = 0;

    cin >> yearsCnt;
    for(i = 0 ; i < yearsCnt ; i++)
      cin >> years[i];

    max = -1;
    for(i = 0 ; i < fabs(yearsCnt-y)+1 ; i++){
      upper = upper_bound(years, years + yearsCnt, years[i]+y-1) - years;
      limit = upper - i;

      if(limit > max){
        max = limit;
        ini = i;
        fin = upper-1;
      }

      if(y > yearsCnt) break;
    }

    cout << max << " " << years[ini] << " " << years[fin] << endl;
  }


  return 0;
}
