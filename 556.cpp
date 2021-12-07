#include <iostream>
#include <utility>
#include <algorithm>
#include <map>
using namespace std;

void turnLeft(int *dir){
  if(*dir == 3)
    *dir = 0;
  else
    (*dir)++;
}

pair<char, int> right(pair<int, int>& pos, string maze[], int rowsCnt, int columnsCnt, int dir){
  char dirs[4] = {'E', 'N', 'W', 'S'};

  if(dirs[dir] == 'N'){
    if((pos.second)+1 == columnsCnt){
      pair<char, int> ret('x', dir);
      return ret;
    }
    else{
      dir = 0;
      pair<char, int> ret(maze[pos.first][(pos.second)+1], dir);
      return ret;
    }
  }
  else if(dirs[dir] == 'E'){
    if((pos.first)+1 == rowsCnt){
      pair<char, int> ret('x', dir);
      return ret;
    }
    else{
      dir = 3;
      pair<char, int> ret(maze[(pos.first)+1][pos.second], dir);
      return ret;
    }
  }
  else if(dirs[dir] == 'S'){
    if((pos.second)-1 < 0){
      pair<char, int> ret('x', dir);
      return ret;
    }
    else{
      dir = 2;
      pair<char, int> ret(maze[pos.first][(pos.second)-1], dir);
      return ret;
    }
  }
  else if(dirs[dir] == 'W'){
    if((pos.first)-1 < 0){
      pair<char, int> ret('x', dir);
      return ret;
    }
    else{
      dir = 1;
      pair<char, int> ret(maze[(pos.first)-1][pos.second], dir);
      return ret;
    }
  }
}

void moveForward(pair<int, int> &position, char dir, map<pair<int,int>, int> &occurrencies){
  if(dir == 'N')
    (position.first)--;
  else if(dir == 'E')
    (position.second)++;
  else if(dir == 'S')
    (position.first)++;
  else if(dir == 'W')
    (position.second)--;

  if(occurrencies.find(position) == occurrencies.end())
    occurrencies[position] = 1;
  else
    (occurrencies[position])++;
}

int main(){
  int rowsCnt, columnsCnt, i, j, ones;
  char dirs[4] = {'E', 'N', 'W', 'S'};

  while(true){
    string maze[100000], row;
    ones = 0;

    cin >> rowsCnt >> columnsCnt;
    if(rowsCnt == 0 and columnsCnt == 0) break;

    for(i = 0 ; i < rowsCnt ; i++){
      cin >> maze[i];
      ones+=count((maze[i]).begin(), (maze[i]).end(), '1');
    }

    map<pair<int, int>, int> occurrencies;
    pair<int, int> position(rowsCnt-1, 0), initial(rowsCnt-1, 0);
    occurrencies[initial] = 1;

    int dir = 0, c;
    i = rowsCnt-1;
    j = c = 0;
    while(occurrencies[initial] == 1){
      if((right(position, maze, rowsCnt, columnsCnt, dir)).first == '0'){
        dir = (right(position, maze, rowsCnt, columnsCnt, dir)).second;
        moveForward(position, dirs[dir], occurrencies);
      }
      else if((j == columnsCnt-1 and dirs[dir] == 'E') or (i == 0 and dirs[dir] == 'N') or (j == 0 and dirs[dir] == 'W') or (i == rowsCnt-1 and dirs[dir] == 'S')){
        turnLeft(&dir);
      }
      else if((j < columnsCnt-1 and maze[i][j+1] == '1' and dirs[dir] == 'E') or (i > 0 and maze[i-1][j] == '1' and dirs[dir] == 'N') or (j > 0 and maze[i][j-1] == '1' and dirs[dir] == 'W') or (i < rowsCnt-1 and maze[i+1][j] == '1' and dirs[dir] == 'S')){
        turnLeft(&dir);
      }
      else
        moveForward(position, dirs[dir], occurrencies);
      i = position.first;
      j = position.second;
    }

    int frequencies[5] = {0, 0, 0, 0, 0};
    for(i = 0 ; i < rowsCnt ; i++){
      for(j = 0 ; j < columnsCnt ; j++){
        pair<int, int> pos(i, j);
        if(occurrencies.find(pos) == occurrencies.end())
          frequencies[0]++;
        else if(occurrencies[pos] == 1)
          frequencies[1]++;
        else if(occurrencies[pos] == 2)
          frequencies[2]++;
        else if(occurrencies[pos] == 3)
          frequencies[3]++;
        else if(occurrencies[pos] == 4)
          frequencies[4]++;
      }
    }

    printf("%3d%3d%3d%3d%3d\n", frequencies[0]-ones, frequencies[1]+1, frequencies[2]-1, frequencies[3], frequencies[4]);
  }



  return 0;
}
