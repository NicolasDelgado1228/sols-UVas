#include <stdio.h>

int main(){
  int cases, n, m, i, j, sonares;

  scanf("%d", &cases);
  while(cases--){
    sonares = 0;
    scanf("%d %d", &n, &m);

    printf("%d\n", (n/3)*(m/3));
  }


  return 0;
}
