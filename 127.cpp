#include <algorithm>
#include <stack>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool match(string carta1, string carta2){
  return carta1[0] == carta2[0] or carta1[1] == carta2[1];
}

int main(){
  while(true){
    bool out = false;
    int i;
    vector<stack<string>> stacks;

    for(i = 0 ; i < 52 ; i++){
      stack<string> stack;
      string card;

      cin >> card;
      if(card == "#"){
        out = true;
        break;
      }

      stack.push(card);
      stacks.push_back(stack);
    }
    if(out) break;

    for(i = 1 ; i < stacks.size() ; i++){
      if(i > 2 and match((stacks[i]).top(), (stacks[i-3]).top())){
        (stacks[i-3]).push((stacks[i]).top());
        (stacks[i]).pop();
        if((stacks[i]).empty())
          stacks.erase(stacks.begin() + i);
        i -= 4;
      }
      else if(i > 0 and match((stacks[i]).top(), (stacks[i-1]).top())){
        (stacks[i-1]).push((stacks[i]).top());
        (stacks[i]).pop();
        if((stacks[i]).empty())
          stacks.erase(stacks.begin() + i);
        i -= 2;
      }
    }

    if(stacks.size() == 1)
      cout << stacks.size() << " pile remaining:";
    else
      cout << stacks.size() << " piles remaining:";
    for(i = 0 ; i < stacks.size() ; i++)
      cout << " " << (stacks[i]).size();
    cout << endl;
  }
  return 0;
}
