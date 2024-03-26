#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2e5+5;

#define int long long

int n, m, a[MAXN], b[MAXN], psa[MAXN];

int32_t main(){
    int tt; cin >> tt;

    while(tt--){
        cin >> n >> m;

        for(int i = 1; i <= n; i++) cin >> a[i];
        for(int i = 1; i <= n; i++){
            cin >> b[i];
            psa[i] = psa[i-1] + b[i];
        }

        int ans = 1e18;
        for(int i = m; i >= 1; i--) ans = min(ans, a[i] + psa[m] - psa[i]);
        for(int i = m+1; i <= n; i++) ans += min(a[i], b[i]);
        cout << ans << "\n";
    }
}