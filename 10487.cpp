#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;


/*La complejidad del algoritmo es del orden O(n²) y es aceptada por uva debido a que el tamaño
de la entrada es de 1000, 1000² = 1000000 y 1000000 < 1000000000*/



int main(){
  int card, i, j, k, n, numbers[1000], min, query, queriesCnt, sums[1000000], cases = 1, closestSum;

  while(true){
    cin >> n;
    if(n == 0) break;

    cout << "Case " << cases++ << ":\n";
    for(i = 0 ; i < n ; i++)
      cin >> numbers[i];

    sort(numbers, numbers + n);


    cin >> queriesCnt;
    for(i = 0 ; i < queriesCnt ; i++){
      cin >> query;
      min = 100000000;
      j = 0;
      while(j < n and numbers[j] - query < min){
        k = 0;
        while(k < n){
          if(k != j and fabs(numbers[k] + numbers[j] - query) < min){
            min = fabs(numbers[k] + numbers[j] - query);
            closestSum = numbers[k] + numbers[j];
          }
          if(min == 0) break;

          k++;
        }
        if(min == 0) break;
        j++;
      }

      cout << "Closest sum to " << query << " is " << closestSum << "." << endl;

    }
  }



  return 0;
}
