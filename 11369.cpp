#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
DESCRIPCION DEL ALGORITMO:
Se necesita encontrar el máximo descuento posible. Hay un descuento cuando se compran 3 productos.
El descuento va a ser del producto con el menor precio. Para dar solución a este problema
ordené los precios de mayor a menor y por cada 3 precios, encontré el mínimo y se lo sumé a una 
variable que representa el total del descuento
*/

bool compare(int a, int b){
  return a > b;
}

int main(){
  int cases, prices[300000], pricesCnt, i, salto, discount, j, k;
  cin >> cases;

  while(cases--){
    cin >> pricesCnt;

    for(i = 0 ; i < pricesCnt ; i++)
      cin >> prices[i];

    sort(prices, prices + pricesCnt, compare);
    i = j = discount = 0;
    while(i < pricesCnt/3){
      discount += *min_element(prices + j, prices + j + 3);
      j+=3;
      i++;
    }
    cout << discount << endl;
  }


  return 0;
}
