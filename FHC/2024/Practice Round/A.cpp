#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define int long long

//use ulimit -s unlimited

int32_t main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int tt; cin >> tt;

    for(int _ = 1; _ <= tt; _++){

        int n, k; cin >> n >> k;

        
        int mn = 1e9;
        for(int i = 1; i <= n; i++){
            int x; cin >> x;

            mn = min(mn, x);
        }

        bool ans = mn * max(1LL,((n-2)*2+1)) <= k;




        cout << "Case #" << _ << ": " << (ans ? "YES" : "NO") << "\n";
    }
}