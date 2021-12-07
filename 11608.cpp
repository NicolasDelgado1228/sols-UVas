#include <iostream>
using namespace std;

int main(){
  int totalProblemas, problems[13], problemsNeeded[12], i, j, k, cases = 1;

  while(true){
    totalProblemas = 0;
    cin >> problems[0];

    if(problems[0] < 0)
      break;

    for(i = 1 ; i < 13 ; i++)
      cin >> problems[i];
    for(i = 0 ; i < 12 ; i++)
      cin >> problemsNeeded[i];

    cout << "Case " << cases << ":" << endl;
    for(i = 0 ; i < 12 ; i++){
      totalProblemas += problems[i];
      if(totalProblemas >= problemsNeeded[i]){
        totalProblemas-=problemsNeeded[i];
        cout << "No problem! :D" << endl;
      }
      else
        cout << "No problem. :(" << endl;


    }


    cases++;
  }
  return 0;
}
