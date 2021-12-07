#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;


/*
Complejidad:
La Complejidad de esta solución se puede decir que es constante porque el tamaño máximo que puede tomar la entrada
es muy pequeño, (no tiende a infinito), de modo que el orden sería O(1). Sim embargo, la operación con más costo
computacional es el ordenamiento, haciendo que si la entrada tiende a infinito, el algoritmo tendría una complejidad
del orden O(nlogn)
*/

bool operator ==(string str[], string array){
  return *str == array;
}


string operator -(string s1, string s2){
  return to_string(stoi(s1)-stoi(s2));
}

string operator +(string s1, string s2){
  return to_string(stoi(s1)+stoi(s2));
}

string operator *(string s1, int a){
  return to_string(stoi(s1)*a);
}

string operator/(string s1, string s2){
  return to_string((double)(stoi(s1)) / (double)(stoi(s2)));
}


void setTeams(string* arreglo, string pos1, string pos2, string pos3, string pos4){
  string nums[4] = {pos1, pos2, pos3, pos4};
  for(int i = 1 ; i < 5 ; i++)
    arreglo[i] = arreglo[i] + nums[i-1];

}

bool arreglosIguales(string* a, string* b){
  return a[1] == b[1] and a[3] == b[3] and a[4] == b[4];
}

bool compare(string* a, string* b){
  string comp1, comp2;
  comp1 = a[0];
  comp2 = b[0];
  transform(comp1.begin(), comp1.end(), comp1.begin(), ::tolower);
  transform(comp2.begin(), comp2.end(), comp2.begin(), ::tolower);

  if(stoi(a[1]) == stoi(b[1])){
    if(stoi(a[5]) == stoi(b[5])){
      if(stoi(a[3]) == stoi(b[3])){
        return  comp1 < comp2;
      }
      else
        return stoi(a[3]) > stoi(b[3]);
    }
    else
      return stoi(a[5]) > stoi(b[5]);
  }
  else
    return stoi(a[1]) > stoi(b[1]);
}



int main(){
  int teamsCnt, gamesCnt, i, j, k, res;
  char relleno;
  string results , teamA, teamB, pointsA, pointsB, teams[28][7], resultsTeamA, resultsTeamB, difference;
  string* team;
  bool first = true;




  while(true){
    cin >> teamsCnt;
    cin >> gamesCnt;

    if(teamsCnt == 0 and gamesCnt == 0) break;

    if(not first)
      cout << endl;

    for(i = 0 ; i < teamsCnt ; i++){
      cin >> teams[i][0];
      fill(teams[i] + 1, teams[i] + 6, "0");
      teams[i][6] = "N/A";
    }


    for(i = 0 ; i < gamesCnt ; i++){
      cin >> teamA;
      cin >> resultsTeamA;
      cin >> relleno;
      cin >> resultsTeamB;
      cin >> teamB;

      if(resultsTeamA > resultsTeamB){
        pointsA = "3";
        pointsB = "0";
      }
      else if(resultsTeamA < resultsTeamB){
        pointsA = "0";
        pointsB = "3";
      }
      else{
        pointsA = pointsB = "1";
      }

      for(j = 0 ; j < teamsCnt ; j++)
        if(teams[j] == teamA)
          team = teams[j];
      setTeams(team, pointsA, "1", resultsTeamA, resultsTeamB);


      for(j = 0 ; j < teamsCnt ; j++)
        if(teams[j] == teamB)
          team = teams[j];
      setTeams(team, pointsB, "1", resultsTeamB, resultsTeamA);
    }

    for(i = 0 ; i < teamsCnt ; i++){
      teams[i][5] = teams[i][3] - teams[i][4];
      if(teams[i][2] != "0")
        teams[i][6] = (teams[i][1] * 100) / (teams[i][2] * 3);
    }

    vector<string*> equipos(teams, teams + teamsCnt);

    sort(equipos.begin(), equipos.end(), compare);

    i = 0;
    while(i < teamsCnt){
      if(equipos[i][6] == "N/A")
        printf("%2d. %15s %3s %3s %3s %3s %3s %6s\n", i+1, equipos[i][0].c_str(), equipos[i][1].c_str(), equipos[i][2].c_str(), equipos[i][3].c_str(), equipos[i][4].c_str(), equipos[i][5].c_str(), equipos[i][6].c_str());
      else
        printf("%2d. %15s %3s %3s %3s %3s %3s %6.2lf\n", i+1, equipos[i][0].c_str(), equipos[i][1].c_str(), equipos[i][2].c_str(), equipos[i][3].c_str(), equipos[i][4].c_str(), equipos[i][5].c_str(), stod(equipos[i][6]));
      j = i + 1;
      while(j < teamsCnt and arreglosIguales(equipos[j], equipos[i])){
        if(equipos[j][6] == "N/A")
          printf("%3s %15s %3s %3s %3s %3s %3s %6s\n", "", equipos[j][0].c_str(), equipos[j][1].c_str(), equipos[j][2].c_str(), equipos[j][3].c_str(), equipos[j][4].c_str(), equipos[j][5].c_str(), equipos[j][6].c_str());
        else
          printf("%3s %15s %3s %3s %3s %3s %3s %6.2lf\n", "", equipos[j][0].c_str(), equipos[j][1].c_str(), equipos[j][2].c_str(), equipos[j][3].c_str(), equipos[j][4].c_str(), equipos[j][5].c_str(), stod(equipos[j][6]));
        j++;
      }
      i = j;
    }
    first = false;
    equipos.clear();
  }



  return 0;
}
