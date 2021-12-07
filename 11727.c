#include <stdio.h>

int main(){
	int cases, employees[3], i, max, min,c=1;

	scanf("%d", &cases);

	while(cases--){
		scanf("%d %d %d", employees, employees + 1, employees + 2);
		max = min = employees[0];
		for(i=1;i<3;i++){
			if(employees[i]>max)
				max = employees[i];
			if(employees[i] < min)
				min = employees[i];
		}

		for(i=0;i<3;i++){
			if(employees[i]!=min && employees[i]!= max){
				printf("Case %d: %d\n", c++, employees[i]);
				break;
			}
		}
	}



	return 0;
}