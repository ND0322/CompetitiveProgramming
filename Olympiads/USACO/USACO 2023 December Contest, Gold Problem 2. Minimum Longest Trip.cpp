#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

const int MAXN = 2e5+5;

typedef pair<pair<int,int>,pair<int,int>> help; 

int n, m, dist[MAXN], dp[MAXN], id[MAXN], out[MAXN];

priority_queue<help, vector<help>, greater<help>> pq;

//dist, -id, tin, node

vector<pair<int,int>> adj[MAXN];

int main(){
    cin >> n >> m;

    while(m--){
        int x, y, c; cin >> x >> y >> c;

        //reverse cause out deg 0 starts
        adj[y].push_back({x,c});
        out[x]++;
    }

    for(int i = 1; i <= n; i++){
        if(!out[i]) pq.push({{0,0},{0,i}});
    }

    int t = 0;

    while(!pq.empty()){
        int node = pq.top().second.second;
        int d = pq.top().first.first;
        int lab = pq.top().first.second;
        int tin = pq.top().second.first;

        pq.pop();

        //cout << node << " " <<d << "\n";

        //if(d != dist[node]) continue;

        for(auto [child, c] : adj[node]){
            if(dist[child] < dist[node] + 1 || (dist[child] == dist[node] + 1 && id[child] > c)){
                dist[child] = d+1;
                dp[child] = dp[node] + c;
                id[child] = c;
            }
            

            if(!(--out[child])) pq.push({{dist[child], id[child]}, {++t, child}});
        }
    }

    for(int i = 1; i <= n; i++) cout << dist[i] << " " << dp[i] << "\n";




}