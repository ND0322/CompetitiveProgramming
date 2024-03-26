#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2e5+5;

#define int long long

int n, t, ca,cb, a[MAXN], psa[MAXN];

int32_t main(){
    cin >> n >> t >> ca >> cb;

    for(int i = 1; i <= n; i++){
        cin >> a[i];
        psa[i] = a[i] + psa[i-1];
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
        int nxt = (t-(i * cb))/ca;
        ans = max(ans, psa[min(i+nxt,n)] - psa[i]);
    }

    cout << ans << "\n";
}