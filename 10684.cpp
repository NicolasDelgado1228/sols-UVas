#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, gain, num, maxGain;

    while(true){
        cin >> n;
        if(n == 0) break;

        gain = maxGain = 0;
        for(int i = 0 ; i < n ; i++){
            cin >> num;
            if(gain + num >= 0){
                gain += num;
                if(gain > maxGain) maxGain = gain;
            }
            else gain = 0;
        }

        if(maxGain > 0) cout << "The maximum winning streak is " << maxGain << ".\n" ;
        else cout << "Losing streak.\n";
    }

    return 0;
}