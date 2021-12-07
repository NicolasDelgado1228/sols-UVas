#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;


vector<string> split(string input, string token){
  vector<string> serie;
  string note;
  int i = 0;
  while(input.find(token, i) != string::npos){
    note = input.substr(i, input.find(token, i) - i);
    if(find(serie.begin(), serie.end(), note) == serie.end())
      serie.push_back(note);
    i = input.find(token, i) + 1;
  }

  if(find(serie.begin(), serie.end(), input.substr(i, input.length()-i)) == serie.end())
    serie.push_back(input.substr(i, input.length()-i));

  return serie;
}

void createScale(string* scale, string key){
  string notas[] = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B", "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B", "C", "C#", "D", "D#", "E", "F", "F#", "G"};
  int j = 0, idx = find(notas, notas + 13, key) - notas;

  for(int i = 0 ; i < 12 ; i++){
    if(i == 0 or i == 2 or i == 4 or i == 5 or i == 7 or i == 9 or i == 11)
      scale[j++] = notas[idx + i];
  }
}

int main(){
  string input, scale[7], key;
  string notas[] = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"};
  vector<string> serie, keys;
  int i, j, k, l, serieCnt;

  while(true){
    getline(cin, input);
    if(input == "END") break;

    serie = split(input, " ");


    sort(serie.begin(), serie.end());

    for(i = 0 ; i < 12 ; i++){
      key = notas[i];

      createScale(scale, key);
      sort(scale, scale + 7);

      if(includes(scale, scale + 7, serie.begin(), serie.end()))
        keys.push_back(key);
    }

    if(not keys.empty()){
      cout << keys[0];
      for(i = 1 ; i < keys.size() ; i++)
        cout << " " << keys[i];
    }
    cout << endl;

    keys.clear();
    input.clear();
    serie.clear();



  }

  return 0;


}
