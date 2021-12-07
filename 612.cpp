#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

/*El algoritmo tiene una complejidad del orden O(n²). Es aceptado en uva debido a que
n² < 1000000000
*/

class Dna{
  public:
    int unsortedness;
    string code;

    bool operator<(Dna dna){
      return unsortedness < dna.unsortedness;
    }
    bool operator==(int uns){
      return unsortedness == uns;
    }
};

int main(){
  int dataSets, len, codesCnt, i, j, unsortedness;
  string code, codeIdx[2];
  bool first = true;
  vector<Dna> sorted, equals;
  cin >> dataSets;

  while(dataSets--){
    if(not first) cout << endl;
    cin >> len >> codesCnt;
    cin.ignore();

    while(codesCnt--){
      unsortedness = 0;
      getline(cin, code);
      Dna dna;

      for(i = 0 ; i < len-1 ; i++)
        for(j = i + 1 ; j < len ; j++)
          if(code[i] > code[j])
            unsortedness++;

      dna.code = code;
      dna.unsortedness = unsortedness;

      if(find(sorted.begin(), sorted.end(), dna.unsortedness) == sorted.end())
        sorted.push_back(dna);
      else
        equals.push_back(dna);
    }

    sort(sorted.begin(), sorted.end());
    reverse(sorted.begin(), sorted.end());

    for(i = 0 ; i < equals.size() ; i++){
      sorted.insert(find(sorted.begin(), sorted.end(), equals[i].unsortedness), equals[i]);
    }

    reverse(sorted.begin(), sorted.end());

    for(i = 0 ; i < sorted.size() ; i++)
      cout << sorted[i].code << endl;

    sorted.clear();
    equals.clear();
    first = false;

  }
  return 0;
}
