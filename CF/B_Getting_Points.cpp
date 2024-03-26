#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define int long long

int n, l,t;

long long k;

bool can(int x){
    return x * l + min((n+6LL)/7LL, 2LL*x) * t >= k;
}

int32_t main(){
    int tt; cin >> tt;

    while(tt--){
        cin >> n >> k >> l >> t;

        int lo = 0;
        int hi = n;
        int ans = -1;

        while(lo <= hi){
            int mid = (lo+hi)>>1;

            //cout << lo << " " << hi << " " << mid << "\n";

            if(can(mid)){
                ans = mid;
                hi = mid-1;
            }
            else lo = mid+1;

        }

       
        cout << n-ans << "\n";
    }
}