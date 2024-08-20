#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <queue>

using namespace std;

const int MAXN = 505;

vector<int> di = {1,-1,0,0}, dj = {0,0,1,-1};

int n, m, k, t,cnt[MAXN*MAXN/2], comp[MAXN][MAXN];

bool grid[MAXN][MAXN];

void bfs(int x, int y){
    queue<pair<int,int>> q;
    q.push({x,y});
    comp[x][y] = t;

    while(q.size()){
        auto [x,y] = q.front();

        q.pop();

        for(int i = 0; i < 4; i++){
            int cx = x + di[i];
            int cy = y + dj[i];

            if(cx <= 0 || cy <= 0 || cx > n || cy > m) continue;
            if(!grid[cx][cy] || comp[cx][cy]) continue;
            comp[cx][cy] = t;
            q.push({cx,cy});
        }
    }
}

int main(){
    cin.tie(NULL) -> ios_base::sync_with_stdio(0);
    cin >> n >> m >> k;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            char c; cin >> c;
            grid[i][j] = (c == 'X');
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(comp[i][j] || !grid[i][j]) continue;
            t++;
            bfs(i,j); 
        }
    }

    int sz = 0;
    int sm = 0;
    for(int i = 1; i <= n-k+1; i++){
        int cur = 0;
        memset(cnt, 0, sizeof(cnt));
        for(int a = i; a < i+k; a++){
            for(int b = 1; b <= k; b++){
                if(!grid[a][b]) continue;
                if(!cnt[comp[a][b]]){
                    cur++;
                }
                cnt[comp[a][b]]++;
            }
        }

        sz++;
        sm += cur;

        for(int b = k+1; b <= n; b++){
            for(int a = i; a < i+k; a++){
                if(grid[a][b]){
                    if(!cnt[comp[a][b]]) cur++;
                    cnt[comp[a][b]]++;
                }
                if(grid[a][b-k]){
                    cnt[comp[a][b-k]]--;
                    if(!cnt[comp[a][b-k]]) cur--;
                }
            }

            //cout << i << " " << b-k+1 << " " << cur << "\n";
            sm += cur;
            sz++;
        }

    }
   

    cout << setprecision(8) << fixed << sm / (double)sz << "\n";

    
}