#include <iostream>
using namespace std;

int main(){
  int cases, rowsCnt, columnsCnt, i;
  char directions[] = {'N', 'E', 'S', 'W'};
  bool first = true;
  cin >> cases;

  while(cases--){
    if(not first) cout << endl;

    string maze[60];
    cin >> rowsCnt >> columnsCnt;
    cin.ignore();
    cin.clear();

    for(i = 0 ; i < rowsCnt ; i++){
      string row;
      getline(cin, row);
      maze[i] = row;
    }

    int position[2], direction = 0;
    cin >> position[0] >> position[1];
    position[0]--;
    position[1]--;


    bool end = false;
    while(not end){
      string instructions;
      cin >> instructions;

      for(i = 0 ; i < instructions.length() ; i++){


        if(instructions[i] == 'Q') end = true;

        else if(instructions[i] == 'R' and direction != 3)
          direction++;
        else if(instructions[i] == 'R' and direction == 3)
          direction = 0;
        else if(instructions[i] == 'L' and direction != 0)
          direction--;
        else if(instructions[i] == 'L' and direction == 0)
          direction = 3;

        else if(directions[direction] == 'N' and position[0] > 0 and maze[position[0] - 1][position[1]] != '*')
          position[0]--;
        else if(directions[direction] == 'S' and position[0] < rowsCnt-1 and maze[position[0] + 1][position[1]] != '*')
          position[0]++;
        else if(directions[direction] == 'E' and position[1] < columnsCnt-1 and maze[position[0]][position[1] + 1] != '*')
          position[1]++;
        else if(directions[direction] == 'W' and position[1] > 0 and maze[position[0]][position[1] - 1] != '*')
          position[1]--;
      }
    }

    cout << ++position[0] << " " << ++position[1] << " " << directions[direction] << endl;
    first = false;
  }


  return 0;
}
