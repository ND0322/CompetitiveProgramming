#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

typedef pair<int,int> pii;

const int MAXN = 2e5+5;

int n, m, distances[MAXN], a[MAXN];

priority_queue<pii, vector<pii>, greater<pii>> pq;

vector<pair<int,pii>> adj[MAXN];

int main(){
    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int x,y, c,r; cin >> x >> c >> y >> r;

        adj[x].push_back({y,{c,r}});
    }

    for(int i = 1; i <= n; i++) cin >> a[i];

    fill(distances+1, distances+n+1, 1e9);
    distances[1] = 0;

    //no need for pq btw

    pq.push({0,1});

    while(!pq.empty()){
        int node = pq.top().second;
        int d = pq.top().first;

        pq.pop();

        //cout << node << " " << d << "\n";

        for(pair<int,pii> c : adj[node]){
            int child = c.first;

            if(d <= c.second.first && c.second.second < distances[child]){
                distances[child] = c.second.second;
                pq.push({c.second.second+a[child], child});
            }
        }
    }

    for(int i = 1; i <= n; i++) cout << (distances[i] == 1e9 ? -1 : distances[i]) << "\n";
}


