#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int compare(const void * a, const void * b) {
  return ( fabs(*(int*)a) - fabs(*(int*)b) );
}



int main(){
	int cases, floors[500000], floorsCnt, i, pisos;

	scanf("%d", &cases);
	while(cases--){
		scanf("%d", &floorsCnt);

		if(floorsCnt == 0){
			printf("0\n");
			continue;
		}

		for(i=0;i<floorsCnt;i++)
			scanf("%d", floors + i);
		
		qsort(floors, floorsCnt, sizeof(int), compare);

		
		pisos = 1;
		for(i = 0; i < floorsCnt-1; i++){
			if((floors[i] < 0 && floors[i+1] > 0) || (floors[i] > 0 && floors[i+1] < 0))
				pisos++;
		}

		printf("%d\n", pisos);
		
	}




	return 0;

}