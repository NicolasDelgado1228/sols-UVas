#include <stdio.h>
#include <string.h>


void limpiar(char* string){
  char* p;
  p=strchr(string, '\n');
  if(p){
    *p='\0';
  }
}

int maximo(int *arreglo, int n){
  int i=0, max=0;
  for(i=0;i<n;i++){
    if(arreglo[i]>max){
      max=i;
    }
  }
  return max;
}


int main(){
  int cases, len, i, j, dots, scarecrows, k=1, last, dotsCnt[120], dotsPos[120], dCnt, historial;
  char field[120];
  scanf("%d\n", &cases);

  while(k<=cases){
    scarecrows = historial = 0;
    scanf("%d\n", &len);
    fgets(field, 101, stdin);
    limpiar(field);

    for(i=0;i<len;i++){
      if(field[i]=='.'){
        last=i;
        break;
      }
    }

    i=last;
    while(i<len){
      if(field[i]=='.')
        last=i;
      else{
        i++;
        continue;
      }
      j = last;
      dCnt=0;
      while(j<len && j-2!=last){
        dots=0;
        if(field[j]=='.')
          dots++;
        if(j+1<len && field[j+1]=='.')
          dots++;
        if(j-1>=0 && j-2!=historial && field[j-1]=='.')
          dots++;
        dotsCnt[dCnt]=dots;
        dotsPos[dCnt]=j;
        dCnt++;
        j++;
      }
      scarecrows++;
      i=dotsPos[maximo(dotsCnt, dCnt)]+2;
      historial=dotsPos[maximo(dotsCnt, dCnt)];
    }
    printf("Case %d: %d\n", k++, scarecrows);

  }

  return 0;
}
