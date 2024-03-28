#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 3e5+5;

int n,k, col[MAXN], last[MAXN];
long long a[MAXN], b[MAXN], psa[MAXN], dp[MAXN];

int main(){
    cin.tie(NULL) -> ios_base::sync_with_stdio(0);
    int tt; cin >> tt;

    while(tt--){
        cin >> n >> k;

        memset(last,0,sizeof(last));
        for(int i = 1; i <= n; i++) cin >> col[i];
        for(int i = 1; i <= k; i++) cin >> a[i];
        for(int i = 1; i <= k; i++) cin >> b[i];
        for(int i = 1; i <= n; i++) psa[i] = psa[i-1] + (col[i] == col[i-1] ? b: a)[col[i]];

        for(int i = 1; i <= n; i++){
            dp[i] = dp[i-1] + (col[i] == col[i-1] ? b : a)[col[i]];
            if(last[col[i]] && last[col[i]] != i-1) dp[i] = min(dp[i], dp[last[col[i]]+1] + psa[i-1] - psa[last[col[i]]+1] + b[col[i]]);
            last[col[i]] = i;
        }
        cout << dp[n] << "\n";
    }
    



}