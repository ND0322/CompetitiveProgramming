#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 5e5+5;

int n, c, dp[MAXN];

int main(){
    cin >> n >> c;

    int cnt = 0;
    int ans = 0;
    for(int i = 1; i <= n; i++){
        int x; cin >> x;

        if(x == c) cnt++;
        else dp[x] = max(dp[x], cnt)+1;
        ans = max(ans, dp[x]-cnt);
    }

    cout << ans + cnt << "\n";
}
