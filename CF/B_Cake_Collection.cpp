#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define int long long

int32_t main(){
    int tt; cin >> tt;

    while(tt--){
        int n,m; cin >> n >> m;

        vector<int> a(n+1);

        for(int i = 1; i <= n; i++) cin >> a[i];

        int t = max(0LL, m-n);
        t++;

        sort(a.begin(), a.end());


        long long ans = 0;
        for(int i = n-min(n,m)+1; i <= n; i++) ans += (t++ ) * a[i];

        cout << ans << "\n";

    }
}