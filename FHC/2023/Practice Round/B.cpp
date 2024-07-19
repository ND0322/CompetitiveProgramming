#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int tt; cin >> tt;

    for(int _ = 1; _ <= tt; _++){

        int r,c,a,b; cin >> r >> c >> a >> b;

        string ans;
        if(r > c) ans = "YES";
        else ans = "NO";

        cout << "Case #" << _ << ": " << ans << "\n";
    }
}