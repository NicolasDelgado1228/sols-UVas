#include <stdio.h>
#include <stdlib.h>

int compare(const void * a, const void * b) {
  if(( *(double*)a - *(double*)b )>0)
    return 1;
  if(( *(double*)a - *(double*)b )==0)
    return 0;
  if(( *(double*)a - *(double*)b )<0)
    return -1;
}

int main(){
  int cases, segmentsCnt, k=0, i=0, j=0, n, pivote, x;
  double pivot, coe;
  double* segSort;
  double* outputs;
  double **segments;



  scanf("%d", &cases);
  while(cases--){
    scanf("%d", &segmentsCnt);
    segments = (double **)malloc(sizeof(double*) *segmentsCnt);
    segSort = (double*)malloc(sizeof(double)*segmentsCnt*2);
    outputs = (double*)malloc(sizeof(double)*segmentsCnt*2);
    for(x=0; x<segmentsCnt; x++){
      segments[x]=(double*)malloc(sizeof(double)*5);
    }
    j=0;
    for(k = 0; k<segmentsCnt; k++){
      scanf("%lf %lf %lf %lf %lf", *(segments+k), (*(segments+k)+1), (*(segments+k)+2), (*(segments+k)+3), (*(segments+k)+4));
      if(segments[k][0]>segments[k][2]){
        pivot=segments[k][2];
        segments[k][2]=segments[k][0];
        segments[k][0]=pivot;
      }
      segSort[j]=segments[k][0];
      segSort[j+1]=segments[k][2];
      j+=2;
    }

    qsort(segSort, segmentsCnt*2, sizeof(double), compare);
    for(i=0;i<segmentsCnt*2-1;i++){
      coe=1.0;
      for(j=0;j<segmentsCnt;j++){
        if((((segSort[i+1]-segSort[i])/2)+segSort[i]) >= segments[j][0] && (((segSort[i+1]-segSort[i])/2)+segSort[i]) < segments[j][2])
          coe*=segments[j][4];
      }

      outputs[i]=coe;
    }
    printf("%d\n-inf %.3lf 1.000\n", segmentsCnt*2+1, segSort[0]);
    for(k=0;k<segmentsCnt*2-1;k++)
      printf("%.3lf %.3lf %.3lf\n", segSort[k], segSort[k+1], outputs[k]);
    printf("%.3lf +inf 1.000\n", segSort[segmentsCnt*2-1]);
    if(cases!=0)
      printf("\n");



  }



  return 0;
}
