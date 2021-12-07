#include <bits/stdc++.h>
using namespace std;

int main(){
    int cases, n, c, i, j, num, ans1, ans2;

    cin >> cases;
    for(c = 1 ; c <= cases ; c++){
        cin >> n;
        vector<int> heights, widths, tab1, tab2;

        //input
        for(i = 0 ; i < n ; i++){
            cin >> num;
            heights.push_back(num);
        }
        for(i = 0 ; i < n ; i++){
            cin >> num;
            widths.push_back(num);
            tab1.push_back(num);
            tab2.push_back(num);
        }

        ans1 = ans2 = widths[0];
        for(i = 1 ; i < n ; i++){
            for(j = 0 ; j < i ; j++){
                if(heights[j] < heights[i])
                    tab1[i] = max(tab1[i], tab1[j]+widths[i]);
                if(heights[j] > heights[i])
                    tab2[i] = max(tab2[i], tab2[j]+widths[i]);
            }
            ans1 = max(ans1, tab1[i]);
            ans2 = max(ans2, tab2[i]);
        }

        if(ans1 >= ans2)
            cout << "Case " << c << ". Increasing (" << ans1 << "). Decreasing (" << ans2 << ")." << endl;
        else
            cout << "Case " << c << ". Decreasing (" << ans2 << "). Increasing (" << ans1 << ")." << endl;
    }


    return 0;
}