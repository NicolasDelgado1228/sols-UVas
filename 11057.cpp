#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main(){
  int pricesCnt, i, upper, money;

  while(cin >> pricesCnt){
    int prices[10001];

    for(i = 0 ; i < pricesCnt ; i++) cin >> prices[i];
    cin >> money;

    sort(prices, prices + pricesCnt);

    upper = *upper_bound(prices, prices + pricesCnt, money/2);

    cout << "Peter should buy books whose prices are " << money - upper << " and " << upper << ".\n\n";
  }

  return 0;
}
