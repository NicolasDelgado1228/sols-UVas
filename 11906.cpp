#include <bits/stdc++.h>
using namespace std;



int main(){
  int cases, r, c, m, n, waters, x, y, evensCnt, oddsCnt, cnt, cas = 1;

  cin >> cases;
  while(cases--){
    cin >> r >> c >> m >> n;
    vector<vector<int>> grid;
    for(int i = 0 ; i < r ; i++){
      vector<int> aux;
      grid.push_back(aux);
      for(int j = 0 ; j < c ; j++)
        grid[i].push_back(0);
    }

    cin >> waters;
    while(waters--){
      cin >> x >> y;
      grid[x][y] = -1;
    }

    pair<int,int> d = make_pair(m,n);

    //DFS
    evensCnt = oddsCnt = 0;
    stack<pair<int,int>> stack;
    stack.push(make_pair(0,0));
    grid[0][0] = 1;

    while(not stack.empty()){
      pair<int,int> node = stack.top();
      stack.pop();

      if(d.first == 0 or d.second == 0){
        int e1[] = {1,-1}, x = node.first, y = node.second, dx1, dy1, dx2, dy2;

        cnt = 0;
        for(int i = 0 ; i < 2 ; i++){
            dx1 = x + d.first*e1[i];
            dy1 = y + d.second*e1[i];
            dx2 = x + d.second*e1[i];
            dy2 = y + d.first*e1[i];

            if(dx1 < c and dx1 >= 0 and dy1 < r and dy1 >= 0 and grid[dy1][dx1] != -1){
              cnt++;
              if(grid[dy1][dx1] == 0){
                stack.push(make_pair(dx1,dy1));
                grid[dy1][dx1] = 1;
              }
            }

            if(dx2 < c and dx2 >= 0 and dy2 < r and dy2 >= 0 and grid[dy2][dx2] != -1 and not (dx2 == dx1 and dy1 == dy2)){
              cnt++;
              if(grid[dy2][dx2] == 0){
                stack.push(make_pair(dx2,dy2));
                grid[dy2][dx2] = 1;
              }
            }
        }
        if(cnt%2==0) evensCnt++;
        else oddsCnt++;
      }
      else{

        int e1[] = {1,1,-1,-1}, e2[] = {-1,1,-1,1}, x = node.first, y = node.second, dx1, dy1, dx2, dy2;

        cnt = 0;
        for(int i = 0 ; i < 4 ; i++){
          dx1 = x + d.first*e1[i];
          dy1 = y + d.second*e2[i];
          dx2 = x + d.second*e1[i];
          dy2 = y + d.first*e2[i];

          if(dx1 < c and dx1 >= 0 and dy1 < r and dy1 >= 0 and grid[dy1][dx1] != -1){
            cnt++;
            if(grid[dy1][dx1] == 0){
              stack.push(make_pair(dx1,dy1));
              grid[dy1][dx1] = 1;
            }
          }

          if(dx2 < c and dx2 >= 0 and dy2 < r and dy2 >= 0 and grid[dy2][dx2] != -1 and not (dx2 == dx1 and dy1 == dy2)){
            cnt++;
            if(grid[dy2][dx2] == 0){
              stack.push(make_pair(dx2,dy2));
              grid[dy2][dx2] = 1;
            }
          }
        }
        if(cnt%2==0) evensCnt++;
        else oddsCnt++;
      }

    }

    cout << "Case " << cas++ << ": " << evensCnt << " " << oddsCnt << endl;
  }



  return 0;
}
