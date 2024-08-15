#include <bits/stdc++.h>
#include <iostream>
#include <deque>

using namespace std;

const int MAXN = 35;

int n,m, dist[MAXN][MAXN], grid[MAXN][MAXN];

vector<int> di = {2, 2, -2, 2, 1, 1, -1, -1}, dj = {1,-1,1,-1, 2, -2, 2, -2};

bool inq[MAXN][MAXN];


set<pair<int,int>> cnt[MAXN][MAXN];


int main(){
    cin >> n >> m;

    pair<int,int> s,t;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            int x; cin >> x;

            if(x == 3) s = {i,j};
            if(x == 4) t = {i,j};

            grid[i][j] = x;
            if(x == 3 || x == 4) grid[i][j] = 1;
            dist[i][j] = 1e9;
            cnt[i][j] = 0;
        }
    }

    dist[s.first][s.second] = 0;
    cnt[s.first][s.second] = 1;
    deque<pair<int,int>> dq;

    dq.push_back({s.first,s.second});

    while(dq.size()){
        auto [x,y] = dq.front();

        dq.pop_front();


        for(int i = 0; i < 8; i++){
            int cx = x + di[i];
            int cy = y + dj[i];

            if(cx < 1 || cx > n || cy < 1 || cy > m) continue;
            if(grid[cx][cy] == 2) continue;
            if(dist[cx][cy] > dist[x][y] + !grid[cx][cy]){
                dist[cx][cy] = dist[x][y] + !grid[cx][cy];
                cnt[cx][cy] = 1;

                if(grid[cx][cy]) dq.push_front({cx,cy});
                else dq.push_back({cx,cy});
            }
            else if(dist[cx][cy] == dist[x][y] + !grid[cx][cy]){
                cnt[cx][cy]++;
                if(make_pair(cx,cy) == t) cout << x << " " << y << " " << cnt[cx][cy] << "\n";
            }
        }
    }

    cout << dist[2][5] << "\n";


    cout << dist[t.first][t.second] << "\n";
    cout << cnt[t.first][t.second] << "\n";

}