#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

#define int long long

int n,m,t;

pair<int,int> hide[6];

long long ans = 1e9;

int dist[25][25][25][25];

int cnt = 0;

char grid[25][25];

vector<int> di = {1,0,-1,0};
vector<int> dj = {0,1,0,-1};

void dfs(int x, int y, int mask, int cur){

 
    if(mask == (1<<cnt)-1){
        ans = min(ans,cur);
        return;
    }

    for(int i = 0; i < cnt; i++){
        if(!(mask & (1<<i))){

            //cout << x << " " << y << " " << hide[i].first << " " << hide[i].second << " " << dist[x][y][hide[i].first][hide[i].second];
            dfs(hide[i].first, hide[i].second, mask ^ (1<<i), cur + dist[x][y][hide[i].first][hide[i].second]);
        }
    }


}

int32_t main(){
    cin >> n >> m >> t;

    

    int x,y;


    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
            if(grid[i][j] == 'H') hide[cnt++] = {i,j};
            if(grid[i][j] == 'G'){
                x = i;
                y = j;
            }
        }
    }

    memset(dist,-1,sizeof(dist));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            queue<pair<int,int>> q;

            q.push({i,j});
            dist[i][j][i][j] = 0;

            while(!q.empty()){
                int xi = q.front().first;
                int yi = q.front().second;

                q.pop();

                for(int c = 0; c < 4; c++){
                    if(xi + di[c] < 0 || xi+di[c] >= n || yi+dj[c] < 0 || yi+dj[c] >= m) continue;
                    if(dist[i][j][xi+di[c]][yi+dj[c]] != -1) continue;
                    if(grid[xi+di[c]][yi+dj[c]] == 'X') continue;

                    dist[i][j][xi+di[c]][yi+dj[c]] = dist[i][j][xi][yi]+1;
                    q.push({xi+di[c], yi+dj[c]});
                }
                
            }
        }
    }

    dfs(x,y,0,0);

    cout << ans << "\n";


}