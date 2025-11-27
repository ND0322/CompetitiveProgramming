#include <bits/stdc++.h>
#include <iostream>

using namespace std;

//use ulimit -s unlimited

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int tt; cin >> tt;

    for(int _ = 1; _ <= tt; _++){

        int n; cin >> n;

        int ans = 0;

        vector<int> a(n+1);

        for(int i = 1; i <= n; i++) cin >> a[i];

        for(int i = 1; i < n; i++) ans = max(ans, abs(a[i+1] - a[i]));

        cout << "Case #" << _ << ": " << ans << "\n";
    }
}