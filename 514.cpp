#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <list>
#include <string>
using namespace std;

//Usuario juandrengifo

int main(){
  int i, j, coach, len;
  bool first = true;
  while(true){
    cin >> len;
    if(len == 0) break;
    if(not first)
      cout << endl;

    while(true){
      vector<int> ordenDeseado;
      stack<int> estacion, carrilA, carrilB;

      //Se crea lista con el orden deseado
      for(i = 0 ; i < len ; i++){
        cin >> coach;
        if(i == 0 and coach == 0) break;
        ordenDeseado.push_back(coach);
      }
      if(coach == 0) break;
      //Se crea el monticulo con los que vienen de A en orden
      for(i = len ; i > 0 ; i--)
        carrilA.push(i);

      i = 0;
      while(not carrilA.empty()){
        if(not estacion.empty() and estacion.top() == ordenDeseado[i]){
          carrilB.push(estacion.top());
          estacion.pop();
          i++;
        }
        else if(carrilA.top() == ordenDeseado[i]){
          carrilB.push(carrilA.top());
          carrilA.pop();
          i++;
        }
        else{
          estacion.push(carrilA.top());
          carrilA.pop();
        }
      }

      while(not estacion.empty()){
        carrilB.push(estacion.top());
        estacion.pop();
      }

      i = len-1;
      while(i >= 0 and carrilB.top() == ordenDeseado[i]){
        carrilB.pop();
        i--;
      }
      if(carrilB.empty())
        cout << "Yes" << endl;
      else{
        cout << "No" << endl;
        while(not carrilB.empty())
          carrilB.pop();
      }


      ordenDeseado.clear();

    }
    first = false;
  }
  cout << endl;
  return 0;
}
