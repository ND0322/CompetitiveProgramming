#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

#define int long long

const int MAXN = 1e5+5;
const int INF = 1e18;

int n, m, dist[MAXN], k, a[MAXN], b[MAXN];

vector<pair<int,int>> adj[MAXN];

int32_t main(){
    cin >> n >> m >> k;

    for(int i = 1; i <= n; i++){
        cin >> a[i];
        dist[i] = INF;
    }

    for(int i = 0; i < m; i++){
        int x,y,c; cin >> x >> y >> c;

        adj[y].push_back({x,c});
    }

    dist[1] = 0;
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;


    pq.push({0,1});

    while(!pq.empty()){
        int d = pq.top().first;
        int node = pq.top().second;

        pq.pop();

        for(auto [child, weight] : adj[node]){
            if(dist[child] > d + weight){
                dist[child] = d + weight;
                pq.push({dist[child], child});
            }
        }
    }

    for(int i = 1; i <= n; i++){
        b[i] = dist[i];
        dist[i] = INF;
    }

    dist[2] = 0;


    pq.push({0,2});

    while(!pq.empty()){
        int d = pq.top().first;
        int node = pq.top().second;

        pq.pop();

        for(auto [child, weight] : adj[node]){
            if(dist[child] > d + weight){
                dist[child] = d + weight;
                pq.push({dist[child], child});
            }
        }
    }

    long long ans = 0;

    priority_queue<pair<int,pair<int,int>>> q;

    for(int i = 1; i <= n; i++){
        if(!a[i]) continue;
        if(b[i] == INF){
            if(dist[i] == INF){
                cout << "-1\n";
                return 0;
            }

            if(a[i] > k){
                cout << "-1\n";
                return 0;
            }

            k -= a[i];
            ans += dist[i] * a[i];
            continue;
        }

        if(b[i] <= dist[i]){
            ans += b[i] * a[i];
            continue;
        }

        q.push({b[i] - dist[i], {-a[i], i}});
        
    }

    
    while(!q.empty() && k >= 0){
        int dif = q.top().first;
        int c = -q.top().second.first;
        int i = q.top().second.second;

        q.pop();
        
        //cout << i << " " << dif << " " << c << "\n";
        //cout << ans << " " << k << "\n";

        if(k >= c){
            k -= c;
            ans += c * dist[i];
            continue;
        }

        ans += k * dist[i];
        
        q.push({dif,{-c + k, i}});
        break;
    }

    while(!q.empty()){
        int dif = q.top().first;
        int c = -q.top().second.first;
        int i = q.top().second.second;

        q.pop();

        ans += c * b[i];
    }

    cout << ans << "\n";











    
}