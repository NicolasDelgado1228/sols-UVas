#include <iostream>
#include <cmath>
using namespace std;

int main(){
  int h1, m1, h2, m2, min1, min2, time;

  while(true){
    scanf("%d %d %d %d", &h1, &m1, &h2, &m2);
    if(h1 == 0 and m1 == 0 and h2 == 0 and m2 == 0)
      break;


    if(h1 == 23 and h2 == 0){
      time = 60 - m1 + m2;
      cout << time << endl;
    }
    else{
      min1 = h1*60 + m1;
      min2 = h2*60 + m2;

      time = fabs(min1 - min2);
      if((h1 > h2) or (h1 >= h2 and m1 >= m2))
        time = 1440 - time;

      cout << time << endl;
    }
  }
}
