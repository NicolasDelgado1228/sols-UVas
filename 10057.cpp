#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
El algoritmo tiene una complejidad del orden O(nlogn). Es aceptado por uva debido a que
1000*log1000 < 1000000000.
*/
int main(){
  int n, i, numero, len, codigo, repeticiones, codigo2, totalCodigos;
  vector<int> numeros;

  while (cin >> n){

    for(i = 0 ; i < n; i++){
      cin >> numero;
      numeros.push_back(numero);
    }

    len = numeros.size();

    sort(numeros.begin(), numeros.end());

    if(len%2 != 0){
      codigo = numeros[len/2];
      repeticiones = count(numeros.begin(), numeros.end(), codigo);
      cout << codigo << " " << repeticiones << " 1" << endl;
    }
    else{
      codigo = numeros[len/2-1];
      if(codigo != numeros[len/2])
        repeticiones = count(numeros.begin(), numeros.end(), codigo) + count(numeros.begin(), numeros.end(), numeros[len/2]);
      else
        repeticiones = count(numeros.begin(), numeros.end(), codigo);
      cout << codigo << " " << repeticiones << " " << numeros[len/2] - codigo + 1 << endl;
    }

    numeros.clear();


  }
  return 0;
}
