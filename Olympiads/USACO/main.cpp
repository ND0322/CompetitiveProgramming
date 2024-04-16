#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1005;
const int MOD = 1e9+7;

int n, m, parents[MAXN*MAXN], cnt;

long long ans = 1, dp[MAXN*MAXN];

bool grid[MAXN][MAXN];

int find(int x){
    while(x != parents[x]){
        parents[x] = parents[parents[x]];
        x = parents[x];
    }
    return x;
}

void uni(int x, int y){
    x = find(x);
    y = find(y);

    if(x == y) return;
    dp[y] = (dp[x] * dp[y]) % MOD;
    parents[x] = y;


}

int main(){
    freopen("cave.in", "r", stdin);
    freopen("cave.out", "w", stdout);
    cin >> n >> m;

    for(int i = 1; i <= n*m; i++){
        parents[i] = i;
        dp[i] = 1;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            char c; cin >> c;

            if(c == '.') grid[i][j] = 1;
        }
    }


    for(int i = n-1; i >= 1; i--){
        for(int j = 2; j < m; j++){
            if(!grid[i][j]) continue;
            if(grid[i][j+1]) uni(m*i+j, m*i+j+1);
            if(grid[i+1][j]) uni((i+1)*m+j, m*i + j);
        }

        for(int j = 2; j < m; j++){
            //only add answer for roots of components
            if(grid[i+1][j] && find((i+1) * m + j) == (i+1) * m + j) ans = (ans * dp[(i+1)*m+j])%MOD;
            if(grid[i][j] && find(i*m+j) == i*m+j){
                dp[i*m+j]++;
                dp[i*m+j] %= MOD;
            }
        }

        
    }

    cout << ans << "\n";

}