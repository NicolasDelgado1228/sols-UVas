#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;


int main(){
	string input, matrix[100][5];
	int i, k , citiesCnt, cities[100], max, optimum;

	while(true){

		

		//Llenar la matriz
		i = 0;
		do{

			cin >> input;
			if(input == "#")
				break;
			if(input[0] == 'e')
				break;

			k = 0;
			for(int j = 0;j < 17;j+=4){
				matrix[i][k] = input.substr(j, 3);
				k++;
			}
			i++;

		}while(input[0] != 'e');

		citiesCnt = i;
		if(input == "#")
			break;

		for(int i = 0;i < citiesCnt;i++)
			cities[i] = 0;

		for(int i = 0; i < citiesCnt; i++){
			for(int j = 0; j < 5; j++){
				for(int k = 0; k < citiesCnt; k++){

					if(k == i) continue;

					for(int l = 0; l < 5; l++){
						if(matrix[k][l] == matrix[i][j])
							cities[i]++;
					}
				}
			}
		}

		max = -10000000;
		for(int i = 0; i < citiesCnt ; i++){
			if(cities[i] > max){
				max = cities[i];
				optimum = i + 1;
			}
		}

		cout << optimum << endl;




	}
	return 0;
}