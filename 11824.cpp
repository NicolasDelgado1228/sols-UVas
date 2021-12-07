/*
Complejidad: La complejidad del algoritmo es del orden O(nlogn). Es aceptada en uva
porque la funcion f(x) = xlogx tiene una tasa de crecimiento muy pequeña*/

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main(){
	int cases, contLands, land;
	double cont, lands[40], exp;
    cin >> cases;
	while(cases--){
		contLands = 0;
		cont = 0;
		exp = 1;
		fill(lands, lands + 40, 0);

		cin >> land;
		while(land != 0){
			lands[contLands] = land;
			contLands++;
			cin >> land;
		}

        sort(lands, lands + contLands, greater<int>());

        for(int i = 0; i < contLands; i++){
            cont += (2 * pow(lands[i], exp));
            exp++;
        }


		if (cont < 5000000){
            cout << cont << endl;
		}

		else{
			cout << "Too expensive" << endl;
		}
	}
}
