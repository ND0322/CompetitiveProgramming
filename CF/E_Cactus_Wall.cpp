#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

#define int long long

//simple 0/1 bfs?

const int MAXN = 2e5+5;

int n,m;

void solve(){
    cin >> n >> m;

    int dist[n+5][m+5];
    pair<int,int> rebuild[n+5][m+5];

    memset(dist,0x3f,sizeof(dist));

    bool good[n+5][m+5];
    char grid[n+5][m+5];

    memset(good, 1, sizeof(good));
    

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> grid[i][j];
            rebuild[i][j] = {-1,-1};

            if(grid[i][j] == '#'){
                good[i+1][j] = 0;
                good[i-1][j] = 0;
                good[i][j+1] = 0;
                good[i][j-1] = 0;
            }

            
        }
    }

    deque<pair<pair<int,int>,int>> dq;

    for(int i = 1; i <= n; i++){
        if(!good[i][1]) continue;
        if(grid[i][1] == '.'){
            dist[i][1] = 1;
            dq.push_back({{i,1},1});
        }
        else{
            dist[i][1] = 0;
            dq.push_front({{i,1},0});
        }
        
    }

    while(dq.size()){
        auto [x,y] = dq.front().first;
        int d = dq.front().second;
        dq.pop_front();

        vector<pair<pair<int,int>, bool>> children;

        if(x+1 <= n && y+1 <= m && good[x+1][y+1]) children.push_back({{x+1, y+1}, grid[x+1][y+1] == '.'});
        if(x-1 >= 1 && y+1 <= m && good[x-1][y+1]) children.push_back({{x-1, y+1}, grid[x-1][y+1] == '.'});
        if(x+1 <= n && y-1 >= 1 && good[x+1][y-1]) children.push_back({{x+1, y-1}, grid[x+1][y-1] == '.'});
        if(x-1 >= 1 && y-1 >= 1 && good[x-1][y-1]) children.push_back({{x-1, y-1}, grid[x-1][y-1] == '.'});
        
        for(auto c : children){
            auto [cx,cy] = c.first;
            bool weight = c.second;

            if(dist[cx][cy] > d + weight){
                dist[cx][cy] = d + weight;
                rebuild[cx][cy] = {x,y};

                if(weight) dq.push_back({{cx,cy}, d+weight});
                else dq.push_front({{cx,cy}, d+weight});
            }
        }
    }

    pair<int,int> ans = {1e9, -1};


    for(int i = 1; i <= n; i++) ans = min(ans, {dist[i][m], i});

    if(ans.first == 1e9){
        cout << "NO\n";
        return;
    }

    cout << "YES\n";

    int x = ans.second;
    int y = m;

    while(x != -1){
        grid[x][y] = '#';

        pair<int,int> nxt = rebuild[x][y];

        x = nxt.first;
        y = nxt.second;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++) cout << grid[i][j];
        cout << "\n";
    }






}
int32_t main(){
    int tt; cin >> tt;

    while(tt--) solve();
}