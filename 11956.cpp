#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void imprimir(int a){
  if(a<=15)
    printf("0%X", a);
  else
    printf("%X", a);
}

int main(){
  int testCases, i, pointer, j;

  cin >> testCases;
  for(i = 0 ; i < testCases ; i++){
    string line;
    int display[100];
    fill(display, display + 100, 0);

    cin >> line;

    pointer = 0;
    for(j = 0 ; j < line.size() ; j++){
      if(line[j] == '>'){
        if(pointer == 99)
          pointer = 0;
        else
          pointer++;
      }
      else if(line[j] == '<'){
        if(pointer == 0)
          pointer = 99;
        else
          pointer--;
      }
      else if(line[j] == '+'){
        if(display[pointer] == 255)
          display[pointer] = 0;
        else
          display[pointer]++;
      }
      else if(line[j] == '-'){
        if(display[pointer] == 0)
          display[pointer] = 255;
        else
          display[pointer]--;
      }
    }

    printf("Case %d: ", i+1);
    imprimir(display[0]);
    for(j = 1 ; j < 100 ; j++){
      printf(" ");
      imprimir(display[j]);
    }

    cout << endl;
  }

  return 0;
}
