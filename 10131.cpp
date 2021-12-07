#include <bits/stdc++.h>
using namespace std;


class Elephant{
    public:
    int weight, iq, num;
    Elephant(int w, int i, int n){
        weight = w;
        iq = i;
        num = n;
    }
};

bool comp(Elephant &a, Elephant &b){
    if(a.weight == b.weight)
        return a.iq > b.iq;
    else
        return a.weight < b.weight;
}



int main(){
    int weight, iq, num = 0, i, j;
    vector<Elephant> elephants;
    
    while(cin >> weight >> iq){
        num++;
        Elephant elephant(weight, iq, num);
        elephants.push_back(elephant);
    }
    sort(elephants.begin(), elephants.end(), comp);

    vector<vector<Elephant>> tab;
    for(i = 0 ; i < elephants.size() ; i++){
        vector<Elephant> aux = {elephants[i]};
        tab.push_back(aux);
    }

    vector<Elephant> ans = {elephants[0]};
    for(i = 1 ; i < elephants.size() ; i++){
        for(j = 0 ; j < i ; j++){
            if(elephants[j].iq > elephants[i].iq and tab[j].size()+1 > tab[i].size() and elephants[i].weight != elephants[j].weight){
                vector<Elephant> aux = tab[j];
                aux.push_back(elephants[i]);
                tab[i].clear();
                tab[i] = aux;
            }
        }

        if(tab[i].size() > ans.size()){
            ans.clear();
            ans = tab[i];
        }
    }

    cout << ans.size() << endl;
    for(i = 0 ; i < ans.size() ; i++)
        cout << ans[i].num << endl;
    

    return 0;
}