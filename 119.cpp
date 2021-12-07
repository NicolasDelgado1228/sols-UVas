#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main(){
  map<string, int> money;
  int peopleCnt, i, moneyCnt, giftsCnt, j;
  string name, gift;
  bool first = true;

  while(cin >> peopleCnt){
    vector<string> names;
    if(not first)
      cout << endl;
    for(i = 0 ; i < peopleCnt ; i++){
      cin >> name;
      money[name] = 0;
      names.push_back(name);
      name.clear();
    }

    for(i = 0 ; i < peopleCnt ; i++){
      cin >> name >> moneyCnt >> giftsCnt;

      for(j = 0 ; j < giftsCnt ; j++){
        cin >> gift;
        if(giftsCnt) money[gift] += moneyCnt/giftsCnt;
        gift.clear();
      }
      if(giftsCnt)
        money[name] += (moneyCnt%giftsCnt) - moneyCnt;

      name.clear();

    }

    for(i = 0 ; i < names.size() ; i++)
      cout << names[i] << " " << money[names[i]] << endl;

    first = false;

  }




  return 0;
}
