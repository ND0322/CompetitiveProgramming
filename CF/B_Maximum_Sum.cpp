#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define int long long

const int MOD = 1e9+7;


int32_t main(){
    int tt; cin >> tt;
    while(tt--){
        int n,k; cin >> n >> k;

        vector<int> a(n);

        long long sum = 0;

        for(int i = 0; i < n; i++){
            cin >> a[i];
            sum = (sum + a[i]) % MOD;
        }

        int mx = 0;
        int r = 0;
 
        for (int i = 0; i < n; i++) {
            r += a[i];
            if (mx < r) mx = r;
            if (r < 0) r = 0;
        }
        
        long long ans = sum;

        for(int i = 1; i <= k; i++){
            ans = (ans + mx) % MOD;
            mx = (mx<<1)%MOD;
        }

        cout << (ans+MOD) % MOD << "\n";

        
    }
}