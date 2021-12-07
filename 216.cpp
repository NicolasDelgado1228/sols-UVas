#include <bits/stdc++.h>
using namespace std;

double minLength;
vector<pair<double,double>> path;



void solve(vector<pair<double,double>> &points, double length, vector<bool> visited, vector<pair<double,double>> graph){
   
    if(length < minLength){
        double distance;
        pair<double,double> a = graph[graph.size()-1], b;
        bool complete = true;

             
        for(double i = 0 ; i < points.size() ; i++){
            if(not visited[i]){
                visited[i] = true;
                complete = false;
                b = points[i];
                distance = pow((pow(a.first-b.first, 2) + pow(a.second-b.second, 2)), 0.5) + 16;
                vector<pair<double,double>> aux = graph;
                aux.push_back(points[i]);
                solve(points, length + distance, visited, aux);
                visited[i] = false;
            }
        }

        if(complete){
            minLength = length;
            path.clear();
            path = graph;
        }
    }
}

int main(){
    double n, i, a, b;
    int net = 1;
    while(true){
        cin >> n;
        if(n == 0) break;

        vector<pair<double,double>> points;
        vector<bool> visited(n, false);
        for(i = 0 ; i < n ; i++){
            cin >> a >> b;
            points.push_back({a, b});
        }

        minLength = 1000000.0;
        for(i = 0 ; i < n ; i++){
            vector<pair<double,double>> graph = {{points[i]}};
            vector<double> d;
            visited[i] = true;
            solve(points, 0.0, visited, graph);
            visited[i] = false;
        }

        std::cout << std::setprecision(2) << std::fixed;
        cout << "**********************************************************" << endl;
        cout << "Network #" << net++ << endl;
        for(i = 0 ; i < path.size()-1 ; i++){
            cout << "Cable requirement to connect (" << (int)path[i].first << "," << (int)path[i].second << ") to (" << (int)path[i+1].first << "," << (int)path[i+1].second << ") is " << pow((pow(path[i].first-path[i+1].first, 2) + pow(path[i].second-path[i+1].second, 2)), 0.5) + 16 << " feet.\n";
        }
        cout << "Number of feet of cable required is " << minLength << ".\n";

    }


    return 0;
}