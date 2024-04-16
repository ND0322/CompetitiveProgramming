#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 505;

int n, m, k, cnt = 1, targ;

bool vis[MAXN][MAXN];
char grid[MAXN][MAXN];

vector<int> di = {1,0,-1,0}, dj = {0,1,0,-1};

void dfs(int x, int y){
    if(grid[x][y] != '.') return;
    if(vis[x][y]) return;
    if(cnt++ > targ-k) return;
    vis[x][y] = 1;
    for(int i = 0; i < 4; i++){
        dfs(x+di[i], y+dj[i]);
    }
}

int main(){
    cin >> n >> m >> k;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> grid[i][j];
            targ += (grid[i][j] == '.');
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(grid[i][j] == '.'){
                dfs(i,j);
                
                for(int a = 1; a <= n; a++){
                    for(int b = 1; b <= m; b++){
                        if(grid[a][b] == '#') cout << "#";
                        if(grid[a][b] == '.') cout << (vis[a][b] ? '.' : 'X');
                    }
                    cout << "\n";
                }

                return 0;
            }
        }
    }



}