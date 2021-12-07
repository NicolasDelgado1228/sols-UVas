#include <bits/stdc++.h>
using namespace std;

class RMQ{
public:
    vector<vector<int>> sparse;
    RMQ(vector<int> &arr){
        int n = arr.size(), k = ((int)log2(arr.size()))+1;
        for(int i = 0 ; i < n ; i++) sparse.push_back(vector<int>(k,0));

        for (int i = 0; i < n; i++) sparse[i][0] = arr[i];

        for (int j = 1; (1 << j) <= n; j++) {
            for (int i = 0; (i + (1 << j) - 1) < n; i++) {
                if (sparse[i][j - 1] < sparse[i + (1 << (j - 1))][j - 1])
                    sparse[i][j] = sparse[i][j - 1];
                else
                    sparse[i][j] = sparse[i + (1 << (j - 1))][j - 1];
            }
        }
    }

    int query(int L, int R){
        int j = (int)log2(R - L + 1);
        if (sparse[L][j] <= sparse[R - (1 << j) + 1][j]) return sparse[L][j];
        else return sparse[R - (1 << j) + 1][j];
    }
};


int main()
{
    vector<int> a = { 7, 2, 3, 0, 5, 10, 3, 18, 12 };
    RMQ rmq = RMQ(a);
    cout << rmq.query(0, 4) << endl;
    cout << rmq.query(4, 7) << endl;
    cout << rmq.query(7, 8) << endl;
    return 0;
}
