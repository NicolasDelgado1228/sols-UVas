#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<vector<int>> G;
#define fst first
#define snd second
#define pb(x) push_back(x)
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define len(vec) vec.size()

int phi(int mask){
    
}

int main(){
    int cases, mask, n;
    cin >> cases;
    while(cases--){
        string str;
        cin >> str;
        mask = 0; n = len(str);
        for(int i = n-1 ; i>=0 ; i--)
            if(str[i]=='a') mask |= (1<<n-1-i);
        cout << phi(mask) << endl;
    }
    return 0;
}