#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define int long long

int32_t main(){
    int tt; cin >> tt;

    while(tt--){
        int n, s; cin >> n >> s;

        int ans = 0;
        for(int i = 0; i < n; i++){
            int dx,dy, x, y; cin >> dx >> dy >> x >> y;

            int a = (dx == 1 ? s-x : x);
            int b = (dy == 1 ? s- y : y);

            if((a-b) % (2 * s) == 0) ans++;
        }
        cout << ans << "\n";
    }
}