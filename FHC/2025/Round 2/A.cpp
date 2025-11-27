#include <bits/stdc++.h>
#include <iostream>

using namespace std;

//use ulimit -s unlimited

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int tt; cin >> tt;

    for(int _ = 1; _ <= tt; _++){

        int a,b; cin >> a >> b;

        bool ans = 0;
        if(a < b) ans = 0;
        if(b <= a && a <= 2 * b - 2) ans = 1;
        if(a >= 2 * b && !(a&1)) ans = 1;

        cout << "Case #" << _ << ": " << (ans ? "YES" : "NO") << "\n";
    }
}
