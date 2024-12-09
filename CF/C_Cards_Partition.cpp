#include <bits/stdc++.h>
#include <iostream>


using namespace std;

#define int long long


int32_t main(){
    int tt; cin >> tt;

    while(tt--){
        int n, k; cin >> n >> k;

        int ans = 0;
        int sm = 0;
        int mx = 0;

        for(int i = 1; i <= n; i++){
            int x; cin >> x;

            sm += x;
            mx = max(mx, x);
        }


        for(int i = 1; i <= n; i++){
            if(((sm+k)/i) * i >= sm && mx <= (sm+k)/i) ans = i;
        }

        cout << ans << "\n";
    }
}

