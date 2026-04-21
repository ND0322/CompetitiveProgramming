#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 4e5+5;

#define int long long



int n,m, dist[MAXN];
map<int,int> id[MAXN];
vector<pair<int,int>> adj[MAXN];
set<int> s[MAXN];

vector<pair<int,pair<int,int>>> edges;
int32_t main(){
    cin.tie(NULL) -> ios_base::sync_with_stdio(0);
    cin >> n >> m;

    for(int i = 1; i <= m; i++){
        int x,y,c; cin >> x >> y >> c;

        s[x].insert(c);
        s[y].insert(c);

        edges.push_back({c, {x,y}});
    }

    if(s[1].find(0) == s[1].end()) s[1].insert(0);

    int cnt = 0;
    for(int i = 1; i <= n; i++){
        int last = -1;
        for(int c : s[i]){
            id[i][c] = ++cnt;

            if(last != -1){
                adj[cnt].push_back({cnt-1,c - last});
                adj[cnt-1].push_back({cnt, c - last});
            }
            last = c;
        }
    }

    for(auto [c, fuck] : edges){
        auto [x,y] = fuck;

        adj[id[x][c]].push_back({id[y][c], 0});
        adj[id[y][c]].push_back({id[x][c], 0});
    }


    for(int i =1 ; i <= cnt; i++) dist[i] = 1e18;

    dist[id[1][0]] = 0;

    priority_queue<pair<int,int>, vector<pair<int,int>>, less<pair<int,int>>> pq;

    pq.push({0, id[1][0]});

    while(pq.size()){
        auto [d, node] = pq.top();

        pq.pop();

        //cout << node << "\n";

        for(auto [child, weight] : adj[node]){
            if(dist[child] > d + weight){
                dist[child] = d + weight;
                pq.push({dist[child], child});
            }
        }
    }


    long long ans = 1e18;
    for(int c : s[n]) ans = min(ans, dist[id[n][c]]);

    cout << ans << "\n";
    
}