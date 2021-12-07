#include <iostream>
#include <algorithm>
using namespace std;

/*El algoritmo tiene una complejidad del orden O(n). Debido a eso es aceptado por uva*/
void imprimir(string a){
	cout << a << " ";
}

int main(){
	int carsCnt, i, j, k, endPos;
	string iniPos, positions[1000];
	bool wrong;

	while(true){
		cin >> carsCnt;
		wrong = false;

		if(carsCnt == 0)
			return 0;

		fill(positions, positions + carsCnt, "0");


		for(i = 0 ; i < carsCnt ; i++){
			cin >> iniPos >> endPos;


			if(i + endPos < carsCnt and i + endPos >= 0 and positions[i + endPos] == "0")
				positions[i + endPos] = iniPos;
			else
				wrong = true;
		}

		if(not wrong){
			for_each(positions, positions + carsCnt - 1, imprimir);
			cout << positions[carsCnt - 1] << endl;
		}
		else
			cout << "-1" << endl;
	}


	return 0;
}
