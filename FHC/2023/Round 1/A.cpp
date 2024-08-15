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

        vector<long long> a(n+1);

        for(int i = 1; i <= n; i++) cin >> a[i];

        sort(a.begin(), a.end());

        if(n == 5){
            cout << "Case #" << _ << ": " << setprecision(6) << fixed << max((a[4] + a[5])/2.0 - (a[1] + a[3])/2.0, (a[3] + a[5])/2.0 - (a[1] + a[2])/2.0) << "\n";
            continue;
        }

        long double ans = (a[n] + a[n-1]) /2.0 - (a[1] + a[2]) /2.0;
        cout << "Case #" << _ << ": " << setprecision(6) << fixed << ans << "\n";
    }
}