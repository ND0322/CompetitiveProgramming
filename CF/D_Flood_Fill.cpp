#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 5005;

int m, n, a[MAXN], dp[MAXN][MAXN];

int main(){
    cin >> m;

    int n = 0;

    int last = -1;
    for(int i = 1; i <= m; i++){
        int x; cin >> x;

        if(x == last) continue;
        a[++n] = x;
        last = x;
    }

    

    for(int i = n; i >= 1; i--){
        for(int j = i+1; j <= n; j++){
            if(a[i] == a[j]){
                dp[i][j] = dp[i+1][j-1] + 1;
                continue;
            }

            dp[i][j] = min(dp[i+1][j], dp[i][j-1])+1;
        }
    }

    

    cout << dp[1][n] << "\n";

}