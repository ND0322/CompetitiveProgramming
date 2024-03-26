#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

const int MAXN = 1005;

typedef pair<int,pair<int,int>> help;

int n,q, MOD, dist[MAXN][MAXN<<1];

vector<pair<int,int>> adj[MAXN];


int main(){
    cin >> n >> q;

    for(int i = 0; i < n-1; i++){
        int x,y,c; cin >> x >> y >> c;

        adj[x].push_back({y,c});
        adj[y].push_back({x,c});


        //just stall this
        if(x == 1 || y == 1) MOD = c<<1;
    }

    memset(dist, 0x3f, sizeof(dist));

    dist[1][0] = 0;
    priority_queue<help, vector<help>, greater<help>> pq;

    pq.push({0,{1,0}});

    while(!pq.empty()){
        int d = pq.top().first;
        int node = pq.top().second.first;
        int m = pq.top().second.second;

        pq.pop();

        for(auto [child, weight] : adj[node]){
            if(dist[child][(m+weight)%MOD] > d + weight){
                dist[child][(m+weight)%MOD] = d + weight;
                pq.push({d + weight, {child, (m+weight)%MOD}});
            }
        }
    }

    while(q--){
        int x, c; cin >> x >> c;

        cout << (dist[x][c%MOD] <= c ? "YES\n" : "NO\n");
    }

}