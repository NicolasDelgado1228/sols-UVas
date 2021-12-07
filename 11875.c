#include <stdio.h>

int main(){
  int cases, c=1, len, i, ages[11];

  scanf("%d", &cases);
  while(c<=cases){
    scanf("%d", &len);
    for(i=0;i<len;i++){
      scanf("%d", ages+i);
    }

    printf("Case %d: %d\n", c++, ages[len/2]);

  }
  return 0;
}
