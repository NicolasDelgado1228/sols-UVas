#include <bits/stdc++.h>
using namespace std;


void countDigits(string n, int freq[]){
  for(int i = 0 ; i < n.length() ; i++){
    int num = (int)(n[i])-48;
    freq[num] = freq[num] + 1;
  }
}


int main(){
  int cases, num;
  cin >> cases;

  while(cases--){
    string n;
    cin >> n;

    int freq[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    for(int i = 1 ; i <= stoi(n) ; i++) countDigits(to_string(i), freq);
    cout << freq[0];
    for(int i = 1 ; i < 10 ; i++) cout << " " << freq[i];
    cout << endl;
  }




  return 0;
}
