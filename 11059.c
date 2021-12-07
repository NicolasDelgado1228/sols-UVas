#include <stdio.h>
#include <string.h>

long long productorio(int* arreglo, int from, int to){
  int i=from;
  long long product=0;
  if(i<to){
    product=1;
    for(i;i<to;i++){
      product*=arreglo[i];
    }
  }
  return product;
}

long long max(long long* arreglo, int n){
  int i=1;
  long long max=arreglo[0];
  for(i;i<n;i++){
    if(arreglo[i]>max){
      max=arreglo[i];
    }
  }
  return max;
}

int main(){
  int n, i, bandera, arreglo[1000], j, negatives[1000], negativesIdx[1000], negCnt, pCnt, neg, k, cases=1;
  long long productos[1000], biggest;

  while(scanf("%d", &n) != EOF){
    pCnt=0;
    for(i=0; i<n ; i++){
      scanf("%d", arreglo+i);
    }
    negCnt=0;
    for(i=0;i<n;i++){
      if(arreglo[i]<0)
        negCnt++;
    }

    i=0;
    while(i<n){
      j=0;
      negCnt=0;
      while((i+j)<n && arreglo[i+j]!=0){
        if(arreglo[i+j]<0){
          negatives[negCnt]=arreglo[j+i];
          negativesIdx[negCnt]=j+i;
          negCnt++;
        }
        j++;
      }

      if(negCnt%2==0){
        productos[pCnt]=productorio(arreglo, i, i+j);
        pCnt++;
      }
      else{
        for(neg=0;neg<negCnt;neg++){
          productos[pCnt]=productorio(arreglo, i, negativesIdx[neg]);
          pCnt++;
          productos[pCnt]=productorio(arreglo, negativesIdx[neg]+1, i+j);
          pCnt++;

        }
      }

      i+=j+1;
    }
    bandera=0;
    for(i=0;i<pCnt;i++){
      if(productos[i]>0)
        bandera=1;
    }
    if(bandera)
      printf("Case #%d: The maximum product is %lld.\n\n", cases, max(productos, pCnt));
    else
      printf("Case #%d: The maximum product is 0.\n\n", cases);
    cases++;
  }



  return 0;
}
