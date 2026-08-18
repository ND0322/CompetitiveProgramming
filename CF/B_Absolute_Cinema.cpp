#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define int long long

int32_t main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;
        
        vector<int> a(n+1);
        vector<int> b(n+1);

        for(int i = 1; i <= n; i ++) cin >> a[i];
        for(int i = 1; i <= n; i++) cin >> b[i];

        for(int i = 1; i <= n;i ++){
            if(a[i] > b[i]) swap(a[i], b[i]);
        }


        int mx = 0;

        int ans = 0;

        for(int i= 1; i <= n; i++){
            mx = max(mx, a[i]);
            ans += b[i];
        }

        cout << ans + mx << "\n";
    }
}