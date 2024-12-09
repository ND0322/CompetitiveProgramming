#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>

using namespace std;

//use ulimit -s unlimited

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int tt; cin >> tt;

    for(int _ = 1; _ <= tt; _++){

        int n; cin >> n;

        double lo = 0;
        double hi = 1e9;

        for(int i = 1; i <= n; i++){
            int l,r; cin >> l >> r;

            lo = max(lo, i/(double)r);
            hi = min(hi, i/(double)l);
        }

        double ans;

        if(hi < lo) ans = -1;
        else ans = lo;

        cout << setprecision(6) << fixed << "Case #" << _ << ": " << ans << "\n";
    }
}