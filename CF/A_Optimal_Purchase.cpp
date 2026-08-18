#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define int long long

int32_t main(){
    int tt; cin >> tt;

    while(tt--){
        int n,a,b; cin >> n >> a >> b;

        if(b < a){
            cout << (int)(b * ceil(n / 3.0)) << "\n";
            continue;
        }

        long long ans = 0;
        if(a * 3 > b){
            ans += b * (n/3);
            n %= 3;
        }


        if(a * 2 > b){
            ans += b * (n/2);
            n %= 2;
        }

        ans += a * n;
        cout << ans << "\n";
    }
}