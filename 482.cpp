#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    int casos, cont,contAr;
    cin >> casos;
    cin.ignore();
    string numeros = "";
    string salto;

    while(casos--){
        getline(cin, salto);
        vector<int> vec;
        vector<string> vec1;
        cont = 0;
        contAr = 0;
        string primero;
        string segundo;
        string val = "";
        getline(cin, primero);
        getline(cin, segundo);

        for(int i = 0; i < primero.size(); i++){
            if(primero[i] == ' '){
                vec.push_back(stoi(primero));
                for (int j = 0; j < i; j++){
                    primero[j] = ' ';
                }
                contAr++;
            }

            if(i == primero.size() - 1){
                vec.push_back(stoi(primero));
            }
        }

        for(int i = 0; i < segundo.size(); i++){
            if(segundo[i] != ' '){
                val.push_back(segundo[i]);
            }

            else if(segundo[i] == ' ' and segundo[i + 1] != ' '){
                vec1.push_back(val);
                val.clear();
            }

            if(i == segundo.size() - 1){
                vec1.push_back(val);
            }
        }

        for (int i = 1; i < vec.size() + 1; i++){
            for(int j = 0; j < vec.size(); j++){
                if(vec[j] == i){
                    cout << vec1[j] << endl;
                }
            }
        }
        cont++;
        if (cont < vec.size() - 1){
            cout << endl;
        }
        vec.clear();
        vec1.clear();
    }
    return 0;
}
