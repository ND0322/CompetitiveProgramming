#include <bits/stdc++.h>
#include <iostream>
#include <queue>


using namespace std;

const int MAXN = 1005;
const double PI = 3.1415926535;

int n, X, Y, x[MAXN], y[MAXN], r[MAXN];

vector<pair<int, double>> adj[MAXN];
double dist[MAXN][MAXN];

/*
shortest path from bottom edge to left or top edge
left to right
right to top
left to bottom
or just straight up covering the origin

multisource dijk starting at respective circles that intersect the things 
or we just dijk from all sources and store all distance arrays and look for the edges after precomp
in an optimal solution each circle will intersect with at most one other circle that has already been placed 
*/



bool sect(int x1, int y1, int x2, int y2, int r1, int r2){
    double d = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));

    if(d <= r1 - r2) return 1;
    if(d <= r2 - r1) return 1;
    if(d < r1 + r2) return 1;
    if(d == r1 + r2) return 1;
    return 0;
}

double uni(int x1, int y1, int x2, int y2, int r1, int r2){
    if(r1 < r2){
        swap(x1, x2);
        swap(y1,y2);
        swap(r1,r2);
    }
    double d = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));

    if(d >= r1 + r2) return 0;
    if(d <= r1 - r2) return -1;
    double d1 = (r1*r1 - r2*r2 + d*d) / (2*d);
    double d2 = d - d1;

    return r1 * r1 * acos(d1/r1) - d1 * sqrt(r1*r1 - d1*d1) + r2 * r2 * acos(d2/r2) - d2 * sqrt(r2*r2 - d2*d2);
}


int main(){
    cin.tie(NULL) -> ios_base::sync_with_stdio(0);
    cin >> n >> X >> Y;

    for(int i = 1; i <= n; i++) cin >> x[i] >> y[i] >> r[i];

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++) dist[i][j] = 1e9;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == j) continue;

            if(!sect(x[i], y[i], x[j], y[j], r[i], r[j])) continue;
            if(uni(x[i], y[i], x[j], y[j], r[i], r[j]) == -1) continue;
            adj[i].push_back({j, r[j] * r[j] * PI - uni(x[i], y[i], x[j], y[j], r[i], r[j])});
        }
    }


    for(int i = 1; i <= n; i++){
        dist[i][i] = 0;
        priority_queue<pair<double,int>, vector<pair<double,int>>, greater<pair<double,int>>> pq;
        pq.push({0,i});

        while(pq.size()){
            auto [d,node] = pq.top();
            pq.pop();

            if (d > dist[i][node]) continue;

            for(auto [child, weight] : adj[node]){
                if(dist[i][child] > d + weight){
                    dist[i][child] = d+weight;
                    pq.push({dist[i][child], child});
                }
            }

        }
    }

    double ans = 1e9;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            //bottom to top
            if(abs(y[i] - 0) <= r[i] && abs(y[j] - Y) <= r[j]) ans = min(ans, dist[i][j] + r[i] * r[i] * PI);
            //left to right
            if(abs(x[i] - 0) <= r[i] && abs(x[j] - X) <= r[j]) ans = min(ans, dist[i][j] + r[i] * r[i] * PI);
            //left to bottom
            if(abs(x[i] - 0) <= r[i] && abs(y[j] - 0) <= r[j]) ans = min(ans, dist[i][j] + r[i] * r[i] * PI);
            //top to right
            if(abs(y[i] - Y) <= r[i] && abs(x[j] - X) <= r[j]) ans = min(ans, dist[i][j] + r[i] * r[i] * PI);

        }
    }

    cout << (ans == 1e9 ? 0 : ans) << "\n";


}