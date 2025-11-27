#include <bits/stdc++.h>
#include <iostream>

using namespace std;

//use ulimit -s unlimited

vector<int> di = {1, 0, -1, 0}, dj = {0, 1, 0, -1};

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int tt; cin >> tt;

    for(int _ = 1; _ <= tt; _++){

        int n,m,k ; cin >> n >> m >> k;

        vector<vector<bool>> grid(n+2, vector<bool>(m+2));
        vector<vector<bool>> vis(n+2, vector<bool>(m+2));
        vector<vector<bool>> vis2(n+2, vector<bool>(m+2));

        for(int i = 1; i <= n; i++) grid[i][0] = 1;
        for(int i = 1; i <= n; i++) grid[i][m+1] = 1;
        for(int i = 1; i <= m; i++) grid[0][i] = 1;
        for(int i = 1; i <= m; i++) grid[n+1][i] = 1;

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                char c; cin >> c;

                if(c == '#') grid[i][j] = 1;
            }
        }

        queue<pair<pair<int,int>, int>> q;

        for(int i = 0; i <= n+1; i++){
            for(int j = 0; j <= m+1; j++){
                if(grid[i][j]) q.push({{i,j}, 0});
            }
        }

        while(q.size()){
            auto [x,y] = q.front().first;
            int d = q.front().second;

            q.pop();


            if(d == k) continue;

            for(int i = 0; i < 4; i++){
                if(x + di[i] < 0 || x + di[i] > n+1 || y + dj[i] < 0 || y + dj[i] > m+1) continue;
                if(vis[x+di[i]][y+dj[i]]) continue;

                vis[x+di[i]][y+dj[i]] = 1;
                q.push({{x+di[i], y + dj[i]}, d+1});
            }
        }

        int ans = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(vis[i][j] || vis2[i][j]) continue;

                queue<pair<int,int>> qq;

                qq.push({i,j});

                vis2[i][j] = 1;

                int cnt = 0;
                
                while(qq.size()){
                    auto [x,y] = qq.front();

                    qq.pop();

                    cnt++;

                    for(int i = 0; i < 4; i++){
                        if(x + di[i] < 0 || x + di[i] > n+1 || y + dj[i] < 0 || y + dj[i] > m+1) continue;
                        if(vis[x+di[i]][y+dj[i]] || vis2[x+di[i]][y+dj[i]]) continue;

                        vis2[x+di[i]][y+dj[i]] = 1;
                        qq.push({x+di[i], y + dj[i]});
                    }
                }

                ans = max(ans, cnt);
            }
        }
        

      


        cout << "Case #" << _ << ": " << ans << "\n";
    }
}