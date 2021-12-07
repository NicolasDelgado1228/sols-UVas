#include <bits/stdc++.h>
using namespace std;

class City{
    public:
        double x, y;
};
class comp{
public:
  bool operator()(const pair<int,int>& l1, const pair<int,int>& l2)const{
    return l1.second > l2.second;
  }
};

int main(){
    int cases, n, r, i, x, y, bridgesCnt, c = 1;
    double dist, bridgesDist, roadsDist;

    cin >> cases;

    while(cases--){
        cin >> n >> r;
        vector<City> cities;

        for(i = 0 ; i < n ; i++){
            cin >> x >> y;
            City city;
            city.x = x + 10000;
            city.y = y + 10000;
            cities.push_back(city);
        }


       
        priority_queue<pair<int,double>, vector<pair<int,double>>, comp> pq;
        vector<bool> visited(n, false);
        pq.push(make_pair(0, 0));
        bridgesCnt = bridgesDist = roadsDist = 0;

        while(not pq.empty()){
            pair<int,double> node = pq.top();
            pq.pop();
            if(visited[node.first]) continue;
            visited[node.first] = true;

            if(node.second > r){
                bridgesDist += node.second;
                bridgesCnt++;
            }
            else
                roadsDist += node.second;
            
            for(i = 0 ; i < n ; i++){
                if(i != node.first and not visited[i]){
                    dist = sqrt(pow(fabs(cities[node.first].x - cities[i].x), 2) + pow(fabs(cities[node.first].y - cities[i].y), 2));
                    
                    pq.push(make_pair(i, dist));
                }
            }
        }

        cout << "Case #" << c++ << ": " << round(bridgesCnt) + 1 << " " << round(roadsDist) << " " << round(bridgesDist) << '\n';

        
    }


    return 0;
}