#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define int long long

int32_t main(){
    int tt; cin >> tt;

    while(tt--){
        int k,n; cin >> k >> n;

        vector<int> a(n);

        int mx = 0;
        int sm = 0;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            mx = max(a[i], mx);
            sm += a[i] - 1;
        }

        sm -= mx - 1;

        sm += k - mx;

        cout << sm << "\n";


    
    }
}