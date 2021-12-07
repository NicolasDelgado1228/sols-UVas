#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

class Robot{
public:
  int i;
  int j;
  int dir;

  Robot(int x, int y, int dir){
    this->i = x;
    this->j = y;
    this->dir = dir;
  }

};

void turnRight(int& a){
  if(a < 3)
    a++;
  else
    a = 0;
}

void turnLeft(int& a){
  if(a > 0)
    a--;
  else
    a = 3;
}

void moveForward(Robot& robot){
  if(robot.dir == 0)
    (robot.i)--;
  else if(robot.dir == 1)
    (robot.j)++;
  else if(robot.dir == 2)
    (robot.i)++;
  else if(robot.dir == 3)
    (robot.j)--;
}

int main(){
  int n, m, insCnt, i, j, dir;
  char dirs[4] = {'N', 'L', 'S', 'O'};

  while(true){
    cin >> n >> m >> insCnt;
    if(n == 0 and m == 0 and insCnt == 0) break;

    string arena[10000], instructions;
    for(i = 0 ; i < n ; i++)
      cin >> arena[i];

    cin >> instructions;

    i = 0;
    for(i ; i < n ; i++){
      j = 0;
      for(j ; j < m ; j++){
        if(arena[i][j] != '.' and arena[i][j] != '*' and arena[i][j] != '#'){

          if(arena[i][j] == 'N')
            dir = 0;
          else if(arena[i][j] == 'L')
            dir = 1;
          else if(arena[i][j] == 'S')
            dir = 2;
          else if(arena[i][j] == 'O')
            dir = 3;
          break;
        }
      }
      if(arena[i][j] == 'N' or arena[i][j] == 'S' or arena[i][j] == 'L' or arena[i][j] == 'O')
        break;
    }

    Robot robot(i, j, dir);
    //cout << robot.i << robot.j << robot.dir << endl;
    int stickers = 0;

    for(i = 0 ; i < insCnt ; i++){


      if(instructions[i] == 'D')
        turnRight(robot.dir);

      else if(instructions[i] == 'E')
        turnLeft(robot.dir);

      else{
        Robot aux(robot.i, robot.j, robot.dir);
        moveForward(robot);

        if(robot.i > n-1 or robot.i < 0 or robot.j > m-1 or robot.j < 0 or arena[robot.i][robot.j] == '#'){
          robot.i = aux.i;
          robot.j = aux.j;
          robot.dir = aux.dir;
        }

        if(arena[robot.i][robot.j] == '*'){
          stickers++;
          arena[robot.i][robot.j] = '.';
        }
      }


    }

    cout << stickers << endl;


  }

  return 0;
}
