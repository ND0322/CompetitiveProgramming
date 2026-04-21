#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1e6+5;

int n,m, col[MAXN], dist[MAXN][2];

set<pair<int,int>> best[MAXN][2];

vector<int> adj[MAXN];

int main(){
    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        cin >> col[i];
        dist[i][0] = 1e9;
        dist[i][1] = 1e9;
    }

    for(int i = 1; i <= m; i++){
        int x,y; cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }


    queue<int> q;

    dist[1][0] = 0;
    q.push(1);

    while(q.size()){
        int node = q.front();

        q.pop();

        for(int child : adj[node]){
            if(dist[child][0] == 1e9){
                dist[child][0] = dist[node][0]+1;
                q.push(child);
            }
        }
    }

    dist[n][1] = 0;
    q.push(n);

    while(q.size()){
        int node = q.front();

        q.pop();

        for(int child : adj[node]){
            if(dist[child][1] == 1e9){
                dist[child][1] = dist[node][1]+1;
                q.push(child);
            }
        }
    }

    for(int i = 1; i <= n; i++) best[col[i]][0].insert({dist[i][0], i});
    for(int i = 1; i <= n; i++) best[col[i]][1].insert({dist[i][1], i});
    

    int ans = 1e9;

    for(int i = 1; i <= n; i++){

        if(!best[i][0].size() || !best[i][1].size()) continue;
        if((*best[i][0].begin()).second == (*best[i][1].begin()).second){
            if(best[i][0].size() > 1) ans = min(ans, (*best[i][1].begin()).first + (*next(best[i][0].begin())).first);
            if(best[i][1].size() > 1) ans = min(ans, (*best[i][0].begin()).first + (*next(best[i][1].begin())).first);
            continue;
        }
        ans = min(ans, (*best[i][0].begin()).first + (*best[i][1].begin()).first);
    }

    cout << (ans == 1e9 ? -1 : ans) << "\n";




}