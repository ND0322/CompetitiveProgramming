#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define int long long

int gcd(int a, int b){
    return !b ? a : gcd(b, a%b);
}

int32_t main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        vector<int> a(n);

        int pref = 0;
        int suf = 0;

        for(int i = 0; i < n; i++){
            cin >> a[i];
            suf += a[i];
        }

        int ans = 0;
        for(int i = 0; i < n-1; i++){
            pref += a[i];
            suf -= a[i];
            ans = max(ans,gcd(pref,suf));
        }

        cout << ans << "\n";
    }
}