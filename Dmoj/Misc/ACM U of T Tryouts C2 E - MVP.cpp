#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

const int MAXN = 1005;

vector<int> di = {-1,1,0,0}, dj = {0,0,-1,1};

int n, m, dist[MAXN][MAXN][2];

char grid[MAXN][MAXN];

bool vis[MAXN][MAXN];

int main(){
    int tt; cin >> tt;

    while(tt--){
        cin >> n >> m;

        vector<pair<int,int>> mines;

        pair<int,int> t;
        pair<int,int> s;

        for(int i = 1; i <= n; i++){

            for(int j = 1; j <= m; j++){
                cin >> grid[i][j];

                if(grid[i][j] == 'M'){
                    mines.push_back({i,j});
                    grid[i][j] = 'W';
                }

                if(grid[i][j] == 'C'){
                    t = {i,j};
                    grid[i][j] = 'E';
                }

                if(grid[i][j] == 'P'){
                    s = {i,j};
                    grid[i][j] = 'E';
                }

            }
        }


        for(int i = 0; i < 2; i++){
            for(int k = 1; k <= n; k++){
                for(int j = 1; j <= m; j++) dist[k][j][i] = 0;
            }
            memset(vis, 0, sizeof(vis));

            queue<pair<int,int>> q;

            q.push(mines[i]);
            vis[mines[i].first][mines[i].second] = 1;
            

            while(q.size()){
                auto [x,y] = q.front();

                q.pop();

                for(int k = 0; k < 4; k++){
                    int cx = x + di[k];
                    int cy = y + dj[k];

                    if(cx <= 0 || cy <= 0 || cx > n || cy > m) continue;
                    if(grid[cx][cy] == 'W') continue;
                    if(vis[cx][cy]) continue;
                    dist[cx][cy][i] = dist[x][y][i] + 1;
                    vis[cx][cy] = 1;
                    q.push({cx,cy});
                }
            }
        }
        

        memset(vis, 0, sizeof(vis));

        queue<pair<pair<int,int>, int>> q;

        bool flag = 1;

        q.push({s, 0});
        vis[s.first][s.second] = 1;

        while(q.size()){
            auto [x,y] = q.front().first;
            int d = q.front().second;

            q.pop();

            if(make_pair(x,y) == t){
                cout << "pwned you in " << d << " seconds eZ, learn to play n00b\n";
                flag = 0;
                break;
            }

            for(int i = 0; i < 4; i++){
                int cx = x + di[i];
                int cy = y + dj[i];

                if(cx <= 0 || cy <= 0 || cx > n || cy > m) continue;
                if(grid[cx][cy] == 'W') continue;
                if(vis[cx][cy]) continue;
                if((grid[cx][cy] == 'U' || grid[x][y] == 'U') && dist[cx][cy][0] >= dist[x][y][0] && dist[cx][cy][1] >= dist[x][y][1]) continue;

                //cout << x << " " << y << " " << cx << " " << cy << "\n";

                vis[cx][cy] = 1;
                q.push({{cx,cy}, d+1});
            }
        }

       

        if(flag) cout << "terran so broken, apologize for playing this race\n";





    }
}