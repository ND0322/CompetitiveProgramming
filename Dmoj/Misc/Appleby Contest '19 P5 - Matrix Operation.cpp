#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2005;

int n, a[MAXN][MAXN], dp[MAXN][MAXN];

//no cyclic states

int dfs(int x, int y){
    
    if(dp[x][y] == -1){
        dp[x][y] = 0;

        if(a[x-1][y] > a[x][y]) dp[x][y] = max(dp[x][y], dfs(x-1,y));
        if(a[x+1][y] > a[x][y]) dp[x][y] = max(dp[x][y], dfs(x+1,y));
        if(a[x][y-1] > a[x][y]) dp[x][y] = max(dp[x][y], dfs(x,y-1));
        if(a[x][y+1] > a[x][y]) dp[x][y] = max(dp[x][y], dfs(x,y+1));
        
        dp[x][y]++;
    }
    return dp[x][y];
}

int main(){
    cin >> n;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++) cin >> a[i][j];
    }

    memset(dp, -1, sizeof(dp));

    int ans = 0;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++) ans = max(ans, dfs(i,j));
    }

    cout << ans-1 << "\n";
}