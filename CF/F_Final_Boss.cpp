#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2e5+5;

#define int long long

int n, a[MAXN], k, c[MAXN];

//bsearch and calc each elements contribution

bool can(long long x){

    long long tmp = k;
    for(int i = 1; i <= n; i++){
        tmp -= a[i] * ceil(x/((long double)c[i]));
        if(tmp <= 0) return 1;

    }

    return 0;
}

int32_t main(){
    int tt; cin >> tt;

    while(tt--){
        cin >> k >> n;

        for(int i = 1; i <= n; i++) cin >> a[i];
        for(int i = 1; i <= n; i++) cin >> c[i];

        int lo = 1;
        int hi = 5e10;

        int ans = -1;

        while(lo <= hi){
            int mid = (lo+hi)>>1;

            if(can(mid)){
                hi = mid-1;
                ans = mid;
            }
            else lo = mid+1;
        }

        cout << ans << "\n";


        //3
    }
}