#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

void swapSymbol(string& instruction){
  if(instruction[0] == '+')
    instruction[0] = '-';
  else
    instruction[0] = '+';
}

int main(){
  string axises[2][4] = {{"+x", "+z", "-x", "-z"}, {"+x", "+y", "-x", "-y"}};

  while(true){
    int instructions, i, axis = 0, ax = 0;
    cin >> instructions;

    if(instructions == 0) break;

    for(i = 0 ; i < instructions-1 ; i++){
      string instruction;
      cin >> instruction;
      if(instruction == "No") continue;


      if(axises[ax][axis] == "+x" or axises[ax][axis] == "-x"){
        if(axises[ax][axis] == "-x")
          swapSymbol(instruction);

        if(instruction[1] == 'z')
          ax = 0;
        else
          ax = 1;
        axis = find(*(axises+ax), *(axises+ax+4), instruction) - *(axises+ax);
      }
      else if(((axises[ax][axis] == "+z" or axises[ax][axis] == "-z") and (instruction == "+z" or instruction == "-z")) or ((axises[ax][axis] == "+y" or axises[ax][axis] == "-y") and (instruction == "+y" or instruction == "-y"))){
        if(instruction[0] == '+'){
          if(axis < 3)
            axis++;
          else
            axis = 0;
        }
        else{
          if(axis > 0)
            axis--;
          else
            axis = 3;
        }
      }
    }

    cout << axises[ax][axis] << endl;
  }


  return 0;
}
