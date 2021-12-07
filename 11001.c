#include <stdio.h>
#include <math.h>

int main(){
	int v, v0, i, maxDisc;
	long double longitud, max;
	long long int num;


	while(1){
		scanf("%d %d", &v, &v0);
		if(v==0 && v0==0)
			break;

		i = 1;
		max = 0.0;
		while((long double)v/i > v0){
			longitud = i*0.3*sqrt((long double)v/i-(long double)v0);

			if(fabs(longitud - max) < 1e-12){
				max = 0;
				maxDisc = 0;
				break;
			}
			else if(longitud > max){
				maxDisc = i;
				max = longitud;
			}
			i++;
		}
		if(max == 0.0)
			maxDisc = 0;
		printf("%d\n", maxDisc);
	}
	return 0;
}
