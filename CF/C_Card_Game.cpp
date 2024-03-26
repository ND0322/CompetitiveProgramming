#include <bits/stdc++.h>
#include <iostream>


using namespace std;

const int MAXN = 2e5+5;

int n;

long long dp[MAXN][2],a[MAXN];

//i, i&1



int main(){
    int tt; cin >> tt;

    while(tt--){
        cin >> n;

        for(int i = 1; i <= n; i++) cin >> a[i];

        dp[n][1] = max(a[n],0LL);

        dp[n][0] = 0;

        //do nothing
        long long ans = max(dp[n][n&1], 0LL);

        for(int i = n-1; i >= 1; i--){
            dp[i][0] = max(dp[i+1][0], dp[i+1][1]);
            dp[i][1] = max(dp[i+1][0] + max(0LL, a[i]), dp[i+1][1] + a[i]);

            ans = max(ans, dp[i][i&1]);
        }

        cout << ans << "\n";


    }
}

