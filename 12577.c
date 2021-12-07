#include <stdio.h>
#include <string.h>

int main(){
  char rito[6];
  int cases=1;

  do{
    scanf("%s", rito);
    if(strcmp(rito,"*")!=0)
      if(strcmp(rito, "Hajj")==0)
        printf("Case %d: Hajj-e-Akbar\n", cases++);
      else
        printf("Case %d: Hajj-e-Asghar\n", cases++);
  }while(strcmp(rito, "*")!=0);
  return 0;
}
