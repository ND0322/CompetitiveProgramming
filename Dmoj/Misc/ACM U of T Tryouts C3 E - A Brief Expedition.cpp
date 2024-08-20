#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

vector<int> di = {1,-1,0,0}, dj = {0,0,1,-1};

const int MAXN = 105;

int n, m, dist[MAXN][MAXN];

char grid[MAXN][MAXN];

int main(){
    int tt; cin >> tt;
    while(tt--){
        cin >> n >> m;

        pair<int,int> s;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                cin >> grid[i][j];
                dist[i][j] = 0;
                if(grid[i][j] == 'C') s = {i,j};
            }
        }

        queue<pair<int,int>> q;
        dist[s.first][s.second] = 0;
        q.push(s);
        vector<int> d;

        while(q.size()){
            auto [x,y] = q.front();

            q.pop();

            for(int i = 0; i < 4; i++){
                int cx = x + di[i];
                int cy = y + dj[i];

                if(cx <= 0 || cy <= 0 || cx > n || cy > m) continue;
                if(grid[cx][cy] == '#') continue;
                if(dist[cx][cy]) continue;

                dist[cx][cy] = dist[x][y]+1;

                if(grid[cx][cy] == 'S') d.push_back(dist[cx][cy]);
                q.push({cx,cy});
            }
        }

        sort(d.rbegin(), d.rend());

        int ans = d.size() * 60 + d[0];

        for(int i = 1; i < d.size(); i++) ans += 2 * d[i];

        cout << ans << "\n";



    }
}