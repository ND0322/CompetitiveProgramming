#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define int long long

int32_t main(){
    int tt; cin >> tt;

    while(tt--){
        int n, h, k; cin >> n >> h >> k;

        vector<int> a(n+1);

        int sm = 0;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            sm += a[i];
        }



        if(h % sm == 0){

            cout << (h / sm) * n + (h/sm-1) * k << "\n";
            continue;
        }
        int ans = (h / sm) * (n+k);
        h -= (h/sm) * sm;




        vector<int> suf(n+2);
        vector<int> pref(n+1, 1e9);

        for(int i = n; i >= 1; i--) suf[i] = max(suf[i+1], a[i]);
        for(int i = 1; i <= n; i++) pref[i] = min(pref[i-1], a[i]);

        int cur = 0;


        for(int i = 1; i <= n; i++){
            cur += a[i];
            if(cur + max(0LL, suf[i+1] - pref[i]) >= h){
                ans += i;
                break;
            }

            
        }

        cout << ans << "\n";
    }
    
}