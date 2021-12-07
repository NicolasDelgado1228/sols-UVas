#include <iostream>
#include <algorithm>
#include <vector>
#include <cctype>
using namespace std;
/*
La Complejidad de esta solución se puede decir que es constante porque el tamaño máximo que puede tomar la entrada
es muy pequeño, (no tiende a infinito), de modo que el orden sería O(1). Sim embargo, la operación con más costo
computacional es el ordenamiento, haciendo que si la entrada tiende a infinito, el algoritmo tendría una complejidad
del orden O(nlogn)
*/
string toLower(string str){
  string ns;
  for(int i = 0 ; i < str.length() ; i++)
    ns.push_back(tolower(str[i]));
  return ns;
}

class Team{
  public:
    string name;
    int points, gamesPlayed, wins, ties, losses, goalDif, goalsScored, goalsAgainst;
    Team(string n){
      name = n;
      points = gamesPlayed = wins = ties = losses = goalDif = goalsScored = goalsAgainst = 0;
    }

    bool operator==(string str){
      return str == name;
    }

    bool operator<(Team team){
      if(points != team.points)
        return points > team.points;
      else if(wins != team.wins)
        return wins > team.wins;
      else if(goalDif != team.goalDif)
        return goalDif > team.goalDif;
      else if(goalsScored != team.goalsScored)
        return goalsScored > team.goalsScored;
      else if(gamesPlayed != team.gamesPlayed)
        return gamesPlayed < team.gamesPlayed;
      else{
        string nameA, nameB;
        nameA = toLower(name);
        nameB = toLower(team.name);

        return nameA < nameB;
      }

    }
};


void updateResults(vector<Team>& teams, string team, int scoreA, int scoreB){
  vector<Team>::iterator it = find(teams.begin(), teams.end(), team);


  (*it).gamesPlayed += 1;
  if(scoreA > scoreB){
    (*it).points += 3;
    (*it).wins += 1;
  }
  else if(scoreA == scoreB){
    (*it).points += 1;
    (*it).ties += 1;
  }
  else{
    (*it).losses += 1;
  }

  (*it).goalsScored += scoreA;
  (*it).goalsAgainst += scoreB;
  (*it).goalDif = (*it).goalsScored - (*it).goalsAgainst;

}



int main(){
  int tournamentsCnt, teamsCnt, gamesCnt, i, j, scoreA, scoreB;
  string tournament, teamName, game, teamA, teamB;
  vector<Team> teams;
  bool first = true;

  cin >> tournamentsCnt;
  cin.ignore();

  while(tournamentsCnt--){
    getline(cin, tournament);

    cin >> teamsCnt;
    cin.ignore();

    while(teamsCnt--){
      getline(cin, teamName);
      Team team(teamName);
      teams.push_back(team);
    }

    cin >> gamesCnt;
    cin.ignore();

    while(gamesCnt--){
      getline(cin, game);

      teamA = game.substr(0, game.find("#"));
      game.erase(0, game.find("#") + 1);
      scoreA = stoi(game.substr(0, game.find("@")));
      game.erase(0, game.find("@") + 1);

      scoreB = stoi(game.substr(0, game.find("#")));
      game.erase(0, game.find("#") + 1);
      teamB = game;

      updateResults(teams, teamA, scoreA, scoreB);
      updateResults(teams, teamB, scoreB, scoreA);
    }

    sort(teams.begin(), teams.end());

    if(not first) cout << endl;
    cout << tournament << endl;
    for(i = 0 ; i < teams.size() ; i++){
      cout << i+1 << ") ";
      cout << teams[i].name << " " << teams[i].points << "p, " << teams[i].gamesPlayed << "g (" << teams[i].wins << "-" << teams[i].ties << "-" << teams[i].losses << "), " << teams[i].goalDif << "gd (" << teams[i].goalsScored << "-" << teams[i].goalsAgainst << ")" << endl;
    }

    first = false;


    teams.clear();
  }



  return 0;
}
