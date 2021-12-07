#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int max(int a, int b){
    if(a > b) return a;
    else return b;
}

int main(){
    int cases, n, c, i, j, num, ans1, ans2;

    scanf("%d", &cases);
    for(c = 1 ; c <= cases ; c++){
        scanf("%d", &n);
        int heights[100000], widths[100000], tab1[100000], tab2[100000];

        for(i = 0 ; i < n ; i++){
            scanf("%d", heights + i);
        }
        for(i = 0 ; i < n ; i++){
            scanf("%d", &num);
            widths[i] = tab1[i] = tab2[i] = num;
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
            printf("Case %d. Increasing (%d). Decreasing (%d).\n", c, ans1, ans2);
        else
            printf("Case %d. Decreasing (%d). Increasing (%d).\n", c, ans2, ans1);
    }


    return 0;
}