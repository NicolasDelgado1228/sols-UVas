#include <iostream>
#include <vector>
#include <list>
#include <map>
using namespace std;

int main(){
  int definitionsCnt, referencesCnt, i, j, num, b, cd, d, lb, ub, lowBound, c0, value;
  map<string, vector<int>> definitions;

  cin >> definitionsCnt >> referencesCnt;

  for(i = 0 ; i < definitionsCnt ; i++){
    string name;
    vector<int> defs;

    cin >> name >> b >> cd >> d;
    defs.push_back(b);
    defs.push_back(cd);
    defs.push_back(d);

    for(j = 0 ; j < d ; j++){
      cin >> lb >> ub;
      defs.push_back(lb);
      defs.push_back(ub);
    }

    definitions[name] = defs;
  }

  map<string, list<int>> values;
  map<string, vector<int>>::iterator it = definitions.begin();

  for(it ; it != definitions.end() ; it++){
    list<int> vals = {(it->second)[1]};
    lowBound = (it->second).size()-2;
    for(i = ((it->second)[2])-1 ; i >= 1 ; i--){
      vals.push_front( (*(vals.begin())) * ( ((it->second)[lowBound+1]) - ((it->second)[lowBound]) + 1));
      lowBound -= 2;
    }
    c0 = (it->second)[0];
    list<int>::iterator c = vals.begin(), lowb = vals.begin();
    i = 3;
    for(c ; c != vals.end() ; c++){
      c0 -= (*c)*(it->second)[i];
      i += 2;
    }
    vals.push_front(c0);

    values[(it->first)] = vals;
  }

  while(referencesCnt--){
    string name;
    cin >> name;
    list<int>::iterator it = (values[name]).begin();

    value = *it++;
    cout << name + "[";

    for(i = 0 ; i < (definitions[name])[2]; i++){
      cin >> j;
      cout << j;
      if(i < (definitions[name])[2]-1)
        cout << ", ";
      value +=  j * *it++;
    }
    cout << "] = " << value << endl;
  }

  return 0;
}
