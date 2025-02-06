#include <bits/stdc++.h>
#include <iostream>
#include <queue>


using namespace std;

const int MAXN = 3e5+5;

int n,m, dist[MAXN], distRev[MAXN];

vector<pair<int,int>> adj[MAXN];
vector<pair<pair<int,int>,int>> edges;


int main(){
    cin >> n >> m;

    for(int i = 1; i <= m; i++){
        int x,y,c; cin >> x >> y >> c;

        adj[x].push_back({y,c});
        adj[y].push_back({x,c});
        edges.push_back({{x,y}, c});
    }    

    memset(dist, 0x3f, sizeof(dist));
    memset(distRev, 0x3f, sizeof(distRev));


    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    dist[1] = 0;
    pq.push({0, 1});

    while(pq.size()){
        auto [d, node] = pq.top();

        pq.pop();

        for(auto [child, weight] : adj[node]){
            if(dist[child] > d + weight){
                dist[child] = d + weight;

                pq.push({dist[child], child});
            }
        }
    }
    
    distRev[n] = 0;
    pq.push({0, n});

    while(pq.size()){
        auto [d, node] = pq.top();

        pq.pop();

        for(auto [child, weight] : adj[node]){
            if(distRev[child] > d + weight){
                distRev[child] = d + weight;

                pq.push({distRev[child], child});
            }
        }
    }

    for(int i = 0; i < m; i++){
        auto [x,y] = edges[i].first;
        int c = edges[i].second;

        if(dist[x] + distRev[y] + c != dist[n]) cout << "No\n";
        else cout << "Yes\n";
    }
    




}