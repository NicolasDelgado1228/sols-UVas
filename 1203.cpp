#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;


int main(){
  int time, times, minVal, i, minKeyVal, query;
  map<int, int> queries, values;

  while(true){
    string instruction;
    getline(cin, instruction);

    if(instruction == "#") break;

    instruction.erase(instruction.begin(), instruction.begin() + 9);

    query = stoi(instruction.substr(0, instruction.find(" ")));
    time = stoi(instruction.substr(instruction.find(" ")+1, instruction.size()-instruction.find(" ")+1));

    queries[query] = time;
    values[query] = time;
  }

  cin >> times;


  for(i = 0 ; i < times ; i++){
    map<int, int>::iterator it = queries.begin();
    minKeyVal = it->first;
    minVal = it->second;

    for(it ; it != queries.end() ; it++)
      if(it->second < minVal){
        minVal = it->second;
        minKeyVal = it->first;
      }

    cout << minKeyVal << endl;
    queries[minKeyVal]+=values[minKeyVal];
  }

  return 0;
}
