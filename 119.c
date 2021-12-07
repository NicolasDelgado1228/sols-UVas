#include <stdio.h>
#include <string.h>

void recibir(char nombres[10][13], int n, int money, char* destino, int* dineros){
	int i=0;
	for(i;i<n;i++){
		if(sdtrcmp(nombres[i], destino)==0){
			dineros[i] += money;
		}
	}
}

void regalar(char nombres[10][13], int n, int money, char* destinatario, int* dineros){
	int i=0;
	for(i;i<n;i++){
		if(strcmp(nombres[i], destinatario)==0){
			dineros[i] -= money;
		}
	}
}

int main(){
	int n, i, dinero[10], money, subList, j, regalo, flag = 0;
	char group[10][13], nombre[13], nombre2[13];

	while(scanf("%d", &n) != EOF){
		if(flag)
			printf("\n");
		for(i=0;i<n;i++){
			scanf("%s", nombre);
			strcpy(group[i], nombre);
			dinero[i] = 0;
		}

		for(i=0;i<n;i++){
			scanf("%s", nombre);
			scanf("%d", &money);
			scanf("%d", &subList);

			for(j=0;j<subList;j++){
				scanf("%s", nombre2);
				regalo = money/subList;
				regalar(group, n, regalo, nombre, dinero);
				recibir(group, n, regalo, nombre2, dinero);
			}
		}

		for(i=0;i<n;i++){
			printf("%s %d\n", group[i], dinero[i]);
		}
		flag = 1;

	}




	return 0;
}
