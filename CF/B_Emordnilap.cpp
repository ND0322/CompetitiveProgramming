#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MOD = 1e9+7;

#define int long long

int32_t main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        //n choose 2 * n!

        int ans = 1;

        for(int i = 1; i <= n; i++) ans = (ans*i) % MOD;
        
        ans = (((n * (n-1)) % MOD) * ans ) % MOD;
        cout << ans << "\n";

        
    }
}