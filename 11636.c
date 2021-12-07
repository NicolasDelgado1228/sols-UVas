#include <stdio.h>
#include <math.h>

int main(){
	int n;
	int times;
	int casesCnt=0;
	while(1){
		scanf("%d",&n);
		if(n<0){
			break;
		}
		else{
			times=0;
			while((int)pow(2,times)<n){
			times++;
		}
			printf("Case %d: %d\n", n, times);
		}
		
	}

	return 0;
}