#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 55;

int n, m, dp[MAXN][MAXN][MAXN][MAXN], a[MAXN][MAXN], psa[MAXN][MAXN];

int solve(int x1, int y1, int x2, int y2){
    if(x1 == x2 && y1 == y2) return 0;

    if(dp[x1][y1][x2][y2] == -1){
        dp[x1][y1][x2][y2] = 1e9;

        for(int i = x1; i < x2; i++) dp[x1][y1][x2][y2] = min(dp[x1][y1][x2][y2], solve(x1, y1, i, y2) + solve(i+1, y1, x2, y2));
        for(int i = y1; i < y2; i++) dp[x1][y1][x2][y2] = min(dp[x1][y1][x2][y2], solve(x1, y1, x2, i) + solve(x1, i+1, x2, y2));

        dp[x1][y1][x2][y2] += psa[x2][y2] - psa[x2][y1 - 1] - psa[x1 - 1][y2] + psa[x1 - 1][y1 - 1];
    }

    return dp[x1][y1][x2][y2];


}
int main(){
    cin >> n >> m;

    memset(dp, -1, sizeof(dp));

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> psa[i][j];

            psa[i][j] += psa[i-1][j] +psa[i][j-1] - psa[i-1][j-1];
        }
    }

    cout << solve(1,1,n,m) << "\n";





    


    
}