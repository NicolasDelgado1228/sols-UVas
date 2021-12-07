#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main(){
  int jack, jill, i, type, cdsCnt;

  while(true){
    cin >> jack >> jill;
    if(jack == 0 and jill == 0) break;

    map<int, bool> cds;

    for(i = 0 ; i < jack ; i++){
      cin >> type;
      cds[type] = true;
    }

    cdsCnt = 0;
    for(i = 0 ; i < jill ; i++){
      cin >> type;
      if(cds.find(type) != cds.end())
        cdsCnt++;
    }

    cout << cdsCnt << endl;
  }

  return 0;
}
