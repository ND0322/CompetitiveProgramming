#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 3005;

int n, a[MAXN], b[MAXN], dp[MAXN][MAXN];

int main(){
    cin >> n;

    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];

    sort(a+1, a+n+1);
    sort(b+1,b+n+1);

    dp[n+1][n+1] = 1;

    for(int i = n; i >= 1; i--){
        for(int j = n; j >= 1; j--){
            dp[i][j] = dp[i+1][j];
            for(int k = j; k <= n; k++) dp[i][j] += dp[i+1][k+1];

            cout << i << " " << j << " " << dp[i][j] << "\n";
        }
    }

    cout << dp[1][1] << "\n";
}