#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define int long long

int32_t main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        int ans = 0;
        for(int i = 1; i <= n; i++) ans += (n / i) * (n/i);

        cout << ans << "\n";
    }
}