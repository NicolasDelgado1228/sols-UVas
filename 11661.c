#include <stdio.h>
#include <string.h>


int main(){
	int len, i, inicial, dist, min;
	char field[2000001], buscado;

	while(1){
		buscado = '0';
		min = dist = 100000000;
		scanf("%d", &len);
		scanf("%s", field);

		if(len == 0)
			break;

		for(i=0;i<len;i++){

			if(field[i] == 'Z'){
				printf("0\n");
				break;
			}
			else if(field[i] == 'R' && buscado != 'R'){
				buscado = 'D';
				inicial = i;
			}
			else if(field[i] == 'R' && buscado == 'R'){
				dist = i - inicial;
				inicial = i;
				buscado = 'D';
			}
			else if(field[i] == 'D' && buscado != 'D'){
				buscado = 'R';
				inicial = i;
			}
			else if(field[i] == 'D' && buscado == 'D'){
				dist = i - inicial;
				buscado = 'R';
				inicial = i;
			}
			

			if(dist < min)
				min = dist;
		}
		if(field[i] != 'Z')
			printf("%d\n", min);
	}



	return 0;
}