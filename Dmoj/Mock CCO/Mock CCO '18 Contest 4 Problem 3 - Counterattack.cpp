#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

//old code is too bad to copy 

const int MAXN = 5e3+5;
const int INF = 1e9;

int n, m, dist[MAXN][2];

vector<pair<int,int>> adj[MAXN];

priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

int main(){
    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int x,y,c; cin >> x >> y >> c;

        adj[x].push_back({y,c});
        adj[y].push_back({x,c});
    }

    for(int i = 1; i <= n; i++) dist[i][0] = dist[i][1] = INF;

    dist[1][0] = 0;
    pq.push({0,1});

    while(pq.size()){
        int node = pq.top().second;
        int d = pq.top().first;

        pq.pop();
        //cout << node << " " << d << "\n";

        for(auto [child, weight] : adj[node]){
            if(dist[child][0] > d + weight){
                dist[child][1] = dist[child][0];
                dist[child][0] = d + weight;
                pq.push({dist[child][0], child}); 
            }
            else if(dist[child][0] != d + weight && dist[child][1] > d + weight){
                dist[child][1] = d+weight;
                pq.push({dist[child][1], child});
            }
        }
    }

    cout << dist[n][1] << "\n";
}