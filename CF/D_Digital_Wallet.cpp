#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1e5+5;

int n,m,k;

long long dp[MAXN][15][15], grid[MAXN][15];
//first i operations, l columns in that operations which is bounded by k,j rows
//greedy transition in o(1)

int main(){
    cin >> n >> m >> k;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++) cin >> grid[j][i];
    }

    for(int i = 1; i <= m; i++){
        sort(grid[i]+1,grid[i]+n+1);
        reverse(grid[i]+1, grid[i]+n+1);
    }

    for(int i = 1; i <= k; i++) dp[1][i][1] = grid[i][1];

    for(int i = 2; i <= m-k+1; i++){
        for(int j = 1; j < k; j++){
            for(int l = 2; l <= n; l++) dp[i][j][l] = max(dp[i][j][l], dp[i-1][j+1][l-1]) + grid[i+j-1][l];
        }
        for(int j = 1; j <= k; j++){
            for(int l = 1; l <= j; l++){
                for(int p = 1; p <= n; p++) dp[i][j][1] = max(dp[i][j][1], dp[i-1][l][p] + grid[i+j-1][1]);
            }
        }

    }

    long long ans = 0;

    for(int i = 1; i <= m-k+1; i++){
        for(int j = 0; j <= k; j++){
            for(int l = 0; l <= n; l++) ans = max(ans,dp[i][j][l]);
        }
    }

    cout << ans << "\n";
}