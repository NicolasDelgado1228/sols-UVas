#include <iostream>
#include <vector>
#include <string>
#include "string.h"
using namespace std;

bool isSubstr(string code, string num){
  int i, j, k, counter;

  for(i = code.length()-1 ; i >= 0 ; i--)
    if(code[i] != num[i])
      return false;
  return true;
}


void setString(char str[], int n){
  for(int i = 0 ; i < n ; i++){
    str[i] = ' ';
  }
}




int main(){
  string input, price, city, codigo, ciudadCosto, ciudad, costo, number, pureNumber, base;
  int duration, len, max;
  vector<string> codigoNumeros, codigosSorted, subStrings, codigos, ciudades, costos, numbers, pureNumbers;
  vector<int> durations;
  int i, j, k;
  bool unknown;

  while(true){
    getline(cin, ciudadCosto);

    i = 0;
    while(i < ciudadCosto.length() and ciudadCosto[i] != ' '){
      codigo.push_back(ciudadCosto[i++]);
    }
    if(codigo == "000000")
      break;
    else
      codigos.push_back(codigo);
    codigo.clear();

    for(j = 0 ; j < i ; j++)
      ciudadCosto.erase(0,1);

    i = 0;
    while(ciudadCosto[i]==' '){
      ciudadCosto.erase(0,1);
      i++;
    }

    i = 0;
    while(ciudadCosto[i] != '$'){
      ciudad.push_back(ciudadCosto[i]);
      i++;
    }
    ciudades.push_back(ciudad);
    ciudad.clear();
    i = i + 1;

    while(i < ciudadCosto.length()){
      if(ciudadCosto[i] != ' ')
        costo.push_back(ciudadCosto[i]);
      i++;
    }
    costos.push_back(costo);
    costo.clear();
  }

  while(true){
    cin >> number;
    if(number == "#")
      break;
    else
      numbers.push_back(number);

    cin >> duration;
    durations.push_back(duration);

    if(number[0] != '0'){
      pureNumbers.push_back(number);
      continue;
    }

    i = 0;
    while(i < codigos.size()){
      if((codigos[i][0]=='0' and codigos[i][1]=='0' and number.length()-codigos[i].length() >= 4
          and number.length()-codigos[i].length() <= 10 and isSubstr(codigos[i], number)) or
          (codigos[i][0]=='0' and codigos[i][1]!='0' and number.length()-codigos[i].length() >= 4
              and number.length()-codigos[i].length() <= 7 and isSubstr(codigos[i], number))){

        base = number.substr(codigos[i].length(), number.length()-codigos[i].length());
        pureNumbers.push_back(base);
        codigoNumeros.push_back(number.substr(0, number.length()-base.length()));
        base.clear();
        break;
      }
      i++;
    }
    if(i == codigos.size())
      pureNumbers.push_back("unknown");
  }




  for(i = 0 ; i < numbers.size() ; i++){
    if(pureNumbers[i] != "unknown"){
      if(pureNumbers[i] == numbers[i])
        printf("%-16s%-25s%10s%5d%6.2lf%7.2lf\n", numbers[i].c_str(), "Local", pureNumbers[i].c_str(), durations[i], 0.0, 0.0);
      else{


        for(j = 0 ; j < codigos.size() ; j++){
          if(isSubstr(codigos[j], numbers[i])){
            subStrings.push_back(codigos[j]);
          }
        }


        for(j = 0 ; j < subStrings.size() ; j++){
          if( subStrings[j]+pureNumbers[i] == numbers[i]){
            max = j;
          }
        }
        for(j = 0 ; j < codigos.size() ; j++){
          if(codigos[j] == subStrings[max]){
            city = ciudades[j];
            price = costos[j];
          }
        }


        printf("%-16s%-25s%10s%5d%6.2lf%7.2lf\n", numbers[i].c_str(), city.c_str(), pureNumbers[i].c_str(), durations[i], (float)stoi(price)/100, ((float)stoi(price)/100)*durations[i]);
        city.clear();
        price.clear();
        subStrings.clear();

      }
    }
    else{
      printf("%-16s%-25s%10s%5d%6s%7.2lf\n", numbers[i].c_str(), "Unknown", "", durations[i], "", -1.00);
    }
  }
















  return 0;
}
