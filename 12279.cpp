#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, a, b, num, c = 1;

    while(true){
        cin >> n;
        if(n == 0) break;

        a = b = 0;
        while(n--){
            cin >> num;
            if(num == 0) b++;
            else a++;
        }

        cout << "Case " << c++ << ": " << a-b << endl;
    }


    return 0;
}