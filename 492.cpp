#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/*La complejidad del algoritmo es del orden O(n²). Es aceptado por uva porque n² < 1000000000*/


vector<string> split(string line){
  vector<string> words;
  string spaces, word;
  int i = 0, wordsCnt = 0;

  while(i < line.length()){
    spaces.clear();
    spaces = "";
    while(i < line.length() and !((line[i] >= 65 and line[i] <= 90) or (line[i] >= 97 and line[i] <= 122))){
      spaces.push_back(line[i]);
      i++;
    }
    if(not spaces.empty())
      words.push_back(spaces);


    while(i < line.length() and ((line[i] >= 65 and line[i] <= 90) or (line[i] >= 97 and line[i] <= 122))){
      word.push_back(line[i]);
      i++;
    }
    if(not word.empty())
      words.push_back(word);
    word.clear();
  }

  return words;
}

bool isWord(string word){
  for(int i = 0 ; i < word.length() ; i++)
    if(!((word[i] >= 65 and word[i] <= 90) or (word[i] >= 97 and word[i] <= 122)))
      return false;
  return true;
}

void traductor(string word){
  string sufix = "ay";
  if(isWord(word)){
    if(word[0] == 'a' or word[0] == 'e' or word[0] == 'i' or word[0] == 'o' or word[0] == 'u' or word[0] == 'A' or word[0] == 'E' or word[0] == 'I' or word[0] == 'O' or word[0] == 'U')
      word = word + sufix;
    else{
      sufix.insert(0, 1, word[0]);
      word.erase(0, 1);
      word = word + sufix;
    }
  }
  cout << word;
  sufix.clear();
}


int main(){
  int idx, len, i, j, k;
  string line, sufix;
  vector<string> words;

  while(getline(cin, line)){
    words = split(line);

    for_each(words.begin(), words.end(), traductor);
    cout << endl;
    words.clear();


  }



  return 0;
}
