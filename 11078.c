#include <stdio.h>



int main(){
	int casos, estudiantes, i=0, senior, noob, dif;
	int iqs[100000];

	scanf("%d",&casos);
	while(casos--){


		scanf("%d",&estudiantes);
		for(i=0;i<estudiantes;i++){
			scanf("%d",iqs+i);
		}
		dif=-100000000;
		senior=iqs[0];
		for(i=1;i<estudiantes;i++){
			noob=iqs[i];
			if(senior-noob>dif && senior-noob!=0)
				dif=senior-noob;
			if(noob>senior)
				senior=noob;
		}
		printf("%d\n", dif);


	}
	return 0;
}