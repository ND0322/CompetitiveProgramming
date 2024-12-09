#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

/*
either create a cycle with a ? or direct it towards a cycle
its always better to create a cycle
we can go from reverse and check if each cell ends with an exit
go through each ? and if it has an option to not reach an exit then we gang
*/

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n,m; cin >> n >> m;

        int di[n+1][m+1], dj[n+1][m+1];

        bool bad[n+1][m+1];

        memset(di, 0, sizeof(di));
        memset(dj, 0, sizeof(dj));
        memset(bad, 0, sizeof(bad));

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                char c; cin >> c;

                if(c == 'U'){
                    di[i][j] = -1;
                    if(i == 1) bad[i][j] = 1;                    
                }
                if(c == 'D'){
                    di[i][j] = 1;
                    if(i == n) bad[i][j] = 1;
                }
                if(c == 'L'){
                    dj[i][j] = -1;
                    if(j == 1) bad[i][j] = 1;
                }
                if(c == 'R'){
                    dj[i][j] = 1;
                    if(j == m) bad[i][j] = 1;
                }
            }
        }


        queue<pair<int,int>> q;

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(bad[i][j]) q.push({i,j});
            }
        }


        while(q.size()){
            auto [x,y] = q.front();

            q.pop();

            vector<pair<int,int>> children;

            if(x != 1 && di[x-1][y] == 1) children.push_back({x-1, y});
            if(x != n && di[x+1][y] == -1) children.push_back({x+1, y});
            if(y != 1 && dj[x][y-1] == 1) children.push_back({x, y-1});
            if(y != m && dj[x][y+1] == -1) children.push_back({x, y+1});

            for(auto [cx,cy] : children){
                if(bad[cx][cy]) continue;
                bad[cx][cy] = 1;
                q.push({cx, cy});
            }
        }

        int cnt = 0;

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++) cnt += bad[i][j];
        }

        int ans = n * m - cnt;

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(di[i][j] || dj[i][j]) continue;

                if(i > 1 && !bad[i-1][j]) continue;
                if(i < n && !bad[i+1][j]) continue;
                if(j > 1 && !bad[i][j-1]) continue;
                if(j < m && !bad[i][j+1]) continue;
                ans--;
            }
        }

        cout << ans << "\n";


        
    }
}

