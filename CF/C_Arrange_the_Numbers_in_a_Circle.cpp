#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define int long long


/*
place blocks of 2
both endcaps need a buffer of size 2
*/

int32_t main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        vector<int> a(n+1);

        for(int i = 1; i <= n; i++) cin >> a[i];

        int ans = 0;

        int cnt = 0;
        for(int i = 1; i <= n; i++){
            if(a[i] >= 2) ans += a[i];
            else cnt++;
        }

        if(!ans){
            cout << "0\n";
            continue;
        }

        if(ans == 2 && !cnt){
            cout << "0\n";
            continue;
        }

        if(ans <= 3){
            cout << ans + min(1LL, cnt) << "\n";
            continue;
        }

        if(cnt == n-1){
            cout << ans + min(ans / 2, cnt) << "\n";
            continue;
        }


        for(int i = 1; i <= n; i++){
            if(a[i] == 1) continue;

            int place = min(cnt, a[i] / 2 - 1);
            ans += place;

            cnt -= place;
            if(!cnt) break;
        }

        cout << ans << "\n";


        


    }
}