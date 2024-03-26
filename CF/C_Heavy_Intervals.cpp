#include <bits/stdc++.h>
#include <iostream>
#include <set>

using namespace std;

#define int long long

int32_t main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        vector<int> l(n);
        vector<int> sz(n);
        vector<int> c(n);
        set<int> r;

        for(int i = 0; i < n; i++) cin >> l[i];
        for(int i = 0; i < n; i++){
            int x; cin >> x;
            r.insert(x);
        }
        for(int i = 0; i < n; i++) cin >> c[i];

        sort(l.begin(), l.end());

        for(int i = n-1;i >= 0; i--){
            auto it = r.lower_bound(l[i]);
            sz[i] = *it - l[i];
            r.erase(it);
        }

        sort(sz.rbegin(), sz.rend());
        sort(c.begin(), c.end());

        long long ans = 0;

        for(int i = 0; i < n; i++) ans += sz[i] * c[i];
        cout << ans << "\n";

       
    }
}