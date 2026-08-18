#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define int long long

int32_t main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        vector<int> a(n+1);
        map<int,int> cnt;

        int ans = 0;

        for(int i = 1; i <= n; i++){
            cin >> a[i];
            cnt[a[i]]++;
            ans += a[i];
        }

        pair<int,int> mx = {-1,-1};

        for(auto i : cnt) mx = max(mx, {i.second, i.first});

        ans -= max(0LL, 2 * mx.first - n - 2) * mx.second;

        cout << ans << "\n";

        



        

    }
}