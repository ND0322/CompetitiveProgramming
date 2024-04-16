#include <bits/stdc++.h>
#include <iostream>
#include <set>
#include <queue>

using namespace std;

typedef pair<int,int> pii;

const int MAXN = 5e4+5;

int n, m, k, r, c, cnt[MAXN];

set<int> vis[MAXN];

vector<pii> adj[MAXN];

priority_queue<pair<long long,pii>, vector<pair<long long,pii>>, greater<pair<long long,pii>>> pq;

//multisource dijkstras
//stop propagating this guy if hes already in the set 


int main(){
    cin >> n >> m >> c >> r >> k;

    for(int i = 0 ; i < m; i++){
        int x,y,c; cin >> x >> y >> c;

        adj[x].push_back({y,c});
        adj[y].push_back({x,c});
    }

    for(int i = 1; i <= c; i++) pq.push({0,{i,i}});

    while(pq.size()){
        int d = pq.top().first;
        auto [node, id] = pq.top().second;

        pq.pop();

        if(cnt[node] == k || vis[node].find(id) != vis[node].end()) continue;

        cnt[node]++;
        vis[node].insert(id);

        for(auto [child, weight] : adj[node]){
            if(d+weight <= r && cnt[child] < k) pq.push({d+weight, {child, id}});
        }
    }

    int ans = 0;
    for(int i = c+1; i <= n; i++){
        if(cnt[i] == k) ans++;
    }

    cout << ans << "\n";

    for(int i = c+1; i <= n; i++){
        if(cnt[i] == k) cout << i << "\n";
    }
    
}
