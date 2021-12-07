#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/*
DESCRIPCIÓN ALGORITMO:
La solucion de este problema vino a mi porque es una situacion parecida al ejercicio 10057, hay que
encontrar la distancia mínima entre todos los puntos. En este caso es necesario encontrar la coordenada
x y la coordenada y que estén mas cerca de todos los números, para solucionar este problema usé el concepto
de la mediana estadíastica, pues esa es la distancia mínima entre un arreglo de numeros. Para calcular
la mediana, es necesario ordenar los números y el resultado será el de la mitad. En caso de que queden
dos, se suman y se dividen, sin embargo, en este problema se elige el de la izquierda (mas pequeño).

*/

int main(){
  int cases, m, n, points, x, y, len;
  vector<int> xS;
  vector<int> yS;

  cin >> cases;

  while(cases--){
    cin >> m >> n >> points;
    while(points--){
      cin >> x >> y;
      xS.push_back(x);
      yS.push_back(y);
    }

    sort(xS.begin(), xS.end());
    sort(yS.begin(), yS.end());
    len = xS.size();
    if(len % 2 == 0)
      cout << "(Street: " << xS[(len/2)-1] << ", Avenue: " << yS[(len/2)-1] << ")" << endl;
    else
      cout << "(Street: " << xS[len/2] << ", Avenue: " << yS[len/2] << ")" << endl;

    xS.clear();
    yS.clear();
  }

  return 0;
}
