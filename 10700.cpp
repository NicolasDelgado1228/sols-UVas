#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>
using namespace std;

int main(){
  long long int cases, sumatory, i, j, k, len, last, productorio, sumatoria;
  vector<long long int> numbers, multiplications, summations;
  vector<char> operations;
  string polynom, number;

  cin >> cases;
  while(cases--){
    cin >> polynom;

    number = "";
    for(i = 0 ; i < polynom.length() ; i++){
      if(polynom[i] == '*' or polynom[i] == '+'){
        operations.push_back(polynom[i]);
        numbers.push_back(stoi(number));
        number = "";
      }
      else{
        number.push_back(polynom[i]);
      }
    }

    numbers.push_back(stoi(number));



    summations = multiplications = numbers;

    i = j = 0;
    while(i < operations.size()){
      if(j < multiplications.size()-1 and operations[i] == '+'){
        multiplications[j] = multiplications[j] + multiplications[j+1];
        multiplications.erase(multiplications.begin()+j+1);
        j--;
      }
      j++;
      i++;
    }

    productorio = 1;
    for(i = 0; i < multiplications.size() ; i++)
      productorio*=multiplications[i];


    i = j = 0;
    while(i < operations.size()){
      if(j < summations.size()-1 and operations[i] == '*'){
        summations[j] = summations[j] * summations[j+1];
        summations.erase(summations.begin()+j+1);
        j--;
      }
      j++;
      i++;
    }

    sumatoria = 0;
    for(i = 0; i < summations.size() ; i++)
      sumatoria+=summations[i];

    cout << "The maximum and minimum are "<< productorio << " and " << sumatoria <<"." << endl;
    numbers.clear();
    multiplications.clear();
    summations.clear();
    operations.clear();

  }


  return 0;
}
