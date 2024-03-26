#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

const int MAXN = 405;

int n, m;

vector<int> adj[MAXN][2];

bool has[MAXN][MAXN], vis[MAXN];

int main(){
    cin >> n >> m;

    for(int i = 0; i < m;i ++){
        int x,y; cin >> x >> y;

        adj[x][0].push_back(y);
        adj[y][0].push_back(x);

        has[x][y] = 1;
        has[y][x] = 1;
    }

    for(int i = 1; i <= n; i++){
        for(int j = i+1; j <= n; j++){
            if(has[i][j]) continue;
            adj[i][1].push_back(j);
            adj[j][1].push_back(i);
        }
    }

    //cout << adj[1][0].size() << " " << adj[1][1].size() << "\n";

    vis[1] = 1;
    queue<pair<int,int>> q;

    q.push({1,0});

    int d1 = 0;

    while(!q.empty()){
        auto [node, d] = q.front();

        q.pop();

        if(node == n){
            d1 = d;
            break;
        }

        for(int child : adj[node][0]){
            if(vis[child]) continue;
            vis[child] = 1;
            q.push({child,d+1});
        }
    }

    memset(vis, 0, sizeof(vis));

    q.push({1,0});

    while(!q.empty()){
        auto [node, d] = q.front();

        q.pop();

        if(node == n){
            cout << (d1 ? max(d1,d) : -1) << "\n";
            return 0;
        }

        for(int child : adj[node][1]){
            if(vis[child]) continue;
            vis[child] = 1;
            q.push({child,d+1});
        }
    }

    cout << "-1\n";


    
}