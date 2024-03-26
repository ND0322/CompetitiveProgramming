#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <set>

using namespace std;

const int MAXN = 1e5+5;
const int INF = 1e9;

int n, m, dist[MAXN][2], cur[MAXN];

set<pair<int,int>> sp;

vector<pair<int,pair<int,int>>> adj[MAXN];
pair<pair<int,int>,int> edges[3*MAXN];

int main(){
    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int x,y,c; cin >> x >> y >> c;

        adj[x].push_back({y,{c,i}});
        adj[y].push_back({x,{c,i}});
        if(x > y) swap(x,y);
        edges[i] = {{x,y},c};
    }

    for(int i = 1; i <= n; i++){
        dist[i][0] = INF;
        dist[i][1] = INF;
        cur[i] = -1;
    }

    dist[1][0] = 0;

    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,1});

    while(pq.size()){
        auto [d,node] = pq.top();
        pq.pop();

        for(auto c : adj[node]){
            int child = c.first;
            auto [weight, id] = c.second;

            if(dist[child][0] > d + weight){
                dist[child][0] = d+weight;
                cur[child] = node;
                pq.push({d+weight, child});
            }
        }
    }

    for(int i = n; i != -1; i = cur[i]){
        if(cur[i] != -1) sp.insert({min(i, cur[i]), max(i, cur[i])});
    }

    dist[n][1] = 0;
    pq.push({0,n});

    while(pq.size()){
        auto [d,node] = pq.top();
        pq.pop();

        for(auto c : adj[node]){
            int child = c.first;
            int weight = c.second.first;

            if(dist[child][1] > d + weight){
                dist[child][1] = d + weight;
                pq.push({d+weight, child});
            }
        }
    }

    int ans = 1e9;

    for(int i = 0; i < m; i++){
        if(sp.find({edges[i].first.first, edges[i].first.second}) != sp.end()) continue;
        ans = min(ans, edges[i].second + min(dist[edges[i].first.first][0] + dist[edges[i].first.second][1],dist[edges[i].first.first][1] + dist[edges[i].first.second][0]));
    }

    //cout << dist[n][0] << "\n";

    cout << (ans + dist[n][0] >= INF ? -1 : ans + dist[n][0]) << "\n";

}