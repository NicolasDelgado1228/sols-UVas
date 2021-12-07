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

double dist(pii &p1, pii &p2){
    return sqrt(pow(p1.fst-p2.fst,2)+pow(p1.snd-p2.snd,2));
}

double bitonic_tsp(int a, int b, vector<pii>&points, vector<vector<double>> &memo){
    double ans;
    if(a == len(points)-1) ans = dist(points[a], points[b]);
    else if(memo[a][b] == -1){
        ans = min(bitonic_tsp(a+1, b,points, memo)+dist(points[a+1],points[a]), bitonic_tsp(a+1,a,points, memo)+dist(points[b],points[a+1]));
        memo[a][b] = ans;
    }
    else ans = memo[a][b];
    return ans;
}

int main(){
    int n, x, y;
    while(cin >> n){
        vector<pii> points;
        fore(i,0,n){
            cin >> x >> y;
            points.push_back({x,y});
        }
        vector<vector<double>> memo(n+1, vector<double>(n+1, -1.0));
        printf("%.2lf\n", bitonic_tsp(0,0,points, memo));
    }
    return 0;
}