#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 10;

int n, dp[MAXN];

int main(){
    cin >> n;

    fill(dp, dp+n+1,1);

    for(int i = 1; i <= n-1; i++){
        int x; cin >> x;

        dp[x] *= (dp[i] + 1);
    }

    cout << dp[n] << "\n";
}