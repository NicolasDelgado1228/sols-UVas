#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

/*
El algoritmo tiene una complejidad del orden O(nlogn) debido a que la operacion mas
costosa en terminos computacionales es el ordenamiento
*/

void imprimir(int i){
	cout << i << endl;
}

class Compare{
public:
	int m;

	bool operator ()(int a, int b){
		if(a%m == b%m){
			if(a%2 == 0 and b%2 != 0)
				return false;
			else if(a%2 != 0 and b%2 == 0)
				return true;
			else if(a%2 != 0 and b%2 != 0)
				return a > b;
			else if(a%2 == 0 and b%2 == 0)
				return a < b;
		}
		else
			return a%m < b%m;
	}
};




int main(){
	int n, m, i, j, numbers[10000];
	Compare compare;


	while(true){
		cin >> n >> m;

		compare.m = m;

		if(n == 0 and m == 0){
			cout << "0 0" << endl;
			break;
		}

		for(i = 0 ; i < n ; i++)
			cin >> numbers[i];

		sort(numbers, numbers + n, compare);
		cout << n << " " << m << endl;
		for_each(numbers, numbers + n, imprimir);
	}


	return 0;
}
