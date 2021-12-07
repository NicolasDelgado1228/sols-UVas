#include <iostream>
using namespace std;

char traducir(string morseCode, char characters[], string morseCodes[]){
  for(int i = 0 ; i < 54 ; i++){
    if(morseCode == morseCodes[i])
      return characters[i];
  }
}

int main(){
  char characters[54]  = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K','L', 'M', 'N', 'O','P','Q',
  'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '.',
  ',', '?', '\'', '!', '/', '(', ')', '&', ':', ';', '=', '+', '-', '_', '"', '@'};

  string morseCode[54] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..",
   "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "-----"
    , ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", ".-.-.-", "--..--", "..--..", ".----.", "-.-.--"
    , "-..-.", "-.--.", "-.--.-", ".-...", "---...", "-.-.-.", "-...-", ".-.-.", "-....-", "..--.-", ".-..-.", ".--.-."};
  string code, key, word;
  char letter;
  int cases, message = 1, i, j, k;

  cin >> cases;
  cin.ignore();
  while(cases--){

    getline(cin, code);

    i = 0;
    while(i < code.length()){
      j = 0;
      while(code[j+i]!=' ' and j+i < code.length()){
        key.push_back(code[i+j++]);
      }
      if(not key.empty())
        word.push_back(traducir(key, characters, morseCode));
      if(j+i+1 < code.length() and code[j+i+1] == ' ' and not word.empty() and word[word.size()-1]!=' '){
        word.push_back(' ');
      }
      key.clear();
      i+=1+j;
    }

    if(cases == 0)
      cout << "Message #" << message++ << endl << word << endl;
    else
      cout << "Message #" << message++ << endl << word << endl << endl;
    word.clear();




  }




  return 0;
}
