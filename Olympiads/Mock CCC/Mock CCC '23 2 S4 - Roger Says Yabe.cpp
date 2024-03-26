#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

//state is node 1 node 2
//transitions either move one if lower case or move both to the same uppercase edge

const int MAXN = 55;

int n, m, d, adj[MAXN][52];

bool out[MAXN], vis[MAXN][MAXN];

int main(){
    cin >> n >> d >> m;

    while(d--){
        int x; cin >> x;
        out[x] = 1;
    }

    for(int i = 0; i < m; i++){
        int x,y;
        char c;

        cin >> x >> c >> y;

        if(islower(c)) adj[x][c-'a'] = y;
        else adj[x][26+c-'A'] = y;
    }

    vis[1][1] = 1;
    queue<pair<pair<int,int>,int>> q;

    q.push({{1,1},0});

    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;

        int d = q.front().second;

        q.pop();

        if(out[x] && out[y] && x != y){
            cout << d << "\n";
            return 0;
        }

        for(int i = 0; i < 26; i++){
            if(adj[x][i] && !vis[adj[x][i]][y]){
                vis[adj[x][i]][y] = 1;
                q.push({{adj[x][i], y}, d+1});
            }
            if(adj[y][i] && !vis[x][adj[y][i]]){
                vis[x][adj[y][i]] = 1;
                q.push({{x, adj[y][i]}, d+1});
            }
        }

        for(int i = 26; i < 52; i++){
            if(adj[x][i] && adj[y][i] && !vis[adj[x][i]][adj[y][i]]){
                vis[adj[x][i]][adj[y][i]] = 1;
                q.push({{adj[x][i], adj[y][i]}, d+1});
            }
        }
    }

}