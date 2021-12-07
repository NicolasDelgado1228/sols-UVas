#include <stdio.h>
#include <string.h>
#include <stdlib.h>



int main(){
  char n[10000];
  int cases, patron[5]={76,16,56,96,36}, len, last;

  scanf("%d", &cases);

  while(cases--){
    scanf("%s",n);
    len=strlen(n);

    if(len==1 && n[0]=='0'){
      printf("1\n");
      continue;
    }
    else if(len==1 && n[0]=='1'){
      printf("66\n");
      continue;
    }

    last=atoi(n+len-1);
    if(last%5==0)
      printf("%d\n", patron[0]);
    else if(last%5==1)
      printf("%d\n", patron[1]);
    else if(last%5==2)
      printf("%d\n", patron[2]);
    else if(last%5==3)
      printf("%d\n", patron[3]);
    else if(last%5==4)
      printf("%d\n", patron[4]);

    }
  return 0;
}
