#include <stdio.h>
#include <math.h>

int main(){
  int cases;
  long long warriors, fila;
  long double w;
  scanf("%d", &cases);
  while(cases--){
    scanf("%lld", &warriors);

    if(warriors==0){
      printf("0\n");
      continue;
    }
    w=(double)warriors;

    fila= (-1+sqrt(1+(8*w)))/2;

    printf("%lld\n", fila);
  }

  return 0;
}
