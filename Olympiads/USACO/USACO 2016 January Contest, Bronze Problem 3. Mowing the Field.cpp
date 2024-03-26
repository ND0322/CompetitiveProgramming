#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2005;

int n, grid[MAXN][MAXN];


int main(){
    freopen("mowing.in", "r", stdin);
    freopen("mowing.out", "w", stdout);
    cin >> n;

    memset(grid, -1, sizeof(grid));

    grid[1000][1000] = 0;
    int x= 1000;
    int y= 1000;

    int t= 0;

    int ans = 1e9;

    for(int i = 0; i < n; i++){
        char dir; cin >> dir;
        int step; cin >> step;

        for(int j = 0; j < step; j++){
            if(dir == 'N') x--;
            if(dir == 'S') x++;
            if(dir == 'E') y++;
            if(dir == 'W') y--;

            t++;

            if(grid[x][y] != -1) ans = min(ans, t-grid[x][y]);

            grid[x][y] = t;
        }
    }

    cout << (ans >= 1e9 ? -1 : ans) << "\n";
}