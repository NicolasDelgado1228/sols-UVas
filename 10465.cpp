#include <bits/stdc++.h>
using namespace std;


int main(){
    int option1, option2, time, a, b;
    int tab[10001];
    fill(tab, tab+10001, 0);

    while(cin >> option1 >> option2 >> time){
        
        for(int t = 0 ; t <= time ; t++){

            if(t == 0)
                tab[t] = 0;
            else{
                a = -1, b = -1;
                if(t-option1 >= 0 and tab[t-option1] != -1) a = 1 + tab[t-option1];
                if(t-option2 >= 0 and tab[t-option2] != -1) b = 1 + tab[t-option2];
                tab[t] = max(a, b);
            }
        }


        if(tab[time] != -1) cout << tab[time] << endl;
        else{
            for(int i = time-1 ; i >= 0 ; i--){
                if(tab[i] != -1){
                    cout << tab[i] << " " << time-i << endl;
                    break;
                }
            }
        }
    }


    return 0;
}