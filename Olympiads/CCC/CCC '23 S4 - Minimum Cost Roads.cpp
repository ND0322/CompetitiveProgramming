#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define int long long

const int MAXN = 2005;

int n, m, dist[MAXN];

vector<pair<int,int>> adj[MAXN];


vector<pair<pair<int,int>, pair<int,int>>> edges;
/*
kruskal style and dijk replace with the edge of dijk is longer
*/

int32_t main(){
    cin >> n >> m;

    for(int i = 1; i <= m; i++){
        int x,y,l,c; cin >> x >> y >> l >> c;

        edges.push_back({{l,c}, {x,y}});
    }


    sort(edges.begin(), edges.end());


    long long ans = 0;

    for(auto [fuck, you] : edges){
        auto [l,c] = fuck;
        auto [x,y] = you;


        priority_queue<pair<int,int>, vector<pair<int,int>>, less<pair<int,int>>> pq;

        for(int i = 1; i <= n; i++) dist[i] = 1e18;


        pq.push({0,x});
        dist[x] = 0;

        while(pq.size()){
            auto [d, node] = pq.top();

            pq.pop();

            for(auto [child, weight] : adj[node]){
                if(dist[child] > d + weight){
                    dist[child] = d+weight;
                    pq.push({dist[child], child});
                }
            }
        }

        if(dist[y] > l){
            ans += c;
            adj[x].push_back({y, l});
            adj[y].push_back({x,l});
        }

    }
    cout << ans << "\n";
}   