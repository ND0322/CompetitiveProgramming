#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

const int MAXN = 1e5+5;

int n,m,q, parents[MAXN], dist[MAXN][2];

vector<int> adj[MAXN];

bitset<MAXN> vis[2];

int find(int x){
    while(x != parents[x]){
        parents[x] = parents[parents[x]];
        x = parents[x];
    }

    return x;
}

void uni(int x, int y){
    x = find(x);
    y = find(y);

    if(x == y) return;
    parents[x] = y;
}

int main(){
    cin.tie(NULL) -> ios_base::sync_with_stdio(0);
    cin >> n >> m >> q;

    for(int i = 1; i <= n; i++) parents[i] = i;

    for(int i = 1; i <= m; i++){
        int x,y; cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
        uni(x,y);
    }

    while(q--){
        int x,y; cin >> x >> y;

        if(find(x) != find(y)){
            cout << "-1\n";
            continue;
        }

        vis[0].reset();
        vis[1].reset();

        queue<pair<pair<int,int>, bool>> qq;

        qq.push({{x, 0}, 0});
        qq.push({{y,0}, 1});

        vis[0][x] = 1;
        vis[1][y] = 1;

        dist[x][0] = 0;
        dist[y][1] = 0;

        while(qq.size()){
            int node = qq.front().first.first;
            int d = qq.front().first.second;
            bool side = qq.front().second;

            qq.pop();

            if(vis[!side][node]){
                cout << d + dist[node][!side] << "\n";
                break;
            }

            for(int child : adj[node]){
                if(vis[side][child]) continue;
                dist[child][side] = d+1;
                vis[side][child] = 1;
                qq.push({{child, d+1}, side});
            }
        }
    }
}