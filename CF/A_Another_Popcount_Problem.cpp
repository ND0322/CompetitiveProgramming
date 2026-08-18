#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define int long long


int32_t main(){
    int tt; cin >> tt;

    while(tt--){
        int a,b; cin >> a >> b;

        if(b >= a){
            cout << a << "\n";
            continue;
        }


        int ans = 0;

        for(int i = 1; i <= a; i *= 2){
            ans += min(b, a / i);
            a -= min(b, a / i) * i;
        }

        cout << ans << "\n";


    }
}