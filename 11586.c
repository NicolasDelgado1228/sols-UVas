#include <stdio.h>
#include <string.h>

void limpiar(char* string){
	char* p = strchr(string, '\n');
	if(p)
		*p = '\0';
}
int main(){
	int cases, i, male, female, len;
	char pieces[500];

	scanf("%d\n", &cases);
	while(cases--){
		male = female = 0;
		fgets(pieces, 500, stdin);
		limpiar(pieces);
		len = strlen(pieces);


		for(i=0;i<len;i++){
			if(pieces[i] == 'M')
				male++;
			else if(pieces[i] == 'F')
				female++;
		}
		if(male == 1 && female == 1)
			printf("NO LOOP\n");
		else if(male == female)
			printf("LOOP\n");
		else
			printf("NO LOOP\n");
	}



	return 0;
}