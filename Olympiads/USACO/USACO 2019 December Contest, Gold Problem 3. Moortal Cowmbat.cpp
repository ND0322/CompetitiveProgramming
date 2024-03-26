#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1e5+5;

int n, dp[MAXN][30], m, k, psa[MAXN][30], a[MAXN], dist[30][30];

//prefix sum of cost to turn the subarray to some letter
//prefix min query

int main(){
    freopen("cowmbat.in", "r", stdin);
    freopen("cowmbat.out", "w", stdout);
    cin >> n >> m >> k;

    for(int i = 1; i <= n; i++){
        char c; cin >> c;

        a[i] = c-'a'+1;
    }

    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= m; j++) cin >> dist[i][j];
    }

    for(int l = 1; l <= m; l++){
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= m; j++) dist[i][j] = min(dist[i][j], dist[i][l] + dist[l][j]);
        }
    }

    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            psa[j][i] = psa[j-1][i] + dist[a[j]][i];
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++) dp[i][j] = 1e9;
    }

    

    for(int i = k; i <= n; i++){
        for(int j = 1; j <= m; j++){
            dp[i][j] = dp[i-1][j] + dist[a[i]][j];
            for(int l = 1; l <= m; l++) dp[i][j] = min(dp[i][j], dp[i-k][l] + psa[i][j] - psa[i-k][j]);
            
        }
    }

   
    int ans = 1e9;

    for(int i = 1; i <= m; i++) ans = min(ans, dp[n][i]);
    cout << ans << "\n";






}

