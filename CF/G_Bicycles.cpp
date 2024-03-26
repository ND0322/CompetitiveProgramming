#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

const int MAXN = 1005;
const long long INF = 1e18;

typedef pair<long long,int> pii;

int n, m, a[MAXN];

long long dist[MAXN][MAXN];

vector<pair<int,int>> adj[MAXN];

int main(){
    int tt; cin >> tt;

    while(tt--){
        cin >> n >> m;

        for(int i = 1; i <= n; i++) adj[i].clear();

        for(int i = 0; i < m; i++){
            int x,y,c; cin >> x >> y >> c;

            adj[x].push_back({y,c});
            adj[y].push_back({x,c});
        }

        for(int i = 1; i <= n; i++){
            cin >> a[i];
            for(int j = 0; j <= 1000; j++) dist[i][j] = INF;
        }

        
        dist[1][a[1]] = 0;
        priority_queue<pair<pii,int>,vector<pair<pii,int>>, greater<pair<pii,int>>> pq;

        pq.push({{0, a[1]}, 1});
        
        while(!pq.empty()){
            long long d = pq.top().first.first;
            int s = pq.top().first.second;
            int node = pq.top().second;

            pq.pop();

            s = min(s,a[node]);

            for(auto [child,w] : adj[node]){
                if(dist[child][s] > d + w * s){
                    dist[child][s] = d + w * s;
                    pq.push({{dist[child][s], s}, child});
                }
            }

        }

        long long ans = 1e18;

        for(int i = 0; i <= 1000; i++) ans = min(ans, dist[n][i]);
        cout << ans << "\n";


        
    }
}

//im bald i thought can only use each bike once