#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int tt; cin >> tt;

    for(int _ = 1; _ <= tt; _++){

        int a,b; cin >> a >> b;

        int k; cin >> k;

        int cnt = min(2*a + 2*b - 1, a + 2*b);


        cout << "Case #" << _ << ": " << (cnt >= k ? "YES" : "NO") << "\n";
    }
}