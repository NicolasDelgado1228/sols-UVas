#include <iostream>
#include <map>
#include <algorithm>
#include <list>
using namespace std;

int main(){
  map<char, char> conversion = {{'A', '2'}, {'B', '2'}, {'C', '2'}, {'D', '3'}, {'E', '3'}, {'F', '3'}
  ,{'G', '4'}, {'H', '4'}, {'I', '4'}, {'J', '5'}, {'K', '5'}, {'L', '5'}, {'M', '6'}, {'N', '6'}, {'O', '6'},
  {'P', '7'},{'R', '7'},{'S', '7'},{'T', '8'},{'U', '8'},{'V', '8'},{'W', '9'},{'X', '9'},{'Y', '9'}};
  bool first = true;

  int cases, numbers, i;
  cin >> cases;

  while(cases--){
    bool duplicate = false;
    map<string, int> stdNums;
    list<string> keys;

    if(not first)
      cout << endl;

    cin >> numbers;

    while(numbers--){
      string number, standardNum;

      cin >> number;
      for(i = 0 ; i < number.size() ; i++){
        if(number[i] >= 48 and number[i] <= 57)
          standardNum.push_back(number[i]);
        else if(number[i] != '-')
          standardNum.push_back(conversion[number[i]]);

        if(standardNum.size() == 3)
          standardNum.push_back('-');
      }

      keys.push_front(standardNum);
      stdNums[standardNum] = 0;
    }

    list<string>::iterator ite = keys.begin();

    for(ite ; ite != keys.end() ; ite++)
      stdNums[*ite]++;

    map<string, int>::iterator it = stdNums.begin();
    for(it ; it != stdNums.end() ; it++){
      if(it->second > 1){
        cout << it->first << " " << it->second << endl;
        duplicate = true;
      }
    }

    if(not duplicate)
      cout << "No duplicates." << endl;


    first = false;

  }



  return 0;
}
