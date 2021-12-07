#include <stdio.h>

int main(){
	int cases, walls, high, low, w[60], i, c=1;
	scanf("%d", &cases);

	while(cases--){
		high = low = 0;
		scanf("%d", &walls);

		for(i=0;i<walls;i++){
			scanf("%d", w+i);
		}

		for(i=0;i<walls-1;i++){
			if(w[i]>w[i+1])
				low++;
			else if(w[i]<w[i+1])
				high++;
		}

		printf("Case %d: %d %d\n", c++, high, low);
	}


	return 0;
}