#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define int long long

int32_t main(){
    int tt; cin >> tt;

    while(tt--){
        int a[3]; cin >> a[0] >> a[1] >> a[2];

        int mn = max({a[0], a[1], a[2]})-min({a[0], a[1], a[2]});

        int b[3];

        for(int i = 0; i < 3; i++){
            b[0] = a[0];
            b[1] = a[1];
            b[2] = a[2];
            b[i] = a[0] + a[1] + a[2] - a[i];

            mn = min(mn, max({b[0], b[1], b[2]})-min({b[0], b[1], b[2]}));
        }

        cout << mn << "\n";
    }
}