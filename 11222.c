#include <stdio.h>
#include <stdlib.h>


int compare(const void * a, const void * b) {
  return ( *(int*)a - *(int*)b );
}

int maxNum(int* arreglo, int n){
	int i=0, max = -10000000;
	for(i;i<n;i++){
		if(arreglo[i]>max)
			max = arreglo[i];
	}
	return max;
}



int main(){
	int cases, c = 1, i, f1[1000], f2[1000], maxAmigos, f3[1000], lens[3], j, matriz[3][10000], num, amigos[3], amigo1, amigo2, amigo3;

	scanf("%d", &cases);
	while(cases--){
		amigo1 = amigo2 = 0;
		amigo3 = 0;

		for(i=0;i<3;i++){
			scanf("%d", lens+i);
			for(j=0;j<lens[i];j++){
				if(i==0)
					scanf("%d", f1+j);
				else if(i==1)
					scanf("%d", f2+j);
				else
					scanf("%d", f3+j);
			}
		}

		qsort(f1, lens[0], sizeof(int), compare);
		qsort(f2, lens[1], sizeof(int), compare);
		qsort(f3, lens[2], sizeof(int), compare);



		for(i=0;i<3;i++)
			for(j=0;j<10000;j++)
				matriz[i][j] = 0;

		for(i=0;i<lens[0];i++){
			num = f1[i];
			matriz[0][num - 1] = num;
		}

		for(i=0;i<lens[1];i++){
			num = f2[i];
			matriz[1][num - 1] = num;
		}

		for(i=0;i<lens[2];i++){
			num = f3[i];
			matriz[2][num - 1] = num;
		}


		for(i=0;i<10000;i++){
			if(matriz[0][i]!=0 && matriz[0][i]!=matriz[1][i] && matriz[0][i]!=matriz[2][i]){
				f1[amigo1] = matriz[0][i];
				amigo1++;
			}
			else if(matriz[1][i]!=0 && matriz[1][i]!=matriz[0][i] && matriz[1][i]!=matriz[2][i]){
				f2[amigo2] = matriz[1][i];
				amigo2++;
			}
			else if(matriz[2][i]!=0 && matriz[2][i]!=matriz[1][i] && matriz[2][i]!=matriz[0][i]){
				f3[amigo3] = matriz[2][i];
				amigo3++;
			}
		}
		amigos[0] = amigo1;
		amigos[1] = amigo2;
		amigos[2] = amigo3;

		maxAmigos = maxNum(amigos, 3);

		printf("Case #%d:\n", c++);
		for(j=0;j<3;j++){
			if(amigos[j] == maxAmigos){
				if(j == 0){
					printf("1 %d ", amigo1);
					for(i=0;i<amigo1;i++){
						if(i+1<=amigo1-1)
							printf("%d ", f1[i]);
						else
							printf("%d", f1[i]);
							
					}
					printf("\n");
				}
				else if(j==1){
					printf("2 %d ", amigo2);
					for(i=0;i<amigo2;i++){
						if(i+1<=amigo2-1)
							printf("%d ", f2[i]);
						else
							printf("%d", f2[i]);
					}
					printf("\n");
				}
				else{
					printf("3 %d ", amigo3);
					for(i=0;i<amigo3;i++){
						if(i+1<=amigo3-1)
							printf("%d ", f3[i]);
						else
							printf("%d", f3[i]);
					}
					printf("\n");
				}
			}
		}

		
		

		for(i=0;i<lens[0];i++)
			f1[i] = 0;
		for(i=0;i<lens[1];i++)
			f2[i] = 0;
		for(i=0;i<lens[2];i++)
			f3[i] = 0;

		for(i=0;i<3;i++)
			for(j=0;j<10000;j++)
				matriz[i][j] = 0;

		
		

	}



	return 0;
}