#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  int heightsCnt, i, heights[50001], query, queriesCnt, lowIdx, upperIdx;

  cin >> heightsCnt;

  for(i = 0 ; i < heightsCnt ; i++)
    cin >> heights[i];

  cin >> queriesCnt;

  for(i = 0 ; i < queriesCnt ; i++){
    cin >> query;

    lowIdx = lower_bound(heights, heights + heightsCnt, query) - heights;
    upperIdx = upper_bound(heights, heights + heightsCnt, query) - heights;

    if(lowIdx == 0)
      cout << "X ";
    else
      cout << heights[--lowIdx] << " ";

    if(upperIdx < heightsCnt)
      cout << heights[upperIdx] << endl;
    else
      cout << "X" << endl;
  }


  return 0;
}
