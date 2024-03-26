#include <bits/stdc++.h>
#include <iostream>

using namespace std;
//obvious n * a * b * b for first couple subtasks
//probably greedy optimization

const int MAXN = 205;

int n, val[MAXN], w[MAXN], x[MAXN], dp[MAXN][MAXN][MAXN],a,b;

int main(){
    cin >> n >> a >> b;

    for(int i = 0; i < n; i++) cin >> val[i] >> w[i] >> x[i];

    for(int i = n-1; i >= 0; i--){
        for(int j = 0; j <= a; j++){
            for(int k = 0; k <= b; k++){
                dp[i][j][k] = dp[i+1][j][k];

                for(int l = 0; l * x[i] <= k && l <= w[i]; l++){
                    if(j - w[i] + l >= 0) dp[i][j][k] = max(dp[i][j][k], dp[i+1][j - w[i] + l][k-l*x[i]] + val[i]);
                }
            }
        }
    }

    cout << dp[0][a][b] << "\n";
}