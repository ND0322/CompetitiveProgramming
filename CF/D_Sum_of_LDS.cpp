#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define int long long

int32_t main(){

    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        vector<int> a(n+1);

        int ans = (n * (n+1) * (n+2)) / 6;

        for(int i = 1; i <= n; i++) cin >> a[i];

        for(int i = 1; i < n; i++) ans -= (a[i] < a[i+1]) * i * (n-i);

        cout << ans << "\n";
    }
    
}