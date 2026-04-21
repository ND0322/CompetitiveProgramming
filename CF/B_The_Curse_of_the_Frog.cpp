#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define int long long

int32_t main(){
    int tt; cin >> tt;

    while(tt--){
        int n;
        long long x; 
        cin >> n >> x;

        vector<int> a(n+1), b(n+1), c(n+1);

        for(int i = 1; i <= n; i++) cin >> a[i] >> b[i] >> c[i];

        long long pos = 0;
        for(int i = 1; i <= n; i++) pos += a[i] * (b[i] - 1);

        if(pos >= x){
            cout << "0\n";
            continue;
        }

        long long ans = 2e18;

        for(int i = 1; i <= n; i++){
            if(c[i] >= b[i] * a[i]) continue;

            long long delta = b[i] * a[i] - c[i];


            ans = min(ans, (long long)ceil((x - pos)/(long double)delta));
        }

        cout << (ans == 2e18 ? -1 : ans) << "\n";



    }
}