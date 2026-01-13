#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 15;

int n,m;

vector<int> di = {1, 0, -1, 0}, dj = {0, 1, 0, -1};

bool grid[MAXN][MAXN], vis[MAXN][MAXN];

bool dfs(int sx, int sy, int x, int y, int lx, int ly){
    if(x > n || x < 1 || y > m || y < 1) return 0;
    if(!grid[x][y]) return 0;
    if(vis[x][y] && x == sx && y == sy) return 1;
    
    
    vis[x][y] = 1;

    for(int i = 0; i < 4; i++){
        if(lx == x + di[i] && ly == y + dj[i]) continue;
        if(dfs(sx, sy, x + di[i], y + dj[i], x, y)) return 1;
    }
    return 0;
}
int main(){
    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        string s; cin >> s;

        for(int j = 0; j < m; j++) grid[i][j+1] = (s[j] == '.');
    }

    bool ans = 1;


    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(!grid[i][j]) continue;

            memset(vis, 0, sizeof(vis));

            ans &= dfs(i,j,i,j, -1, -1);
        }
    }

    cout << !ans << "\n";


}