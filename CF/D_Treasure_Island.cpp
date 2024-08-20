#include <bits/stdc++.h>
#include <iostream>
#include <map>

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,tune=native")


using namespace std;

int n, m;

vector<vector<char>> grid;
vector<vector<bool>> vis, dp[2];



bool dfs(int x, int y, int dir){
    if(x <= 0 || y <= 0 || x > n || y > m) return 0;
    if(grid[x][y] == '#') return 0;
    if(dir == 1 && x == n && y == m) return 1;
    if(dir == -1 && x == 1 && y == 1) return 1;
    if(vis[x][y]) return dp[dir == 1][x][y];
    vis[x][y] = 1;
    return dp[dir == 1][x][y] = dfs(x+dir, y, dir) | dfs(x,y+dir, dir);
}
//upperbound is min(2, n, m)
//dfs for the 1 check

int main(){
    cin.tie(NULL) -> ios_base::sync_with_stdio(0);
    cin >> n >> m;

    grid = vector<vector<char>>(n+1, vector<char>(m+1));
    vis = vector<vector<bool>>(n+1, vector<bool>(m+1, 0));
    dp[0] = vector<vector<bool>>(n+1, vector<bool>(m+1, 0));
    dp[1] = vector<vector<bool>>(n+1, vector<bool>(m+1, 0));

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++) cin >> grid[i][j];
    }

    if(!dfs(1,1,1)){
        cout << "0\n";
        return 0;
    }

    if(n == 1 || m == 1){
        cout << "1\n";
        return 0;
    }

    if(grid[2][1] == '#' || grid[1][2] == '#' || grid[n-1][m] == '#' || grid[n][m-1] == '#'){
        cout << "1\n";
        return 0;
    }

    dfs(1,1,1);
    vis = vector<vector<bool>>(n+1, vector<bool>(m+1, 0));
    dfs(n,m,-1);

    map<int,int> mp;

    for(int i =1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(!dp[0][i][j] || !dp[1][i][j]) continue;
            mp[i + j]++;
        }
    }


    for(auto i : mp){
        if(i.second == 1){
            cout << "1\n";
            return 0;
        }
    }

    cout << 2 << "\n";
}
