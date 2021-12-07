#include <iostream>
#include <list>
using namespace std;

int main(){
  int tracksCnt, i, mCnt, fCnt;
  string pieces;

  cin >> tracksCnt;
  cin.ignore();
  cin.clear();
  for(int l = 0 ; l < tracksCnt ; l++){
    mCnt = fCnt = 0;
    getline(cin, pieces);

    for(i = 0 ; i < pieces.size() ; i++){
      if(pieces[i] == 'F')
        fCnt++;
      else if(pieces[i] == 'M')
        mCnt++;
    }

    if((mCnt == 1 and fCnt == 1) or mCnt != fCnt)
      cout << "NO LOOP" << endl;
    else
      cout << "LOOP" << endl;
    pieces.clear();
  }





  return 0;
}
